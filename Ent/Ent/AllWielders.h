#pragma once
#include "Wielder.h"
#include <map>

static class AllWielders
{
public:
	static map<string, Wielder> allWielders;

	static void InitAllWielders();

};

