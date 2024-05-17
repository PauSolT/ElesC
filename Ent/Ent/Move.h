#pragma once
#include <string>
#include "Constants.h"

using namespace std;

class Ele;

class Move
{
public:
	enum class MoveType
	{
		Offensive,
		Defensive,
	};

private:
	int potency = 0;
	int accuracy = 0;
	int maxUses = 0;
	int uses = 0;
	int stat = -1;
	bool affectsEveryone = false;
	string name = " ";
	string description = " ";
	MoveType type = MoveType::Offensive;
	Elem element = Elem::Normal;


	void UseOffensiveMovement(Ele& user, Ele& target);
	void UseDefensiveMovement(Ele& user,  bool affectsEveryone = false);

public:
	Move() {}
	Move(int potency_, int accuracy_, int uses_, string name_, MoveType type_, Elem element_, string description_ = " ", bool affectsEveryone_ = false);
	int& Potency() { return potency; }
	const int& Potency() const { return potency; }
	int& Accuracy() { return accuracy; }
	const int& Accuracy() const { return accuracy; }
	int& MaxUses() { return maxUses; }
	const int& MaxUses() const { return maxUses; }
	int& Uses() { return uses; }
	const int& Uses() const { return uses; }
	string& Name() { return name; }
	const string& Name() const { return name; }
	MoveType& Type() { return type; }
	const MoveType& Type() const { return type; }
	Elem& Element() { return element; }
	const Elem& Element() const { return element; }
	string& Description() { return description; }
	const string& Description() const { return description; }

	bool UseMovement(Ele &user, Ele &target);

	
	void Log();

};

