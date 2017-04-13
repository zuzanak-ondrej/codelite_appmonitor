/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "appmonitorsettingsdialog.h"

AppMonitorSettingsDialog::AppMonitorSettingsDialog(wxWindow* parent, AppMonitorSettings *settings)
    : AppMonitorSettingsDialogBase(parent)
{
    #ifdef __WXMSW__ // Windows;
        m_staticTextOS->SetLabel(_("MSW:"));
    #elif defined(__WXGTK__) // Gtk;
        m_staticTextOS->SetLabel(_("GTK:"));
    #elif defined(__WXMAC__) // Mac;
        m_staticTextOS->SetLabel(_("MAC:"));
    #endif
    
    m_settings = settings;
    m_settings->LoadFromConfig();
    
    RefreshValues();
    
    SetName("AppMonitorSettingsDialog");
    WindowAttrManager::Load(this);
}

AppMonitorSettingsDialog::~AppMonitorSettingsDialog()
{
}

void AppMonitorSettingsDialog::RefreshValues()
{
    m_choiceRefreshTime->SetSelection(RefreshTimeValueToIndex(m_settings->GetRefreshTime()));
    m_checkBoxDiscUsage->SetValue(m_settings->GetShowDiscUsage());
    m_checkBoxlogToFile->SetValue(m_settings->GetLogToFile());
    m_textLogFileName->SetValue(m_settings->GetLogFileName());
    m_colourCPUUsage->SetColour(m_settings->GetColorCPUUsage());
    m_colourMemoryUsage->SetColour(m_settings->GetColorMemoryUsage());
    m_colourDiscReading->SetColour(m_settings->GetColorDiscReading());
    m_colourDiscWriting->SetColour(m_settings->GetColorDiscWriting());
    
    m_textLogFileName->SetToolTip(_("Log file is located in project folder."));
    
    #ifdef __WXMSW__ // Windows;
        m_textCtrlCommand->SetValue(m_settings->GetCommandForWXMSW());
    #elif defined(__WXGTK__) // Gtk;
        m_textCtrlCommand->SetValue(m_settings->GetCommandForWXGTK());
    #elif defined(__WXMAC__) // Mac;
        m_textCtrlCommand->SetValue(m_settings->GetCommandForWXMAC());
    #endif
    
    #ifdef __WXMSW__ // Windows;
        m_textCtrlCommand->SetToolTip(_("Must contain two specifiers %s. First for filename and second for PID."));
    #else
        m_textCtrlCommand->SetToolTip(_("Must contain two specifiers %s. First for PID and second for filename."));
    #endif
}

void AppMonitorSettingsDialog::OnCancel(wxCommandEvent& event) 
{ 
    EndModal(wxID_CANCEL);
}

void AppMonitorSettingsDialog::OnDefaultSettings(wxCommandEvent& event) 
{ 
    wxMessageDialog dlg(this, _("Restore default settings?"), _("AppMonitor"), wxYES_NO|wxICON_QUESTION);
    
    if (dlg.ShowModal() == wxID_YES)
    {
        m_settings->SetDefault();
        RefreshValues();
    }
}

bool AppMonitorSettingsDialog::CheckFileName(wxFileName fileName)
{
    wxString forbiddenChars = fileName.GetForbiddenChars();
    wxString stringName = fileName.GetName();
    
    if (stringName.find_first_of(forbiddenChars) != std::string::npos)
    {
        return false;
    }
    
    return true;
}

bool AppMonitorSettingsDialog::CheckCommand(wxString cmd)
{
    size_t position;
    wxString searchedString = "%s";
    
    if ((position = cmd.find(searchedString)) != wxNOT_FOUND)
    {
        if ((position = cmd.find(searchedString, position + strlen(searchedString))) != wxNOT_FOUND)
        {
            return true;
        }
    }
    
    return false;
}

void AppMonitorSettingsDialog::OnSave(wxCommandEvent& event) 
{ 
    wxFileName fileName = wxFileName(m_textLogFileName->GetValue());
    if (!fileName.IsOk() || !CheckFileName(fileName))
    {
        m_textLogFileName->SetBackgroundColour(wxColour("#C04242"));
        return;
    }
    m_textLogFileName->SetBackgroundColour(*wxWHITE);
    
    if (!CheckCommand(m_textCtrlCommand->GetValue()))
    {
        m_textCtrlCommand->SetBackgroundColour(wxColour("#C04242"));
        return;
    }
    m_textCtrlCommand->SetBackgroundColour(*wxWHITE);
    
    m_settings->SetRefreshTime(RefreshTimeIndexToValue(m_choiceRefreshTime->GetSelection()));
    m_settings->SetShowDiscUsage(m_checkBoxDiscUsage->GetValue());
    m_settings->SetLogToFile(m_checkBoxlogToFile->GetValue());
    m_settings->SetLogFileName(m_textLogFileName->GetValue());
    m_settings->SetColorCPUUsage(m_colourCPUUsage->GetColour());
    m_settings->SetColorMemoryUsage(m_colourMemoryUsage->GetColour());
    m_settings->SetColorDiscReading(m_colourDiscReading->GetColour());
    m_settings->SetColorDiscWriting(m_colourDiscWriting->GetColour());
    
    #ifdef __WXMSW__ // Windows;
        m_settings->SetCommandForWXMSW(m_textCtrlCommand->GetValue());
    #elif defined(__WXGTK__) // Gtk;
        m_settings->SetCommandForWXGTK(m_textCtrlCommand->GetValue());
    #elif defined(__WXMAC__) // Mac;
        m_settings->SetCommandForWXMAC(m_textCtrlCommand->GetValue());
    #endif
    
    m_settings->SaveToConfig();
 
    EndModal(wxID_SAVE);
}

unsigned int AppMonitorSettingsDialog::RefreshTimeIndexToValue(int value)
{
    unsigned int refreshTime;
    
    switch(value)
    {
        case 0 : 
            refreshTime = 2000;
            break;
        case 1 : 
            refreshTime = 1000;
            break;
        case 2 : 
            refreshTime = 500;
            break;
        case 3 : 
            refreshTime = 250;
            break;
        case 4 : 
            refreshTime = 100;
            break;
        default:
            refreshTime = 2000;
            break;
    }
    
    return refreshTime;
}

int AppMonitorSettingsDialog::RefreshTimeValueToIndex(unsigned int value)
{
    int index;
    
    switch(value)
    {
        case 2000 : 
            index = 0;
            break;
        case 1000 : 
            index = 1;
            break;
        case 500 : 
            index = 2;
            break;
        case 250 : 
            index = 3;
            break;
        case 100 : 
            index = 4;
            break;
        default:
            index = 0;
            break;
    }
    
    return index;
}