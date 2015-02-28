#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

int main() {
	Deck deck = Deck(1, "aDeck");
	Deck *dptr = &deck;
	Dealer dealer = Dealer(dptr);
	Player player = Player("aDeck");

	deck.shuffleDeck();

	player.hits(dealer.dealOne());
	player.hits(dealer.dealOne());
	dealer.dealOneSelf();
	dealer.dealOneSelf();

	while (player.getHandValue() < 17) {
		player.hits(dealer.dealOne());
	}

	player.stays();

	cout << endl << "Player - " << endl;
	player.printHand();
	cout << "Player Total - " << player.getHandValue() << endl;

	int pval1 = player.getHandValue();

	if (player.getStays()) {
		dealer.dealSelf();
	}
	cout << endl << "Dealer's Hand  - " << endl;
	dealer.printHand();
	cout << "Dealer Total - " << dealer.getHandTotal() << endl;

	int playerV = player.getHandValue();
	int dealerV = dealer.getHandTotal();

	cout<< endl << "****Logic test, RACC. Predicate - Player wins****" << endl;

	//playerV = 23;
	//dealerV = 22;
	if (!(playerV <= 21) && dealerV > 21) {
		cout << endl << "Test Case 1(a Major). Player busts Dealer busts" << endl;
	}

	//playerV = 21;
	//dealerV = 22;
	if (playerV <= 21 && dealerV > 21) {
		cout << endl << "Test Case 2(a Major). Player wins, dealer busts" << endl;
	}

	//playerV = 19;
	//dealerV = 20;
	if (playerV <= 21 && !(dealerV > 21)) {
		cout << endl << "Test Case 1(b Major). Player and dealer does not bust " << endl;
	}

	//playerV = 19;
	//dealerV = 22;
	if (playerV <= 21 && dealerV > 21) {
		cout << endl << "Test Case 2(b Major). Player wins dealer busts. " << endl;
	}

	cout<< endl << "****Logic test, RACC. Predicate - Dealer wins****" << endl;
	//playerV = 19;
	//dealerV = 20;
	if (!(playerV > 21) && dealerV <= 21) {
		cout << endl << "Test Case 1(a Major). Player and dealer do not bust. " << endl;
	}

	//playerV = 22;
	//dealerV = 20;
	if (playerV > 21 && dealerV <= 21) {
		cout << endl << "Test Case 2(a Major). Player busts Dealer wins. " << endl;
	}

	//playerV = 23;
	//dealerV = 22;
	if (playerV > 21 && !(dealerV <= 21)) {
		cout << endl << "Test Case 1(b Major). Player and dealer bust. " << endl;
	}

	//playerV = 24;
	//dealerV = 19;
	if (playerV > 21 && dealerV <= 21) {
		cout << endl << "Test Case 2(b Major). Player busts dealer wins. " << endl;
	}

}
