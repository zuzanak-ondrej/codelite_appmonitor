#include "php_configuration_data.h"
#include "php_utils.h"
#include <wx/ffile.h>
#include <wx/stdpaths.h>
#include "php_utils.h"
#include <cl_config.h>
#include "PHPSetterGetterEntry.h"

PHPConfigurationData::PHPConfigurationData()
    : clConfigItem("PHPConfigurationData")
    , m_errorReporting(wxT("E_ALL & ~E_NOTICE"))
    , m_xdebugPort(9000)
    , m_flags(kRunLintOnFileSave)
    , m_xdebugIdeKey("codeliteide")
    , m_xdebugHost("127.0.0.1")
    , m_findInFilesMask(
          "*.php;*.inc;*.phtml;*.js;*.html;*.css;*.scss;*.json;*.xml;*.ini;*.md;*.txt;*.text;.htaccess;*.sql")
    , m_workspaceType(0)
    , m_settersGettersFlags(kSG_None)
{
}

PHPConfigurationData::~PHPConfigurationData() {}

void PHPConfigurationData::FromJSON(const JSONElement& json)
{
    m_includePaths = json.namedObject("m_includePaths").toArrayString();
    m_findInFilesMask = json.namedObject("m_findInFilesMask").toString(m_findInFilesMask);

    m_phpExe = json.namedObject("m_phpExe").toString("php");
    m_errorReporting = json.namedObject("m_errorReporting").toString(m_errorReporting);
    m_xdebugPort = json.namedObject("m_xdebugPort").toInt(m_xdebugPort);
    m_xdebugHost = json.namedObject("m_xdebugHost").toString(m_xdebugHost);
    m_flags = json.namedObject("m_flags").toSize_t(m_flags);
    m_settersGettersFlags = json.namedObject("m_settersGettersFlags").toSize_t(m_settersGettersFlags);
    m_xdebugIdeKey = json.namedObject("m_xdebugIdeKey").toString(m_xdebugIdeKey);
    m_workspaceType = json.namedObject("m_workspaceType").toInt(m_workspaceType);
    m_xdebugIdeKey.Trim().Trim(false);

    // xdebug IDE can not be an empty string, or else debugging in command line
    // will not work
    if(m_xdebugIdeKey.IsEmpty()) {
        m_xdebugIdeKey = "codeliteide";
    }
    m_ccIncludePath = json.namedObject("m_ccIncludePath").toArrayString();
}

JSONElement PHPConfigurationData::ToJSON() const
{
    JSONElement e = JSONElement::createObject(GetName());
    e.addProperty("m_includePaths", m_includePaths);
    e.addProperty("m_phpExe", m_phpExe);
    e.addProperty("m_errorReporting", m_errorReporting);
    e.addProperty("m_xdebugPort", m_xdebugPort);
    e.addProperty("m_xdebugHost", m_xdebugHost);
    e.addProperty("m_ccIncludePath", m_ccIncludePath);
    e.addProperty("m_flags", m_flags);
    e.addProperty("m_xdebugIdeKey", m_xdebugIdeKey);
    e.addProperty("m_findInFilesMask", m_findInFilesMask);
    e.addProperty("m_workspaceType", m_workspaceType);
    e.addProperty("m_settersGettersFlags", m_settersGettersFlags);
    return e;
}

wxString PHPConfigurationData::GetIncludePathsAsString() const
{
    wxString str;
    for(size_t i = 0; i < m_includePaths.GetCount(); i++) {
        str << m_includePaths.Item(i) << wxT("\n");
    }
    if(str.IsEmpty() == false) {
        str.RemoveLast();
    }
    return str;
}

wxString PHPConfigurationData::GetCCIncludePathsAsString() const
{
    wxString str;
    for(size_t i = 0; i < m_ccIncludePath.GetCount(); i++) {
        str << m_ccIncludePath.Item(i) << wxT("\n");
    }
    if(str.IsEmpty() == false) {
        str.RemoveLast();
    }
    return str;
}

PHPConfigurationData& PHPConfigurationData::Load()
{
    clConfig conf("php.conf");
    conf.ReadItem(this);
    return *this;
}

void PHPConfigurationData::Save()
{
    clConfig conf("php.conf");
    conf.WriteItem(this);
}