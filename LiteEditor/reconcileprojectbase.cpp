//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: reconcileproject.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "reconcileprojectbase.h"


// Declare the bitmap loading function
extern void wxCrafterjdrz3kInitBitmapResources();

static bool bBitmapLoaded = false;


ReconcileProjectDlgBaseClass::ReconcileProjectDlgBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterjdrz3kInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer83 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer83);
    
    m_notebook214 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    m_notebook214->SetName(wxT("m_notebook214"));
    
    boxSizer83->Add(m_notebook214, 1, wxALL|wxEXPAND, 5);
    
    m_panel220 = new wxPanel(m_notebook214, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook214->AddPage(m_panel220, _("New Files"), true);
    
    wxBoxSizer* boxSizer224 = new wxBoxSizer(wxVERTICAL);
    m_panel220->SetSizer(boxSizer224);
    
    m_banner270 = new wxBannerWindow(m_panel220, wxID_ANY, wxTOP, wxDefaultPosition, wxSize(-1,-1), wxBORDER_THEME);
    m_banner270->SetBitmap(wxNullBitmap);
    m_banner270->SetText(_("New Files"), _("Select files from the left pane and add them to the project by clicking on the right arrow button"));
    m_banner270->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    m_banner270->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    
    boxSizer224->Add(m_banner270, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer276 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer224->Add(boxSizer276, 1, wxEXPAND, 5);
    
    m_splitter = new wxSplitterWindow(m_panel220, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxSP_LIVE_UPDATE|wxSP_3DSASH);
    m_splitter->SetSashGravity(0.5);
    m_splitter->SetMinimumPaneSize(10);
    
    boxSizer276->Add(m_splitter, 1, wxALL|wxEXPAND, 5);
    
    m_splitterPage1 = new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer248 = new wxBoxSizer(wxHORIZONTAL);
    m_splitterPage1->SetSizer(boxSizer248);
    
    wxBoxSizer* boxSizer179 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer248->Add(boxSizer179, 1, wxEXPAND, 5);
    
    wxBoxSizer* boxSizer183 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer179->Add(boxSizer183, 1, wxEXPAND, 5);
    
    m_dvListCtrl1Unassigned = new wxDataViewListCtrl(m_splitterPage1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_MULTIPLE);
    m_dvListCtrl1Unassigned->SetToolTip(_("These files have not yet been assigned a Virtual Directory. You can do this yourself by selecting one or more files and clicking the 'Forward' arrow button. A Virtual Directory selector will then appear. After your choice the selection(s) will be moved to the right-hand pane.\nAlternatively click the 'Wizard' button for best-guess auto-allocation."));
    
    boxSizer183->Add(m_dvListCtrl1Unassigned, 1, wxEXPAND, 5);
    
    m_dvListCtrl1Unassigned->AppendIconTextColumn(_("Unassigned files:"), wxDATAVIEW_CELL_INERT, 300, wxALIGN_LEFT);
    wxBoxSizer* boxSizer192 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer183->Add(boxSizer192, 0, wxEXPAND, 5);
    
    wxBoxSizer* boxSizer194 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer248->Add(boxSizer194, 0, wxEXPAND, 5);
    
    boxSizer194->Add(0, 0, 1, wxALL, 5);
    
    m_bmpButtonAdd = new wxBitmapButton(m_splitterPage1, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("forward")), wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
    m_bmpButtonAdd->SetToolTip(_("Add selected files"));
    
    boxSizer194->Add(m_bmpButtonAdd, 0, wxALL|wxEXPAND, 5);
    
    m_bmpButtonRemove = new wxBitmapButton(m_splitterPage1, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("back")), wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
    m_bmpButtonRemove->SetToolTip(_("Remove selected files"));
    
    boxSizer194->Add(m_bmpButtonRemove, 0, wxALL|wxEXPAND, 5);
    
    m_bmpButtonAutoAdd = new wxBitmapButton(m_splitterPage1, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("wand")), wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
    m_bmpButtonAutoAdd->SetToolTip(_("Wherever possible, automatically allocate files to the appropriate virtual directory"));
    
    boxSizer194->Add(m_bmpButtonAutoAdd, 0, wxALL|wxEXPAND, 5);
    
    boxSizer194->Add(0, 0, 1, wxALL, 5);
    
    m_splitterPage2 = new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitter->SplitVertically(m_splitterPage1, m_splitterPage2, 0);
    
    wxBoxSizer* boxSizer250 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage2->SetSizer(boxSizer250);
    
    wxBoxSizer* boxSizer181 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer250->Add(boxSizer181, 1, wxEXPAND, 5);
    
    m_dataviewAssigned = new wxDataViewCtrl(m_splitterPage2, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_MULTIPLE);
    m_dataviewAssigned->SetToolTip(_("Each file here has been assigned a Virtual Directory. If you're happy with the choice, select the file and click 'Apply'. Otherwise select the file and use the 'back' button to return it to the Unassigned Files section."));
    
    m_dataviewAssignedModel = new AssignedFilesModel;
    m_dataviewAssignedModel->SetColCount( 2 );
    m_dataviewAssigned->AssociateModel(m_dataviewAssignedModel.get() );
    
    boxSizer181->Add(m_dataviewAssigned, 1, wxEXPAND, 5);
    
    m_dataviewAssigned->AppendIconTextColumn(_("Assigned files:"), m_dataviewAssigned->GetColumnCount(), wxDATAVIEW_CELL_INERT, 300, wxALIGN_LEFT);
    m_dataviewAssigned->AppendTextColumn(_("Virtual Folder"), m_dataviewAssigned->GetColumnCount(), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    wxBoxSizer* boxSizer278 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer276->Add(boxSizer278, 0, wxEXPAND, 5);
    
    m_button274 = new wxButton(m_panel220, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer278->Add(m_button274, 0, wxALL|wxEXPAND, 5);
    
    m_button280 = new wxButton(m_panel220, wxID_ANY, _("A&pply All"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer278->Add(m_button280, 0, wxALL|wxEXPAND, 5);
    
    m_panel222 = new wxPanel(m_notebook214, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook214->AddPage(m_panel222, _("Stale Files"), false);
    
    wxBoxSizer* boxSizer226 = new wxBoxSizer(wxVERTICAL);
    m_panel222->SetSizer(boxSizer226);
    
    m_banner272 = new wxBannerWindow(m_panel222, wxID_ANY, wxTOP, wxDefaultPosition, wxSize(-1,-1), wxBORDER_THEME);
    m_banner272->SetBitmap(wxNullBitmap);
    m_banner272->SetText(_("Stale Files"), _("The list below contains files that exist in the project but not on the file system"));
    m_banner272->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    m_banner272->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    
    boxSizer226->Add(m_banner272, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer262 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer226->Add(boxSizer262, 1, wxEXPAND, 5);
    
    m_dataviewStaleFiles = new wxDataViewCtrl(m_panel222, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_NO_HEADER|wxDV_ROW_LINES|wxDV_MULTIPLE);
    m_dataviewStaleFiles->SetToolTip(_("The files listed below are contained in the project, but no longer exist in reality. You can select individual items and delete them from the project, or use the Delete All button."));
    
    m_dataviewStaleFilesModel = new StaleFilesModel;
    m_dataviewStaleFilesModel->SetColCount( 1 );
    m_dataviewStaleFiles->AssociateModel(m_dataviewStaleFilesModel.get() );
    
    boxSizer262->Add(m_dataviewStaleFiles, 1, wxALL|wxEXPAND, 5);
    
    m_dataviewStaleFiles->AppendIconTextColumn(_("File path"), m_dataviewStaleFiles->GetColumnCount(), wxDATAVIEW_CELL_INERT, 600, wxALIGN_LEFT);
    wxBoxSizer* boxSizer264 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer262->Add(boxSizer264, 0, wxALL|wxEXPAND, 5);
    
    m_button266 = new wxButton(m_panel222, wxID_DELETE, _("&Delete"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer264->Add(m_button266, 0, wxALL|wxEXPAND, 5);
    
    m_button282 = new wxButton(m_panel222, wxID_ANY, _("Delete &All"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer264->Add(m_button282, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer252 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer83->Add(boxSizer252, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button258 = new wxButton(this, wxID_CLOSE, _("&Close"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button258->SetDefault();
    
    boxSizer252->Add(m_button258, 0, wxALL, 5);
    
    
    #if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_notebook214)){
        wxPersistenceManager::Get().RegisterAndRestore(m_notebook214);
    } else {
        wxPersistenceManager::Get().Restore(m_notebook214);
    }
    #endif
    
    SetName(wxT("ReconcileProjectDlgBaseClass"));
    SetSizeHints(-1,-1);
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
    m_bmpButtonAdd->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnAddFile), NULL, this);
    m_bmpButtonAdd->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnAddFileUI), NULL, this);
    m_bmpButtonRemove->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnUndoSelectedFiles), NULL, this);
    m_bmpButtonRemove->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnUndoSelectedFilesUI), NULL, this);
    m_bmpButtonAutoAdd->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnAutoSuggest), NULL, this);
    m_bmpButtonAutoAdd->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnAutoAssignUI), NULL, this);
    m_button274->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnApply), NULL, this);
    m_button274->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnApplyUI), NULL, this);
    m_button280->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnApply), NULL, this);
    m_button280->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnApplyAllUI), NULL, this);
    m_button266->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnDeleteStaleFiles), NULL, this);
    m_button266->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnDeleteStaleFilesUI), NULL, this);
    m_button282->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnDeleteStaleFiles), NULL, this);
    m_button282->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnDeleteAllStaleFilesUI), NULL, this);
    m_button258->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnClose), NULL, this);
    
}

ReconcileProjectDlgBaseClass::~ReconcileProjectDlgBaseClass()
{
    m_bmpButtonAdd->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnAddFile), NULL, this);
    m_bmpButtonAdd->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnAddFileUI), NULL, this);
    m_bmpButtonRemove->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnUndoSelectedFiles), NULL, this);
    m_bmpButtonRemove->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnUndoSelectedFilesUI), NULL, this);
    m_bmpButtonAutoAdd->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnAutoSuggest), NULL, this);
    m_bmpButtonAutoAdd->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnAutoAssignUI), NULL, this);
    m_button274->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnApply), NULL, this);
    m_button274->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnApplyUI), NULL, this);
    m_button280->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnApply), NULL, this);
    m_button280->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnApplyAllUI), NULL, this);
    m_button266->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnDeleteStaleFiles), NULL, this);
    m_button266->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnDeleteStaleFilesUI), NULL, this);
    m_button282->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnDeleteStaleFiles), NULL, this);
    m_button282->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectDlgBaseClass::OnDeleteAllStaleFilesUI), NULL, this);
    m_button258->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectDlgBaseClass::OnClose), NULL, this);
    
}

ReconcileProjectFiletypesDlgBaseClass::ReconcileProjectFiletypesDlgBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterjdrz3kInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer114 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer114);
    
    wxBoxSizer* boxSizer160 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer114->Add(boxSizer160, 0, wxALL|wxEXPAND, 5);
    
    m_staticText116 = new wxStaticText(this, wxID_ANY, _("Look for files starting with this directory:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer160->Add(m_staticText116, 0, wxALL, 5);
    
    m_dirPickerToplevel = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxSize(-1,-1), wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL|wxDIRP_DIR_MUST_EXIST);
    
    boxSizer160->Add(m_dirPickerToplevel, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer16016 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer114->Add(boxSizer16016, 0, wxALL|wxEXPAND, 5);
    
    m_staticText11617 = new wxStaticText(this, wxID_ANY, _("Extensions to consider when looking for missing files:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer16016->Add(m_staticText11617, 0, wxALL, 5);
    
    m_textExtensions = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textExtensions->SetToolTip(_("A semi-colon separated list of extensions e.g. cpp;h;xrc\nIf you really want to find all possible files, just add *"));
    #if wxVERSION_NUMBER >= 3000
    m_textExtensions->SetHint(wxT(""));
    #endif
    
    boxSizer16016->Add(m_textExtensions, 0, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer11517115 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer11517115->SetFlexibleDirection( wxBOTH );
    flexGridSizer11517115->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer11517115->AddGrowableCol(0);
    flexGridSizer11517115->AddGrowableRow(1);
    
    boxSizer114->Add(flexGridSizer11517115, 1, wxALL|wxEXPAND, 5);
    
    m_staticText11618216 = new wxStaticText(this, wxID_ANY, _("Files to ignore:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer11517115->Add(m_staticText11618216, 0, wxALL, 5);
    
    flexGridSizer11517115->Add(0, 0, 0, wxALL, 5);
    
    wxArrayString m_listIgnoreFilesArr;
    m_listIgnoreFiles = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_listIgnoreFilesArr, wxLB_SINGLE);
    m_listIgnoreFiles->SetToolTip(_("Here you can add the names of any files that you want to ignore. Standard wildcards will work e.g. moc_*"));
    
    flexGridSizer11517115->Add(m_listIgnoreFiles, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer124519 = new wxBoxSizer(wxVERTICAL);
    
    flexGridSizer11517115->Add(boxSizer124519, 1, wxRIGHT|wxBOTTOM|wxEXPAND, 5);
    
    m_button11921620 = new wxButton(this, wxID_ANY, _("Add"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer124519->Add(m_button11921620, 0, wxALL|wxEXPAND, 5);
    
    m_button125721 = new wxButton(this, wxID_ANY, _("Remove"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer124519->Add(m_button125721, 0, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer11517 = new wxFlexGridSizer(2, 2, 0, 0);
    flexGridSizer11517->SetFlexibleDirection( wxBOTH );
    flexGridSizer11517->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer11517->AddGrowableCol(0);
    flexGridSizer11517->AddGrowableRow(1);
    
    boxSizer114->Add(flexGridSizer11517, 1, wxALL|wxEXPAND, 5);
    
    m_staticText11618 = new wxStaticText(this, wxID_ANY, _("Paths to ignore:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer11517->Add(m_staticText11618, 0, wxALL, 5);
    
    flexGridSizer11517->Add(0, 0, 0, wxALL, 5);
    
    wxArrayString m_listExcludeArr;
    m_listExclude = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_listExcludeArr, wxLB_SINGLE);
    m_listExclude->SetToolTip(_("The filepaths of any folders that shouldn't be searched for missing files"));
    
    flexGridSizer11517->Add(m_listExclude, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer124 = new wxBoxSizer(wxVERTICAL);
    
    flexGridSizer11517->Add(boxSizer124, 1, wxRIGHT|wxBOTTOM|wxEXPAND, 5);
    
    m_button11921 = new wxButton(this, wxID_ANY, _("Add"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer124->Add(m_button11921, 0, wxALL|wxEXPAND, 5);
    
    m_button125 = new wxButton(this, wxID_ANY, _("Remove"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer124->Add(m_button125, 0, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer115171 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer115171->SetFlexibleDirection( wxBOTH );
    flexGridSizer115171->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer115171->AddGrowableCol(0);
    flexGridSizer115171->AddGrowableRow(1);
    
    boxSizer114->Add(flexGridSizer115171, 1, wxALL|wxEXPAND, 5);
    
    m_staticText116182 = new wxStaticText(this, wxID_ANY, _("Regexs to use (optional):"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer115171->Add(m_staticText116182, 0, wxALL, 5);
    
    flexGridSizer115171->Add(0, 0, 0, wxALL, 5);
    
    m_listCtrlRegexes = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLC_SINGLE_SEL|wxLC_REPORT);
    m_listCtrlRegexes->SetToolTip(_("Most of the time you should find that files automatically get added to the most appropriate virtual directory. If yours don't, here you can add one or more regular expressions suitable for your situation. They'll be remembered for this project."));
    
    flexGridSizer115171->Add(m_listCtrlRegexes, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer1245 = new wxBoxSizer(wxVERTICAL);
    
    flexGridSizer115171->Add(boxSizer1245, 1, wxRIGHT|wxBOTTOM|wxEXPAND, 5);
    
    m_button119216 = new wxButton(this, wxID_ANY, _("Add"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer1245->Add(m_button119216, 0, wxALL|wxEXPAND, 5);
    
    m_button1257 = new wxButton(this, wxID_ANY, _("Remove"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer1245->Add(m_button1257, 0, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer120 = new wxStdDialogButtonSizer();
    
    boxSizer114->Add(m_stdBtnSizer120, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button121 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer120->AddButton(m_button121);
    
    m_button122 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button122->SetDefault();
    m_stdBtnSizer120->AddButton(m_button122);
    m_stdBtnSizer120->Realize();
    
    SetName(wxT("ReconcileProjectFiletypesDlgBaseClass"));
    SetSizeHints(-1,-1);
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
    m_button11921620->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreFileBrowse), NULL, this);
    m_button125721->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreFileRemove), NULL, this);
    m_button125721->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreFileRemoveUpdateUI), NULL, this);
    m_button11921->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreBrowse), NULL, this);
    m_button125->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreRemove), NULL, this);
    m_button125->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreRemoveUpdateUI), NULL, this);
    m_button119216->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnAddRegex), NULL, this);
    m_button1257->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnRemoveRegex), NULL, this);
    m_button1257->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnRemoveRegexUpdateUI), NULL, this);
    
}

ReconcileProjectFiletypesDlgBaseClass::~ReconcileProjectFiletypesDlgBaseClass()
{
    m_button11921620->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreFileBrowse), NULL, this);
    m_button125721->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreFileRemove), NULL, this);
    m_button125721->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreFileRemoveUpdateUI), NULL, this);
    m_button11921->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreBrowse), NULL, this);
    m_button125->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreRemove), NULL, this);
    m_button125->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnIgnoreRemoveUpdateUI), NULL, this);
    m_button119216->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnAddRegex), NULL, this);
    m_button1257->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnRemoveRegex), NULL, this);
    m_button1257->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileProjectFiletypesDlgBaseClass::OnRemoveRegexUpdateUI), NULL, this);
    
}

ReconcileByRegexDlgBaseClass::ReconcileByRegexDlgBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterjdrz3kInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer141 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer141);
    
    wxFlexGridSizer* flexGridSizer157 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer157->SetFlexibleDirection( wxBOTH );
    flexGridSizer157->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer157->AddGrowableCol(0);
    
    boxSizer141->Add(flexGridSizer157, 1, wxALL|wxEXPAND, 5);
    
    m_staticText145 = new wxStaticText(this, wxID_ANY, _("Enter the regex:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer157->Add(m_staticText145, 0, wxLEFT|wxRIGHT|wxTOP, 5);
    
    flexGridSizer157->Add(0, 0, 0, wxALL, 5);
    
    m_textCtrlRegex = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_PROCESS_ENTER);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlRegex->SetHint(wxT(""));
    #endif
    
    flexGridSizer157->Add(m_textCtrlRegex, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    flexGridSizer157->Add(0, 0, 0, wxALL, 5);
    
    m_staticText147 = new wxStaticText(this, wxID_ANY, _("Destination Virtual Directory:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer157->Add(m_staticText147, 0, wxLEFT|wxRIGHT|wxTOP, 10);
    
    flexGridSizer157->Add(0, 0, 0, wxALL, 5);
    
    m_textCtrlVirtualFolder = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_PROCESS_ENTER);
    m_textCtrlVirtualFolder->SetToolTip(_("Select the virtual folder in which to place the matching files"));
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlVirtualFolder->SetHint(wxT(""));
    #endif
    
    flexGridSizer157->Add(m_textCtrlVirtualFolder, 1, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_bmpButton21010 = new wxBitmapButton(this, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("wxdirpickerctrl")), wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW|wxBORDER_NONE);
    m_bmpButton21010->SetToolTip(_("Browse for virtual folder"));
    
    flexGridSizer157->Add(m_bmpButton21010, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    flexGridSizer157->Add(0, 0, 0, wxALL, 5);
    
    wxBoxSizer* boxSizer2088 = new wxBoxSizer(wxHORIZONTAL);
    
    flexGridSizer157->Add(boxSizer2088, 0, wxRIGHT|wxBOTTOM|wxEXPAND, 5);
    
    m_stdBtnSizer12011 = new wxStdDialogButtonSizer();
    
    boxSizer141->Add(m_stdBtnSizer12011, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button12112 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer12011->AddButton(m_button12112);
    
    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer12011->AddButton(m_buttonOK);
    m_stdBtnSizer12011->Realize();
    
    SetName(wxT("ReconcileByRegexDlgBaseClass"));
    SetSizeHints(-1,-1);
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
    m_textCtrlRegex->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(ReconcileByRegexDlgBaseClass::OnTextEnter), NULL, this);
    m_textCtrlVirtualFolder->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(ReconcileByRegexDlgBaseClass::OnTextEnter), NULL, this);
    m_bmpButton21010->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileByRegexDlgBaseClass::OnVDBrowse), NULL, this);
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileByRegexDlgBaseClass::OnRegexOKCancelUpdateUI), NULL, this);
    
}

ReconcileByRegexDlgBaseClass::~ReconcileByRegexDlgBaseClass()
{
    m_textCtrlRegex->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(ReconcileByRegexDlgBaseClass::OnTextEnter), NULL, this);
    m_textCtrlVirtualFolder->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(ReconcileByRegexDlgBaseClass::OnTextEnter), NULL, this);
    m_bmpButton21010->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReconcileByRegexDlgBaseClass::OnVDBrowse), NULL, this);
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ReconcileByRegexDlgBaseClass::OnRegexOKCancelUpdateUI), NULL, this);
    
}
