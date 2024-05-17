#include "AllMoves.h"

map<string, Move> AllMoves::allMoves;

void AllMoves::InitAllMoves() {

#pragma region Offensive

#pragma region Normal
	allMoves["moveN1"] = Move(20, 100, 25, "moveN 1", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN2"] = Move(30, 100, 20, "moveN 2", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN3"] = Move(50, 100, 10, "moveN 3", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN4"] = Move(75, 95, 10, "moveN 4", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN5"] = Move(90, 95, 5, "moveN 5", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN6"] = Move(100, 90, 5, "moveN 6", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN7"] = Move(120, 85, 5, "moveN 7", Move::MoveType::Offensive, Elem::Normal, "description");
	allMoves["moveN8"] = Move(150, 100, 1, "moveN 8", Move::MoveType::Offensive, Elem::Normal, "description");

#pragma endregion


#pragma region Fire
	allMoves["moveF1"] = Move(20, 100, 25, "moveF 1", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF2"] = Move(30, 100, 20, "moveF 2", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF3"] = Move(50, 100, 10, "moveF 3", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF4"] = Move(75, 95, 10, "moveF 4", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF5"] = Move(90, 95, 5, "moveF 5", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF6"] = Move(100, 90, 5, "moveF 6", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF7"] = Move(120, 85, 5, "moveF 7", Move::MoveType::Offensive, Elem::Fire, "description");
	allMoves["moveF8"] = Move(150, 100, 1, "moveF 8", Move::MoveType::Offensive, Elem::Fire, "description");
#pragma endregion


#pragma region Water
	allMoves["moveW1"] = Move(20, 100, 25, "moveW 1", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW2"] = Move(30, 100, 20, "moveW 2", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW3"] = Move(50, 100, 10, "moveW 3", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW4"] = Move(75, 95, 10, "moveW 4", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW5"] = Move(90, 95, 5, "moveW 5", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW6"] = Move(100, 90, 5, "moveW 6", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW7"] = Move(120, 85, 5, "moveW 7", Move::MoveType::Offensive, Elem::Water, "description");
	allMoves["moveW8"] = Move(150, 100, 1, "moveW 8", Move::MoveType::Offensive, Elem::Water, "description");
#pragma endregion


#pragma region Grass
	allMoves["moveG1"] = Move(20, 100, 25, "moveG 1", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG2"] = Move(30, 100, 20, "moveG 2", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG3"] = Move(50, 100, 10, "moveG 3", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG4"] = Move(75, 95, 10, "moveG 4", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG5"] = Move(90, 95, 5, "moveG 5", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG6"] = Move(100, 90, 5, "moveG 6", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG7"] = Move(120, 85, 5, "moveG 7", Move::MoveType::Offensive, Elem::Grass, "description");
	allMoves["moveG8"] = Move(150, 100, 1, "moveG 8", Move::MoveType::Offensive, Elem::Grass, "description");
#pragma endregion
#pragma endregion
	
#pragma region Defensive
	allMoves["heal1"] = Move(50, 100, 15, "heal 1", Move::MoveType::Defensive, Elem::Normal, "description");
	allMoves["heal2"] = Move(100, 100, 10, "heal 2", Move::MoveType::Defensive, Elem::Normal, "description");
	allMoves["heal3"] = Move(25, 100, 10, "heal 3", Move::MoveType::Defensive, Elem::Normal, "description", true);
	allMoves["heal4"] = Move(50, 100, 5, "heal 4", Move::MoveType::Defensive, Elem::Normal, "description", true);
	allMoves["heal5"] = Move(100, 100, 1, "heal 5", Move::MoveType::Defensive, Elem::Normal, "description", true);
#pragma endregion

}
