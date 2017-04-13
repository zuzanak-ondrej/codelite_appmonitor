//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: findinfiles_dlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "findinfiles_dlg.h"


// Declare the bitmap loading function
extern void wxCABC4InitBitmapResources();

static bool bBitmapLoaded = false;


FindInFilesDialogBase::FindInFilesDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCABC4InitBitmapResources();
        bBitmapLoaded = true;
    }
    // Set icon(s) to the application/dialog
    wxIconBundle app_icons;
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("16-find_in_files"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("16-find_in_files@2x"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    SetIcons( app_icons );

    
    wxBoxSizer* boxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(boxSizer7);
    
    m_panelMainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    
    boxSizer7->Add(m_panelMainPanel, 1, wxALL|wxEXPAND, WXC_FROM_DIP(10));
    
    wxBoxSizer* boxSizer95 = new wxBoxSizer(wxVERTICAL);
    m_panelMainPanel->SetSizer(boxSizer95);
    
    wxFlexGridSizer* fgSizer41 = new wxFlexGridSizer(0, 3, 0, 0);
    fgSizer41->SetFlexibleDirection( wxBOTH );
    fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer41->AddGrowableCol(1);
    fgSizer41->AddGrowableRow(4);
    
    boxSizer95->Add(fgSizer41, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticText1 = new wxStaticText(m_panelMainPanel, wxID_ANY, _("Find What :"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    
    fgSizer41->Add(m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_findStringArr;
    m_findString = new wxComboBox(m_panelMainPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), m_findStringArr, 0);
    m_findString->SetToolTip(_("Find what"));
    m_findString->SetFocus();
    #if wxVERSION_NUMBER >= 3000
    m_findString->SetHint(_("Find what"));
    #endif
    
    fgSizer41->Add(m_findString, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_find = new wxButton(m_panelMainPanel, wxID_FIND, _("&Find"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_find->SetDefault();
    m_find->SetToolTip(_("Begin search"));
    
    fgSizer41->Add(m_find, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_staticText102 = new wxStaticText(m_panelMainPanel, wxID_ANY, _("Replace With:"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1,-1)), 0);
    
    fgSizer41->Add(m_staticText102, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_replaceStringArr;
    m_replaceString = new wxComboBox(m_panelMainPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1,-1)), m_replaceStringArr, 0);
    #if wxVERSION_NUMBER >= 3000
    m_replaceString->SetHint(_("Replace with"));
    #endif
    
    fgSizer41->Add(m_replaceString, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_replaceAll = new wxButton(m_panelMainPanel, wxID_REPLACE, _("&Replace"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_replaceAll->SetToolTip(_("Search for matches and place them in the 'Replace' window as candidates for possible replace operation"));
    
    fgSizer41->Add(m_replaceAll, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_staticText3 = new wxStaticText(m_panelMainPanel, wxID_ANY, _("File Mask:"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    
    fgSizer41->Add(m_staticText3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_fileTypesArr;
    m_fileTypesArr.Add(wxT("*.c;*.cpp;*.cxx;*.cc;*.h;*.hpp;*.inc;*.mm;*.m;*.xrc"));
    m_fileTypes = new wxComboBox(m_panelMainPanel, wxID_ANY, wxT("*.c;*.cpp;*.cxx;*.cc;*.h;*.hpp;*.inc;*.mm;*.m;*.xrc"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), m_fileTypesArr, 0);
    m_fileTypes->SetToolTip(_("Search these file types"));
    #if wxVERSION_NUMBER >= 3000
    m_fileTypes->SetHint(wxT(""));
    #endif
    m_fileTypes->SetSelection(0);
    
    fgSizer41->Add(m_fileTypes, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_cancel = new wxButton(m_panelMainPanel, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_cancel->SetToolTip(_("Close this dialog"));
    
    fgSizer41->Add(m_cancel, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_staticText5 = new wxStaticText(m_panelMainPanel, wxID_ANY, _("Files Encoding:"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    
    fgSizer41->Add(m_staticText5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_choiceEncodingArr;
    m_choiceEncoding = new wxChoice(m_panelMainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), m_choiceEncodingArr, 0);
    m_choiceEncoding->SetToolTip(_("Use this file encoding when scanning files for matches"));
    
    fgSizer41->Add(m_choiceEncoding, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_stop = new wxButton(m_panelMainPanel, wxID_STOP, _("Sto&p"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_stop->SetToolTip(_("Stop the current search"));
    
    fgSizer41->Add(m_stop, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_staticText2 = new wxStaticText(m_panelMainPanel, wxID_ANY, _("Look in :"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    
    fgSizer41->Add(m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, WXC_FROM_DIP(5));
    
    wxArrayString m_listPathsArr;
    m_listPaths = new wxListBox(m_panelMainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), m_listPathsArr, wxLB_MULTIPLE);
    
    fgSizer41->Add(m_listPaths, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* bSizer9 = new wxBoxSizer(wxHORIZONTAL);
    
    fgSizer41->Add(bSizer9, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    
    bSizer9->Add(boxSizer1, 0, wxEXPAND|wxALIGN_TOP, WXC_FROM_DIP(5));
    
    m_btnAddPath = new wxButton(m_panelMainPanel, wxID_ANY, _("Add Path..."), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1,-1)), 0);
    m_btnAddPath->SetToolTip(_("Add new search location"));
    
    boxSizer1->Add(m_btnAddPath, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_btnClearSelectedPath = new wxButton(m_panelMainPanel, wxID_ANY, _("Clear Path"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1,-1)), 0);
    m_btnClearSelectedPath->SetToolTip(_("Clear the selected entry from the\n'Look In' list box"));
    
    boxSizer1->Add(m_btnClearSelectedPath, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    fgSizer41->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer105 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer95->Add(boxSizer105, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));
    
    wxFlexGridSizer* fgSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    fgSizer3->SetFlexibleDirection( wxBOTH );
    fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    boxSizer105->Add(fgSizer3, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_matchCase = new wxCheckBox(m_panelMainPanel, wxID_ANY, _("&Match case"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_matchCase->SetValue(false);
    m_matchCase->SetToolTip(_("Toggle case sensitive search"));
    
    fgSizer3->Add(m_matchCase, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_matchWholeWord = new wxCheckBox(m_panelMainPanel, wxID_ANY, _("Match &whole word"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_matchWholeWord->SetValue(false);
    m_matchWholeWord->SetToolTip(_("Toggle whole word search"));
    
    fgSizer3->Add(m_matchWholeWord, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_checkBoxPipeForGrep = new wxCheckBox(m_panelMainPanel, wxID_ANY, _("Enable pipe filtering"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1,-1)), 0);
    m_checkBoxPipeForGrep->SetValue(false);
    m_checkBoxPipeForGrep->SetToolTip(_("Use the pipe character (\"|\") as a special separator for applying additional filters. This has the similar effect as using the \"grep\" command line tool"));
    
    fgSizer3->Add(m_checkBoxPipeForGrep, 0, wxALL, WXC_FROM_DIP(5));
    
    m_regualrExpression = new wxCheckBox(m_panelMainPanel, wxID_ANY, _("Regular &expression"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_regualrExpression->SetValue(false);
    m_regualrExpression->SetToolTip(_("The 'Find What' field is a regular expression"));
    
    fgSizer3->Add(m_regualrExpression, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_checkBoxSaveFilesBeforeSearching = new wxCheckBox(m_panelMainPanel, wxID_ANY, _("&Save files before search"), wxDefaultPosition, wxDLG_UNIT(m_panelMainPanel, wxSize(-1, -1)), 0);
    m_checkBoxSaveFilesBeforeSearching->SetValue(false);
    m_checkBoxSaveFilesBeforeSearching->SetToolTip(_("Save any modified files before search starts"));
    
    fgSizer3->Add(m_checkBoxSaveFilesBeforeSearching, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    SetName(wxT("FindInFilesDialogBase"));
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
    m_find->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnFind), NULL, this);
    m_find->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesDialogBase::OnFindWhatUI), NULL, this);
    m_replaceAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnReplace), NULL, this);
    m_replaceAll->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesDialogBase::OnReplaceUI), NULL, this);
    m_cancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnButtonClose), NULL, this);
    m_stop->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnStop), NULL, this);
    m_listPaths->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(FindInFilesDialogBase::OnLookInKeyDown), NULL, this);
    m_btnAddPath->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnAddPath), NULL, this);
    m_btnClearSelectedPath->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnClearSelectedPath), NULL, this);
    m_btnClearSelectedPath->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesDialogBase::OnClearSelectedPathUI), NULL, this);
    
}

FindInFilesDialogBase::~FindInFilesDialogBase()
{
    m_find->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnFind), NULL, this);
    m_find->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesDialogBase::OnFindWhatUI), NULL, this);
    m_replaceAll->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnReplace), NULL, this);
    m_replaceAll->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesDialogBase::OnReplaceUI), NULL, this);
    m_cancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnButtonClose), NULL, this);
    m_stop->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnStop), NULL, this);
    m_listPaths->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(FindInFilesDialogBase::OnLookInKeyDown), NULL, this);
    m_btnAddPath->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnAddPath), NULL, this);
    m_btnClearSelectedPath->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesDialogBase::OnClearSelectedPath), NULL, this);
    m_btnClearSelectedPath->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesDialogBase::OnClearSelectedPathUI), NULL, this);
    
}

FindInFilesLocationsDlgBase::FindInFilesLocationsDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCABC4InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer111 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer111);
    
    wxBoxSizer* boxSizer120 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer111->Add(boxSizer120, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxArrayString m_checkListBoxLocationsArr;
    m_checkListBoxLocations = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), m_checkListBoxLocationsArr, wxLB_SINGLE);
    m_checkListBoxLocations->SetFocus();
    
    boxSizer120->Add(m_checkListBoxLocations, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer125 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer120->Add(boxSizer125, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, WXC_FROM_DIP(5));
    
    m_buttonAdd = new wxButton(this, wxID_ANY, _("Add..."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_buttonAdd->SetToolTip(_("Add Folder..."));
    
    boxSizer125->Add(m_buttonAdd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, WXC_FROM_DIP(5));
    
    m_buttonDelete = new wxButton(this, wxID_ANY, _("Remove"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_buttonDelete->SetToolTip(_("Remove the selected path"));
    
    boxSizer125->Add(m_buttonDelete, 0, wxALL, WXC_FROM_DIP(5));
    
    m_stdBtnSizer113 = new wxStdDialogButtonSizer();
    
    boxSizer111->Add(m_stdBtnSizer113, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(10));
    
    m_button115 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button115->SetDefault();
    m_stdBtnSizer113->AddButton(m_button115);
    
    m_button117 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer113->AddButton(m_button117);
    m_stdBtnSizer113->Realize();
    
    SetName(wxT("FindInFilesLocationsDlgBase"));
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
    m_buttonAdd->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesLocationsDlgBase::OnAddPath), NULL, this);
    m_buttonDelete->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesLocationsDlgBase::OnDeletePath), NULL, this);
    m_buttonDelete->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesLocationsDlgBase::OnDeletePathUI), NULL, this);
    
}

FindInFilesLocationsDlgBase::~FindInFilesLocationsDlgBase()
{
    m_buttonAdd->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesLocationsDlgBase::OnAddPath), NULL, this);
    m_buttonDelete->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindInFilesLocationsDlgBase::OnDeletePath), NULL, this);
    m_buttonDelete->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FindInFilesLocationsDlgBase::OnDeletePathUI), NULL, this);
    
}
