#include "utils.h"
#include "Ele.h"
#include "Move.h"
#include <iostream>
#include <random>
#include <math.h>
#include <time.h>
#include <thread>
#include <iomanip>

int CalculateDamage(Ele& attacker, Ele& defender, Move& move) {

    float damage = 1 + (static_cast<float>(move.Potency()) * 
            static_cast<float>(attacker.Attack()) / 
            static_cast<float>(defender.Defense()));
    
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

void PrintText(string text, long long customTime)
{
    for (char c : text) {
        cout << c;
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(customTime));
    }
}


