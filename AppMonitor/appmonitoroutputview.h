/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef APPMONITOROUTPUTVIEW_H
#define APPMONITOROUTPUTVIEW_H

#include <wx/valnum.h>
#include <wx/tipwin.h>

#include "appmonitorui.h"
#include "appmonitor.h"
#include "identifiers.h"
#include "visualizer.h"
#include "appmonitorsettings.h"

/**
 * AppMonitorOutputViewBase is generated by formbuilder in appmonitorui.h.
 * @class AppMonitorOutputView
 * @brief Displays module controls and graphs. It monitors process in cycles.
 */
class AppMonitorOutputView : public AppMonitorOutputViewBase
{
public:
    /**
     * @param parent
     * @param plugin
     * @param mgr
     */
    AppMonitorOutputView(wxWindow* parent, AppMonitor* plugin, IManager* mgr);
    ~AppMonitorOutputView();

    /**
     * @brief Starts monitor process with the PID.
     * @param PID - PID monitored process
     */
    void StartMonitor(int PID);
    
    /**
     * @brief Stops monitoring.
     */
    void StopMonitor();
    
    /**
     * @brief Sets environment by setting.
     * @param settings
     */
    void ApplySettings(AppMonitorSettings *settings);
    
protected:

    void OnPause(wxCommandEvent& event);
    void OnPauseUpdateUI(wxUpdateUIEvent& event);
    void OnContinue(wxCommandEvent& event);
    void OnContinueUpdateUI(wxUpdateUIEvent& event);
    
    IManager *m_mgr;
    Visualizer *m_visualizer;
};

#endif // APPMONITOROUTPUTVIEW_H