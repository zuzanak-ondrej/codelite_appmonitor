//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : wxcrafter.h
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
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_TWEAKS_WXCRAFTER_BASE_CLASSES_H
#define CODELITE_TWEAKS_WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/bannerwindow.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class TweaksSettingsDlgBase : public wxDialog
{
protected:
    wxCheckBox* m_checkBoxEnableTweaks;
    wxNotebook* m_notebook12;
    wxPanel* m_tabEditorTabsColours;
    wxBannerWindow* m_banner136;
    wxPropertyGridManager* m_pgMgrTabColours;
    wxPGProperty* m_pgProp114;
    wxPGProperty* m_pgPropGlobalTabBG;
    wxPGProperty* m_pgPropGlobalTabFG;
    wxPGProperty* m_pgPropProjectsColours;
    wxButton* m_button124;
    wxPanel* m_tabProjectIcons;
    wxBannerWindow* m_banner138;
    wxPropertyGridManager* m_pgMgr;
    wxPGProperty* m_pgPropProjects;
    wxButton* m_button8;
    wxButton* m_button88;

protected:
    virtual void OnEnableTweaks(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEnableTweaksCheckboxUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnEnableTweaksUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnEnableColoursTableUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnColourChanged(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void OnResetColours(wxCommandEvent& event) { event.Skip(); }
    virtual void OnImageSelected(wxPropertyGridEvent& event) { event.Skip(); }

public:
    wxCheckBox* GetCheckBoxEnableTweaks() { return m_checkBoxEnableTweaks; }
    wxBannerWindow* GetBanner136() { return m_banner136; }
    wxPropertyGridManager* GetPgMgrTabColours() { return m_pgMgrTabColours; }
    wxButton* GetButton124() { return m_button124; }
    wxPanel* GetTabEditorTabsColours() { return m_tabEditorTabsColours; }
    wxBannerWindow* GetBanner138() { return m_banner138; }
    wxPropertyGridManager* GetPgMgr() { return m_pgMgr; }
    wxPanel* GetTabProjectIcons() { return m_tabProjectIcons; }
    wxNotebook* GetNotebook12() { return m_notebook12; }
    wxButton* GetButton8() { return m_button8; }
    wxButton* GetButton88() { return m_button88; }
    TweaksSettingsDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Tweaks Setting"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~TweaksSettingsDlgBase();
};

#endif
