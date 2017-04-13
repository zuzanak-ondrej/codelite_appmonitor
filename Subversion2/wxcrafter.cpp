//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC38D8InitBitmapResources();

static bool bBitmapLoaded = false;


SvnCommitDialogBaseClass::SvnCommitDialogBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC38D8InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    wxFlexGridSizer* flexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer5->SetFlexibleDirection( wxBOTH );
    flexGridSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer5->AddGrowableCol(1);
    
    boxSizer1->Add(flexGridSizer5, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticText32 = new wxStaticText(this, wxID_ANY, _("Feature Request ID:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    flexGridSizer5->Add(m_staticText32, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, WXC_FROM_DIP(5));
    
    m_textCtrlFrID = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFrID->SetHint(wxT(""));
    #endif
    
    flexGridSizer5->Add(m_textCtrlFrID, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticTextBugID = new wxStaticText(this, wxID_ANY, _("Bug ID:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    flexGridSizer5->Add(m_staticTextBugID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, WXC_FROM_DIP(5));
    
    m_textCtrlBugID = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlBugID->SetHint(wxT(""));
    #endif
    
    flexGridSizer5->Add(m_textCtrlBugID, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_splitterV = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME);
    m_splitterV->SetSashGravity(0.5);
    m_splitterV->SetMinimumPaneSize(10);
    
    boxSizer1->Add(m_splitterV, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_splitterPage52 = new wxPanel(m_splitterV, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterV, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer58 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage52->SetSizer(boxSizer58);
    
    m_splitterH = new wxSplitterWindow(m_splitterPage52, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterPage52, wxSize(-1,-1)), wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME);
    m_splitterH->SetSashGravity(0.5);
    m_splitterH->SetMinimumPaneSize(10);
    
    boxSizer58->Add(m_splitterH, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    m_panel1 = new wxPanel(m_splitterH, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterH, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer15 = new wxBoxSizer(wxVERTICAL);
    m_panel1->SetSizer(boxSizer15);
    
    m_staticText17 = new wxStaticText(m_panel1, wxID_ANY, _("Modified Paths:"), wxDefaultPosition, wxDLG_UNIT(m_panel1, wxSize(-1,-1)), 0);
    
    boxSizer15->Add(m_staticText17, 0, wxALL|wxALIGN_LEFT, WXC_FROM_DIP(5));
    
    wxArrayString m_checkListFilesArr;
    m_checkListFiles = new wxCheckListBox(m_panel1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel1, wxSize(-1,-1)), m_checkListFilesArr, wxLB_SINGLE);
    
    boxSizer15->Add(m_checkListFiles, 1, wxALL|wxEXPAND, WXC_FROM_DIP(2));
    
    m_splitterPage14 = new wxPanel(m_splitterH, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterH, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_splitterH->SplitVertically(m_panel1, m_splitterPage14, 0);
    
    wxBoxSizer* boxSizer16 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage14->SetSizer(boxSizer16);
    
    m_staticText19 = new wxStaticText(m_splitterPage14, wxID_ANY, _("Diff:"), wxDefaultPosition, wxDLG_UNIT(m_splitterPage14, wxSize(-1,-1)), 0);
    
    boxSizer16->Add(m_staticText19, 0, wxALL|wxALIGN_LEFT, WXC_FROM_DIP(5));
    
    m_stcDiff = new wxStyledTextCtrl(m_splitterPage14, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterPage14, wxSize(-1,-1)), 0);
    // Configure the fold margin
    m_stcDiff->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcDiff->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcDiff->SetMarginSensitive(4, true);
    m_stcDiff->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcDiff->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcDiff->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcDiff->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcDiff->SetMarginWidth(2, 0);
    m_stcDiff->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcDiff->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcDiff->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcDiff->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcDiff->SetMarginMask(3, 0);
    m_stcDiff->SetMarginWidth(3,0);
    // Select the lexer
    m_stcDiff->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcDiff->StyleClearAll();
    m_stcDiff->SetWrapMode(0);
    m_stcDiff->SetIndentationGuides(0);
    m_stcDiff->SetKeyWords(0, wxT(""));
    m_stcDiff->SetKeyWords(1, wxT(""));
    m_stcDiff->SetKeyWords(2, wxT(""));
    m_stcDiff->SetKeyWords(3, wxT(""));
    m_stcDiff->SetKeyWords(4, wxT(""));
    
    boxSizer16->Add(m_stcDiff, 1, wxALL|wxEXPAND, WXC_FROM_DIP(2));
    
    m_splitterPage56 = new wxPanel(m_splitterV, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterV, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_splitterV->SplitHorizontally(m_splitterPage52, m_splitterPage56, 0);
    
    wxBoxSizer* boxSizer60 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage56->SetSizer(boxSizer60);
    
    m_auibar76 = new wxAuiToolBar(m_splitterPage56, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterPage56, wxSize(-1,-1)), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE|wxAUI_TB_HORZ_TEXT);
    m_auibar76->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer60->Add(m_auibar76, 0, wxEXPAND, WXC_FROM_DIP(5));
    
    m_auibar76->AddTool(ID_SHOW_COMMIT_HISTORY, _("Commit History"), wxXmlResource::Get()->LoadBitmap(wxT("16-history")), wxNullBitmap, wxITEM_NORMAL, _("Show Commit History"), _("Show Commit History"), NULL);
    
    m_auibar76->AddStretchSpacer(1);
    
    m_auibar76->AddTool(ID_TOOL_CLEAR_HISTORY, _("Clear History"), wxXmlResource::Get()->LoadBitmap(wxT("16-clear")), wxNullBitmap, wxITEM_NORMAL, _("Clear History"), _("Clear History"), NULL);
    m_auibar76->Realize();
    
    m_stcMessage = new wxStyledTextCtrl(m_splitterPage56, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterPage56, wxSize(-1,-1)), wxBORDER_THEME);
    m_stcMessage->SetFocus();
    // Configure the fold margin
    m_stcMessage->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcMessage->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcMessage->SetMarginSensitive(4, true);
    m_stcMessage->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcMessage->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcMessage->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcMessage->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcMessage->SetMarginWidth(2, 0);
    m_stcMessage->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcMessage->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcMessage->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcMessage->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcMessage->SetMarginMask(3, 0);
    m_stcMessage->SetMarginWidth(3,0);
    // Select the lexer
    m_stcMessage->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcMessage->StyleClearAll();
    m_stcMessage->SetWrapMode(0);
    m_stcMessage->SetIndentationGuides(0);
    m_stcMessage->SetKeyWords(0, wxT(""));
    m_stcMessage->SetKeyWords(1, wxT(""));
    m_stcMessage->SetKeyWords(2, wxT(""));
    m_stcMessage->SetKeyWords(3, wxT(""));
    m_stcMessage->SetKeyWords(4, wxT(""));
    
    boxSizer60->Add(m_stcMessage, 1, wxALL|wxEXPAND, WXC_FROM_DIP(2));
    
    wxBoxSizer* boxSizer86 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer1->Add(boxSizer86, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));
    
    m_button88 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_button88->SetDefault();
    
    boxSizer86->Add(m_button88, 0, wxALL, WXC_FROM_DIP(5));
    
    m_button90 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    boxSizer86->Add(m_button90, 0, wxALL, WXC_FROM_DIP(5));
    
    SetName(wxT("SvnCommitDialogBaseClass"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_checkListFiles->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnFileSelected), NULL, this);
    this->Connect(ID_SHOW_COMMIT_HISTORY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnShowCommitHistory), NULL, this);
    this->Connect(ID_SHOW_COMMIT_HISTORY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnCommitDialogBaseClass::OnShowCommitHistoryUI), NULL, this);
    this->Connect(ID_TOOL_CLEAR_HISTORY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnClearHistory), NULL, this);
    this->Connect(ID_TOOL_CLEAR_HISTORY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnCommitDialogBaseClass::OnClearHistoryUI), NULL, this);
    
}

SvnCommitDialogBaseClass::~SvnCommitDialogBaseClass()
{
    m_checkListFiles->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnFileSelected), NULL, this);
    this->Disconnect(ID_SHOW_COMMIT_HISTORY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnShowCommitHistory), NULL, this);
    this->Disconnect(ID_SHOW_COMMIT_HISTORY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnCommitDialogBaseClass::OnShowCommitHistoryUI), NULL, this);
    this->Disconnect(ID_TOOL_CLEAR_HISTORY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(SvnCommitDialogBaseClass::OnClearHistory), NULL, this);
    this->Disconnect(ID_TOOL_CLEAR_HISTORY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnCommitDialogBaseClass::OnClearHistoryUI), NULL, this);
    
}

SvnSyncDialogBaseClass::SvnSyncDialogBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC38D8InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer26 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer26);
    
    wxBoxSizer* boxSizer32 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer26->Add(boxSizer32, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, WXC_FROM_DIP(5));
    
    m_staticText31 = new wxStaticText(this, wxID_ANY, _("Root URL:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    wxFont m_staticText31Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText31Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText31->SetFont(m_staticText31Font);
    
    boxSizer32->Add(m_staticText31, 0, wxALL, WXC_FROM_DIP(5));
    
    m_staticTextSvnInfo = new wxStaticText(this, wxID_ANY, _("<none detected>"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    boxSizer32->Add(m_staticTextSvnInfo, 0, wxALL, WXC_FROM_DIP(5));
    
    wxFlexGridSizer* flexGridSizer37 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer37->SetFlexibleDirection( wxBOTH );
    flexGridSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer37->AddGrowableCol(1);
    
    boxSizer26->Add(flexGridSizer37, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticText34 = new wxStaticText(this, wxID_ANY, _("Root Directory:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    flexGridSizer37->Add(m_staticText34, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, WXC_FROM_DIP(5));
    
    m_dirPickerRootDir = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxDIRP_DEFAULT_STYLE);
    
    flexGridSizer37->Add(m_dirPickerRootDir, 0, wxEXPAND|wxALL, WXC_FROM_DIP(5));
    
    m_staticText40 = new wxStaticText(this, wxID_ANY, _("Exclude these file extensions:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    flexGridSizer37->Add(m_staticText40, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, WXC_FROM_DIP(5));
    
    m_textCtrlExclude = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxTE_RICH2);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlExclude->SetHint(wxT(""));
    #endif
    
    flexGridSizer37->Add(m_textCtrlExclude, 0, wxEXPAND|wxALL, WXC_FROM_DIP(5));
    
    flexGridSizer37->Add(0, 0, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxBin = new wxCheckBox(this, wxID_ANY, _("Exclude binary (application/octet-stream) files"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_checkBoxBin->SetValue(false);
    
    flexGridSizer37->Add(m_checkBoxBin, 0, wxALL, WXC_FROM_DIP(5));
    
    boxSizer26->Add(0, 0, 1, wxEXPAND|wxALL, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer26->Add(boxSizer27, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, WXC_FROM_DIP(5));
    
    m_button28 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_button28->SetDefault();
    
    boxSizer27->Add(m_button28, 0, wxALL, WXC_FROM_DIP(5));
    
    m_button29 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    boxSizer27->Add(m_button29, 0, wxALL, WXC_FROM_DIP(5));
    
    SetName(wxT("SvnSyncDialogBaseClass"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button28->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnSyncDialogBaseClass::OnOkUI), NULL, this);
    m_button28->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SvnSyncDialogBaseClass::OnButtonOK), NULL, this);
    
}

SvnSyncDialogBaseClass::~SvnSyncDialogBaseClass()
{
    m_button28->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SvnSyncDialogBaseClass::OnOkUI), NULL, this);
    m_button28->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SvnSyncDialogBaseClass::OnButtonOK), NULL, this);
    
}
