//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : new_class.h
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
// wxCrafter project file: new_class.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITEPHP_PHP_PLUGIN_NEW_CLASS_BASE_CLASSES_H
#define CODELITEPHP_PHP_PLUGIN_NEW_CLASS_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class NewPHPClassBase : public wxDialog
{
protected:
    wxStaticText* m_staticText50;
    wxChoice* m_choiceType;
    wxStaticText* m_staticText12;
    wxTextCtrl* m_textCtrlClassName;
    wxStaticText* m_staticText16;
    wxTextCtrl* m_textCtrlNamespace;
    wxStaticText* m_staticText74;
    wxTextCtrl* m_textCtrlExtends;
    wxButton* m_button90;
    wxStaticText* m_staticText78;
    wxTextCtrl* m_textCtrlImplements;
    wxButton* m_button92;
    wxCheckBox* m_checkBoxCtor;
    wxCheckBox* m_checkBoxDtor;
    wxCheckBox* m_checkBoxFolderPerNamespace;
    wxCheckBox* m_checkBoxSingleton;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:
    virtual void OnClassNameUpdate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnNamespaceTextUpdated(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEditExtends(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEditImplements(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMakeSingletonUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnFolderPerNamespace(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText50() { return m_staticText50; }
    wxChoice* GetChoiceType() { return m_choiceType; }
    wxStaticText* GetStaticText12() { return m_staticText12; }
    wxTextCtrl* GetTextCtrlClassName() { return m_textCtrlClassName; }
    wxStaticText* GetStaticText16() { return m_staticText16; }
    wxTextCtrl* GetTextCtrlNamespace() { return m_textCtrlNamespace; }
    wxStaticText* GetStaticText74() { return m_staticText74; }
    wxTextCtrl* GetTextCtrlExtends() { return m_textCtrlExtends; }
    wxButton* GetButton90() { return m_button90; }
    wxStaticText* GetStaticText78() { return m_staticText78; }
    wxTextCtrl* GetTextCtrlImplements() { return m_textCtrlImplements; }
    wxButton* GetButton92() { return m_button92; }
    wxCheckBox* GetCheckBoxCtor() { return m_checkBoxCtor; }
    wxCheckBox* GetCheckBoxDtor() { return m_checkBoxDtor; }
    wxCheckBox* GetCheckBoxFolderPerNamespace() { return m_checkBoxFolderPerNamespace; }
    wxCheckBox* GetCheckBoxSingleton() { return m_checkBoxSingleton; }
    wxButton* GetButtonOK() { return m_buttonOK; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
    NewPHPClassBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New Class"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~NewPHPClassBase();
};

#endif
