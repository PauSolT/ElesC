#include "utils.h"
#include "Ele.h"
#include "Move.h"
#include <iostream>
#include <random>
#include <math.h>
#include <time.h>
#include <thread>
#include <iomanip>

int CalculateDamage(Ele &attacker, Ele &defender, Move& move) {

    float damage = 1 + (static_cast<float>(move.Potency()) * 
            static_cast<float>(attacker.Attack()) * ( 1+ attacker.AttackModifier() * 0.1f ) /
            static_cast<float>(defender.Defense()) * (1 + defender.DefenseModifier() * 0.1f));
    
    damage *= GetElemAdvantage(move.Element(), defender.Element());

    if (damage < 1)
    {
        damage = 1;
    }

    return static_cast<int>(round(damage));
}

int RandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(min, max);

    return distribution(gen);
}

void PrintText(string text, long long customTime, bool wantEndOfLine)
{
    for (char c : text) {
        cout << c;
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(customTime));
    }
    if (wantEndOfLine) {
        cout << endl;
    }
}

float GetElemAdvantage(Elem attacker, Elem defender) {
    switch (attacker) {
    case Elem::Water:
        return (defender == Elem::Fire) ? 1.5 : ((defender == Elem::Grass) ? 0.75 : 1);
    case Elem::Fire:
        return (defender == Elem::Grass) ? 1.5 : ((defender == Elem::Water) ? 0.75 : 1);
    case Elem::Grass:
        return (defender == Elem::Water) ? 1.5 : ((defender == Elem::Fire) ? 0.75 : 1);
    default:
        return 1;
    }
}
