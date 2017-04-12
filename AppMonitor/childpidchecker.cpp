/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "childpidchecker.h"

wxDEFINE_EVENT(wxEVT_CHILD_PID_CHECKER_OUTPUT, wxCommandEvent);

ChildPIDChecker::ChildPIDChecker(IManager* input_mgr)
       : m_timer(this, XRCID("childpidchecker_timer"))
{
    m_mgr = input_mgr;
    
    this->Connect(m_timer.GetId(), wxEVT_TIMER, wxTimerEventHandler(ChildPIDChecker::OnTimer));
}

ChildPIDChecker::~ChildPIDChecker()
{
    this->Disconnect(m_timer.GetId(), wxEVT_TIMER, wxTimerEventHandler(ChildPIDChecker::OnTimer));
}

void ChildPIDChecker::Start(long PID, AppMonitorSettings *settings)
{
    m_checkPID = PID;
    m_outputLogFileName = wxFileName(clStandardPaths::Get().GetTempDir(), wxT("AppMonitor.log")).GetFullPath();
    
    m_mgr->AppendOutputTabText(kOutputTab_Output, wxString::Format("AppMonitor: created terminal with PID: %ld\n", m_checkPID));
    if (wxFileExists(m_outputLogFileName))
    {
        wxRemoveFile(m_outputLogFileName);
    }
    
    PrepareCmd(settings);
    m_numAttempts = 0;
    m_timer.Start(WAIT_TIME);
}

void ChildPIDChecker::PrepareCmd(AppMonitorSettings *settings)
{
    
    wxString sPID = wxString::Format(wxT("%ld"), m_checkPID);
    
#ifdef __WXMSW__ // Windows;
    
    //m_cmd = wxString::Format("wmic /OUTPUT:'%s' process where (ParentProcessId=%ld) get ProcessId", m_outputLogFileName, sPID);
    m_cmd = wxString::Format(settings->GetCommandForWXMSW(), m_outputLogFileName, sPID);
    //m_cmd = wxString::Format("SET \"xprvar=\" & FOR /F \"usebackq skip=1\" %%a IN (`wmic process where ^(ParentProcessId^=%ld^) get ProcessId`) DO IF NOT DEFINED xprvar SET \"xprvar=%%a\" & wmic /OUTPUT:\"%s\" process where ^(ParentProcessId^=%%a^) get ProcessId", m_checkPID, m_outputLogFileName);
    m_mgr->AppendOutputTabText(kOutputTab_Output, wxString() << _("AppMonitor: Windows command: ") << m_cmd << "\n");
    
#elif defined(__WXGTK__) // Gtk;

    m_cmd = wxString::Format(settings->GetCommandForWXGTK(), sPID, m_outputLogFileName);
    m_mgr->AppendOutputTabText(kOutputTab_Output, wxString() << _("AppMonitor: Gtk command: ") << m_cmd << "\n");
    //m_cmd = wxString::Format("pgrep -P `pgrep -P %ld` > %s", check_PID, m_outputLogFileName);
    
#elif defined(__WXMAC__) // Mac;

    m_cmd = wxString::Format(settings->GetCommandForWXMAC(), sPID, m_outputLogFileName);
    m_mgr->AppendOutputTabText(kOutputTab_Output, wxString() << _("AppMonitor: Mac command: ") << m_cmd << "\n");

#else

    m_cmd = wxString::Format("");
    m_mgr->AppendOutputTabText(kOutputTab_Output, _("AppMonitor: ERROR, unknown platform\n"));

#endif

}

wxUint32 ChildPIDChecker::CheckFile()
{
    wxUint32 child_PID = 0;
    
    wxFileInputStream inputStream(m_outputLogFileName);

    if (inputStream.IsOk() && !inputStream.Eof())
    {   
        wxTextInputStream text(inputStream);
        text >> child_PID;
#ifdef __WXMSW__ // Windows;    
        text >> child_PID;
        text >> child_PID;
#endif
        if (child_PID != 0)
        {
            m_mgr->AppendOutputTabText(kOutputTab_Output, 
                wxString() << _("AppMonitor: PID found ") << child_PID << _(", attempt ") << m_numAttempts << "\n");
            
            wxCommandEvent eventOutput(wxEVT_CHILD_PID_CHECKER_OUTPUT);
            eventOutput.SetString(wxString() << child_PID);
            AddPendingEvent(eventOutput);
            
            wxRemoveFile(m_outputLogFileName);
            return child_PID;
        }
    }
    
    return child_PID;
}

void ChildPIDChecker::OnTimer(wxTimerEvent& event)
{
    m_timer.Stop();
    
    if (m_numAttempts > 0)
    {
        if (CheckFile() != 0)
        {
            return; // done
        }
    }
    
    if (m_numAttempts <= MAX_ATTEMPTS)
    {
        m_numAttempts ++;
        m_helperTerminal.ExecuteNoConsole(m_cmd, "");
        m_timer.Start(WAIT_TIME);
    }
    else
    {
        wxCommandEvent eventOutput(wxEVT_CHILD_PID_CHECKER_OUTPUT);
        eventOutput.SetString(wxString() << 0);
        AddPendingEvent(eventOutput);
    }
}