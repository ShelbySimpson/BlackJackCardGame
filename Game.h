#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Dealer.h"
#include "Player.h"
#include "Deck.h"
#include "Hand.h"

class Game{
    public:
    	//Constructor-
    	Game(char* numSets);

    	//destructor
    	~Game();

		//Vector to hold deck of cards.
		std::vector<Player *> playerV;

		//Show all cards,dealer only when all stays = 0
		void showCards();

		//Hit or stay handling
		void playerTurns();

		//Start game
		void play();

		Dealer *dealer;

		//Deal initial two cards
		void _dealInit();

		//check hit or stay commands
		int hsCheck(std::string choice);

		//Dealer's turn
		void dealerTurn();

		//Figure out who won the game
		void getWinner();

		//Play another game
		void playAgain();

		//exit game
		void quit();





    private:
		std::string _name;

		int numP;

		//Determine amount of players
		void _determineNumPlys();

		//Add players to game
		void _addPlayers();
};








#endif
