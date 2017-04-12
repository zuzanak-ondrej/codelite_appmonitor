//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : wxFlatButtonBase.h
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
// wxCrafter project file: wxFlatButton.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_PLUGIN_WXFLATBUTTON_BASE_CLASSES_H
#define CODELITE_PLUGIN_WXFLATBUTTON_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class wxFlatButtonBase : public wxPanel
{
protected:

protected:
    virtual void OnEnterWindow(wxMouseEvent& event) { event.Skip(); }
    virtual void OnLeaveWindow(wxMouseEvent& event) { event.Skip(); }
    virtual void OnPaint(wxPaintEvent& event) { event.Skip(); }
    virtual void OnEraseBackground(wxEraseEvent& event) { event.Skip(); }
    virtual void OnLeftDown(wxMouseEvent& event) { event.Skip(); }
    virtual void OnSize(wxSizeEvent& event) { event.Skip(); }
    virtual void OnLeftDClick(wxMouseEvent& event) { event.Skip(); }
    virtual void OnLeftUp(wxMouseEvent& event) { event.Skip(); }

public:
    wxFlatButtonBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxWANTS_CHARS|wxTAB_TRAVERSAL);
    virtual ~wxFlatButtonBase();
};


class wxFlatButtonBarBase : public wxPanel
{
protected:
    wxFlexGridSizer* m_mainSizer;

protected:
    virtual void OnPaint(wxPaintEvent& event) { event.Skip(); }
    virtual void OnSize(wxSizeEvent& event) { event.Skip(); }

public:
    wxFlatButtonBarBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxWANTS_CHARS|wxTAB_TRAVERSAL|wxBORDER_NONE);
    virtual ~wxFlatButtonBarBase();
};

#endif