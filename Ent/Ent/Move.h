#pragma once
#include <string>

using namespace std;

class Ele;

class Move
{
public:
	enum class MoveType
	{
		Offensive,
		Buff,
		Debuff,
		Defensive,
		Mixed
	};

private:
	int potency = 0;
	int accuracy = 0;
	int maxUses = 0;
	int uses = 0;
	int stat = -1;
	string name = " ";
	string description = " ";
	MoveType type = MoveType::Offensive;

	void UseOffensiveMovement(Ele& user, Ele& target);
	void UseBuffMovement(Ele& user, int stages, int stat);
	void UseDebuffMovement(Ele& target, int stages, int stat);
	void UseDefensiveMovement(Ele& user);
	void UseMixedMovement(Ele& user, Ele& target, int stages, int stat);

public:
	Move() {}
	Move(int potency_, int accuracy_, int uses_, string name_, MoveType type_, string description_ = " ", int stat_ = -1);
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
	string& Description() { return description; }
	const string& Description() const { return description; }

	bool UseMovement(Ele &user, Ele &target);

	
	void Log();

};

