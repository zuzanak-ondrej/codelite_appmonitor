#include "PHPEntityKeyword.h"

PHPEntityKeyword::PHPEntityKeyword() {}

PHPEntityKeyword::~PHPEntityKeyword() {}

wxString PHPEntityKeyword::FormatPhpDoc(const CommentConfigData& data) const { return ""; }
void PHPEntityKeyword::FromResultSet(wxSQLite3ResultSet& res) {}
wxString PHPEntityKeyword::GetDisplayName() const { return m_shortName; }
bool PHPEntityKeyword::Is(eEntityType type) const { return type == kEntityTypeKeyword; }
void PHPEntityKeyword::PrintStdout(int indent) const { wxUnusedVar(indent); }
void PHPEntityKeyword::Store(wxSQLite3Database& db) { wxUnusedVar(db); }
wxString PHPEntityKeyword::Type() const { return ""; }
