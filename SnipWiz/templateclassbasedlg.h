//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : templateclassbasedlg.h
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
// wxCrafter project file: templateclassbasedlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_SNIPWIZ_TEMPLATECLASSBASEDLG_BASE_CLASSES_H
#define CODELITE_SNIPWIZ_TEMPLATECLASSBASEDLG_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/button.h>
#include <wx/stc/stc.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class TemplateClassBaseDlg : public wxDialog
{
protected:
    wxNotebook* ID_NOTEBOOK1;
    wxPanel* ID_PANEL;
    wxStaticText* m_static1;
    wxTextCtrl* m_textCtrlClassName;
    wxStaticText* m_static2;
    wxComboBox* m_comboxCurrentTemplate;
    wxStaticText* m_static3;
    wxTextCtrl* m_textCtrlHeaderFile;
    wxStaticText* m_static4;
    wxTextCtrl* m_textCtrlCppFile;
    wxStaticText* m_staticProjectTreeFolder;
    wxTextCtrl* m_textCtrlVD;
    wxButton* m_buttonBrowseVD;
    wxStaticText* m_static5;
    wxTextCtrl* m_textCtrlFilePath;
    wxButton* m_buttonBrowsePath;
    wxButton* m_buttonGenerate;
    wxButton* m_buttonCancel;
    wxPanel* ID_PANEL1;
    wxStaticText* m_static6;
    wxComboBox* m_comboxTemplates;
    wxButton* m_buttonAddTemplate;
    wxButton* m_buttonChangeTemplate;
    wxButton* m_buttonRemoveTemplate;
    wxButton* m_buttonClear;
    wxButton* m_buttonInsertClassMacro;
    wxNotebook* m_notebookFiles;
    wxPanel* m_panel3;
    wxStyledTextCtrl* m_textCtrlHeader;
    wxPanel* m_panel4;
    wxStyledTextCtrl* m_textCtrlImpl;

protected:
    virtual void OnClassNameEntered(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowseVD(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBrowseFilePath(wxCommandEvent& event) { event.Skip(); }
    virtual void OnGenerate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnGenerateUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnQuit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnTemplateClassSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonAdd(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonAddUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnButtonChange(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonChangeUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnButtonRemove(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonRemoveUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnButtonClear(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonClearUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnInsertClassKeyword(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInsertClassKeywordUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnStcHeaderFileContentChnaged(wxStyledTextEvent& event) { event.Skip(); }
    virtual void OnStcImplFileContentChnaged(wxStyledTextEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStatic1() { return m_static1; }
    wxTextCtrl* GetTextCtrlClassName() { return m_textCtrlClassName; }
    wxStaticText* GetStatic2() { return m_static2; }
    wxComboBox* GetComboxCurrentTemplate() { return m_comboxCurrentTemplate; }
    wxStaticText* GetStatic3() { return m_static3; }
    wxTextCtrl* GetTextCtrlHeaderFile() { return m_textCtrlHeaderFile; }
    wxStaticText* GetStatic4() { return m_static4; }
    wxTextCtrl* GetTextCtrlCppFile() { return m_textCtrlCppFile; }
    wxStaticText* GetStaticProjectTreeFolder() { return m_staticProjectTreeFolder; }
    wxTextCtrl* GetTextCtrlVD() { return m_textCtrlVD; }
    wxButton* GetButtonBrowseVD() { return m_buttonBrowseVD; }
    wxStaticText* GetStatic5() { return m_static5; }
    wxTextCtrl* GetTextCtrlFilePath() { return m_textCtrlFilePath; }
    wxButton* GetButtonBrowsePath() { return m_buttonBrowsePath; }
    wxButton* GetButtonGenerate() { return m_buttonGenerate; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
    wxPanel* GetID_PANEL() { return ID_PANEL; }
    wxStaticText* GetStatic6() { return m_static6; }
    wxComboBox* GetComboxTemplates() { return m_comboxTemplates; }
    wxButton* GetButtonAddTemplate() { return m_buttonAddTemplate; }
    wxButton* GetButtonChangeTemplate() { return m_buttonChangeTemplate; }
    wxButton* GetButtonRemoveTemplate() { return m_buttonRemoveTemplate; }
    wxButton* GetButtonClear() { return m_buttonClear; }
    wxButton* GetButtonInsertClassMacro() { return m_buttonInsertClassMacro; }
    wxStyledTextCtrl* GetTextCtrlHeader() { return m_textCtrlHeader; }
    wxPanel* GetPanel3() { return m_panel3; }
    wxStyledTextCtrl* GetTextCtrlImpl() { return m_textCtrlImpl; }
    wxPanel* GetPanel4() { return m_panel4; }
    wxNotebook* GetNotebookFiles() { return m_notebookFiles; }
    wxPanel* GetID_PANEL1() { return ID_PANEL1; }
    wxNotebook* GetID_NOTEBOOK1() { return ID_NOTEBOOK1; }
    TemplateClassBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Template Class Wizard"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL);
    virtual ~TemplateClassBaseDlg();
};

#endif
