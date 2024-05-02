#pragma once
#include <vector>
#include <string>

using namespace std;

class Ele;

class Wielder
{
private:
	vector<Ele> eles;
	string name;

public:
	vector<Ele>& Eles() { return eles; }
	const vector<Ele>& Eles() const { return eles; }
	string& Name() { return name; }
	const string& Name() const { return name; }

	Ele GetEleInCombat();
	bool HasElesAlive();
	void SelectEle();

};

