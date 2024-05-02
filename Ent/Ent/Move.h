#pragma once
#include <string>

using namespace std;

class Ele;

class Move
{
private:
	int potency = 0;
	int accuracy = 0;
	int maxUses = 0;
	int uses = 0;
	string name = " ";
	string description = " ";

public:
	Move() {}
	Move(int potency_, int accuracy_, int uses_, string name_, string description_ = " ");
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
	string& Description() { return description; }
	const string& Description() const { return description; }

	bool UseMovement(Ele &user, Ele &target);
	
	void Log();

};

