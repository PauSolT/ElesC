#include <iostream>
#include "Ele.h"
#include <iomanip>
#include "utils.h"

Ele::Ele(int health_, int attack_, int defense_, int speed_, string name_, int maxHealth_) {
	maxHealth = maxHealth_;
	if (maxHealth_ == -1.f)
	{
		maxHealth = health_;
	}
	health = health_;
	attack = attack_;
	defense = defense_;
	speed = speed_;
	name = name_;
}

void Ele::Log() {
	 PrintText("Name: " + Name() + "\n" 
		+ "HP: " + to_string(Health()) + "/" + to_string(MaxHealth()) + "\n"
		+ "Defense: " + to_string(Defense()) + "\n"
		+ "Speed: " + to_string(Speed()) + "\n"
		+ StateToString());
}

int Ele::TakeDamage(int damage) {
	int initialHealth = Health();
	Health() -= damage;
	if (Health() < 0)
	{
		Health() = 0;
	}

	int effectiveDamage = initialHealth - Health();
	PrintText(Name() + " took " + to_string(effectiveDamage) + " damage!");
	PrintText(Name() + " is at " + to_string((Health() * 100 / MaxHealth())) + "% HP!");
	if (Health() <= 0)
	{
		Die();
	}

	return effectiveDamage;
}

void Ele::Die()
{
	PrintText(Name() + " died!");
	State() = Ele::EleState::Dead;
}


void Ele::ChangeStat(int stages, int stat)
{
	int& statToChange = (stat == 1) ? defenseModifier : 
		(stat == 2) ? speedModifier : attackModifier;

	if (statToChange >= maxModifier) {
		PrintText("Attack can't be higher!");
	}
	else if (statToChange <= -maxModifier) {
		PrintText("Attack can't be lower!");
	}
	else {
		statToChange += stages;
		if (statToChange > maxModifier) {
			statToChange = maxModifier;
		}
		else if (statToChange < -maxModifier) {
			statToChange = -maxModifier;
		}
	}
}

string Ele::StateToString() {
	string stateToString;
	switch (state)
	{
	case Ele::EleState::InCombat:
		stateToString = "In Combat";
		break;
	default:
	case Ele::EleState::InParty:
		stateToString = "In Party";
		break;
	case Ele::EleState::Dead:
		stateToString = "Dead";
		break;
	}

	return stateToString;
}
