#pragma once
#include <xstring>
#include "CommonDLL.h"

class COMMONDLL_API Plugin
{
public:
	Plugin(void);
	virtual ~Plugin(void);

	void SetName( const std::wstring &name ) { m_Name = name; };
	std::wstring GetName() const { return m_Name; }

private:
	std::wstring m_Name; 
};

