//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: qmaketabbase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "qmaketabbase.h"


// Declare the bitmap loading function
extern void wxCraftergbQa9FInitBitmapResources();

static bool bBitmapLoaded = false;


QMakeTabBase::QMakeTabBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCraftergbQa9FInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_checkBoxUseQmake = new wxCheckBox(this, wxID_ANY, _("This project uses qmake"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxUseQmake->SetValue(false);
    
    mainSizer->Add(m_checkBoxUseQmake, 0, wxALL, 5);
    
    wxFlexGridSizer* fgSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer1->AddGrowableCol(1);
    
    mainSizer->Add(fgSizer1, 0, wxALL|wxEXPAND, 5);
    
    m_staticText3 = new wxStaticText(this, wxID_ANY, _("qmake settings:"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText3->SetToolTip(_("Select the QMake to be used for this build configuration as defined in 'Plugins -> QMake -> Settings'"));
    
    fgSizer1->Add(m_staticText3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxArrayString m_choiceQmakeSettingsArr;
    m_choiceQmakeSettings = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_choiceQmakeSettingsArr, 0);
    m_choiceQmakeSettings->SetToolTip(_("Select the QMake to be used for this build configuration as defined in 'Plugins -> QMake -> Settings'"));
    
    fgSizer1->Add(m_choiceQmakeSettings, 0, wxALL|wxEXPAND, 5);
    
    m_staticText4 = new wxStaticText(this, wxID_ANY, _("qmake execution line:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    fgSizer1->Add(m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlQmakeExeLine = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlQmakeExeLine->SetHint(wxT(""));
    #endif
    
    fgSizer1->Add(m_textCtrlQmakeExeLine, 0, wxALL|wxEXPAND, 5);
    
    m_staticText5 = new wxStaticText(this, wxID_ANY, _("CodeLite will place the below text after the auto generated section (so you may override the generated variables)"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    mainSizer->Add(m_staticText5, 0, wxALL|wxEXPAND, 5);
    
    m_textCtrlFreeText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), wxTE_RICH2|wxTE_PROCESS_TAB|wxTE_MULTILINE|wxTE_DONTWRAP);
    wxFont m_textCtrlFreeTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans"));
    m_textCtrlFreeText->SetFont(m_textCtrlFreeTextFont);
    
    mainSizer->Add(m_textCtrlFreeText, 1, wxALL|wxEXPAND, 5);
    
    SetName(wxT("QMakeTabBase"));
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
    // Connect events
    m_staticText3->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_choiceQmakeSettings->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_staticText4->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_textCtrlQmakeExeLine->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_staticText5->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_textCtrlFreeText->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    
}

QMakeTabBase::~QMakeTabBase()
{
    m_staticText3->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_choiceQmakeSettings->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_staticText4->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_textCtrlQmakeExeLine->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_staticText5->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    m_textCtrlFreeText->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(QMakeTabBase::OnUseQmake), NULL, this);
    
}
