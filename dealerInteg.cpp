#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

int main() {
	int start1;
	//set up for 3 players and dealer
	cout << endl << "Integration with 3 players and a dealer" << endl;
	cout << endl << "Press 1 to begin integration testing - " << endl;
	cin >> start1;
	Deck deck = Deck(1, "aDeck");
	Deck *dptr = &deck;
	Dealer dealer = Dealer(dptr);
	Player player1 = Player("aDeck");
	Player player2 = Player("aDeck");
	Player player3 = Player("aDeck");
	Card *card;

	dealer.shuffleDeck();

	//Everyone gets first two cards
	player1.hits(dealer.dealOne());
	player1.hits(dealer.dealOne());
	player2.hits(dealer.dealOne());
	player2.hits(dealer.dealOne());
	player3.hits(dealer.dealOne());
	player3.hits(dealer.dealOne());
	dealer.dealOneSelf();
	dealer.dealOneSelf();

//Deal each player until they have a hand value 17 or higher.
	while (player1.getHandValue() < 17) {
		player1.hits(dealer.dealOne());
	}

	player1.stays();

	while (player2.getHandValue() < 17) {
		player2.hits(dealer.dealOne());
	}

	player2.stays();

	while (player3.getHandValue() < 17) {
		player3.hits(dealer.dealOne());
	}

	player3.stays();

//Print each players hand and their bust status
	cout << endl << "Player one's hand - " << endl;
	player1.printHand();
	cout << "Player one bust - " << player1.getBust() << endl;
	cout << endl << "Player two's hand - " << endl;
	player2.printHand();
	cout << "Player two bust - " << player2.getBust() << endl;
	cout << endl << "Player three's hand - " << endl;
	player3.printHand();
	cout << "Player three bust - " << player3.getBust() << endl;

//if all players's stay status is true then dealer deals self until 17 or higher.
	if (player1.getStays() && player2.getStays() && player3.getStays()) {
		dealer.dealSelf();
	}
//print dealers hand and bust status
	cout << endl << "Dealer's Hand  - " << endl;
	dealer.printHand();
	cout << "Dealer bust - " << dealer.getBust() << endl;

//Clear hands and deck and repeat
	cout << endl << "Clear hands, decks and play another hand - " << endl;
	player1.clearHand();
	player1.resetBust();
	player1.resetStay();

	player2.clearHand();
	player2.resetBust();
	player2.resetStay();

	player3.clearHand();
	player3.resetBust();
	player3.resetStay();

	dealer.clearHand();
	dealer.setBust(0);
	dealer.clearDeck();
	dealer.newDeck();

//Play another game -
	dealer.shuffleDeck();

	player1.hits(dealer.dealOne());
	player1.hits(dealer.dealOne());
	player2.hits(dealer.dealOne());
	player2.hits(dealer.dealOne());
	player3.hits(dealer.dealOne());
	player3.hits(dealer.dealOne());
	dealer.dealOneSelf();
	dealer.dealOneSelf();

	while (player1.getHandValue() < 17) {
		player1.hits(dealer.dealOne());
	}

	player1.stays();

	while (player2.getHandValue() < 17) {
		player2.hits(dealer.dealOne());
	}

	player2.stays();

	while (player3.getHandValue() < 17) {
		player3.hits(dealer.dealOne());
	}

	player3.stays();

	cout << endl << "Player one - " << endl;
	player1.printHand();
	cout << "Player one bust - " << player1.getBust() << endl;
	cout << endl << "Player two - " << endl;
	player2.printHand();
	cout << "Player two bust - " << player2.getBust() << endl;
	cout << endl << "Player three - " << endl;
	player3.printHand();
	cout << "Player three bust - " << player3.getBust() << endl;

	if (player1.getStays() && player2.getStays() && player3.getStays()) {
		dealer.dealSelf();
	}
	cout << endl << "Dealer's Hand  - " << endl;
	dealer.printHand();
	cout << "Dealer bust - " << dealer.getBust() << endl;


//Test Five Card Charlie
	int start;
	cout << endl
			<< "------------------------- 5 card Charlie probability ----------------------------------------"
			<< endl;
	cout << endl << "Hit 1 to begin Charlie test - " << endl;
	//Prompt user
	cin >> start;
	//set up
	Deck chDeck(16, "chDeck");
	Hand chHand("chDeck");
	Deck *chDptr = &chDeck;
	Dealer chDealer(chDptr);
	Player charlie("chDeck");
	int counter = 0;
	chDealer.shuffleDeck();
	//Deal
	for (int i = 0; i < 830; i = i + 5) {
		cout << "i value - " << i << endl;
		charlie.hits(chDealer.dealOne());
		charlie.hits(chDealer.dealOne());
		charlie.hits(chDealer.dealOne());
		charlie.hits(chDealer.dealOne());
		charlie.hits(chDealer.dealOne());
		cout << endl << "Check for 5 card charlie - " << endl;
		//Decide
		if (!charlie.getBust()) {
			cout << endl << "****Five Card Charlie!!!***" << endl;
			charlie.printHand();
			charlie.clearHand();
			counter++;
			charlie.resetBust();
		} else {
			cout << "Busted" << endl << endl;
			charlie.printHand();
			charlie.clearHand();
			charlie.resetBust();
		}

	}
	//calculate percentage
	int cPercent = (counter * 100) / (166);
	cout << endl << "You played 166 hands and had  " << counter
			<< " five card charlies" << endl;
	cout << endl << "Probability was - " << cPercent << " percent" << endl;

	cout << endl
			<< "------------------------- Blackjack Probability ----------------------------------------"
			<< endl;
	int wait = 0;
	cout << endl << "Hit 1 to begin Blackjack Probability" << endl;
	//prompt user
	cin >> wait;
	//set up
	Deck bkjDeck(16, "bkjDeck");
	Deck *bkjkDptr = &bkjDeck;
	Dealer bkDealer(bkjkDptr);
	Deck *bkjDptr = &bkjDeck;
	Player blackjack("bkjDeck");

	bkDealer.shuffleDeck();

	//deal and decide
	int counter2 = 0;
	for (int i = 0; i < 832; i = i + 2) {
		blackjack.hits(bkDealer.dealOne());
		blackjack.hits(bkDealer.dealOne());
		if (blackjack.getHandValue() == 21) {
			cout << endl << "****Black jack!!!****" << endl;
			blackjack.printHand();
			blackjack.clearHand();
			counter2++;
		} else {
			cout << endl << "No 21, Try Again" << endl;
			blackjack.printHand();
			blackjack.clearHand();

		}
	}
	//calculate percentage
	int cPercent2 = (counter2 * 100) / (416);
	cout << endl << "You played 416 hands and  had " << counter2
			<< " blackjacks" << endl;
	cout << endl << "Probability was " << cPercent2 << " percent" << endl;

	deck.disposeCards();
	dealer.clearDeck();

}
