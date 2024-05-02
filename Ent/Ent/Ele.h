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
	int maxHealth;
	int health;
	int attack;
	int defense;
	int speed;
	int level;
	string name;
	vector<Move> moves;
	EleState state = EleState::InParty;
	

public:
	Ele();
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
	string& Name() { return name; }
	const string& Name() const { return name; }
	vector<Move>& Moves() { return moves; }
	const vector<Move>& Moves() const{ return moves; }
	EleState& State() { return state; }
	const EleState& State() const { return state; }

	int TakeDamage(int damage);
	void Log();
};

