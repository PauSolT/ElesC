#pragma once
#include <vector>
#include <string>
#include "Ele.h"

using namespace std;

class Wielder
{
private:
	vector<Ele> eles;
	string name;

public:
	Wielder(){}
	Wielder(string name_);
	vector<Ele>& Eles() { return eles; }
	const vector<Ele>& Eles() const { return eles; }
	string& Name() { return name; }
	const string& Name() const { return name; }

	Ele& GetEleInCombat();
	bool AllElesDead();
	void SelectEle();
	int SelectMove();

};

