#include "Wielder.h"
#include "Ele.h"
#include "utils.h"
#include <iostream>

Wielder::Wielder(string name_) {
	name = name_;
}

Ele& Wielder::GetEleInCombat() {
	for (Ele& ele : eles)
	{
		if (ele.State() == Ele::EleState::InCombat) 
		{
			return ele;
		}
	}
}

bool Wielder::HasElesAlive() {
	bool allDead = true;
	for (unsigned int i = 0; i < eles.size(); i++)
	{
		if (eles[i].State() == Ele::EleState::InCombat ||
			eles[i].State() == Ele::EleState::InParty)
		{
			allDead = false;
		}
	}
	return allDead;
}

void Wielder::SelectEle() {
	for (unsigned int i = 0; i < eles.size(); i++)
	{
		Ele playerEle = eles[i];
		PrintText(to_string(i + 1) + ".");
		playerEle.Log();
	}

	unsigned int playerChoice;
	bool goodEle = true;

	do
	{
		if (!goodEle) {
			PrintText("Which one will you choose?");
		}

		goodEle = true;
		cin >> playerChoice;
		playerChoice--;
		if (playerChoice < 0 || playerChoice > eles.size() - 1)
		{
			goodEle = false;
			PrintText("That is not a valid option");
		} else if (eles[playerChoice].State() != Ele::EleState::InParty)
		{
			goodEle = false;
			PrintText("That is not a valid option");
		}

		} while (!goodEle);
	eles[playerChoice].State() = Ele::EleState::InCombat;

	PrintText("You send out " + GetEleInCombat().Name() + "!");
}

int Wielder::SelectMove()
{
	PrintText("Which move will you choose?");
	for (unsigned int i = 0; i < GetEleInCombat().Moves().size(); i++)
	{
		Move move = GetEleInCombat().Moves()[i];
		PrintText(to_string(i + 1) + ".");
		move.Log();
	}

	unsigned int playerChoice;
	bool goodMove = true;

	do
	{
		if (!goodMove) {
			PrintText("Which move will you choose?");
		}
		goodMove = true;
		cin >> playerChoice;
		playerChoice--;
		if (playerChoice < 0 || playerChoice > GetEleInCombat().Moves().size() - 1)
		{
			goodMove = false;
			PrintText("That is not a valid move");
		} else if (GetEleInCombat().Moves()[playerChoice].Uses() <= 0)
		{
			goodMove = false;
			PrintText("That is not a valid move");
		}

	} while (!goodMove);

	return playerChoice;
}
