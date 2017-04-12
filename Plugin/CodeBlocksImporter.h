//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Copyright            : (C) 2015 Eran Ifrah
// File name            : CodeBlocksImporter.h
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

#ifndef CODEBLOCKSIMPORTER_H
#define CODEBLOCKSIMPORTER_H

#include <wx/filename.h>
#include <wx/string.h>
#include "GenericImporter.h"

class CodeBlocksImporter : public GenericImporter
{
public:
    virtual bool OpenWordspace(const wxString& filename, const wxString& defaultCompiler);
    virtual bool isSupportedWorkspace();
    virtual GenericWorkspacePtr PerformImport();

private:
    void GenerateFromWorkspace(GenericWorkspacePtr genericWorkspace);
    void GenerateFromProject(GenericWorkspacePtr genericWorkspace, GenericProjectDataType& genericProjectData);

    wxFileName wsInfo;
    wxString extension;
};

#endif // CODEBLOCKSIMPORTER_H
