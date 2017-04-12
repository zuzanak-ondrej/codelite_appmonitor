/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */


#include "appmonitorsettings.h"

AppMonitorSettings::AppMonitorSettings() : clConfigItem(CONFIG_ITEM_NAME_APPMONITOR)
{
    SetDefault();
}

AppMonitorSettings::~AppMonitorSettings()
{
}

void AppMonitorSettings::SetDefault()
{
    m_refreshTime = APPMONITOR_REFRESH_TIME;
    m_showDiscUsage = APPMONITOR_SHOW_DISC_USAGE;
    m_logToFile = APPMONITOR_LOG_TO_FILE;
    m_logFileName = APPMONITOR_LOG_FILE_NAME; 
    m_colorCPUUsage = wxColour(40, 90, 145);
    m_colorMemoryUsage = wxColour(110, 50, 210);
    m_colorDiscWriting = wxColour(35, 140, 35);
    m_colorDiscReading = wxColour(180, 0, 0);
    m_commandForWXMSW = "wmic /OUTPUT:'%s' process where (ParentProcessId=%s) get ProcessId";
    m_commandForWXGTK = "pgrep -P %s > %s";
    m_commandForWXMAC = "ps -ef | awk '{if ($3 == %s) print $2} >> %s'";
}

void AppMonitorSettings::FromJSON(const JSONElement &json)
{
    if (json.hasNamedObject("m_refreshTime")) m_refreshTime = json.namedObject("m_refreshTime").toInt();
    if (json.hasNamedObject("m_showDiscUsage")) m_showDiscUsage = json.namedObject("m_showDiscUsage").toBool();
    if (json.hasNamedObject("m_logToFile")) m_logToFile = json.namedObject("m_logToFile").toBool();
    if (json.hasNamedObject("m_logFileName")) m_logFileName = json.namedObject("m_logFileName").toString();
    if (json.hasNamedObject("m_colorCPUUsage")) m_colorCPUUsage = json.namedObject("m_colorCPUUsage").toColour();
    if (json.hasNamedObject("m_colorMemoryUsage")) m_colorMemoryUsage = json.namedObject("m_colorMemoryUsage").toColour();
    if (json.hasNamedObject("m_colorDiscWriting")) m_colorDiscWriting = json.namedObject("m_colorDiscWriting").toColour();
    if (json.hasNamedObject("m_colorDiscReading")) m_colorDiscReading = json.namedObject("m_colorDiscReading").toColour();
    if (json.hasNamedObject("m_commandForWXMSW")) m_commandForWXMSW = json.namedObject("m_commandForWXMSW").toString();
    if (json.hasNamedObject("m_commandForWXGTK")) m_commandForWXGTK = json.namedObject("m_commandForWXGTK").toString();
    if (json.hasNamedObject("m_commandForWXMAC")) m_commandForWXMAC = json.namedObject("m_commandForWXMAC").toString();
}

JSONElement AppMonitorSettings::ToJSON() const
{
    JSONElement element = JSONElement::createObject(GetName());
    element.addProperty("m_refreshTime", m_refreshTime);
    element.addProperty("m_showDiscUsage", m_showDiscUsage);
    element.addProperty("m_logToFile", m_logToFile);
    element.addProperty("m_logFileName", m_logFileName);
    element.addProperty("m_colorCPUUsage", m_colorCPUUsage);
    element.addProperty("m_colorMemoryUsage", m_colorMemoryUsage);
    element.addProperty("m_colorDiscWriting", m_colorDiscWriting);
    element.addProperty("m_colorDiscReading", m_colorDiscReading);
    element.addProperty("m_commandForWXMSW", m_commandForWXMSW);
    element.addProperty("m_commandForWXGTK", m_commandForWXGTK);
    element.addProperty("m_commandForWXMAC", m_commandForWXMAC);

    return element;
}