#pragma once
#include <string>
#include <vector>
#include "Move.h"
using namespace std;

class Ele
{
public:
	enum class EleState
	{
		InCombat,
		InParty,
		Dead
	};

private:
	int maxHealth = 0;
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	int level = 1;

	int attackModifier = 0;
	int defenseModifier = 0;
	int speedModifier = 0;
	int maxModifier = 5;

	string name = " ";
	vector<Move> moves;
	EleState state = EleState::InParty;
	

public:
	Ele() {}
	Ele(int health_, int attack_, int defense_, int speed_, string name_, int maxHealth_ = -1.f);
	int &Health() { return health; }
	const int &Health() const { return health; }
	int& MaxHealth() { return maxHealth; }
	const int& MaxHealth() const { return maxHealth; }
	int& Attack() { return attack; }
	const int& Attack() const { return attack; }
	int& Defense() { return defense; }
	const int& Defense() const { return defense; }
	int& Speed() { return speed; }
	const int& Speed() const { return speed; }
	int& Level() { return level; }
	const int& Level() const { return level; }
	int& AttackModifier() { return attackModifier; }
	const int& AttackModifier() const { return attackModifier; }
	int& DefenseModifier() { return defenseModifier; }
	const int& DefenseModifier() const { return defenseModifier; }
	int& SpeedModifier() { return speedModifier; }
	const int& SpeedModifier() const { return speedModifier; }
	string& Name() { return name; }
	const string& Name() const { return name; }
	vector<Move>& Moves() { return moves; }
	const vector<Move>& Moves() const{ return moves; }
	EleState& State() { return state; }
	const EleState& State() const { return state; }

	int TakeDamage(int damage);
	void Die();
	void ChangeStat(int stages, int stat);
	void Log();

	string StateToString();

};

