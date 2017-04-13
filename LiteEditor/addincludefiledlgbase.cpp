//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: AddIncludeFile.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "addincludefiledlgbase.h"


// Declare the bitmap loading function
extern void wxC10CDInitBitmapResources();

static bool bBitmapLoaded = false;


AddIncludeFileDlgBase::AddIncludeFileDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC10CDInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer7 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer7);
    
    m_auibar6 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibar6->SetToolBitmapSize(wxSize(16,16));
    
    bSizer7->Add(m_auibar6, 0, wxEXPAND, 5);
    
    m_auibar6->AddLabel(wxID_ANY, _("Edit the line to add:"), -1);
    
    m_auibar6->AddStretchSpacer(1);
    
    m_auibar6->AddTool(ID_LINEUP, _("Move Up"), wxXmlResource::Get()->LoadBitmap(wxT("16-up")), wxNullBitmap, wxITEM_NORMAL, _("Move the #include statement one line up"), _("Move the #include statement one line up"), NULL);
    
    m_auibar6->AddTool(ID_LINEDOWN, _("Move Down"), wxXmlResource::Get()->LoadBitmap(wxT("16-down")), wxNullBitmap, wxITEM_NORMAL, _("Move the #include statement one line down"), _("Move the #include statement one line down"), NULL);
    
    m_auibar6->AddTool(wxID_CLEAR, _("Clear Cached Paths"), wxXmlResource::Get()->LoadBitmap(wxT("16-clear")), wxNullBitmap, wxITEM_NORMAL, _("Clear Cached Paths"), _("Clear Cached Paths"), NULL);
    m_auibar6->Realize();
    
    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    
    bSizer7->Add(m_mainPanel, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* bSizer9 = new wxBoxSizer(wxVERTICAL);
    m_mainPanel->SetSizer(bSizer9);
    
    m_textCtrlPreview = new wxStyledTextCtrl(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(400,300), 0);
    #ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to wxFONTFAMILY_TELETYPE
    wxFont m_textCtrlPreviewFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_textCtrlPreviewFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #else
    wxFont m_textCtrlPreviewFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_textCtrlPreviewFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #endif
    m_textCtrlPreview->SetFont(m_textCtrlPreviewFont);
    m_textCtrlPreview->SetFocus();
    // Configure the fold margin
    m_textCtrlPreview->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_textCtrlPreview->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_textCtrlPreview->SetMarginSensitive(4, true);
    m_textCtrlPreview->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_textCtrlPreview->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_textCtrlPreview->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_textCtrlPreview->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_textCtrlPreview->SetMarginWidth(2, 0);
    m_textCtrlPreview->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    int m_textCtrlPreview_PixelWidth = 4 + 5 *m_textCtrlPreview->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("9"));
    m_textCtrlPreview->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrlPreview->SetMarginWidth(0,m_textCtrlPreview_PixelWidth);
    
    // Configure the line symbol margin
    m_textCtrlPreview->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_textCtrlPreview->SetMarginMask(3, 0);
    m_textCtrlPreview->SetMarginWidth(3,0);
    // Select the lexer
    m_textCtrlPreview->SetLexer(wxSTC_LEX_CPP);
    // Set default font / styles
    m_textCtrlPreview->StyleClearAll();
    for(int i=0; i<wxSTC_STYLE_MAX; ++i) {
        m_textCtrlPreview->StyleSetFont(i, m_textCtrlPreviewFont);
    }
    m_textCtrlPreview->SetWrapMode(0);
    m_textCtrlPreview->SetIndentationGuides(0);
    m_textCtrlPreview->SetKeyWords(0, wxT(""));
    m_textCtrlPreview->SetKeyWords(1, wxT(""));
    m_textCtrlPreview->SetKeyWords(2, wxT(""));
    m_textCtrlPreview->SetKeyWords(3, wxT(""));
    m_textCtrlPreview->SetKeyWords(4, wxT(""));
    
    bSizer9->Add(m_textCtrlPreview, 1, wxLEFT|wxRIGHT|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer4->SetFlexibleDirection( wxBOTH );
    flexGridSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer4->AddGrowableCol(1);
    
    bSizer9->Add(flexGridSizer4, 0, wxALL|wxEXPAND, 5);
    
    m_staticText21 = new wxStaticText(m_mainPanel, wxID_ANY, _("Line to add:"), wxDefaultPosition, wxSize(-1,-1), 0);
    wxFont m_staticText21Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText21Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText21->SetFont(m_staticText21Font);
    
    flexGridSizer4->Add(m_staticText21, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticTextPreview = new wxStaticText(m_mainPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    #ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to wxFONTFAMILY_TELETYPE
    wxFont m_staticTextPreviewFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticTextPreviewFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #else
    wxFont m_staticTextPreviewFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_staticTextPreviewFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #endif
    m_staticTextPreview->SetFont(m_staticTextPreviewFont);
    
    flexGridSizer4->Add(m_staticTextPreview, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticText5 = new wxStaticText(m_mainPanel, wxID_ANY, _("File's full path:"), wxDefaultPosition, wxSize(-1, -1), 0);
    wxFont m_staticText5Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText5Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText5->SetFont(m_staticText5Font);
    
    flexGridSizer4->Add(m_staticText5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFullPath = new wxTextCtrl(m_mainPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(400,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFullPath->SetHint(wxT(""));
    #endif
    
    flexGridSizer4->Add(m_textCtrlFullPath, 0, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer23 = new wxStdDialogButtonSizer();
    
    bSizer7->Add(m_stdBtnSizer23, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
    
    m_button25 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button25->SetDefault();
    m_stdBtnSizer23->AddButton(m_button25);
    
    m_button27 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer23->AddButton(m_button27);
    m_stdBtnSizer23->Realize();
    
    SetName(wxT("AddIncludeFileDlgBase"));
    SetMinClientSize(wxSize(250,-1));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent();
    } else {
        CentreOnScreen();
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    this->Connect(ID_LINEUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnButtonUp), NULL, this);
    this->Connect(ID_LINEDOWN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnButtonDown), NULL, this);
    this->Connect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnClearCachedPaths), NULL, this);
    m_button25->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnButtonOK), NULL, this);
    
}

AddIncludeFileDlgBase::~AddIncludeFileDlgBase()
{
    this->Disconnect(ID_LINEUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnButtonUp), NULL, this);
    this->Disconnect(ID_LINEDOWN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnButtonDown), NULL, this);
    this->Disconnect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnClearCachedPaths), NULL, this);
    m_button25->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddIncludeFileDlgBase::OnButtonOK), NULL, this);
    
}
