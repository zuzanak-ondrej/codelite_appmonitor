//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: TailUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "TailUI.h"


// Declare the bitmap loading function
extern void wxCB60EInitBitmapResources();

static bool bBitmapLoaded = false;


TailPanelBase::TailPanelBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB60EInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);
    
    wxBoxSizer* boxSizer43 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer2->Add(boxSizer43, 0, wxEXPAND, WXC_FROM_DIP(5));
    
    m_auibar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibar->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer43->Add(m_auibar, 0, wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_auibar->AddTool(ID_TAIL_OPEN, _("Open file"), wxXmlResource::Get()->LoadBitmap(wxT("16-folder")), wxNullBitmap, wxITEM_NORMAL, _("Open file"), wxT(""), NULL);
    wxAuiToolBarItem* m_toolbarItemOpen = m_auibar->FindToolByIndex(m_auibar->GetToolCount()-1);
    if (m_toolbarItemOpen) {
        m_toolbarItemOpen->SetHasDropDown(true);
    }
    
    m_auibar->AddTool(ID_TAIL_CLOSE, _("Close"), wxXmlResource::Get()->LoadBitmap(wxT("16-file_close")), wxNullBitmap, wxITEM_NORMAL, _("Close"), wxT(""), NULL);
    
    m_auibar->AddTool(ID_TAIL_CLEAR, _("Clear"), wxXmlResource::Get()->LoadBitmap(wxT("16-clear")), wxNullBitmap, wxITEM_NORMAL, _("Clear"), wxT(""), NULL);
    
    m_auibar->AddSeparator();
    
    m_auibar->AddTool(ID_TAIL_PAUSE, _("Pause"), wxXmlResource::Get()->LoadBitmap(wxT("16-interrupt")), wxNullBitmap, wxITEM_NORMAL, _("Pause"), wxT(""), NULL);
    
    m_auibar->AddTool(ID_TAIL_PLAY, _("Play"), wxXmlResource::Get()->LoadBitmap(wxT("16-debugger_start")), wxNullBitmap, wxITEM_NORMAL, _("Play"), wxT(""), NULL);
    
    m_auibar->AddSeparator();
    
    m_auibar->AddTool(ID_TAIL_DETACH, _("Open in a separate window"), wxXmlResource::Get()->LoadBitmap(wxT("16-windows")), wxNullBitmap, wxITEM_NORMAL, _("Open in a separate window"), _("Open in a separate window"), NULL);
    m_auibar->Realize();
    
    boxSizer43->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));
    
    m_staticTextFileName = new wxStaticText(this, wxID_ANY, _("<No opened file>"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    
    boxSizer43->Add(m_staticTextFileName, 0, wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    boxSizer43->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));
    
    m_stc = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
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
    m_stc->SetMarginWidth(2, 0);
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
    
    boxSizer2->Add(m_stc, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    SetName(wxT("TailPanelBase"));
    SetSize(500,300);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    this->Connect(ID_TAIL_OPEN, wxEVT_COMMAND_AUITOOLBAR_TOOL_DROPDOWN, wxAuiToolBarEventHandler(TailPanelBase::OnOpen), NULL, this);
    this->Connect(ID_TAIL_CLOSE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnClose), NULL, this);
    this->Connect(ID_TAIL_CLOSE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnCloseUI), NULL, this);
    this->Connect(ID_TAIL_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnClear), NULL, this);
    this->Connect(ID_TAIL_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnClearUI), NULL, this);
    this->Connect(ID_TAIL_PAUSE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnPause), NULL, this);
    this->Connect(ID_TAIL_PAUSE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnPauseUI), NULL, this);
    this->Connect(ID_TAIL_PLAY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnPlay), NULL, this);
    this->Connect(ID_TAIL_PLAY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnPlayUI), NULL, this);
    this->Connect(ID_TAIL_DETACH, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnDetachWindow), NULL, this);
    this->Connect(ID_TAIL_DETACH, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnDetachWindowUI), NULL, this);
    
    this->Connect(wxID_ANY, wxEVT_COMMAND_AUITOOLBAR_TOOL_DROPDOWN, wxAuiToolBarEventHandler(TailPanelBase::ShowAuiToolMenu), NULL, this);
}

TailPanelBase::~TailPanelBase()
{
    this->Disconnect(ID_TAIL_OPEN, wxEVT_COMMAND_AUITOOLBAR_TOOL_DROPDOWN, wxAuiToolBarEventHandler(TailPanelBase::OnOpen), NULL, this);
    this->Disconnect(ID_TAIL_CLOSE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnClose), NULL, this);
    this->Disconnect(ID_TAIL_CLOSE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnCloseUI), NULL, this);
    this->Disconnect(ID_TAIL_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnClear), NULL, this);
    this->Disconnect(ID_TAIL_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnClearUI), NULL, this);
    this->Disconnect(ID_TAIL_PAUSE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnPause), NULL, this);
    this->Disconnect(ID_TAIL_PAUSE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnPauseUI), NULL, this);
    this->Disconnect(ID_TAIL_PLAY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnPlay), NULL, this);
    this->Disconnect(ID_TAIL_PLAY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnPlayUI), NULL, this);
    this->Disconnect(ID_TAIL_DETACH, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(TailPanelBase::OnDetachWindow), NULL, this);
    this->Disconnect(ID_TAIL_DETACH, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TailPanelBase::OnDetachWindowUI), NULL, this);
    
    std::map<int, wxMenu*>::iterator menuIter = m_dropdownMenus.begin();
    for( ; menuIter != m_dropdownMenus.end(); ++menuIter ) {
        wxDELETE( menuIter->second );
    }
    m_dropdownMenus.clear();

    this->Disconnect(wxID_ANY, wxEVT_COMMAND_AUITOOLBAR_TOOL_DROPDOWN, wxAuiToolBarEventHandler(TailPanelBase::ShowAuiToolMenu), NULL, this);
}


void TailPanelBase::ShowAuiToolMenu(wxAuiToolBarEvent& event)
{
    event.Skip();
    if (event.IsDropDownClicked()) {
        wxAuiToolBar* toolbar = wxDynamicCast(event.GetEventObject(), wxAuiToolBar);
        if (toolbar) {
            wxAuiToolBarItem* item = toolbar->FindTool(event.GetId());
            if (item) {
                std::map<int, wxMenu*>::iterator iter = m_dropdownMenus.find(item->GetId());
                if (iter != m_dropdownMenus.end()) {
                    event.Skip(false);
                    wxPoint pt = event.GetItemRect().GetBottomLeft();
                    pt.y++;
                    toolbar->PopupMenu(iter->second, pt);
                }
            }
        }
    }
}
TailFrameBase::TailFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB60EInitBitmapResources();
        bBitmapLoaded = true;
    }
    // Set icon(s) to the application/dialog
    wxIconBundle app_icons;
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("16-find"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("16-find@2x"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    SetIcons( app_icons );

    
    wxBoxSizer* boxSizer37 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer37);
    
    SetName(wxT("TailFrameBase"));
    SetSize(500,300);
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
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(TailFrameBase::OnClose), NULL, this);
    
}

TailFrameBase::~TailFrameBase()
{
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(TailFrameBase::OnClose), NULL, this);
    
}
