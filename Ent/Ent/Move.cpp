#include "Move.h"
#include "Ele.h"
#include "utils.h"
#include <iostream>

Move::Move(int potency_, int accuracy_, int uses_, string name_, string description_) {
	potency = potency_;
	accuracy = accuracy_;
	maxUses = uses_;
	uses = uses_;
	name = name_;
	description = description_;
}

void Move::Log() {
	PrintText("Name: " + Name() + "\n"
		+ "Potency: " + to_string(Potency()) + "\n"
		+ "Accuracy: " + to_string(Accuracy()) + "\n"
		+ "Uses: " + to_string(Uses()) + "/" + to_string(MaxUses()) + "\n");
}

bool Move::UseMovement(Ele &user, Ele &target)
{
	PrintText(user.Name() + " uses " + Name() + "!" + "\n");
	bool moveHits = true;
	if (RandomNumber(1, 100) > accuracy)
	{
		moveHits = false;
		PrintText("But misses the target!\n");
	}
	else {
		target.TakeDamage(CalculateDamage(user, target, *this));
	}

	return moveHits;
}
