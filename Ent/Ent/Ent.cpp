#include <iostream>
#include "Ele.h"
#include "Move.h"
#include "AllMoves.h"
#include "AllEles.h"
#include "AllWielders.h"
#include "utils.h"

Wielder player("player");
map<string, Ele> elesOfAllGame;
map<string, Move> moves;
map<string, Wielder> allWielders;
Wielder currentOpponent;

void StartCombat();
void StartDuel();
bool StartTurn();
void StartRun();

int main()
{
    AllMoves::InitAllMoves();
    AllEles::InitAllEles();
    AllWielders::InitAllWielders();
    elesOfAllGame = AllEles::allEles;
    moves = AllMoves::allMoves;
    allWielders = AllWielders::allWielders;
    
    elesOfAllGame["Ele1"].Moves().push_back(moves["move1"]);
    elesOfAllGame["Ele1"].Moves().push_back(moves["move3"]);
    elesOfAllGame["Ele1"].Moves().push_back(moves["move5"]);
    elesOfAllGame["Ele1"].Moves().push_back(moves["move6"]);

    elesOfAllGame["Ele2"].Moves().push_back(moves["move2"]);
    elesOfAllGame["Ele2"].Moves().push_back(moves["move4"]);
    elesOfAllGame["Ele2"].Moves().push_back(moves["move5"]);
    elesOfAllGame["Ele2"].Moves().push_back(moves["move7"]);

    player.Eles().push_back(elesOfAllGame["Ele1"]);
    allWielders["wielder1"].Eles().push_back(elesOfAllGame["Ele2"]);

    StartRun();

    StartDuel();
    bool inCombat = true;

    do
    {
        inCombat = StartTurn();
    } while (inCombat);

    PrintText("YOU FINISHED THE GAME!");


}

void StartRun() {
    PrintText("What's your name?");
    cin >> player.Name();
    //PrintText("Great");
}

void StartDuel() {
    allWielders["wielder1"].Eles()[0].State() = Ele::EleState::InCombat;
    currentOpponent = allWielders["wielder1"];
    PrintText(currentOpponent.Name() + " sends " + allWielders["wielder1"].Eles()[0].Name() + "!");
    PrintText("Which one will you choose?");
    player.SelectEle();
   
}

bool StartTurn() {
    bool startAnotherTurn = true;
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
        if (currentOpponent.HasEleInCombat()) {
            currentOpponent.GetEleInCombat().Moves()[opponentMove].UseMovement(currentOpponent.GetEleInCombat(), player.GetEleInCombat());
        }
    }
    else if (player.GetEleInCombat().Speed() < currentOpponent.GetEleInCombat().Speed())
    {
        currentOpponent.GetEleInCombat().Moves()[opponentMove].UseMovement(currentOpponent.GetEleInCombat(), player.GetEleInCombat());
        if (player.HasEleInCombat()) {
            player.GetEleInCombat().Moves()[playerMove].UseMovement(player.GetEleInCombat(), currentOpponent.GetEleInCombat());
        }
    }


    if (!currentOpponent.HasEleInCombat()) {
        if (currentOpponent.AllElesDead()) {
            PrintText("You win!");
            startAnotherTurn = false;
        }
        else {
            for (unsigned int i = 0; i < currentOpponent.Eles().size(); i++)
            {
                Ele& ele = currentOpponent.Eles()[i];
                if (ele.State() == Ele::EleState::InParty) {
                    ele.State() = Ele::EleState::InCombat;
                    i = currentOpponent.Eles().size();
                }
            }
        }
    }

    if (!player.HasEleInCombat()) {
        if (player.AllElesDead()) {
            PrintText("You have no Eles to fight with!");
            PrintText("You lose!");
            startAnotherTurn = false;
        }
        else {
            player.SelectEle();
        }
    }

    return startAnotherTurn;
}
