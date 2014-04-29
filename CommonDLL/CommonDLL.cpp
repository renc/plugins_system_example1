// CommonDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CommonDLL.h"


// This is an example of an exported variable
COMMONDLL_API int nCommonDLL=0;

// This is an example of an exported function.
COMMONDLL_API int fnCommonDLL(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see CommonDLL.h for the class definition
CCommonDLL::CCommonDLL()
{
	return;
}
