//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: CscopeTabBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "CscopeTabBase.h"


// Declare the bitmap loading function
extern void wxC59CAInitBitmapResources();

static bool bBitmapLoaded = false;


CscopeTabBase::CscopeTabBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC59CAInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    wxBoxSizer* bSizer3 = new wxBoxSizer(wxHORIZONTAL);
    
    mainSizer->Add(bSizer3, 1, wxALL|wxEXPAND, 2);
    
    wxBoxSizer* boxSizer4 = new wxBoxSizer(wxVERTICAL);
    
    bSizer3->Add(boxSizer4, 1, wxEXPAND, 2);
    
    m_stc = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    // Configure the fold margin
    m_stc->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stc->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stc->SetMarginSensitive(4, true);
    m_stc->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stc->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stc->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stc->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stc->SetMarginWidth(2, 16);
    m_stc->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stc->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stc->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stc->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stc->SetMarginMask(3, 0);
    m_stc->SetMarginWidth(3,0);
    // Select the lexer
    m_stc->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stc->StyleClearAll();
    m_stc->SetWrapMode(0);
    m_stc->SetIndentationGuides(0);
    m_stc->SetKeyWords(0, wxT(""));
    m_stc->SetKeyWords(1, wxT(""));
    m_stc->SetKeyWords(2, wxT(""));
    m_stc->SetKeyWords(3, wxT(""));
    m_stc->SetKeyWords(4, wxT(""));
    
    boxSizer4->Add(m_stc, 1, wxALL|wxEXPAND, 2);
    
    wxBoxSizer* bSizer31 = new wxBoxSizer(wxVERTICAL);
    
    bSizer3->Add(bSizer31, 0, wxEXPAND, 2);
    
    m_staticText2 = new wxStaticText(this, wxID_ANY, _("Search scope:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    bSizer31->Add(m_staticText2, 0, wxLEFT|wxRIGHT|wxTOP|wxALIGN_LEFT, 5);
    
    wxArrayString m_choiceSearchScopeArr;
    m_choiceSearchScope = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_choiceSearchScopeArr, 0);
    
    bSizer31->Add(m_choiceSearchScope, 0, wxALL|wxEXPAND, 5);
    
    m_checkBoxUpdateDb = new wxCheckBox(this, wxID_ANY, _("Update Db if stale"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxUpdateDb->SetValue(false);
    m_checkBoxUpdateDb->SetToolTip(_("If checked, before executing a command CScope will look for any changed files and, if found, try to update the database. In practice this seems unreliable."));
    
    bSizer31->Add(m_checkBoxUpdateDb, 0, wxALL|wxALIGN_LEFT, 5);
    
    m_checkBoxRevertedIndex = new wxCheckBox(this, wxID_ANY, _("Create reverted Index"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxRevertedIndex->SetValue(false);
    m_checkBoxRevertedIndex->SetToolTip(_("Create reverted Index database"));
    
    bSizer31->Add(m_checkBoxRevertedIndex, 0, wxALL|wxALIGN_LEFT, 5);
    
    bSizer31->Add(0, 0, 1, wxALL, 5);
    
    m_buttonUpdateDbNow = new wxButton(this, wxID_ANY, _("&Update"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonUpdateDbNow->SetToolTip(_("Perform an immediate database update"));
    
    bSizer31->Add(m_buttonUpdateDbNow, 0, wxLEFT|wxRIGHT|wxEXPAND, 5);
    
    m_buttonClear = new wxButton(this, wxID_ANY, _("&Clear"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    bSizer31->Add(m_buttonClear, 0, wxALL|wxEXPAND, 5);
    
    m_gauge = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxSize(-1,-1), wxGA_SMOOTH|wxGA_HORIZONTAL);
    m_gauge->SetValue(0);
    
    bSizer31->Add(m_gauge, 0, wxALL|wxEXPAND, 5);
    
    SetName(wxT("CscopeTabBase"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    m_stc->Connect(wxEVT_STC_HOTSPOT_CLICK, wxStyledTextEventHandler(CscopeTabBase::OnHotspotClicked), NULL, this);
    m_choiceSearchScope->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(CscopeTabBase::OnChangeSearchScope), NULL, this);
    m_checkBoxUpdateDb->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CscopeTabBase::OnChangeSearchScope), NULL, this);
    m_checkBoxUpdateDb->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnWorkspaceOpenUI), NULL, this);
    m_checkBoxRevertedIndex->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CscopeTabBase::OnChangeSearchScope), NULL, this);
    m_checkBoxRevertedIndex->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnWorkspaceOpenUI), NULL, this);
    m_buttonUpdateDbNow->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CscopeTabBase::OnCreateDB), NULL, this);
    m_buttonUpdateDbNow->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnWorkspaceOpenUI), NULL, this);
    m_buttonClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CscopeTabBase::OnClearResults), NULL, this);
    m_buttonClear->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnClearResultsUI), NULL, this);
    
}

CscopeTabBase::~CscopeTabBase()
{
    m_stc->Disconnect(wxEVT_STC_HOTSPOT_CLICK, wxStyledTextEventHandler(CscopeTabBase::OnHotspotClicked), NULL, this);
    m_choiceSearchScope->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(CscopeTabBase::OnChangeSearchScope), NULL, this);
    m_checkBoxUpdateDb->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CscopeTabBase::OnChangeSearchScope), NULL, this);
    m_checkBoxUpdateDb->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnWorkspaceOpenUI), NULL, this);
    m_checkBoxRevertedIndex->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CscopeTabBase::OnChangeSearchScope), NULL, this);
    m_checkBoxRevertedIndex->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnWorkspaceOpenUI), NULL, this);
    m_buttonUpdateDbNow->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CscopeTabBase::OnCreateDB), NULL, this);
    m_buttonUpdateDbNow->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnWorkspaceOpenUI), NULL, this);
    m_buttonClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CscopeTabBase::OnClearResults), NULL, this);
    m_buttonClear->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CscopeTabBase::OnClearResultsUI), NULL, this);
    
}

CScopeSettingsDlgBase::CScopeSettingsDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC59CAInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer10 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer10);
    
    wxFlexGridSizer* flexGridSizer18 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer18->SetFlexibleDirection( wxBOTH );
    flexGridSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer18->AddGrowableCol(1);
    
    boxSizer10->Add(flexGridSizer18, 1, wxALL|wxEXPAND, 5);
    
    m_staticText20 = new wxStaticText(this, wxID_ANY, _("CScope executable:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer18->Add(m_staticText20, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_filePickerCScopeExe = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*"), wxDefaultPosition, wxSize(-1,-1), wxFLP_USE_TEXTCTRL|wxFLP_SMALL);
    m_filePickerCScopeExe->SetToolTip(_("Set the path to cscope executable"));
    m_filePickerCScopeExe->SetFocus();
    
    flexGridSizer18->Add(m_filePickerCScopeExe, 0, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer12 = new wxStdDialogButtonSizer();
    
    boxSizer10->Add(m_stdBtnSizer12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button14 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button14->SetDefault();
    m_stdBtnSizer12->AddButton(m_button14);
    
    m_button16 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer12->AddButton(m_button16);
    m_stdBtnSizer12->Realize();
    
    SetName(wxT("CScopeSettingsDlgBase"));
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
}

CScopeSettingsDlgBase::~CScopeSettingsDlgBase()
{
}