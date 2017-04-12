/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef APPMONITORSETTINGSDIALOG_H
#define APPMONITORSETTINGSDIALOG_H

#include <string>
#include <wx/msgdlg.h>
#include <wx/colour.h>

#include "appmonitorui.h"
#include "appmonitorsettings.h"
#include "windowattrmanager.h"

/**
 * AppMonitorSettingsDialogBase is generated by formbuilder in appmonitorui.h.
 * @class AppMonitorSettingsDialog
 * @brief UI for settings plugin.
 */
class AppMonitorSettingsDialog : public AppMonitorSettingsDialogBase
{
public:
    /**
     * @param parent
     * @param settings
     */
    AppMonitorSettingsDialog(wxWindow* parent, AppMonitorSettings *settings);
    ~AppMonitorSettingsDialog();

protected:
    
    /**
     * @brief Return without save settings.
     * @param event
     */
    virtual void OnCancel( wxCommandEvent& event );
    
    /**
     * @brief Save settings and closes window.
     * @param event
     */
    virtual void OnSave(wxCommandEvent& event);
    
    /**
     * @brief Restore default settings plugin.
     * @param event
     */
    virtual void OnDefaultSettings( wxCommandEvent& event );
    
    /**
     * @brief Refresh value in UI.
     */
    void RefreshValues();

    /**
     * @brief Converter combobox index to refresh time.
     * @param value - index of combobox item
     * @return value of refresh time
     */
    unsigned int RefreshTimeIndexToValue(int value);
    
    /**
     * @brief Converter refresh time to index into combobox item.
     * @param value of refresh time
     * @return index of combobox item
     */
    int RefreshTimeValueToIndex(unsigned int value);
    
    /**
     * @brief Checks filename.
     * @param fileName
     * @return true if ok
     */
    bool CheckFileName(wxFileName fileName);
    
    /**
     * @brief Checks command to content of specifiers. Command looks for offspring of running terminal.
     * @param cmd - command to capture PID process in command line
     * @return true if command is ok
     */
    bool CheckCommand(wxString cmd);
    
    AppMonitorSettings *m_settings;
};

#endif // APPMONITORSETTINGSDIALOG_H
