#include <iostream>
#include "Ele.h"
#include "Move.h"
#include "AllMoves.h"
#include "AllEles.h"
#include "AllWielders.h"
#include "utils.h"

Wielder player("player");
map<string, Ele> eles;
map<string, Move> moves;
map<string, Wielder> allWielders;
Wielder currentOpponent;

void StartCombat();
void StartRun();

int main()
{
    AllMoves::InitAllMoves();
    AllEles::InitAllEles();
    AllWielders::InitAllWielders();
    eles = AllEles::allEles;
    moves = AllMoves::allMoves;
    allWielders = AllWielders::allWielders;
    
    eles["Ele1"].Moves().push_back(moves["move1"]);
    eles["Ele1"].Moves().push_back(moves["move3"]);
    eles["Ele1"].Moves().push_back(moves["move5"]);
    eles["Ele1"].Moves().push_back(moves["move6"]);

    eles["Ele2"].Moves().push_back(moves["move2"]);
    eles["Ele2"].Moves().push_back(moves["move4"]);
    eles["Ele2"].Moves().push_back(moves["move5"]);
    eles["Ele2"].Moves().push_back(moves["move7"]);

    player.Eles().push_back(eles["Ele1"]);
    allWielders["wielder1"].Eles().push_back(eles["Ele2"]);

    StartCombat();

    player.GetEleInCombat().Moves()[1].UseMovement(player.GetEleInCombat(), currentOpponent.GetEleInCombat());

}

void StartRun() {
    PrintText("What's your name?");
    cin >> player.Name();
    PrintText("Great.");
}

void StartCombat() {
    player.Eles()[0].State() = Ele::EleState::InCombat;
    allWielders["wielder1"].Eles()[0].State() = Ele::EleState::InCombat;
    currentOpponent = allWielders["wielder1"];

}
