//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : continousbuildbasepane.h
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
// wxCrafter project file: continousbuildbasepane.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_CONTINUOUSBUILD_CONTINOUSBUILDBASEPANE_BASE_CLASSES_H
#define CODELITE_CONTINUOUSBUILD_CONTINOUSBUILDBASEPANE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class ContinousBuildBasePane : public wxPanel
{
protected:
    wxCheckBox* m_checkBox1;
    wxButton* m_buttonCancel;
    wxListBox* m_listBoxQueue;
    wxStaticText* m_staticText4;
    wxListBox* m_listBoxFailedFiles;

protected:
    virtual void OnEnableCB(wxCommandEvent& event) { event.Skip(); }
    virtual void OnStopAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnStopUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnEnableContBuildUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxCheckBox* GetCheckBox1() { return m_checkBox1; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
    wxListBox* GetListBoxQueue() { return m_listBoxQueue; }
    wxStaticText* GetStaticText4() { return m_staticText4; }
    wxListBox* GetListBoxFailedFiles() { return m_listBoxFailedFiles; }
    ContinousBuildBasePane(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(389,188), long style = wxTAB_TRAVERSAL);
    virtual ~ContinousBuildBasePane();
};

#endif
