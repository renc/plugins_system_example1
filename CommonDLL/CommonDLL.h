#pragma once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMONDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMMONDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMMONDLL_EXPORTS
#define COMMONDLL_API __declspec(dllexport)
#else
#define COMMONDLL_API __declspec(dllimport)
#endif

// This class is exported from the CommonDLL.dll
class COMMONDLL_API CCommonDLL {
public:
	CCommonDLL(void);
	// TODO: add your methods here.
};

extern COMMONDLL_API int nCommonDLL;

COMMONDLL_API int fnCommonDLL(void);
