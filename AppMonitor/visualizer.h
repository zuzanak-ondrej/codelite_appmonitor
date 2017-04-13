/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <wx/sizer.h>
#include <wx/timer.h>
#include <wx/event.h>
#include <wx/stattext.h>
#include <wx/datetime.h>
#include <wx/filefn.h> 
#include <wx/textfile.h>

#include "workspace.h"
#include "simpledynamicchart.h"
#include "multipledynamicchart.h"
#include "sigarmanager.h"
#include "appmonitorsettings.h"
#include "chartlegend.h"
#include "plugin.h"

/**
 * @class Visualizer
 * @brief This class displays charts runtime information. It monitors process in cycles.
 */
class Visualizer : public wxBoxSizer, wxEvtHandler
{
public:
    /**
     * @param parent
     */
    Visualizer(wxWindow* parent);
    ~Visualizer();

    /**
     * @brief Test of running
     * @return true if monitoring is running
     */
    bool IsRunning()
    {
        return m_isRunning;
    }
    
    /**
     * @brief Test pause
     * @return true if monitoring is paused
     */
    bool IsPaused()
    {
        return m_isPaused;
    }

    /**
     * @brief Starts monitoring.
     * @param PID - PID of monitored process
     * @param mgr
     */
    void Start(int PID, IManager *mgr);
    
    /**
     * @brief Ends monitoring
     */
    void Stop();
    
    /**
     * @brief Resets values in graphs.
     */
    void Reset();
    
    /**
     * @brief Pauses monitoring.
     */
    void Pause();
    
    /**
     * @brief Recovers monitoring.
     */
    void Continue();
    
    /**
     * @brief Applies setting values.
     * @param settings
     */
    void ApplySettings(AppMonitorSettings *settings);

private:
  
    /**
     * @brief Events caused by timer. Calls updateData.
     * @param ev
     */
    void OnTimerTimeout(wxTimerEvent &ev);
    
    /**
     * @brief Asks about values of sigar
     */
    void updateData();
    
    /**
     * @brief Converts character to value of process state.
     * @param state - character representation
     * @return state of process
     */
    wxString stateToString(char state);
    
    /**
     * @brief Creates text output of runtime information.
     * @param numberOfColumns - numbers of columns for text values
     * @param withDiscGraph - if true adjusts display for disc chart
     * @return wxGridSizer with labels and values
     */
    wxGridSizer *CreateTextInfo(int numberOfColumns, bool withDiscGraph);
    
    /**
     * @brief Storing values to file.
     * @param processState
     */
    void LogValuesToFile(structProcessState processState);
    
    /**
     * @brief Creates file or cleans existing. Location is project directory.
     */
    void PrepareFileForLog();
    
    
    wxWindow* m_parent;
    wxBoxSizer* m_sizerDiscAndTextInfo;
    wxGridSizer* m_sizerTextInfo;
    
    double m_samplingPeriod; // in seconds
    wxTimer* m_timer;
    
    bool m_allowedDiscChart;
    bool m_logToFile;
    wxString m_outputLogFileName;
    wxString m_logFileName;
    wxTextFile logFile;
    
    SimpleDynamicChart *m_CPUChart;
    SimpleDynamicChart *m_MemChart;
    MultipleDynamicChart *m_DiscChart;
    
    long m_counter;
    
    SigarManager *m_sigarManag;
    structProcessState m_processState;

    bool m_isRunning;
    bool m_isPaused;
    int m_PID;
    
    wxStaticText* m_titlePID;
    wxStaticText* m_titleState;
    wxStaticText* m_titleCPUUsage;
    wxStaticText* m_titleMemUsage;
    wxStaticText* m_titleDiscUsage;
    wxStaticText* m_titleDiscReading;
    
    ChartLegend *m_legendCPUUsage;
    ChartLegend *m_legendMemUsage;
    ChartLegend *m_legendDiscWriting;
    ChartLegend *m_legendDiscReading;
    
    wxStaticText* m_valuePID;
    wxStaticText* m_valueState;
    wxStaticText* m_valueCPUUsage;
    wxStaticText* m_valueMemUsage;
    wxStaticText* m_valueDiscUsage;
    wxStaticText* m_valueDiscReading;
    
    AppMonitorSettings *m_settings;
    
    IManager *m_mgr;
};

#endif // VISUALIZER_H
