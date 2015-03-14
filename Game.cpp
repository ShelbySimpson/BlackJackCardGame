#include <iostream>
#include <string>
#include <cstdlib>

#include "Game.h"
#include "Deck.h"
#include "Dealer.h"

using namespace std;

//constructor
Game::Game(char* numSets) {
	int numSets2 = 0;
	numSets2 += atoi(numSets);
	Deck deck = Deck(numSets2, "deck");
	Deck *deckPtr = &deck;
	dealer = new Dealer(deckPtr);
	vector<Player *> playerV;

	//shuffle
	deck.shuffleDeck();

	//Set up for num of players
	_determineNumPlys();

	//set up players
	_addPlayers();

	cout << endl << "OK lets Play! Valid commands: hit stay quit" << endl;

	play();
}

//destructor
Game::~Game() {
}

void Game::play() {
	_dealInit();
	showCards();
	playerTurns();
	dealerTurn();
	getWinner();
	playAgain();
}

void Game::_dealInit() {
	int vSize = playerV.size();
	for (int i = 0; i < vSize; i++) {
		playerV[i]->hits(dealer->dealOne());
		playerV[i]->hits(dealer->dealOne());
	}
	dealer->dealOneSelf();
	dealer->dealOneSelf();
}

void Game::showCards() {
	int vSize = playerV.size();
	for (int i = 0; i < vSize; i++) {
		cout << endl << playerV[i]->getName() << " - " << endl;
		playerV[i]->printHand();
		cout << "Hand total - " << playerV[i]->getHandValue() << endl;
	}
	cout << endl << "Dealer - " << endl;
	dealer->showHand();

}

void Game::playerTurns() {
	string choice;
	int done = 0;
	int yes = 1;
	int vSize = playerV.size();

	for (int i = 0; i < vSize; i++) {
		cout << endl << playerV[i]->getName()
				<< "'s turn, would you like to hit or stay?" << endl;
		cin >> choice;
		if (choice.compare("quit") == 0) {
			quit();
		}
		while (!done) {
			if (choice.compare("hit") == 0) {
				//------------------------------------------------------------------------
				//while the player wants another card or has not busted
				while (yes) {
					//player hits, deal card, printhand and get total
					playerV[i]->hits(dealer->dealOne());
					playerV[i]->printHand();
					cout << "Hand total - " << playerV[i]->getHandValue()
							<< endl;

					//end game if player busts
					if (playerV[i]->getBust()) {
						int highAce = playerV[i]->findHighAce();
						if (highAce == -1) {
							cout << endl << "You have busted! Game over!"
									<< endl << endl;
							playerV[i]->stays();
							done = 1;
							break;
						} else {
							//change ace value
							playerV[i]->changeAceValue(highAce);
							playerV[i]->resetBust();
							cout << endl << "Change ace value, hand total - "
									<< playerV[i]->getHandValue() << endl;
						}
					}

					//player hits again
					cout << endl << playerV[i]->getName()
							<< "'s turn, would you like to hit or stay?"
							<< endl;
					cin >> choice;
					if (choice.compare("quit") == 0) {
						quit();
					}

					//check to see that user input is valid
					while (!hsCheck(choice)) {
						cout
								<< "invalid command try again. Valid commands: hit  stay"
								<< endl;
						cin >> choice;
						if (choice.compare("quit") == 0) {
							quit();
						}
					}

					//player chooses to stay, move on to next player
					if (choice.compare("stay") == 0) {
						playerV[i]->stays();
						yes = 0;
						done = 1;
					}
				}

			} else if (choice.compare("stay") == 0) {
				cout << "You chose to stay" << endl;
				done = 1;
			} else {
				cout << "invalid command try again. Valid commands: hit  stay"
						<< endl;
				cin >> choice;
				if (choice.compare("quit") == 0) {
					quit();
				}
			}
		}
		//reset while loops for next player
		done = 0;
		yes = 1;

	}
	//Print hands
	for (int i = 0; i < vSize; i++) {
		cout << endl << playerV[i]->getName() << " hand - " << endl;
		playerV[i]->printHand();
		cout << "Hand total - " << playerV[i]->getHandValue() << endl << endl;
	}
}

void Game::_addPlayers() {
	Player *plyr;
	if (numP <= 5) {
		for (int i = 0; i < numP; i++) {
			cout << endl << "Player " << i + 1 << " enter name: " << endl;
			cin >> _name;
			if (_name.compare("quit") == 0) {
				quit();
			}
			plyr = new Player("deck");
			playerV.push_back(plyr);
			playerV[i]->setName(_name);
		}
	}
}

void Game::_determineNumPlys() {
	bool done = false;
	int age = 0;
	cout << endl << "How many players? 1 to 5 Players " << endl;
	//Determine amount of players
	cin >> numP;
//	if(cin.fail()){
//		playAgain();
//	}
//
//	if((numP < 1 || numP > 5)){
//		playAgain();
//	}
}

int Game::hsCheck(string choice) {
	if (choice.compare("stay") == 0 || choice.compare("hit") == 0) {
		return 1;
	} else
		return 0;
}

void Game::dealerTurn() {
	bool done = false;
	//dealer takes turn while consider possible
	//aces in hand
	while (!done) {
		dealer->dealSelf();
		//check to find aces, no aces returns -1
		int highAce = dealer->findHighAce();
		if (!dealer->getBust()) {
			//No bust and dealer hand 17 to 21, show hand.
			cout << endl << "Dealer's hand- " << endl;
			dealer->showHand();
			cout << "Hand total - " << dealer->getHandTotal() << endl << endl;
			done = true;
		} else if (highAce == -1 && dealer->getBust()) {
			//Dealer has busted and there is no aces to change
			cout << "Dealer Busted!" << endl;
			dealer->printHand();
			done = true;
		} else {
			//dealer has ace, change value and reevaluate
			dealer->changeAceValue(highAce);
			dealer->setBust(0);
		}
	}

}

//Allow players to play another game
void Game::playAgain() {
	string answer;
	cout << endl << "Would you like to play again? yes or no" << endl;
	cin >> answer;
	//Player chooses yes, set up for next game
	if (answer.compare("yes") == 0) {
		int vSize = playerV.size();
		for (int i = 0; i < vSize; i++) {
			playerV[i]->clearHand();
			playerV[i]->resetBust();
		}
		dealer->clearHand();
		dealer->setShowHand(0);
		dealer->setBust(0);
		dealer->clearDeck();
		dealer->newDeck();
		dealer->shuffleDeck();
		play();
	} else {
		cout << endl << "Have a nice day! Come back soon!" << endl;
	}
}

void Game::getWinner() {
	int vSize = playerV.size();
	vector<Player *> pBust;
	vector<Player *> pNoBust;
	int pNoBustSize = 0;
	int bustSize = 0;

	//print hands
	for (int i = 0; i < vSize; i++) {
		cout << playerV[i]->getName() << " - " << playerV[i]->getHandValue()
				<< endl;
	}
	cout << "Dealer - " << dealer->getHandTotal() << endl;

	//Load arrays
	for (int i = 0; i < vSize; i++) {

		if (playerV[i]->getBust()) {
			pBust.push_back(playerV[i]);
		} else {
			pNoBust.push_back(playerV[i]);
		}
	}
	//get Vector sizes
	pNoBustSize = pNoBust.size();
	bustSize = pBust.size();

	if (dealer->getHandTotal() > 21) {
		if (pNoBustSize == 0) {
			cout << endl
					<< "This game does have a happy ending, everyone needs to reevaluate their existence. Pathetic! You're all losers!"
					<< endl;
		} else {
			cout << endl << "Winners - " << endl;
			for (int i = 0; i < pNoBustSize; i++) {
				cout << pNoBust[i]->getName() << endl;
			}
		}
	} else if (dealer->getHandTotal() <= 21) {
		for (int i = 0; i < pNoBustSize; i++) {
			if (pNoBust[i]->getHandValue() > dealer->getHandTotal()) {
				cout << endl << "Congrats " << pNoBust[i]->getName()
						<< " you won! Now go roll in all that money you didn't win."
						<< endl;
			}
			if (pNoBust[i]->getHandValue() < dealer->getHandTotal()) {
				cout << endl << pNoBust[i]->getName() << " you lost." << endl;
			}
			if (pNoBust[i]->getHandValue() == dealer->getHandTotal()) {
				cout << endl << pNoBust[i]->getName() << " , its a draw!"
						<< endl;
			}
		}

	}
	//Print who busted
	for (int i = 0; i < bustSize; i++) {
		cout << pBust[i]->getName() << " you have busted" << endl;
	}

	pBust.clear();
	pNoBust.clear();
}

void Game::quit() {
	exit(1);
}

