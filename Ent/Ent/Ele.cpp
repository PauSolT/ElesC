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
		+ "Speed: " + to_string(Speed()) + "\n");
}

int Ele::TakeDamage(int damage) {
	int initialHealth = Health();
	Health() -= damage;
	if (Health() < 0)
	{
		Health() = 0;
	}

	int effectiveDamage = initialHealth - Health();
	PrintText(Name() + " took " + to_string(effectiveDamage) + " damage!" + "\n");
	PrintText(Name() + " is at " + to_string((Health() * 100 / MaxHealth())) + "% HP!" + "\n");
	if (Health() < 0)
	{
		PrintText(Name() + " died!" + "\n");
	}

	return effectiveDamage;
}