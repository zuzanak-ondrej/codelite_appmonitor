//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : gizmos_base.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: gizmos.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_GIZMOS_GIZMOS_BASE_CLASSES_H
#define CODELITE_GIZMOS_GIZMOS_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/wizard.h>
#include <vector>
#include <wx/artprov.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class PluginWizardBase : public wxWizard
{
protected:
    std::vector<wxWizardPageSimple*> m_pages;

    wxWizardPageSimple* m_wizardPage1;
    wxStaticText* m_staticText14;
    wxTextCtrl* m_textCtrlName;
    wxStaticText* m_staticText18;
    wxTextCtrl* m_textCtrlDescription;
    wxWizardPageSimple* m_wizardPage2;
    wxStaticText* m_staticText42;
    wxDirPickerCtrl* m_dirPickerCodeliteDir;
    wxStaticText* m_staticText26;
    wxDirPickerCtrl* m_dirPickerPluginPath;
    wxTextCtrl* m_textCtrlPreview;

protected:
    virtual void OnPageChanging(wxWizardEvent& event) { event.Skip(); }
    virtual void OnFinish(wxWizardEvent& event) { event.Skip(); }
    virtual void OnProjectPathChanged(wxFileDirPickerEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText14() { return m_staticText14; }
    wxTextCtrl* GetTextCtrlName() { return m_textCtrlName; }
    wxStaticText* GetStaticText18() { return m_staticText18; }
    wxTextCtrl* GetTextCtrlDescription() { return m_textCtrlDescription; }
    wxWizardPageSimple* GetWizardPage1() { return m_wizardPage1; }
    wxStaticText* GetStaticText42() { return m_staticText42; }
    wxDirPickerCtrl* GetDirPickerCodeliteDir() { return m_dirPickerCodeliteDir; }
    wxStaticText* GetStaticText26() { return m_staticText26; }
    wxDirPickerCtrl* GetDirPickerPluginPath() { return m_dirPickerPluginPath; }
    wxTextCtrl* GetTextCtrlPreview() { return m_textCtrlPreview; }
    wxWizardPageSimple* GetWizardPage2() { return m_wizardPage2; }
    PluginWizardBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New Plugin Wizard"), const wxBitmap& bmp = wxNullBitmap, const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE);
    wxWizardPageSimple* GetFirstPage() const { if(!m_pages.empty()) return m_pages.at(0); return NULL; }
    virtual ~PluginWizardBase();
};

#endif
