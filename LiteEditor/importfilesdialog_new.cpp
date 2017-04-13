//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: importfilesdialog.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "importfilesdialog_new.h"


// Declare the bitmap loading function
extern void wxC945BInitBitmapResources();

static bool bBitmapLoaded = false;


ImportFilesDialogNewBase::ImportFilesDialogNewBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC945BInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_banner1 = new wxBannerWindow(this, wxID_ANY, wxTOP, wxDefaultPosition, wxSize(-1,-1), wxBORDER_THEME);
    m_banner1->SetBitmap(wxNullBitmap);
    m_banner1->SetText(_("Import Files"), _("Select the directories to import from"));
    m_banner1->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    m_banner1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    
    mainSizer->Add(m_banner1, 0, wxALL|wxEXPAND, 5);
    
    m_dirPicker = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxSize(-1,-1), wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL);
    m_dirPicker->SetToolTip(_("Select the base folder for importing"));
    m_dirPicker->SetFocus();
    
    mainSizer->Add(m_dirPicker, 0, wxALL|wxEXPAND, 5);
    
    m_dataview = new wxDataViewCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_VERT_RULES|wxDV_ROW_LINES|wxDV_SINGLE);
    m_dataview->SetToolTip(_("Check the folders you wish to import\nfiles from"));
    
    m_dataviewModel = new FolderModel;
    m_dataviewModel->SetColCount( 2 );
    m_dataview->AssociateModel(m_dataviewModel.get() );
    
    mainSizer->Add(m_dataview, 1, wxALL|wxEXPAND, 5);
    
    m_dataview->AppendToggleColumn(_("?"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_ACTIVATABLE, 20, wxALIGN_LEFT);
    m_dataview->AppendIconTextColumn(_("Folder"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_ACTIVATABLE, 500, wxALIGN_LEFT);
    m_staticText1 = new wxStaticText(this, wxID_ANY, _("Files extension to import (semicolon delimited):"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    mainSizer->Add(m_staticText1, 0, wxALL|wxEXPAND, 5);
    
    m_textCtrSpec = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrSpec->SetHint(wxT(""));
    #endif
    
    mainSizer->Add(m_textCtrSpec, 0, wxALL|wxEXPAND, 5);
    
    m_checkBoxFilesWOExt = new wxCheckBox(this, wxID_ANY, _("Import files without extensions"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxFilesWOExt->SetValue(false);
    m_checkBoxFilesWOExt->SetToolTip(_("If you wish to import files without extensions, tick this option"));
    
    mainSizer->Add(m_checkBoxFilesWOExt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_stdBtnSizer7 = new wxStdDialogButtonSizer();
    
    mainSizer->Add(m_stdBtnSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer7->AddButton(m_buttonOK);
    
    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer7->AddButton(m_buttonCancel);
    m_stdBtnSizer7->Realize();
    
    SetName(wxT("ImportFilesDialogNewBase"));
    SetSizeHints(400,400);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_dirPicker->Connect(wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler(ImportFilesDialogNewBase::OnDirChanged), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_VALUE_CHANGED, wxDataViewEventHandler(ImportFilesDialogNewBase::OnValueChanged), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_EXPANDING, wxDataViewEventHandler(ImportFilesDialogNewBase::OnItemExpanding), NULL, this);
    
}

ImportFilesDialogNewBase::~ImportFilesDialogNewBase()
{
    m_dirPicker->Disconnect(wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler(ImportFilesDialogNewBase::OnDirChanged), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_VALUE_CHANGED, wxDataViewEventHandler(ImportFilesDialogNewBase::OnValueChanged), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_EXPANDING, wxDataViewEventHandler(ImportFilesDialogNewBase::OnItemExpanding), NULL, this);
    
}
