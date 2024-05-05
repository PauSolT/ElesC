#pragma once
#include "Move.h"
#include <map>

class AllMoves
{
public:
	static map<string, Move> allMoves;

	static void InitAllMoves();
};

