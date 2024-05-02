#pragma once
#include "Move.h"
#include <map>

static class AllMoves
{
public:
	static map<string, Move> allMoves;

	static void InitAllMoves();
};

