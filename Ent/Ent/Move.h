#pragma once
#include <string>

using namespace std;

class Ele;

class Move
{
private:
	int potency;
	int accuracy;
	string name;
	string description;

public:
	Move(int potency_, int accuracy_, string name_, string description_ = " ");
	int& Potency() { return potency; }
	const int& Potency() const { return potency; }
	int& Accuracy() { return accuracy; }
	const int& Accuracy() const { return accuracy; }
	string& Name() { return name; }
	const string& Name() const { return name; }
	string& Description() { return description; }
	const string& Description() const { return description; }

	bool UseMovement(Ele &user, Ele &target);
	
	void Log();

};

