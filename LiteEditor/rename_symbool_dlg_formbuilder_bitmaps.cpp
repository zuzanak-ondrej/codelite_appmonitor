//
// This file was automatically generated by wxrc, do not edit by hand.
//

#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include <wx/filesys.h>
#include <wx/fs_mem.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_all.h>

#if wxCHECK_VERSION(2,8,5) && wxABI_VERSION >= 20805
    #define XRC_ADD_FILE(name, data, size, mime) \
        wxMemoryFSHandler::AddFileWithMimeType(name, data, size, mime)
#else
    #define XRC_ADD_FILE(name, data, size, mime) \
        wxMemoryFSHandler::AddFile(name, data, size)
#endif

static size_t xml_res_size_0 = 90;
static unsigned char xml_res_file_0[] = {
60,63,120,109,108,32,118,101,114,115,105,111,110,61,34,49,46,48,34,32,101,
110,99,111,100,105,110,103,61,34,85,84,70,45,56,34,63,62,10,60,114,101,
115,111,117,114,99,101,32,120,109,108,110,115,61,34,104,116,116,112,58,
47,47,119,119,119,46,119,120,119,105,100,103,101,116,115,46,111,114,103,
47,119,120,120,114,99,34,47,62,10};

void wxCF5E0InitBitmapResources()
{

    // Check for memory FS. If not present, load the handler:
    {
        wxMemoryFSHandler::AddFile(wxT("XRC_resource/dummy_file"), wxT("dummy one"));
        wxFileSystem fsys;
        wxFSFile *f = fsys.OpenFile(wxT("memory:XRC_resource/dummy_file"));
        wxMemoryFSHandler::RemoveFile(wxT("XRC_resource/dummy_file"));
        if (f) delete f;
        else wxFileSystem::AddHandler(new wxMemoryFSHandlerBase);
    }

    XRC_ADD_FILE(wxT("XRC_resource/rename_symbool_dlg_formbuilder_bitmaps.cpp$_mnt_SanDisk128-common_david_devel_git_CL_formbuilder_rename_symbool_dlg_formbuilder_bitmaps.xrc"), xml_res_file_0, xml_res_size_0, wxT("text/xml"));
    wxXmlResource::Get()->Load(wxT("memory:XRC_resource/rename_symbool_dlg_formbuilder_bitmaps.cpp$_mnt_SanDisk128-common_david_devel_git_CL_formbuilder_rename_symbool_dlg_formbuilder_bitmaps.xrc"));
}
