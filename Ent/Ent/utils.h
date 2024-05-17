#pragma once
#include <string>
#include "Constants.h"

#ifndef UTILS
#define UTILS

class Ele;
class Move;

// Function declarations
int CalculateDamage(Ele& attacker, Ele& defender, Move& move);
int RandomNumber(int min, int max);
void PrintText(std::string text, long long customTime = 20, bool wantEndOfLine = true);
float GetElemAdvantage(Elem attacker, Elem defender);


#endif