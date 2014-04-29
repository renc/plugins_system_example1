#pragma once

#include <string>
#include <xstring>
#include <map>
#include "CommonDLL.h"
#include "Plugin.h"

class COMMONDLL_API PluginManager
{
public:
	PluginManager(void);
	~PluginManager(void);

	static PluginManager& Instance() { static PluginManager pm; return pm; }

	Plugin *LoadPlugin( const std::wstring &plugName );
	void UnloadPlugin( Plugin *&plugin );

private:
	typedef std::map<std::wstring, Plugin *> PluginMap;
	typedef std::map<std::wstring, HMODULE > LibraryMap;

	PluginMap m_Plugins;
	LibraryMap m_Libs; 
};

