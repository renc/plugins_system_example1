// PluginDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PluginDLL.h"
#include "ConcretePlugin.h"
#include <assert.h>

// This is an example of an exported variable
PLUGINDLL_API int nPluginDLL=0;

// This is an example of an exported function.
PLUGINDLL_API int fnPluginDLL(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see PluginDLL.h for the class definition
CPluginDLL::CPluginDLL()
{
	return;
}

ConcretePlugin* g_ConcretePlugin = NULL;
 
extern "C" PLUGINDLL_API Plugin* CreatePlugin(void)
{
    assert(g_ConcretePlugin == NULL);
    g_ConcretePlugin = new ConcretePlugin();
    return g_ConcretePlugin;
}
 
extern "C" PLUGINDLL_API void DestroyPlugin(void)
{
    assert(g_ConcretePlugin);
    delete g_ConcretePlugin;
    g_ConcretePlugin = NULL;
}