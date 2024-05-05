#include "AllMoves.h"

map<string, Move> AllMoves::allMoves;

void AllMoves::InitAllMoves() {
	allMoves["move1"] = Move(20, 100, 20, "move 1", Move::MoveType::Offensive, "description");
	allMoves["move2"] = Move(35, 100, 15, "move 2", Move::MoveType::Offensive, "description");
	allMoves["move3"] = Move(50, 95, 10, "move 3", Move::MoveType::Offensive, "description");
	allMoves["move4"] = Move(70, 100, 5, "move 4", Move::MoveType::Offensive, "description");
	allMoves["move5"] = Move(80, 90, 10, "move 5", Move::MoveType::Offensive, "description");
	allMoves["move6"] = Move(100, 80, 10, "move 6", Move::MoveType::Offensive, "description");
	allMoves["move7"] = Move(120, 75, 5, "move 7", Move::MoveType::Offensive, "description");
	allMoves["move8"] = Move(150, 70, 5, "move 8", Move::MoveType::Offensive, "description");

}
