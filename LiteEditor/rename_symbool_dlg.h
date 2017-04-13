//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : rename_symbool_dlg.h
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
// wxCrafter project file: rename_symbool_dlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CL_FORMBUILDER_RENAME_SYMBOOL_DLG_BASE_CLASSES_H
#define CL_FORMBUILDER_RENAME_SYMBOOL_DLG_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/panel.h>
#include <wx/dataview.h>
#include <wx/button.h>
#include <wx/stc/stc.h>
#include <wx/statline.h>
#include <wx/bannerwindow.h>
#include <wx/checklst.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class RenameSymbolBase : public wxDialog
{
public:
    enum {
        ID_CHECK_ALL = 1001,
        ID_UNCHECK_ALL = 1002,
    };
protected:
    wxStaticText* m_staticText31;
    wxTextCtrl* m_textCtrlNewName;
    wxSplitterWindow* m_splitter7;
    wxPanel* m_splitterPage11;
    wxDataViewListCtrl* m_dvListCtrl;
    wxButton* m_buttonCheckAll;
    wxButton* m_buttonUncheckAll;
    wxPanel* m_splitterPage15;
    wxStyledTextCtrl* m_preview;
    wxStaticLine* m_staticLine55;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:
    virtual void OnSelection(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnCheckAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUncheckAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText31() { return m_staticText31; }
    wxTextCtrl* GetTextCtrlNewName() { return m_textCtrlNewName; }
    wxDataViewListCtrl* GetDvListCtrl() { return m_dvListCtrl; }
    wxButton* GetButtonCheckAll() { return m_buttonCheckAll; }
    wxButton* GetButtonUncheckAll() { return m_buttonUncheckAll; }
    wxPanel* GetSplitterPage11() { return m_splitterPage11; }
    wxStyledTextCtrl* GetPreview() { return m_preview; }
    wxPanel* GetSplitterPage15() { return m_splitterPage15; }
    wxSplitterWindow* GetSplitter7() { return m_splitter7; }
    wxStaticLine* GetStaticLine55() { return m_staticLine55; }
    wxButton* GetButtonOk() { return m_buttonOk; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
    RenameSymbolBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Rename Symbol"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~RenameSymbolBase();
};


class SelectProjectsDlgBase : public wxDialog
{
public:
    enum {
        ID_CHECK_ALL = 1001,
        ID_UNCHECK_ALL = 1002,
    };
protected:
    wxBannerWindow* m_banner45;
    wxCheckListBox* m_checkListBoxProjects;
    wxButton* m_button37;
    wxButton* m_button39;
    wxButton* m_button29;
    wxButton* m_button31;

protected:
    virtual void OnSelectAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUnSelectAll(wxCommandEvent& event) { event.Skip(); }

public:
    wxBannerWindow* GetBanner45() { return m_banner45; }
    wxCheckListBox* GetCheckListBoxProjects() { return m_checkListBoxProjects; }
    wxButton* GetButton37() { return m_button37; }
    wxButton* GetButton39() { return m_button39; }
    wxButton* GetButton29() { return m_button29; }
    wxButton* GetButton31() { return m_button31; }
    SelectProjectsDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Rename Symbol Scope"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxCAPTION|wxRESIZE_BORDER);
    virtual ~SelectProjectsDlgBase();
};

#endif
