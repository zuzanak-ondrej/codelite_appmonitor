/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include <wx/xrc/xmlres.h>
#include <wx/wx.h>
#include <wx/busyinfo.h>

#include "event_notifier.h"
#include "workspace.h"
#include "file_logger.h"
#include "dirsaver.h"
#include "environmentconfig.h"
#include "async_executable_cmd.h"
#include "appmonitorsettingsdialog.h"
#include "appmonitoroutputview.h"
#include "appmonitor.h"
#include "appmonitorui.h"
#include "sigarmanager.h"
#include "sigarclass.h"
#include "icons/monitor24.png.h"

static AppMonitor* thePlugin = NULL;

wxDECLARE_EVENT(wxEVT_CHILD_PID_CHECKER_OUTPUT, wxCommandEvent);

// Define the plugin entry point
CL_PLUGIN_API IPlugin* CreatePlugin(IManager* manager)
{
    if(thePlugin == NULL) {
        thePlugin = new AppMonitor(manager);
    }
    return thePlugin;
}

CL_PLUGIN_API PluginInfo* GetPluginInfo()
{
    static PluginInfo info;
    info.SetAuthor(wxT("Zuzaňák"));
    info.SetName(wxT("AppMonitor"));
    info.SetDescription(_("Application_Monitor"));
    info.SetVersion(wxT("v1.0"));
    return &info;
}

CL_PLUGIN_API int GetPluginInterfaceVersion()
{
    return PLUGIN_INTERFACE_VERSION;
}

AppMonitor::AppMonitor(IManager* manager)
    : IPlugin(manager)
    , m_childPIDChecker(m_mgr)
{
    m_longName = _("Application_Monitor");
    m_shortName = _("AppMonitor");
    
    m_terminal.Bind(wxEVT_TERMINAL_COMMAND_EXIT, &AppMonitor::OnProcessTerminated, this);
    m_terminal.Bind(wxEVT_TERMINAL_COMMAND_OUTPUT, &AppMonitor::OnProcessOutput, this);

    m_childPIDChecker.Bind(wxEVT_CHILD_PID_CHECKER_OUTPUT, &AppMonitor::OnCheckerOutput, this);
    
    m_mgr->GetTheApp()->Connect(ID_TOOL_STOP_PROCESS,
                                wxEVT_COMMAND_MENU_SELECTED,
                                wxCommandEventHandler(AppMonitor::OnStopProcess),
                                NULL,
                                (wxEvtHandler*)this);
    m_mgr->GetTheApp()->Connect(ID_TOOL_STOP_PROCESS,
                                wxEVT_UPDATE_UI,
                                wxUpdateUIEventHandler(AppMonitor::OnStopProcessUI),
                                NULL,
                                (wxEvtHandler*)this);
    
    m_mgr->GetTheApp()->Connect(XRCID("appmonitor_run"), 
                                wxEVT_COMMAND_MENU_SELECTED, 
                                wxCommandEventHandler(AppMonitor::OnRun), 
                                NULL, 
                                (wxEvtHandler*)this);
    m_mgr->GetTheApp()->Connect(XRCID("appmonitor_run"),
                                wxEVT_UPDATE_UI,
                                wxUpdateUIEventHandler(AppMonitor::OnAppMonitorUI),
                                NULL,
                                (wxEvtHandler*)this);
    
    m_mgr->GetTheApp()->Connect(XRCID("appmonitor_settings"), 
                                wxEVT_COMMAND_MENU_SELECTED, 
                                wxCommandEventHandler(AppMonitor::OnSettings), 
                                NULL, 
                                (wxEvtHandler*)this);
    m_mgr->GetTheApp()->Connect(XRCID("appmonitor_settings"),
                                wxEVT_UPDATE_UI,
                                wxUpdateUIEventHandler(AppMonitor::OnAppMonitorUI),
                                NULL,
                                (wxEvtHandler*)this);                             
                   
    EventNotifier::Get()->Connect(
        wxEVT_WORKSPACE_LOADED, wxCommandEventHandler(AppMonitor::OnWorkspaceLoaded), NULL, this);
    EventNotifier::Get()->Connect(
        wxEVT_WORKSPACE_CLOSED, wxCommandEventHandler(AppMonitor::OnWorkspaceClosed), NULL, this);
                   
    m_outputView = new AppMonitorOutputView(m_mgr->GetOutputPaneNotebook(), this, m_mgr);   
    m_mgr->GetOutputPaneNotebook()->AddPage(m_outputView, _("AppMonitor"), false, monitor24_png_to_wx_bitmap()); 
    
    m_tabHelper.reset(new clTabTogglerHelper(_("AppMonitor"), m_outputView, "", NULL));
    
    m_settings = new AppMonitorSettings();
    GetSettings()->LoadFromConfig();
    GetSettings()->SaveToConfig();
    
    ApplySettings();
}

AppMonitor::~AppMonitor()
{
    wxDELETE(m_settings);
}

clToolBar* AppMonitor::CreateToolBar(wxWindow* parent)
{
    // Create the toolbar to be used by the plugin
    clToolBar* tb(NULL);
    return tb;
}

void AppMonitor::CreatePluginMenu(wxMenu* pluginsMenu)
{
    wxMenu* menu = new wxMenu();
    wxMenuItem* item(NULL);
    
    item = new wxMenuItem(menu, XRCID("appmonitor_run"), _("&Run AppMonitor"), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);

    menu->AppendSeparator();
    
    item = new wxMenuItem(menu, XRCID("appmonitor_settings"), _("&Settings..."), wxEmptyString, wxITEM_NORMAL);
    menu->Append(item);
    
    item = new wxMenuItem(pluginsMenu, wxID_ANY, _("AppMonitor"), wxEmptyString, wxITEM_NORMAL, menu);
    item->SetBitmap(monitor24_png_to_wx_bitmap());
    pluginsMenu->Append(item);
}

void AppMonitor::UnPlug()
{
    m_tabHelper.reset(NULL);
    m_terminal.Unbind(wxEVT_TERMINAL_COMMAND_EXIT, &AppMonitor::OnProcessTerminated, this);
    m_terminal.Unbind(wxEVT_TERMINAL_COMMAND_OUTPUT, &AppMonitor::OnProcessOutput, this);
    
    m_childPIDChecker.Unbind(wxEVT_CHILD_PID_CHECKER_OUTPUT, &AppMonitor::OnCheckerOutput, this);
    
    m_mgr->GetTheApp()->Disconnect(XRCID("appmonitor_run"), 
                                   wxEVT_COMMAND_MENU_SELECTED, 
                                   wxCommandEventHandler(AppMonitor::OnRun), 
                                   NULL, 
                                   (wxEvtHandler*)this);
    m_mgr->GetTheApp()->Disconnect(XRCID("appmonitor_run"),
                                   wxEVT_UPDATE_UI,
                                   wxUpdateUIEventHandler(AppMonitor::OnAppMonitorUI),
                                   NULL,
                                   (wxEvtHandler*)this);
    
    m_mgr->GetTheApp()->Disconnect(XRCID("appmonitor_settings"), 
                                   wxEVT_COMMAND_MENU_SELECTED, 
                                   wxCommandEventHandler(AppMonitor::OnSettings), 
                                   NULL, 
                                   (wxEvtHandler*)this);
    m_mgr->GetTheApp()->Disconnect(XRCID("appmonitor_settings"),
                                   wxEVT_UPDATE_UI,
                                   wxUpdateUIEventHandler(AppMonitor::OnAppMonitorUI),
                                   NULL,
                                   (wxEvtHandler*)this); 
    
    EventNotifier::Get()->Disconnect(
        wxEVT_WORKSPACE_LOADED, wxCommandEventHandler(AppMonitor::OnWorkspaceLoaded), NULL, this);
    EventNotifier::Get()->Disconnect(
        wxEVT_WORKSPACE_CLOSED, wxCommandEventHandler(AppMonitor::OnWorkspaceClosed), NULL, this);
    
    // before this plugin is un-plugged we must remove the tab we added
    for(size_t i = 0; i < m_mgr->GetOutputPaneNotebook()->GetPageCount(); i++) {
        if(m_outputView == m_mgr->GetOutputPaneNotebook()->GetPage(i)) {
            m_mgr->GetOutputPaneNotebook()->RemovePage(i);
            m_outputView->Destroy();
            break;
        }
    }
}

void AppMonitor::OnWorkspaceLoaded(wxCommandEvent& event)
{
    ApplySettings();
    event.Skip();
}

void AppMonitor::OnWorkspaceClosed(wxCommandEvent& event)
{
    ApplySettings();
    event.Skip();
}

bool AppMonitor::IsReady(wxUpdateUIEvent& event)
{
    bool ready = !m_mgr->IsBuildInProgress() && !m_terminal.IsRunning();
    int id = event.GetId();
    if(id == XRCID("appmonitor_run")) 
    {
        ready &= !m_mgr->GetWorkspace()->GetActiveProjectName().IsEmpty();
    }
    return ready;
}

void AppMonitor::ApplySettings()
{
    m_outputView->ApplySettings(m_settings);
}

void AppMonitor::SwitchToMyPage()
{
    for(size_t i = 0; i < m_mgr->GetOutputPaneNotebook()->GetPageCount(); i++) 
    {
        if(m_outputView == m_mgr->GetOutputPaneNotebook()->GetPage(i)) 
        {
            m_mgr->GetOutputPaneNotebook()->ChangeSelection(i);
            break;
        }
    }
}

void AppMonitor::OnRun(wxCommandEvent& event)
{
    CHECK_CL_SHUTDOWN()
    ProjectPtr project = m_mgr->GetSelectedProject();
    if(project) 
    {
        CheckProject(project->GetName());
    }
}

void AppMonitor::OnSettings(wxCommandEvent& event)
{
    AppMonitorSettingsDialog dialog(m_mgr->GetTheApp()->GetTopWindow(), m_settings);
    if(dialog.ShowModal() == wxID_SAVE) 
    {
        ApplySettings();
    }
}

void AppMonitor::CheckProject(const wxString& projectName)
{   
    if(m_terminal.IsRunning()) 
    {
        ::wxMessageBox(_("Another instance is already running. Please stop it before executing another one"),
                       "CodeLite",
                       wxICON_WARNING | wxCENTER | wxOK);
        return;
    }

    wxString errMsg;
    ProjectPtr project = m_mgr->GetWorkspace()->FindProjectByName(projectName, errMsg);
    wxString path = project->GetFileName().GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
    
    
    wxString workingDir;
    wxString command2 = m_mgr->GetProjectExecutionCommand(projectName, workingDir);
#ifdef __WXMSW__ // Windows;
    wxString command = wxString() << "\"" << command2 << "\"";
#else
    wxString command = command2;
#endif
    
    DirSaver ds;
    EnvSetter envGuard(m_mgr->GetEnv());
    wxSetWorkingDirectory(path);
    wxSetWorkingDirectory(workingDir);
    m_mgr->AppendOutputTabText(kOutputTab_Output, _("Launching AppMonitor...\n"));
    
    m_mgr->AppendOutputTabText(kOutputTab_Output, wxString() << _("Working directory is set to: ") << ::wxGetCwd() << "\n");
    m_mgr->AppendOutputTabText(kOutputTab_Output, wxString() << _("AppMonitor: command: ") << command << "\n");
    
    m_terminal.ExecuteConsole(command, "", false, wxString::Format("AppMonitor: %s", projectName));
    
    m_childPIDChecker.Start(m_terminal.GetPID(), m_settings);
}

void AppMonitor::OnProcessOutput(clCommandEvent& event)
{
    m_mgr->AppendOutputTabText(kOutputTab_Output, event.GetString());
}

void AppMonitor::OnCheckerOutput(wxCommandEvent& event)
{
    long PID = wxAtol(event.GetString());
    
    if (PID > 0)
    {
        m_mgr->AppendOutputTabText(kOutputTab_Output, 
            wxString() << _("AppMonitor: event OnCheckerOutput catch with ") << PID << _(" PID\n"));
        m_outputView->StartMonitor(PID);
        SwitchToMyPage();
    }
    else
    {
        m_mgr->AppendOutputTabText(kOutputTab_Output, _("AppMonitor: attach process failed\n"));
        ::wxMessageBox(_("Attach process failed."),
                       "CodeLite",
                       wxICON_WARNING | wxCENTER | wxOK);
    }
}

void AppMonitor::OnProcessTerminated(clCommandEvent& event)
{
    m_outputView->StopMonitor();
    
    m_mgr->AppendOutputTabText(kOutputTab_Output, _("AppMonitor: end\n"));
    wxWindowDisabler disableAll;
    wxBusyInfo wait(_("Please wait, working..."));
    m_mgr->GetTheApp()->Yield();

    SwitchToMyPage();
}

void AppMonitor::OnAppMonitorUI(wxUpdateUIEvent& event)
{
    CHECK_CL_SHUTDOWN()
    event.Enable(IsReady(event));
}

void AppMonitor::StopProcess()
{
    m_mgr->AppendOutputTabText(kOutputTab_Output, _("AppMonitor: -- PROCESS TERMINATED\n"));
    m_outputView->StopMonitor();
    if (m_terminal.IsRunning()) m_terminal.Terminate();
}

void AppMonitor::OnStopProcess(wxCommandEvent& event)
{
    wxUnusedVar(event);
    StopProcess();
}

void AppMonitor::OnStopProcessUI(wxUpdateUIEvent& event) 
{ 
    event.Enable(IsRunning()); 
}