/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef APPMONITORSETTINGS_H
#define APPMONITORSETTINGS_H

#include "cl_config.h"

// default settings values
#define CONFIG_ITEM_NAME_APPMONITOR "AppMonitorConf"
#define APPMONITOR_CONFIG_FILE "appmonitor.conf"
#define APPMONITOR_REFRESH_TIME 1000
#define APPMONITOR_SHOW_DISC_USAGE true
#define APPMONITOR_LOG_TO_FILE false
#define APPMONITOR_LOG_FILE_NAME "appmonitor_log.csv"

/**
 * @class AppMonitorSettings
 * @brief This class wraps setting values.
 */
class AppMonitorSettings : public clConfigItem
{
public:
    AppMonitorSettings();
    ~AppMonitorSettings();

    virtual void FromJSON(const JSONElement &json);
    virtual JSONElement ToJSON() const;
    
    void SetRefreshTime(const int refreshTime) 
    {
        m_refreshTime = refreshTime;
    }
    
    int GetRefreshTime()
    {
        return m_refreshTime;
    }
    
    void SetShowDiscUsage(bool choice)
    {
        m_showDiscUsage = choice;
    }
    
    bool GetShowDiscUsage()
    {
        return m_showDiscUsage;
    }

    void SetLogToFile(bool choice)
    {
        m_logToFile = choice;
    }
    
    bool GetLogToFile()
    {
        return m_logToFile;
    }
    
    void SetLogFileName(wxString fileName)
    {
        m_logFileName = fileName;
    }
    
    wxString GetLogFileName()
    {
        return m_logFileName;
    }
    
    void SetColorCPUUsage(wxColour colour)
    {
        m_colorCPUUsage = colour;
    }
    
    wxColour GetColorCPUUsage()
    {
        return m_colorCPUUsage;
    }

    void SetColorMemoryUsage(wxColour colour)
    {
        m_colorMemoryUsage = colour;
    }
    
    wxColour GetColorMemoryUsage()
    {
        return m_colorMemoryUsage;
    }
    
    void SetColorDiscWriting(wxColour colour)
    {
        m_colorDiscWriting = colour;
    }
    
    wxColour GetColorDiscWriting()
    {
        return m_colorDiscWriting;
    }
    
    void SetColorDiscReading(wxColour colour)
    {
        m_colorDiscReading = colour;
    }
    
    wxColour GetColorDiscReading()
    {
        return m_colorDiscReading;
    }
    
    void SetCommandForWXMSW(wxString cmd)
    {
        m_commandForWXMSW = cmd;
    }
    
    wxString GetCommandForWXMSW()
    {
        return m_commandForWXMSW;
    }
    
    void SetCommandForWXGTK(wxString cmd)
    {
        m_commandForWXGTK = cmd;
    }
    
    wxString GetCommandForWXGTK()
    {
        return m_commandForWXGTK;
    }

    void SetCommandForWXMAC(wxString cmd)
    {
        m_commandForWXMAC = cmd;
    }
    
    wxString GetCommandForWXMAC()
    {
        return m_commandForWXMAC;
    }

    void SetDefault();

    void SaveToConfig() {
        clConfig conf(APPMONITOR_CONFIG_FILE);
        conf.WriteItem(this);
    }

    void LoadFromConfig() {
        clConfig conf(APPMONITOR_CONFIG_FILE);
        conf.ReadItem(this);
    }

private:
    int m_refreshTime;
    bool m_showDiscUsage;
    bool m_logToFile;
    wxString m_logFileName;
    
    wxColour m_colorCPUUsage;
    wxColour m_colorMemoryUsage;
    wxColour m_colorDiscWriting;
    wxColour m_colorDiscReading;
    
    wxString m_commandForWXMSW;
    wxString m_commandForWXGTK;
    wxString m_commandForWXMAC;
};

#endif // APPMONITORSETTINGS_H
