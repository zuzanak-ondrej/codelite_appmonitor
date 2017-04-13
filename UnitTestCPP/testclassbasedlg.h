//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : testclassbasedlg.h
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
// wxCrafter project file: NewClassTestBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_UNITTESTCPP_NEWCLASSTESTBASE_BASE_CLASSES_H
#define CODELITE_UNITTESTCPP_NEWCLASSTESTBASE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/checklst.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class TestClassBaseDlg : public wxDialog
{
protected:
    wxStaticText* m_staticText1;
    wxTextCtrl* m_textCtrlClassName;
    wxButton* m_buttonClass;
    wxButton* m_buttonRefresh;
    wxStaticText* m_staticText4;
    wxTextCtrl* m_textCtrlFixtureName;
    wxStaticText* m_staticText3;
    wxTextCtrl* m_textCtrlFileName;
    wxStaticText* m_staticText5;
    wxChoice* m_choiceProjects;
    wxStaticText* m_staticText6;
    wxCheckListBox* m_checkListMethods;
    wxButton* m_buttonCheckAll;
    wxButton* m_buttonUnCheckAll;
    wxStdDialogButtonSizer* m_stdBtnSizer2;
    wxButton* m_button4;
    wxButton* m_button6;

protected:
    virtual void OnShowClassListDialog(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRefreshFunctions(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRefreshButtonUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnCheckAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUnCheckAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonOk(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText1() { return m_staticText1; }
    wxTextCtrl* GetTextCtrlClassName() { return m_textCtrlClassName; }
    wxButton* GetButtonClass() { return m_buttonClass; }
    wxButton* GetButtonRefresh() { return m_buttonRefresh; }
    wxStaticText* GetStaticText4() { return m_staticText4; }
    wxTextCtrl* GetTextCtrlFixtureName() { return m_textCtrlFixtureName; }
    wxStaticText* GetStaticText3() { return m_staticText3; }
    wxTextCtrl* GetTextCtrlFileName() { return m_textCtrlFileName; }
    wxStaticText* GetStaticText5() { return m_staticText5; }
    wxChoice* GetChoiceProjects() { return m_choiceProjects; }
    wxStaticText* GetStaticText6() { return m_staticText6; }
    wxCheckListBox* GetCheckListMethods() { return m_checkListMethods; }
    wxButton* GetButtonCheckAll() { return m_buttonCheckAll; }
    wxButton* GetButtonUnCheckAll() { return m_buttonUnCheckAll; }
    TestClassBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Create UnitTests for Class.."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~TestClassBaseDlg();
};

#endif
