#include "PHPEntityFunctionAlias.h"
#include "file_logger.h"

PHPEntityFunctionAlias::PHPEntityFunctionAlias() {}

PHPEntityFunctionAlias::~PHPEntityFunctionAlias() {}

bool PHPEntityFunctionAlias::Is(eEntityType type) const { return type == kEntityTypeFunctionAlias; }

void PHPEntityFunctionAlias::FromResultSet(wxSQLite3ResultSet& res)
{
    SetDbId(res.GetInt("ID"));
    SetShortName(res.GetString("NAME"));
    SetRealname(res.GetString("REALNAME"));
    SetLine(res.GetInt("LINE_NUMBER"));
    SetFilename(res.GetString("FILE_NAME"));
    SetFullName(res.GetString("FULLNAME"));
    SetScope(res.GetString("SCOPE"));
}

void PHPEntityFunctionAlias::Store(wxSQLite3Database& db)
{
    try {
        wxSQLite3Statement statement = db.PrepareStatement(
            "INSERT OR REPLACE INTO FUNCTION_ALIAS_TABLE VALUES(NULL, :SCOPE_ID, :NAME, :REALNAME, :FULLNAME, :SCOPE, "
            ":LINE_NUMBER, :FILE_NAME)");
        statement.Bind(statement.GetParamIndex(":SCOPE_ID"), Parent()->GetDbId());
        statement.Bind(statement.GetParamIndex(":NAME"), GetShortName());
        statement.Bind(statement.GetParamIndex(":REALNAME"), GetRealname());
        statement.Bind(statement.GetParamIndex(":FULLNAME"), GetFullName());
        statement.Bind(statement.GetParamIndex(":SCOPE"), GetScope());
        statement.Bind(statement.GetParamIndex(":LINE_NUMBER"), GetLine());
        statement.Bind(statement.GetParamIndex(":FILE_NAME"), GetFilename().GetFullPath());
        statement.ExecuteUpdate();
        SetDbId(db.GetLastRowId());

    } catch(wxSQLite3Exception& exc) {
        CL_WARNING("PHPEntityFunctionAlias::Store: %s", exc.GetMessage());
    }
}

wxString PHPEntityFunctionAlias::FormatPhpDoc(const CommentConfigData& data) const
{
    if(m_func) {
        return m_func->FormatPhpDoc(data);
    }
    return "";
}

wxString PHPEntityFunctionAlias::GetDisplayName() const { return GetShortName(); }

void PHPEntityFunctionAlias::PrintStdout(int indent) const { wxUnusedVar(indent); }

wxString PHPEntityFunctionAlias::Type() const
{
    if(m_func) {
        return m_func->Type();
    }
    return "";
}
