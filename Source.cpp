#include <iostream>
#include<string>
#include "Player.h"
#include ""
using namespace std;

Player* createPlayer()
{
	cout << "enter name: ";
	string name;

}

int main()
{
	//Setup game
	srand(time(NULL));

	//choose class
	Player* playerOne, playerTwo, currentPlayer, targetPlayer, ;

	//Coin toss
	int p1Roll = rand() % 100 + playerOne->speed;
	int p2Roll = rand() % 100 + playerTwo->speed;
	if (p1Roll > p2Roll)
	{
		currentPlayer = playerOne;
		currentPlayer = playerTwo;
	}

	//Process effects
	bool endTurn = false;
	bool dead = currentPlayer->processEffects(targetPlayer, endTurn);
	if (dead)
		break;

	//Display Status
	cout << currentPlayer->name << "'s Turn" << endl;
	currentPlayer->display();
	targetPlayer->display();

	//Take action
	switch (choice)
	{
	case 1:
		endGame = currentPlayer->attack(targetPlayer);
		break;
	case 2:
		endGame = currentPlayer->specialOne(targetPlayer);
		break;
	case 3:
		endGame = currentPlayer->specialTwo(targetPlayer);
		break;
	case 4:
		endGame = currentPlayer->weapon->weaponSpecial(currentPlayer, targetPlayer, "Physical");
	default:
		cout << "Your character does nothing and loses a turn." << endl;
	}
	cout << "Press Enter to start next round..." << endl;
	getline(cin, temp);
