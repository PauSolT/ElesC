#include "AllMoves.h"

map<string, Move> AllMoves::allMoves;

void AllMoves::InitAllMoves() {
	allMoves["move1"] = Move(20, 100, 20, "move 1", "description");
	allMoves["move2"] = Move(35, 100, 15, "move 2", "description");
	allMoves["move3"] = Move(50, 95, 10, "move 3", "description");
	allMoves["move4"] = Move(70, 100, 5, "move 4", "description");
	allMoves["move5"] = Move(80, 90, 10, "move 5", "description");
	allMoves["move6"] = Move(100, 80, 10, "move 6", "description");
	allMoves["move7"] = Move(120, 75, 5, "move 7", "description");
	allMoves["move8"] = Move(150, 70, 5, "move 8", "description");

}
