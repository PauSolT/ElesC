#include "Wielder.h"
#include "Ele.h"

Wielder::Wielder(string name_) {
	name = name_;
}

Ele& Wielder::GetEleInCombat() {
	for (Ele& ele : eles)
	{
		if (ele.State() == Ele::EleState::InCombat) 
		{
			return ele;
		}
	}
}

bool Wielder::HasElesAlive() {
	bool allDead = true;
	for (unsigned int i = 0; i < eles.size(); i++)
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
