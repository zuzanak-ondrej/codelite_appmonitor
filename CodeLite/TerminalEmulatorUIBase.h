//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : TerminalEmulatorUIBase.h
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
// wxCrafter project file: TerminalEmulatorUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_CODELITE_TERMINALEMULATORUI_BASE_CLASSES_H
#define CODELITE_CODELITE_TERMINALEMULATORUI_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stc/stc.h>
#include <wx/textctrl.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif
#include "codelite_exports.h"

class WXDLLIMPEXP_CL TerminalEmulatorUIBase : public wxPanel
{
protected:
    wxStyledTextCtrl* m_stc;
    wxTextCtrl* m_textCtrl;

protected:
    virtual void OnSendCommand(wxCommandEvent& event) { event.Skip(); }

public:
    wxStyledTextCtrl* GetStc() { return m_stc; }
    wxTextCtrl* GetTextCtrl() { return m_textCtrl; }
    TerminalEmulatorUIBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxTAB_TRAVERSAL);
    virtual ~TerminalEmulatorUIBase();
};


class WXDLLIMPEXP_CL TerminalEmulatorFrameBase : public wxFrame
{
protected:

protected:

public:
    TerminalEmulatorFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Terminal"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxDEFAULT_FRAME_STYLE|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER);
    virtual ~TerminalEmulatorFrameBase();
};

#endif