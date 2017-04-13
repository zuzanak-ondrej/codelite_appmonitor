///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "appmonitorui.h"

#include "icons/cog16.png.h"
#include "icons/continue16.png.h"
#include "icons/execute_stop16.png.h"
#include "icons/interrupt16.png.h"
#include "icons/start16.png.h"

///////////////////////////////////////////////////////////////////////////

AppMonitorSettingsDialogBase::AppMonitorSettingsDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 270,320 ), wxDefaultSize );
	
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, _("Graph refresh time:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString m_choiceRefreshTimeChoices[] = { _("2s"), _("1s"), _("500ms"), _("250ms") };
	int m_choiceRefreshTimeNChoices = sizeof( m_choiceRefreshTimeChoices ) / sizeof( wxString );
	m_choiceRefreshTime = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRefreshTimeNChoices, m_choiceRefreshTimeChoices, 0 );
	m_choiceRefreshTime->SetSelection( 1 );
	bSizer5->Add( m_choiceRefreshTime, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* m_bSizerDiscUsage;
	m_bSizerDiscUsage = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBoxDiscUsage = new wxCheckBox( m_panel1, wxID_ANY, _("Show disc usage:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_bSizerDiscUsage->Add( m_checkBoxDiscUsage, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer4->Add( m_bSizerDiscUsage, 0, wxEXPAND, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, _("CPU usage colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourCPUUsage = new wxColourPickerCtrl( m_panel1, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourCPUUsage, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 25 );
	
	m_staticText41 = new wxStaticText( m_panel1, wxID_ANY, _("Memory usage colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	gSizer1->Add( m_staticText41, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourMemoryUsage = new wxColourPickerCtrl( m_panel1, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourMemoryUsage, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 25 );
	
	m_staticText5 = new wxStaticText( m_panel1, wxID_ANY, _("Disc writing colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer1->Add( m_staticText5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourDiscWriting = new wxColourPickerCtrl( m_panel1, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourDiscWriting, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 25 );
	
	m_static45 = new wxStaticText( m_panel1, wxID_ANY, _("Disc reading colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static45->Wrap( -1 );
	gSizer1->Add( m_static45, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_colourDiscReading = new wxColourPickerCtrl( m_panel1, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gSizer1->Add( m_colourDiscReading, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 25 );
	
	
	bSizer4->Add( gSizer1, 0, 0, 5 );
	
	
	m_panel1->SetSizer( bSizer4 );
	m_panel1->Layout();
	bSizer4->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("Visualizer"), false );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Log") ), wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBoxlogToFile = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("Logging values to file:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer8->Add( m_checkBoxlogToFile, 0, wxTOP|wxLEFT, 5 );
	
	
	sbSizer1->Add( bSizer8, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer9->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_textLogFileName = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_textLogFileName->HasFlag( wxTE_MULTILINE ) )
	{
	m_textLogFileName->SetMaxLength( 50 );
	}
	#else
	m_textLogFileName->SetMaxLength( 50 );
	#endif
	bSizer9->Add( m_textLogFileName, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer1->Add( bSizer9, 0, wxEXPAND|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	
	bSizer7->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Command for capture PID") ), wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextOS = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("OS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOS->Wrap( -1 );
	bSizer11->Add( m_staticTextOS, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlCommand = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrlCommand->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlCommand->SetMaxLength( 500 );
	}
	#else
	m_textCtrlCommand->SetMaxLength( 500 );
	#endif
	bSizer11->Add( m_textCtrlCommand, 1, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer11, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );
	
	
	sbSizer2->Add( bSizer121, 1, wxEXPAND, 5 );
	
	
	bSizer7->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonDefaultSettings = new wxButton( m_panel2, wxID_ANY, _("Default settings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_buttonDefaultSettings, 1, wxEXPAND, 5 );
	
	
	bSizer7->Add( bSizer12, 0, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer7 );
	m_panel2->Layout();
	bSizer7->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, _("Advanced"), true );
	
	mainSizer->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	mainSizer->Add( m_sdbSizer1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	mainSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonDefaultSettings->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AppMonitorSettingsDialogBase::OnDefaultSettings ), NULL, this );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AppMonitorSettingsDialogBase::OnCancel ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AppMonitorSettingsDialogBase::OnSave ), NULL, this );
}

AppMonitorSettingsDialogBase::~AppMonitorSettingsDialogBase()
{
	// Disconnect Events
	m_buttonDefaultSettings->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AppMonitorSettingsDialogBase::OnDefaultSettings ), NULL, this );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AppMonitorSettingsDialogBase::OnCancel ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AppMonitorSettingsDialogBase::OnSave ), NULL, this );
	
}

AppMonitorOutputViewBase::AppMonitorOutputViewBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( -1,300 ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_auiToolBar1 = new wxAuiToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_HORZ_LAYOUT ); 
	m_toolRun = m_auiToolBar1->AddTool( XRCID("appmonitor_run"), _("Run AppMonitor"), start16_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, _("Run AppMonitor"), wxEmptyString, NULL ); 
	
	m_toolStop = m_auiToolBar1->AddTool( ID_TOOL_STOP_PROCESS, _("Stop execution"), execute_stop16_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, _("Stop execution"), wxEmptyString, NULL ); 
	
	m_auiToolBar1->AddSeparator(); 
	
	m_toolPause = m_auiToolBar1->AddTool( XRCID("appmonitor_pause"), _("Pause"), interrupt16_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, _("Pause"), wxEmptyString, NULL ); 
	
	m_toolContinue = m_auiToolBar1->AddTool( XRCID("appmonitor_continue"), _("Continue"), continue16_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, _("Continue"), wxEmptyString, NULL ); 
	
	m_auiToolBar1->AddSeparator(); 
	
	m_toolSettings = m_auiToolBar1->AddTool( XRCID("appmonitor_settings"), _("Settings"), cog16_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, _("Settings"), wxEmptyString, NULL ); 
	
	m_auiToolBar1->Realize(); 
	
	bSizer2->Add( m_auiToolBar1, 0, wxALL|wxEXPAND, 5 );
	
	m_visualizerWrapper = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer2->Add( m_visualizerWrapper, 4, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
}

AppMonitorOutputViewBase::~AppMonitorOutputViewBase()
{
}
