#include "AllEles.h"

map<string, Ele> AllEles::allEles;

void AllEles::InitAllEles() {
	allEles["Ele1"] = Ele(110, 45, 80, 60, "Ele1", Elem::Normal);
	allEles["Ele2"] = Ele(110, 45, 80, 60, "Ele2", Elem::Fire);
	allEles["Ele3"] = Ele(110, 65, 80, 60, "Ele3", Elem::Water);
	allEles["Ele4"] = Ele(110, 65, 80, 60, "Ele4", Elem::Grass);
	allEles["Ele5"] = Ele(110, 65, 80, 60, "Ele5", Elem::Normal);
	allEles["Ele6"] = Ele(110, 65, 80, 60, "Ele6", Elem::Fire);
	allEles["Ele7"] = Ele(110, 65, 80, 60, "Ele7", Elem::Water);
	allEles["Ele8"] = Ele(110, 65, 80, 60, "Ele8", Elem::Grass);
}
