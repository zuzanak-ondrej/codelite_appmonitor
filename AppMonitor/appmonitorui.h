///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __APPMONITORUI_H__
#define __APPMONITORUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/clrpicker.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/dialog.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class AppMonitorSettingsDialogBase
///////////////////////////////////////////////////////////////////////////////
class AppMonitorSettingsDialogBase : public wxDialog 
{
	private:
		wxBoxSizer* mainSizer;
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxChoice* m_choiceRefreshTime;
		wxCheckBox* m_checkBoxDiscUsage;
		wxStaticText* m_staticText3;
		wxColourPickerCtrl* m_colourCPUUsage;
		wxStaticText* m_staticText41;
		wxColourPickerCtrl* m_colourMemoryUsage;
		wxStaticText* m_staticText5;
		wxColourPickerCtrl* m_colourDiscWriting;
		wxStaticText* m_static45;
		wxColourPickerCtrl* m_colourDiscReading;
		wxCheckBox* m_checkBoxlogToFile;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textLogFileName;
		wxStaticText* m_staticTextOS;
		wxTextCtrl* m_textCtrlCommand;
		wxButton* m_buttonDefaultSettings;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDefaultSettings( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		
		AppMonitorSettingsDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("AppMonitor settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~AppMonitorSettingsDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AppMonitorOutputViewBase
///////////////////////////////////////////////////////////////////////////////
class AppMonitorOutputViewBase : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_TOOL_STOP_PROCESS = 9500
		};
		
		wxAuiToolBar* m_auiToolBar1;
		wxAuiToolBarItem* m_toolRun; 
		wxAuiToolBarItem* m_toolStop; 
		wxAuiToolBarItem* m_toolPause; 
		wxAuiToolBarItem* m_toolContinue; 
		wxAuiToolBarItem* m_toolSettings; 
		wxBoxSizer* m_visualizerWrapper;
	
	public:
		
		AppMonitorOutputViewBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxHSCROLL|wxTAB_TRAVERSAL ); 
		~AppMonitorOutputViewBase();
	
};

#endif //__APPMONITORUI_H__