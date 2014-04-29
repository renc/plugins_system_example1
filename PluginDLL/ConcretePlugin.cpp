#include "stdafx.h"
#include "ConcretePlugin.h"
#include <iostream>

ConcretePlugin::ConcretePlugin(void)
{
	std::cout << "ConcretePlugin constructor.\n"; 
}


ConcretePlugin::~ConcretePlugin(void)
{
	std::cout << "ConcretePlugin destructor.\n"; 
}
