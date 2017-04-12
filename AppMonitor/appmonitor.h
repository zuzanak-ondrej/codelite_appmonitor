/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef __AppMonitor__
#define __AppMonitor__

#include "plugin.h"
#include "appmonitorui.h"
#include "childpidchecker.h"
#include "TerminalEmulator.h"
#include "clTabTogglerHelper.h"
#include "appmonitorsettings.h"

class AppMonitorOutputView;

class AppMonitor : public IPlugin
{
public:
    AppMonitor(IManager *manager);
    ~AppMonitor();

    enum
    {
        ID_TOOL_STOP_PROCESS = 9500
    };

    //--------------------------------------------
    //Abstract methods
    //--------------------------------------------
    virtual clToolBar *CreateToolBar(wxWindow *parent);
    
    /**
     * @brief Adds plugin menu to the "Plugins" menu item in the menu bar.
     */
    virtual void CreatePluginMenu(wxMenu *pluginsMenu);
    
    /**
     * @brief Unplugs the plugin. Perform here any cleanup needed (e.g. unbind events, destroy allocated windows)
     */
    virtual void UnPlug();
    
    /**
     * @brief Stops the current running process using SIGTERM.
     */
    void StopProcess();
    
    /**
     * @brief Returns true if test is not runnging and GUI can respond.
     * @param event
     * @return Plugin status.
     */
    bool IsReady(wxUpdateUIEvent& event);
        
    /**
     * @brief Returns true if monitoring is currently running.
     * @return true if running
     */
    bool IsRunning() const
    {
        return m_terminal.IsRunning();
    }

    /**
     * @brief After settings dialogue is closed, settings are reapplied in plugin.
     */
    void ApplySettings();
    
    AppMonitorSettings* const GetSettings()
    {
        return m_settings;
    };

protected:
    
    AppMonitorOutputView *m_outputView; ///< Main plugin UI pane.
    TerminalEmulator m_terminal;
    TerminalEmulator m_helperTerminal;
    wxProcess *m_process;
    ChildPIDChecker m_childPIDChecker;
    clTabTogglerHelper::Ptr_t m_tabHelper;
    AppMonitorSettings *m_settings;
    
    void OnWorkspaceLoaded(wxCommandEvent& event);
    void OnWorkspaceClosed(wxCommandEvent& event);
    
    void OnProcessOutput(clCommandEvent& event);
    void OnProcessTerminated(clCommandEvent& event);
    
    /**
     * @brief Captures PID and calls StartMonitor.
     * @param event
     */
    void OnCheckerOutput(wxCommandEvent& event);
    
    /**
     * @brief Stops currently running process.
     * @param event
     */
    void OnStopProcess(wxCommandEvent& event);
    void OnStopProcessUI(wxUpdateUIEvent& event);
    
    /**
     * @brief Starts active project and monitor.
     * @param projectName
     */
    void CheckProject(const wxString& projectName);
    
    /**
     * @brief After start and end monitoring shows plugin Notebook.
     */
    void SwitchToMyPage();
    
    /**
     * @brief Settings dialog invoked.
     * @param event
     */
    void OnSettings(wxCommandEvent& event);
    
    void OnRun(wxCommandEvent& event);
    void OnAppMonitorUI(wxUpdateUIEvent& event);
    
};

#endif //AppMonitor
