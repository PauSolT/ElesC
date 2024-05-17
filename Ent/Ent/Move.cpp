#include "Move.h"
#include "Ele.h"
#include "utils.h"
#include <iostream>

Move::Move(int potency_, int accuracy_, int uses_, string name_, MoveType type_, Elem element_, string description_, bool affectsEveryone_) {
	potency = potency_;
	accuracy = accuracy_;
	maxUses = uses_;
	uses = uses_;
	name = name_;
	type = type_;
	description = description_;
	element = element_;
	affectsEveryone = affectsEveryone_;
}

void Move::Log() {
	PrintText("Name: " + Name() + "\n"
		+ "Potency: " + to_string(Potency()) + "\n"
		+ "Accuracy: " + to_string(Accuracy()) + "\n"
		+ "Uses: " + to_string(Uses()) + "/" + to_string(MaxUses()));
}

bool Move::UseMovement(Ele &user, Ele &target)
{
	PrintText(user.Name() + " uses " + Name() + "!");
	uses--;
	bool moveHits = true;
	if (RandomNumber(1, 100) > accuracy)
	{
		moveHits = false;
		PrintText("But misses the target!");
	}
	else {
		switch (type)
		{
		case MoveType::Offensive:
		default:
			UseOffensiveMovement(user, target);
			break;
		case MoveType::Defensive:
			UseDefensiveMovement(user);
			break;
		}
	}

	return moveHits;
}

void Move::UseOffensiveMovement(Ele& user, Ele& target)
{
	target.TakeDamage(CalculateDamage(user, target, *this));
}

void Move::UseDefensiveMovement(Ele& user, bool affectsEveryone)
{
	if (!affectsEveryone)
	{
		user.Heal(potency);
	}
	else {
		for (Ele ele : player.Eles())
		{
			ele.Heal(potency);
		}
	}
}

