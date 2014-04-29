// ApplicationTest.cpp : Defines the entry point for the console application.
//

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
 
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
 
#include "PluginManager.h"
 #include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// load a dynamic plugin

	Plugin *plugin = PluginManager::Instance().LoadPlugin( L"PluginDLL.dll" );
	if (plugin)
	{
		PluginManager::Instance().UnloadPlugin(plugin); 
	}

	system("PAUSE");

	return 0;
}

