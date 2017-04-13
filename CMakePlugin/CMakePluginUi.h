//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: CMakePlugin.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CODELITE_CMAKEPLUGIN_CMAKEPLUGIN_BASE_CLASSES_H
#define CODELITE_CMAKEPLUGIN_CMAKEPLUGIN_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/gauge.h>
#include <wx/srchctrl.h>
#include <wx/listbox.h>
#include <wx/imaglist.h>
#include <wx/bitmap.h>
#include <map>
#include <wx/icon.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class CMakeSettingsDialogBase : public wxDialog
{
protected:
    wxStaticText* m_staticTextProgram;
    wxFilePickerCtrl* m_filePickerProgram;
    wxStaticText* m_staticTextDefaultGenerator;
    wxChoice* m_choiceDefaultGenerator;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:

public:
    wxStaticText* GetStaticTextProgram() { return m_staticTextProgram; }
    wxFilePickerCtrl* GetFilePickerProgram() { return m_filePickerProgram; }
    wxStaticText* GetStaticTextDefaultGenerator() { return m_staticTextDefaultGenerator; }
    wxChoice* GetChoiceDefaultGenerator() { return m_choiceDefaultGenerator; }
    CMakeSettingsDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CMakePlugin Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CMakeSettingsDialogBase();
};


class CMakeHelpTabBase : public wxPanel
{
protected:
    wxStaticText* m_staticTextVersion;
    wxStaticText* m_staticTextVersionValue;
    wxStaticText* m_staticText222;
    wxChoice* m_choiceTopics;
    wxButton* m_buttonReload;
    wxGauge* m_gaugeLoad;
    wxSearchCtrl* m_searchCtrlFilter;
    wxListBox* m_listBoxList;

protected:
    virtual void OnUpdateUi(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnChangeTopic(wxCommandEvent& event) { event.Skip(); }
    virtual void OnReload(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSearch(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSearchCancel(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSelect(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInsert(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticTextVersion() { return m_staticTextVersion; }
    wxStaticText* GetStaticTextVersionValue() { return m_staticTextVersionValue; }
    wxStaticText* GetStaticText222() { return m_staticText222; }
    wxChoice* GetChoiceTopics() { return m_choiceTopics; }
    wxButton* GetButtonReload() { return m_buttonReload; }
    wxGauge* GetGaugeLoad() { return m_gaugeLoad; }
    wxSearchCtrl* GetSearchCtrlFilter() { return m_searchCtrlFilter; }
    wxListBox* GetListBoxList() { return m_listBoxList; }
    CMakeHelpTabBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~CMakeHelpTabBase();
};


class cmakeImages : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;


protected:

public:
    cmakeImages();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name) )
            return wxNullBitmap;
        return m_bitmaps.find(name)->second;
    }
    virtual ~cmakeImages();
};

#endif
