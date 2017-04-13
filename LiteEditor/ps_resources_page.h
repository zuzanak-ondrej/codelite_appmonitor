//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : ps_resources_page.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifndef __ps_resources_page__
#define __ps_resources_page__

/**
@file
Subclass of PSResourcesPageBase, which is generated by wxFormBuilder.
*/

#include "project_settings_base_dlg.h"
#include "project_settings_dlg.h"

//// end generated include

/** Implementing PSResourcesPageBase */
class PSResourcesPage : public PSResourcesPageBase, public IProjectSettingsPage
{
    ProjectSettingsDlg *m_dlg;

protected:
    virtual void OnProjectEnabledUI(wxUpdateUIEvent& event);
    virtual void OnResourcesEnabledUI(wxUpdateUIEvent& event);
    virtual void OnCustomEditorClicked(wxCommandEvent& event);
    virtual void OnValueChanged(wxPropertyGridEvent& event);

public:
    /** Constructor */
    PSResourcesPage( wxWindow* parent, ProjectSettingsDlg *dlg );
    //// end generated class members

    virtual void Load(BuildConfigPtr buildConf);
    virtual void Save(BuildConfigPtr buildConf, ProjectSettingsPtr projSettingsPtr);
    virtual void Clear();

};

#endif // __ps_resources_page__
