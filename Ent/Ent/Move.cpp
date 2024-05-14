#include "Move.h"
#include "Ele.h"
#include "utils.h"
#include <iostream>

Move::Move(int potency_, int accuracy_, int uses_, string name_, MoveType type_, string description_, int stat_) {
	potency = potency_;
	accuracy = accuracy_;
	maxUses = uses_;
	uses = uses_;
	name = name_;
	type = type_;
	description = description_;

	if (stat != -1) {
		stat = stat_;
	}
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
		case MoveType::Buff:
			UseBuffMovement(user, 0, 0);
			break;
		case MoveType::Debuff:
			UseDebuffMovement(target, 0, 0);
			break;
		case MoveType::Defensive:
			UseDefensiveMovement(user);
			break;
		case MoveType::Mixed:
			UseMixedMovement(user, target, 0, 0);
			break;
		}
	}

	return moveHits;
}

void Move::UseOffensiveMovement(Ele& user, Ele& target)
{
	target.TakeDamage(CalculateDamage(user, target, *this));
}

void Move::UseBuffMovement(Ele& user, int stages, int stat)
{
	user.ChangeStat(stages, stat);
}

void Move::UseDebuffMovement(Ele& target, int stages, int stat)
{
	target.ChangeStat(stages, stat);
}

void Move::UseDefensiveMovement(Ele& user)
{
}

void Move::UseMixedMovement(Ele& user, Ele& target, int stages, int stat)
{
}
