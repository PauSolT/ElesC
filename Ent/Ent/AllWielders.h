#pragma once
#include "Wielder.h"
#include <map>

class AllWielders
{
public:
	static map<string, Wielder> allWielders;

	static void InitAllWielders();

};

