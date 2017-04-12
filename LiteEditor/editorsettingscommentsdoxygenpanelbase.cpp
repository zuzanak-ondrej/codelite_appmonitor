//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: editor_options_comments_doxygen.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "editorsettingscommentsdoxygenpanelbase.h"


// Declare the bitmap loading function
extern void wxCB83BInitBitmapResources();

static bool bBitmapLoaded = false;


EditorSettingsCommentsDoxygenPanelBase::EditorSettingsCommentsDoxygenPanelBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB83BInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);
    
    wxArrayString m_pgMgrDoxyArr;
    wxUnusedVar(m_pgMgrDoxyArr);
    wxArrayInt m_pgMgrDoxyIntArr;
    wxUnusedVar(m_pgMgrDoxyIntArr);
    m_pgMgrDoxy = new wxPropertyGridManager(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(300,300)), wxPG_DESCRIPTION|wxPG_SPLITTER_AUTO_CENTER|wxPG_BOLD_MODIFIED);
    
    bSizer1->Add(m_pgMgrDoxy, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_pgProp10 = m_pgMgrDoxy->Append(  new wxPropertyCategory( _("General") ) );
    m_pgProp10->SetHelpString(wxT(""));
    
    m_pgPropAutoGen = m_pgMgrDoxy->AppendIn( m_pgProp10,  new wxBoolProperty( _("Generate comment after \"/**\" or \"/*!\""), wxPG_LABEL, 1) );
    m_pgPropAutoGen->SetHelpString(_("When the user hit ENTER after \"/**\" generate the proper documentation block"));
    
    m_pgMgrDoxyArr.Clear();
    m_pgMgrDoxyIntArr.Clear();
    m_pgMgrDoxyArr.Add(_("/**"));
    m_pgMgrDoxyArr.Add(_("/*!"));
    m_pgPropCommentBlockPrefix = m_pgMgrDoxy->AppendIn( m_pgProp10,  new wxEnumProperty( _("Comment block start"), wxPG_LABEL, m_pgMgrDoxyArr, m_pgMgrDoxyIntArr, 0) );
    m_pgPropCommentBlockPrefix->SetHelpString(_("Select the comment block prefix (\"/**\" or \"/*!\")"));
    
    m_pgProp4 = m_pgMgrDoxy->Append(  new wxPropertyCategory( _("Templates") ) );
    m_pgProp4->SetHelpString(wxT(""));
    
    m_pgPropDoxyClassPrefix = m_pgMgrDoxy->AppendIn( m_pgProp4,  new wxStringProperty( _("Class documentation template"), wxPG_LABEL, wxT("")) );
    m_pgPropDoxyClassPrefix->SetHelpString(_("Set the template to use when generating documentation for a class (or C/C++ struct).\nThe following macros are available: $(CurrentFileName), $(CurrentFilePath), $(User), $(Date), $(Name) $(CurrentFileFullPath), $(CurrentFileExt), $(ProjectName), $(WorkspaceName)"));
    m_pgPropDoxyClassPrefix->SetEditor( wxT("TextCtrlAndButton") );
    
    m_pgPropDoxyFunctionPrefix = m_pgMgrDoxy->AppendIn( m_pgProp4,  new wxStringProperty( _("Function documentation template"), wxPG_LABEL, wxT("")) );
    m_pgPropDoxyFunctionPrefix->SetHelpString(_("Set the template to use when generating documentation for a function\nThe following macros are available: $(CurrentFileName), $(CurrentFilePath), $(User), $(Date), $(Name) $(CurrentFileFullPath), $(CurrentFileExt), $(ProjectName), $(WorkspaceName)"));
    m_pgPropDoxyFunctionPrefix->SetEditor( wxT("TextCtrlAndButton") );
    
    SetName(wxT("EditorSettingsCommentsDoxygenPanelBase"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    m_pgMgrDoxy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditorSettingsCommentsDoxygenPanelBase::OnButtonClicked), NULL, this);
    
}

EditorSettingsCommentsDoxygenPanelBase::~EditorSettingsCommentsDoxygenPanelBase()
{
    m_pgMgrDoxy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditorSettingsCommentsDoxygenPanelBase::OnButtonClicked), NULL, this);
    
}
