#include "Wielder.h"
#include "Ele.h"

Ele Wielder::GetEleInCombat() {
	Ele eleInCombat;
	for (Ele ele : eles)
	{
		if (ele.State() == Ele::EleState::InCombat) 
		{
			eleInCombat = ele;
		}
	}
	return eleInCombat;
}

bool Wielder::HasElesAlive() {
	bool allDead = true;
	for (int i = 0; i < eles.size(); i++)
	{
		if (eles[i].State() == Ele::EleState::InCombat ||
			eles[i].State() == Ele::EleState::InParty)
		{
			allDead = false;
		}
	}
	return allDead;
}

void Wielder::SelectEle() {

}
