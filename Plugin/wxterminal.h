//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : wxterminal.h
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

#ifndef __wxterminal__
#define __wxterminal__

/**
@file
Subclass of wxTerminalBase, which is generated by wxFormBuilder.
*/

#include "wxterminalbase.h"
#include <set>
#include "codelite_exports.h"
#include "cl_command_event.h"

class IProcess;

class wxTerminalHistory
{
    wxArrayString m_history;
    size_t m_historyCursor;

public:
    wxTerminalHistory();
    ~wxTerminalHistory();

    void AddCommand(const wxString& command);
    wxString ArrowUp();
    wxString ArrowDown();
};

/** Implementing wxTerminalBase */
class WXDLLIMPEXP_SDK wxTerminal : public wxTerminalBase
{
protected:
    IProcess* m_process;
    wxString m_workingDir;
    wxTextAttr m_defaultStyle;
    wxTextAttr m_promptStyle;
    bool m_exitWhenProcessDies;
    bool m_exitOnKey;
    long m_inferiorEnd;
#if defined(__WXGTK__) || defined(__WXMAC__)
    wxString m_tty;
    IProcess* m_dummyProcess;
    int m_slave;
#endif
    bool m_interactive;
    wxString m_outputBuffer;

protected:
    void DoProcessCommand(const wxString& command);
    void DoCtrlC();
    void DoFlushOutputBuffer();

protected:
    // Handlers for wxTerminalBase events.
    DECLARE_EVENT_TABLE()
    virtual void OnText(wxCommandEvent& event);
    virtual void OnEnter(wxCommandEvent& event);
    virtual void OnURL(wxTextUrlEvent& event);
    virtual void OnKey(wxKeyEvent& event);
    virtual void OnReadProcessOutput(clProcessEvent& event);
    virtual void OnProcessEnd(clProcessEvent& event);
    virtual void OnIdle(wxIdleEvent& event);
    void OnEdit(wxCommandEvent& event);

public:
    /** Constructor */
    wxTerminal(wxWindow* parent);
    virtual ~wxTerminal();

    void SetInteractive(bool interactive) { this->m_interactive = interactive; }
    bool IsInteractive() const { return m_interactive; }
    void Execute(const wxString& command, bool exitWhenDone = false, const wxString& workingDir = wxT(""));
    void KillInferior();
    bool IsRunning();
    void Clear();
#if defined(__WXGTK__) || defined(__WXMAC__)
    wxString StartTTY();
    wxString GetTTY() const { return m_tty; }
    void StopTTY();
#endif
};

#endif // __wxterminal__
