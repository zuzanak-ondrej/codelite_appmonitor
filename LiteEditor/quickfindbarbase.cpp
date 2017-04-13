//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: quickfindbarbase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "quickfindbarbase.h"


// Declare the bitmap loading function
extern void wxCrafteryhjh4ZInitBitmapResources();

static bool bBitmapLoaded = false;


QuickFindBarBase::QuickFindBarBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafteryhjh4ZInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainSizer);
    
    SetName(wxT("QuickFindBarBase"));
    SetSizeHints(400,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
}

QuickFindBarBase::~QuickFindBarBase()
{
}

QuickFindBarOptionsMenuBase::QuickFindBarOptionsMenuBase(wxWindow* parent,long style)
    : wxPopupTransientWindow(parent, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafteryhjh4ZInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer60 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer60);
    
    m_panel71 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    
    boxSizer60->Add(m_panel71, 1, wxEXPAND, 5);
    
    wxGridSizer* gridSizer49 = new wxGridSizer(0, 2, 0, 0);
    m_panel71->SetSizer(gridSizer49);
    
    m_checkBoxCase = new wxCheckBox(m_panel71, wxID_ANY, _("Case Sensitive"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxCase->SetValue(false);
    m_checkBoxCase->SetToolTip(_("Use case sensitive match"));
    
    gridSizer49->Add(m_checkBoxCase, 0, wxALL|wxALIGN_LEFT, 3);
    
    m_checkBoxRegex = new wxCheckBox(m_panel71, wxID_ANY, _("Regular Expression"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxRegex->SetValue(false);
    m_checkBoxRegex->SetToolTip(_("Use regular expression"));
    
    gridSizer49->Add(m_checkBoxRegex, 0, wxALL|wxALIGN_LEFT, 3);
    
    m_checkBoxWord = new wxCheckBox(m_panel71, wxID_ANY, _("Match a whole word"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxWord->SetValue(false);
    m_checkBoxWord->SetToolTip(_("Match a whole word only"));
    
    gridSizer49->Add(m_checkBoxWord, 0, wxALL|wxALIGN_LEFT, 3);
    
    m_checkBoxWildcard = new wxCheckBox(m_panel71, wxID_ANY, _("Use wildcard syntax"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxWildcard->SetValue(false);
    m_checkBoxWildcard->SetToolTip(_("Use wildcard syntax (* and ?)"));
    
    gridSizer49->Add(m_checkBoxWildcard, 0, wxALL|wxALIGN_LEFT, 3);
    
    m_checkBoxMultipleSelections = new wxCheckBox(m_panel71, wxID_ANY, _("Enable multiple selections"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBoxMultipleSelections->SetValue(false);
    m_checkBoxMultipleSelections->SetToolTip(_("Select each match without de-selectiing the previous match"));
    
    gridSizer49->Add(m_checkBoxMultipleSelections, 0, wxALL|wxALIGN_LEFT, 3);
    
    SetName(wxT("QuickFindBarOptionsMenuBase"));
    SetSizeHints(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    m_checkBoxRegex->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(QuickFindBarOptionsMenuBase::OnCheckBoxRegex), NULL, this);
    m_checkBoxWildcard->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(QuickFindBarOptionsMenuBase::OnCheckWild), NULL, this);
    
}

QuickFindBarOptionsMenuBase::~QuickFindBarOptionsMenuBase()
{
    m_checkBoxRegex->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(QuickFindBarOptionsMenuBase::OnCheckBoxRegex), NULL, this);
    m_checkBoxWildcard->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(QuickFindBarOptionsMenuBase::OnCheckWild), NULL, this);
    
}

QuickFindBarImages::QuickFindBarImages()
    : wxImageList(16, 16, true)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafteryhjh4ZInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("m_bmpMenu"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("m_bmpMenu"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("marker-16"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("marker-16"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("case-sensitive"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("case-sensitive"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("word"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("word"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("regex"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("regex"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("replace-controls"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("replace-controls"), bmp ) );
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("find-bar-close-16"));
        icn.CopyFromBitmap( bmp );
        this->Add( icn );
        m_bitmaps.insert( std::make_pair(wxT("find-bar-close-16"), bmp ) );
    }
    
}

QuickFindBarImages::~QuickFindBarImages()
{
}
