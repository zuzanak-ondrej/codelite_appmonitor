/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include <wx/stc/stc.h>
#include <wx/busyinfo.h>
#include <wx/clipbrd.h>

#include "event_notifier.h"
#include "workspace.h"
#include "file_logger.h"
#include "dirsaver.h"
#include "stringsearcher.h"
#include "appmonitoroutputview.h"

AppMonitorOutputView::AppMonitorOutputView(wxWindow* parent, AppMonitor* plugin, IManager* mgr)
    : AppMonitorOutputViewBase(parent)
    , m_mgr(mgr)
{
    this->Connect(XRCID("appmonitor_pause"), 
                  wxEVT_COMMAND_MENU_SELECTED, 
                  wxCommandEventHandler(AppMonitorOutputView::OnPause), 
                  NULL, 
                  (wxEvtHandler*)this);
    this->Connect(XRCID("appmonitor_pause"),
                  wxEVT_UPDATE_UI,
                  wxUpdateUIEventHandler(AppMonitorOutputView::OnPauseUpdateUI),
                  NULL,
                  (wxEvtHandler*)this);
    
    this->Connect(XRCID("appmonitor_continue"), 
                  wxEVT_COMMAND_MENU_SELECTED, 
                  wxCommandEventHandler(AppMonitorOutputView::OnContinue), 
                  NULL, 
                  (wxEvtHandler*)this);
    this->Connect(XRCID("appmonitor_continue"),
                  wxEVT_UPDATE_UI,
                  wxUpdateUIEventHandler(AppMonitorOutputView::OnContinueUpdateUI),
                  NULL,
                  (wxEvtHandler*)this);
    
    
    m_visualizer = new Visualizer(this);
    m_visualizerWrapper->Add(m_visualizer, 1, wxEXPAND);
}

AppMonitorOutputView::~AppMonitorOutputView()
{
}

void AppMonitorOutputView::StartMonitor(int PID)
{
    m_visualizer->Start(PID, m_mgr);
}

void AppMonitorOutputView::StopMonitor()
{
    m_visualizer->Stop();
}

void AppMonitorOutputView::OnPause(wxCommandEvent& event)
{
    wxUnusedVar(event);
    m_visualizer->Pause();
}

void AppMonitorOutputView::OnPauseUpdateUI(wxUpdateUIEvent& event)
{
    event.Enable(m_visualizer->IsRunning() && !m_visualizer->IsPaused());
}

void AppMonitorOutputView::OnContinue(wxCommandEvent& event)
{
    wxUnusedVar(event);
    m_visualizer->Continue();
}

void AppMonitorOutputView::OnContinueUpdateUI(wxUpdateUIEvent& event)
{
    event.Enable(m_visualizer->IsRunning() && m_visualizer->IsPaused());
}

void AppMonitorOutputView::ApplySettings(AppMonitorSettings *settings)
{
    m_visualizer->ApplySettings(settings);
}