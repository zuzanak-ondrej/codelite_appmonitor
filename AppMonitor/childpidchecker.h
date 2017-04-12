/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef CHILDPIDCHECKER_H
#define CHILDPIDCHECKER_H

#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/xrc/xmlres.h>
#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>

#include "plugin.h"
#include "TerminalEmulator.h"
#include "appmonitorsettings.h"
#include "workspace.h"

#define WAIT_TIME 200 // millisecond
#define MAX_ATTEMPTS 10

wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_CL, wxEVT_CHILD_PID_CHECKER_OUTPUT, wxCommandEvent);

/**
 * @class ChildPIDChecker
 * @brief This class determines running process PID, launched in terminal.
 */
class ChildPIDChecker : public wxEvtHandler
{
public:
    /**
     * @param input_mgr
     */
    ChildPIDChecker(IManager* input_mgr);
    ~ChildPIDChecker();

    /**
     * @brief Starts timer and check process launched in terminal.
     * @param PID of terminal
     * @param settings
     */
    void Start(long PID, AppMonitorSettings *settings);
    
    /**
     * @brief Checks temporary file and performs asking command.
     * @param event
     */
    void OnTimer(wxTimerEvent& event);


private:

    /**
     * @brief Prepares request command to PID by platform.
     * @param settings
     */
    void PrepareCmd(AppMonitorSettings *settings);
    
    /**
     * @brief Checks temporary file for PID.
     * @return PID of process or zero if failed
     */
    wxUint32 CheckFile();

    IManager* m_mgr;
    long m_checkPID; /**PID of terminal */
    long m_numAttempts; /**number of attempts */
    wxString m_outputLogFileName;
    wxString m_cmd;

    TerminalEmulator m_helperTerminal;

    wxTimer m_timer;
};

#endif // CHILDPIDCHECKER_H
