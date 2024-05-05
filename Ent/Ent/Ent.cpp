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
void StartDuel();
void StartTurn();
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

    StartRun();

    StartDuel();
    StartTurn();
    StartTurn();
}

void StartRun() {
    PrintText("What's your name?");
    cin >> player.Name();
    PrintText("Great");
}

void StartDuel() {
    allWielders["wielder1"].Eles()[0].State() = Ele::EleState::InCombat;
    currentOpponent = allWielders["wielder1"];
    PrintText(currentOpponent.Name() + " sends " + allWielders["wielder1"].Eles()[0].Name() + "!");
    PrintText("Which one will you choose?");
    player.SelectEle();
   
}

void StartTurn() {
    int playerChoice;
    int playerMove;
    int opponentMove = RandomNumber(0, currentOpponent.GetEleInCombat().Moves().size() -1);
    PrintText("What will you do?");
    PrintText("1. Select Move");
    cin >> playerChoice;
    if (playerChoice == 1)
    {
        playerMove = player.SelectMove();
    }

    if (player.GetEleInCombat().Speed() >= currentOpponent.GetEleInCombat().Speed())
    {
        player.GetEleInCombat().Moves()[playerMove].UseMovement(player.GetEleInCombat(), currentOpponent.GetEleInCombat());
        currentOpponent.GetEleInCombat().Moves()[opponentMove].UseMovement(currentOpponent.GetEleInCombat(), player.GetEleInCombat());

    } else if (player.GetEleInCombat().Speed() < currentOpponent.GetEleInCombat().Speed())
    {
        currentOpponent.GetEleInCombat().Moves()[opponentMove].UseMovement(currentOpponent.GetEleInCombat(), player.GetEleInCombat());
        player.GetEleInCombat().Moves()[playerMove].UseMovement(player.GetEleInCombat(), currentOpponent.GetEleInCombat());
    }

}
