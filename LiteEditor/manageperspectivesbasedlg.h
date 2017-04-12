//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : manageperspectivesbasedlg.h
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

///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __manageperspectivesbasedlg__
#define __manageperspectivesbasedlg__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/combobox.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_RENAME 1000

///////////////////////////////////////////////////////////////////////////////
/// Class ManagePerspectivesBaseDlg
///////////////////////////////////////////////////////////////////////////////
class ManagePerspectivesBaseDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_listBox;
		wxButton* m_button3;
		wxButton* m_button4;
		wxStaticLine* m_staticline1;
		wxButton* m_buttonOk;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDeletePerspective( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeletePerspectiveUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnRenamePerspective( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRenamePerspectiveUI( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		ManagePerspectivesBaseDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Perspectives..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~ManagePerspectivesBaseDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SavePerspectiveDlgBase
///////////////////////////////////////////////////////////////////////////////
class SavePerspectiveDlgBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxComboBox* m_comboBox;
		wxStaticLine* m_staticline2;
		wxButton* m_button5;
		wxButton* m_button6;
	
	public:
		
		SavePerspectiveDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Save Perspective As..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~SavePerspectiveDlgBase();
	
};

#endif //__manageperspectivesbasedlg__
