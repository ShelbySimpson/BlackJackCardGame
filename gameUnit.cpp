#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	if(argc != 2){
		cout << "usage: ./gameUnit numOfSets(1-16)" << endl;
		exit(1);
	}
	Game game = Game(argv[1]);

}
