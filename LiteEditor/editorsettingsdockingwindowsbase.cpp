//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: editor_options_docking_windows.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "editorsettingsdockingwindowsbase.h"


// Declare the bitmap loading function
extern void wxCrafterKZwxilInitBitmapResources();

static bool bBitmapLoaded = false;


EditorSettingsDockingWindowsBase::EditorSettingsDockingWindowsBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterKZwxilInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_notebook10 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxBK_DEFAULT);
    m_notebook10->SetName(wxT("m_notebook10"));
    
    mainSizer->Add(m_notebook10, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    m_panel12 = new wxPanel(m_notebook10, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook10, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_notebook10->AddPage(m_panel12, _("Docking"), true);
    
    wxBoxSizer* boxSizer22 = new wxBoxSizer(wxVERTICAL);
    m_panel12->SetSizer(boxSizer22);
    
    wxBoxSizer* bSizer2 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer22->Add(bSizer2, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxArrayString m_radioBoxHintArr;
    m_radioBoxHintArr.Add(_("Transparent hint"));
    m_radioBoxHintArr.Add(_("Rectangle hint"));
    m_radioBoxHintArr.Add(_("Venetian blinds hints"));
    m_radioBoxHint = new wxRadioBox(m_panel12, wxID_ANY, _("Docking Style:"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1, -1)), m_radioBoxHintArr, 1, wxRA_SPECIFY_COLS);
    m_radioBoxHint->SetSelection(0);
    
    bSizer2->Add(m_radioBoxHint, 1, wxLEFT|wxRIGHT|wxTOP|wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer32 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer22->Add(boxSizer32, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, WXC_FROM_DIP(5));
    
    wxStaticBoxSizer* staticBoxSizer27 = new wxStaticBoxSizer( new wxStaticBox(m_panel12, wxID_ANY, _("Tabs")), wxVERTICAL);
    
    boxSizer32->Add(staticBoxSizer27, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxFlexGridSizer* flexGridSizer36 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer36->SetFlexibleDirection( wxBOTH );
    flexGridSizer36->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer36->AddGrowableCol(1);
    
    staticBoxSizer27->Add(flexGridSizer36, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticText46 = new wxStaticText(m_panel12, wxID_ANY, _("Tab Style:"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    
    flexGridSizer36->Add(m_staticText46, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_choiceTabStyleArr;
    m_choiceTabStyleArr.Add(wxT("DEFAULT"));
    m_choiceTabStyleArr.Add(wxT("MINIMAL"));
    m_choiceTabStyleArr.Add(wxT("TRAPEZOID"));
    m_choiceTabStyle = new wxChoice(m_panel12, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), m_choiceTabStyleArr, 0);
    m_choiceTabStyle->SetSelection(0);
    
    flexGridSizer36->Add(m_choiceTabStyle, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticTextTabHeight = new wxStaticText(m_panel12, wxID_ANY, _("Tab Height:"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    
    flexGridSizer36->Add(m_staticTextTabHeight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_choiceTabHeightArr;
    m_choiceTabHeightArr.Add(wxT("TALL"));
    m_choiceTabHeightArr.Add(wxT("MEDIUM"));
    m_choiceTabHeightArr.Add(wxT("SHORT"));
    m_choiceTabHeightArr.Add(wxT("TINY"));
    m_choiceTabHeight = new wxChoice(m_panel12, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), m_choiceTabHeightArr, 0);
    m_choiceTabHeight->SetSelection(3);
    
    flexGridSizer36->Add(m_choiceTabHeight, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_staticText38 = new wxStaticText(m_panel12, wxID_ANY, _("Workspace Pane Tabs Orientation:"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    
    flexGridSizer36->Add(m_staticText38, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_choiceWorkspaceTabsOrientationArr;
    m_choiceWorkspaceTabsOrientationArr.Add(wxT("LEFT"));
    m_choiceWorkspaceTabsOrientationArr.Add(wxT("RIGHT"));
    m_choiceWorkspaceTabsOrientationArr.Add(wxT("TOP"));
    m_choiceWorkspaceTabsOrientationArr.Add(wxT("BOTTOM"));
    m_choiceWorkspaceTabsOrientation = new wxChoice(m_panel12, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), m_choiceWorkspaceTabsOrientationArr, 0);
    m_choiceWorkspaceTabsOrientation->SetSelection(0);
    
    flexGridSizer36->Add(m_choiceWorkspaceTabsOrientation, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_staticText42 = new wxStaticText(m_panel12, wxID_ANY, _("Output Pane Tabs Orientation:"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    
    flexGridSizer36->Add(m_staticText42, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    wxArrayString m_choiceOutputTabsOrientationArr;
    m_choiceOutputTabsOrientationArr.Add(wxT("TOP"));
    m_choiceOutputTabsOrientationArr.Add(wxT("BOTTOM"));
    m_choiceOutputTabsOrientation = new wxChoice(m_panel12, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), m_choiceOutputTabsOrientationArr, 0);
    m_choiceOutputTabsOrientation->SetSelection(0);
    
    flexGridSizer36->Add(m_choiceOutputTabsOrientation, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_checkBoxShowXButton = new wxCheckBox(m_panel12, wxID_ANY, _("Show close button on active tab"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    m_checkBoxShowXButton->SetValue(true);
    m_checkBoxShowXButton->SetToolTip(_("Show close button on active tab"));
    
    staticBoxSizer27->Add(m_checkBoxShowXButton, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxEditorTabsFollowsTheme = new wxCheckBox(m_panel12, wxID_ANY, _("The editor tabs matches to the editor colour theme"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    m_checkBoxEditorTabsFollowsTheme->SetValue(true);
    m_checkBoxEditorTabsFollowsTheme->SetToolTip(_("The editor tabs matches to the editor colour theme"));
    
    staticBoxSizer27->Add(m_checkBoxEditorTabsFollowsTheme, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxUseDarkTabTheme = new wxCheckBox(m_panel12, wxID_ANY, _("Use dark notebook tab theme by default"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    m_checkBoxUseDarkTabTheme->SetValue(false);
    
    staticBoxSizer27->Add(m_checkBoxUseDarkTabTheme, 0, wxALL, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer25 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer22->Add(boxSizer25, 0, wxALL, WXC_FROM_DIP(10));
    
    m_checkBoxHideCaptions = new wxCheckBox(m_panel12, wxID_ANY, _("Hide Docking Windows captions"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    m_checkBoxHideCaptions->SetValue(false);
    
    boxSizer25->Add(m_checkBoxHideCaptions, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxEnsureCaptionsVisible = new wxCheckBox(m_panel12, wxID_ANY, _("Ensure captions are visible on mouse hover"), wxDefaultPosition, wxDLG_UNIT(m_panel12, wxSize(-1,-1)), 0);
    m_checkBoxEnsureCaptionsVisible->SetValue(false);
    m_checkBoxEnsureCaptionsVisible->SetToolTip(_("When the option 'Hide Docking Windows captions' is enabled, ensure captions are visible on mouse hover. This is useful so the user can still move around the docking  windows"));
    
    boxSizer25->Add(m_checkBoxEnsureCaptionsVisible, 0, wxALL, WXC_FROM_DIP(5));
    
    m_panel14 = new wxPanel(m_notebook10, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook10, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_notebook10->AddPage(m_panel14, _("Find / Find In Files"), false);
    
    wxBoxSizer* boxSizer20 = new wxBoxSizer(wxVERTICAL);
    m_panel14->SetSizer(boxSizer20);
    
    m_checkBoxFindBarAtBottom = new wxCheckBox(m_panel14, wxID_ANY, _("Place the Find bar at the bottom"), wxDefaultPosition, wxDLG_UNIT(m_panel14, wxSize(-1, -1)), 0);
    m_checkBoxFindBarAtBottom->SetValue(true);
    
    boxSizer20->Add(m_checkBoxFindBarAtBottom, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_checkBoxDontFoldSearchResults = new wxCheckBox(m_panel14, wxID_ANY, _("Don't automatically fold Search results"), wxDefaultPosition, wxDLG_UNIT(m_panel14, wxSize(-1, -1)), 0);
    m_checkBoxDontFoldSearchResults->SetValue(false);
    m_checkBoxDontFoldSearchResults->SetToolTip(_("By default, all but the first results of 'Search' are automatically folded; you have to click on each subsequent file to see its contained matches. Tick this box to prevent this.\nYou can still fold and unfold results with the button in the output pane toolbar."));
    
    boxSizer20->Add(m_checkBoxDontFoldSearchResults, 0, wxALL, WXC_FROM_DIP(5));
    
    m_panel16 = new wxPanel(m_notebook10, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook10, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_notebook10->AddPage(m_panel16, _("Debug / Output panes"), false);
    
    wxBoxSizer* boxSizer21 = new wxBoxSizer(wxVERTICAL);
    m_panel16->SetSizer(boxSizer21);
    
    wxBoxSizer* boxSizer19 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer21->Add(boxSizer19, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneOnClick = new wxCheckBox(m_panel16, wxID_ANY, _("When user clicks inside an editor, hide the output pane -- unless it's one of:"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneOnClick->SetValue(true);
    m_checkBoxHideOutputPaneOnClick->SetToolTip(_("When e.g. you compile your project, or use 'Find in Files', the Output Pane opens to show the results. If this box is ticked, it will automatically close as soon as you click in the editor."));
    
    boxSizer19->Add(m_checkBoxHideOutputPaneOnClick, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxFlexGridSizer* fgSizer1 = new wxFlexGridSizer(0, 4, 0, 0);
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    boxSizer19->Add(fgSizer1, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT, WXC_FROM_DIP(20));
    
    m_checkBoxHideOutputPaneNotIfBuild = new wxCheckBox(m_panel16, wxID_ANY, _("Build"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfBuild->SetValue(false);
    m_checkBoxHideOutputPaneNotIfBuild->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing e.g. you may not want it to close while you correct one of many build errors."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfBuild, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfSearch = new wxCheckBox(m_panel16, wxID_ANY, _("Search"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfSearch->SetValue(false);
    m_checkBoxHideOutputPaneNotIfSearch->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfSearch, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfReplace = new wxCheckBox(m_panel16, wxID_ANY, _("Replace"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfReplace->SetValue(false);
    m_checkBoxHideOutputPaneNotIfReplace->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfReplace, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfReferences = new wxCheckBox(m_panel16, wxID_ANY, _("References"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfReferences->SetValue(false);
    m_checkBoxHideOutputPaneNotIfReferences->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfReferences, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfOutput = new wxCheckBox(m_panel16, wxID_ANY, _("Output"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfOutput->SetValue(false);
    m_checkBoxHideOutputPaneNotIfOutput->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfOutput, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfTrace = new wxCheckBox(m_panel16, wxID_ANY, _("Trace"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfTrace->SetValue(false);
    m_checkBoxHideOutputPaneNotIfTrace->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfTrace, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfTasks = new wxCheckBox(m_panel16, wxID_ANY, _("Tasks"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfTasks->SetValue(false);
    m_checkBoxHideOutputPaneNotIfTasks->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfTasks, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfBuildQ = new wxCheckBox(m_panel16, wxID_ANY, _("BuildQ"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfBuildQ->SetValue(false);
    m_checkBoxHideOutputPaneNotIfBuildQ->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfBuildQ, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfCppCheck = new wxCheckBox(m_panel16, wxID_ANY, _("CppCheck"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfCppCheck->SetValue(false);
    m_checkBoxHideOutputPaneNotIfCppCheck->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfCppCheck, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfSvn = new wxCheckBox(m_panel16, wxID_ANY, _("Subversion"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfSvn->SetValue(false);
    m_checkBoxHideOutputPaneNotIfSvn->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfSvn, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfCscope = new wxCheckBox(m_panel16, wxID_ANY, _("CScope"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfCscope->SetValue(false);
    m_checkBoxHideOutputPaneNotIfCscope->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfCscope, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfGit = new wxCheckBox(m_panel16, wxID_ANY, _("Git"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfGit->SetValue(false);
    m_checkBoxHideOutputPaneNotIfGit->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfGit, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfDebug = new wxCheckBox(m_panel16, wxID_ANY, _("Debug"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfDebug->SetValue(true);
    m_checkBoxHideOutputPaneNotIfDebug->SetToolTip(_("Don't automatically close the Debugger Pane on an editor click if this tab is showing. You probably don't want it to close whenever you set a breakpoint, for example."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfDebug, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxHideOutputPaneNotIfMemCheck = new wxCheckBox(m_panel16, wxID_ANY, _("MemCheck"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxHideOutputPaneNotIfMemCheck->SetValue(true);
    m_checkBoxHideOutputPaneNotIfMemCheck->SetToolTip(_("Don't automatically close the Output Pane on an editor click if this tab is showing."));
    
    fgSizer1->Add(m_checkBoxHideOutputPaneNotIfMemCheck, 0, wxALL, WXC_FROM_DIP(5));
    
    m_checkBoxShowDebugOnRun = new wxCheckBox(m_panel16, wxID_ANY, _("Show 'Debug' tab on starting the debugger"), wxDefaultPosition, wxDLG_UNIT(m_panel16, wxSize(-1, -1)), 0);
    m_checkBoxShowDebugOnRun->SetValue(true);
    m_checkBoxShowDebugOnRun->SetToolTip(_("When starting the debugger, if the Debug tab is not visible, checking this will make it visible"));
    
    boxSizer21->Add(m_checkBoxShowDebugOnRun, 0, wxALL, WXC_FROM_DIP(5));
    
    SetName(wxT("EditorSettingsDockingWindowsBase"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    m_checkBoxEnsureCaptionsVisible->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnEnsureCaptionsVisibleUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfBuild->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfSearch->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfReplace->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfReferences->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfOutput->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfTrace->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfTasks->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfBuildQ->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfCppCheck->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfSvn->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfCscope->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfGit->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfDebug->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfMemCheck->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    
}

EditorSettingsDockingWindowsBase::~EditorSettingsDockingWindowsBase()
{
    m_checkBoxEnsureCaptionsVisible->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnEnsureCaptionsVisibleUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfBuild->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfSearch->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfReplace->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfReferences->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfOutput->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfTrace->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfTasks->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfBuildQ->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfCppCheck->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfSvn->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfCscope->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfGit->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfDebug->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    m_checkBoxHideOutputPaneNotIfMemCheck->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditorSettingsDockingWindowsBase::OnHideOutputPaneNotIfDebugUI), NULL, this);
    
}