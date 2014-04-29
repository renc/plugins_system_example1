#include "stdafx.h"
#include "PluginManager.h"
#include <iostream>

// Define the prototype for a function that should exist in the DLL
// that is used to create and return the plugin type in the DLL.
typedef Plugin* (*fnCreatePlugin)(void);
// Destroys the plugin type from the DLL before the library is unloaded.
typedef void (*fnDestroyPlugin)(void);
  
PluginManager::PluginManager(void)
{
}
  
PluginManager::~PluginManager(void)
{
}

Plugin* PluginManager::LoadPlugin( const std::wstring& pluginName )
{
    Plugin* plugin = NULL;
    PluginMap::iterator iter = m_Plugins.find( pluginName );
    if ( iter == m_Plugins.end() )
    {
        // Try to load the plugin library
        HMODULE hModule = LoadLibraryW( pluginName.c_str() );
        if ( hModule != NULL )
        {
            fnCreatePlugin CreatePlugin = (fnCreatePlugin)GetProcAddress( hModule, "CreatePlugin" );
            if ( CreatePlugin != NULL )
            {
                // Invoke the function to get the plugin from the DLL.
                plugin = CreatePlugin();
 
                if ( plugin != NULL )
                {
                    plugin->SetName( pluginName );
                    // Add the plugin and library to the maps.
                    m_Plugins.insert( PluginMap::value_type( pluginName, plugin ) );
                    m_Libs.insert( LibraryMap::value_type(pluginName, hModule ) );
                }
                else
                {
                    std::wcerr << "ERROR: Could not load plugin from " << pluginName << std::endl;
                    // Unload the library.
                    FreeLibrary(hModule);
                }
            }
            else
            {
                std::wcerr << "ERROR: Could not find symbol \"CreatePlugin\" in " <<  pluginName << std::endl;
                FreeLibrary(hModule);
            }
        }
        else
        {
            std::wcerr << "ERROR: Could not load library: " << pluginName << std::endl;
        }
    }
    else
    {
        std::wcout << "INFO: Library \"" << pluginName << "\" already loaded." << std::endl;
        plugin = iter->second;
    }
 
    return plugin;
}

void PluginManager::UnloadPlugin( Plugin*& plugin )
{
    if ( plugin != NULL )
    {
        LibraryMap::iterator iter = m_Libs.find( plugin->GetName() );
        if( iter != m_Libs.end() )
        {
            // Remove the plugin from our plugin map.
            m_Plugins.erase(plugin->GetName());
 
            HMODULE hModule = iter->second;
            fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)GetProcAddress( hModule, "DestroyPlugin" );
            if ( DestroyPlugin != NULL )
            {
                DestroyPlugin();
            }
            else
            {
                std::wcerr << "ERROR: Unable to find symbol \"DestroyPlugin\" in library \"" << plugin->GetName() << std::endl;
            }
            // Unload the library and remove the library from the map.
            FreeLibrary(hModule);
            m_Libs.erase(iter);
        }
        else
        {
            std::cout << "WARNING: Trying to unload a plugin that is already unloaded or has never been loaded." << std::endl;
        }
        // NULL the plugin
        plugin = NULL;
    }
}
