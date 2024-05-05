#include "AllWielders.h"

map<string, Wielder> AllWielders::allWielders;

void AllWielders::InitAllWielders() {
	allWielders["wielder1"] = Wielder("wielder1");
}