#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

int main(){
	Deck deck(1,"deck");
	Deck *deckptr = &deck;
	Hand hand("deck");
	Hand *handptr = &hand;
	Player player("deck");
	player.setName("Shelby");
	int start;
	deck.shuffleDeck();

	cout << endl << "*** Test printHand() and getValue ***" << endl;
	cout << endl << "Press 1 to start testing - " << endl;
	cin >> start;
	cout << endl << "Hand - "<< endl;
	player.hits(deck.dealOne());
	player.hits(deck.dealOne());
	player.printHand();
	cout << endl << "Value of hand - " << player.getHandValue()<< endl;

	cout << endl << "*** Test to see if hand busts ***" << endl;
	while(player.getBust() != 1){
		player.hits(deck.dealOne());
		player.printHand();
		deck.shuffleDeck();
		cout << "Hand value - " << player.getHandValue() << " Bust status - " << player.getBust() << endl << endl;
	}

	cout << "*** Test clear() ***" << endl;
	cout << "Print current hand, clear hand, print hand, add a card and print hand again" << endl << endl;
	cout << endl << "Press 1 to start testing - " << endl;
	cin >> start;
	player.printHand();
	player.clearHand();
	player.printHand();
	player.hits(deck.dealOne());
	player.printHand();
	cout << endl;

	cout << endl << "*** Test stay() ***" << endl;
	cout << endl << "Chose a number between 15-19 to stay() on" << endl;
	Deck deck2(16,"deck2");
	Deck *deckptr2 = &deck2;
	Hand hand2("deck2");
	Hand *handptr2 = &hand2;
	Player player2("deck2");
	player2.setName("Shelby");
	deck2.shuffleDeck();
	int pstay = 0;
	int stay;
	cin >> stay;
	while(stay != pstay){
		player2.hits(deck2.dealOne());
		player2.hits(deck2.dealOne());
		cout << "Two cards dealt, hand value - " << player2.getHandValue() << endl;
	while(!player2.getBust() || player.getStays() == 1){
		if(player2.getHandValue() == stay){
			player2.stays();
			pstay = stay;
			cout << endl << "stay status - " << player2.getStays() << endl << endl;
			break;
		}
		player2.hits(deck2.dealOne());
		cout << "hit, get value - " << player2.getHandValue() << endl;
	}
		player2.resetBust();
		player2.clearHand();
	}

	cout << endl << "--------------------------- Test Multiple players ----------------------------------------" << endl;
	cout << endl << "Shelby, Bob and Annie are going to play together - " << endl;
    cout << endl << "Press 1 to start testing - " << endl;
	cin >> start;
	Deck mDeck(1,"mDeck");
	Deck *mDptr = &mDeck;
	Hand Shelbyh("mDeck");
	Hand bobh("mDeck");
	Hand annieh("mDeck");
	Hand *sHptr = &Shelbyh;
	Hand *bHptr = &bobh;
	Hand *aHptr = &annieh;
	Player shelby = Player("mDeck");
	Player bob = Player("mDeck");
	Player annie = Player("mDeck");

	mDeck.shuffleDeck();
	cout << endl << "Shelby dealt two cards - " << endl;
	shelby.hits(mDeck.dealOne());
	shelby.hits(mDeck.dealOne());
	shelby.printHand();
	cout << endl << "hits() printHand() - " << endl;
	shelby.hits(mDeck.dealOne());
	shelby.printHand();
	if(shelby.getBust()){
		cout << "You have busted!" << endl;
	}
	cout << endl << "Bob - " << endl;
	bob.hits(mDeck.dealOne());
	bob.hits(mDeck.dealOne());
	bob.printHand();
	cout << endl << "hits() printHand() - " << endl;
	bob.hits(mDeck.dealOne());
	bob.printHand();
	if(bob.getBust()){
		cout << endl << "You have busted!" << endl;
	}
	cout << endl << "Annie - " << endl;
	annie.hits(mDeck.dealOne());
	annie.hits(mDeck.dealOne());
	annie.printHand();
	cout << endl << "hits() printHand() - " << endl;
	annie.hits(mDeck.dealOne());
	annie.printHand();
	if(annie.getBust()){
		cout << endl << "You have busted!" << endl;
	}
	cout << endl << "Print Deck to show that all players are playing from the same deck - " << endl;
	mDeck.printDeck();

	cout << endl << "------------------------- 5 card Charlie probability ----------------------------------------" << endl;
	cout << endl << "Press 1 to start testing - " << endl;
	cin >> start;
	Deck chDeck(16,"chDeck");
	chDeck.shuffleDeck();
	Hand chHand("chDeck");
	Hand *chHptr = &chHand;
	Deck *chDptr = &chDeck;
	Player charlie("chDeck");
	int counter = 0;

	for(int i=0; i<830; i= i+5){
		cout << "i value - " << i << endl;
		charlie.hits(chDeck.dealOne());
		charlie.hits(chDeck.dealOne());
		charlie.hits(chDeck.dealOne());
		charlie.hits(chDeck.dealOne());
		charlie.hits(chDeck.dealOne());
		cout << endl << "Check for 5 card charlie - " << endl;
		if(!charlie.getBust()){
			cout << endl << "****Five Card Charlie!!!***" << endl;
			charlie.printHand();
			charlie.clearHand();
			counter++;
			charlie.resetBust();
		}else{
			cout << "Busted" << endl << endl;
			charlie.printHand();
			charlie.clearHand();
			charlie.resetBust();
		}

	}
		int cPercent = (counter * 100) / (166);
		cout << endl << "You played 166 hands and had  " << counter << " five card charlies" << endl;
		cout << endl << "Probability was - " << cPercent << " percent" << endl;


		cout << endl << "------------------------- Blackjack Probability ----------------------------------------" << endl;
		int wait = 0;
		cout << endl << "Hit 1 to begin Blackjack Probability" << endl;
		cin >> wait;
		Deck bkjDeck(16,"bkjDeck");
		bkjDeck.shuffleDeck();
		Hand bkjHand("bkjDeck");
		Hand *bkjHptr = &bkjHand;
		Deck *bkjDptr = &bkjDeck;
		Player blackjack("bkjDeck");
		int counter2 = 0;

		for(int i=0; i<832; i=i+2){
			blackjack.hits(bkjDeck.dealOne());
			blackjack.hits(bkjDeck.dealOne());
			if(blackjack.getHandValue() == 21){
				cout << endl << "****Black jack!!!****" << endl;
				blackjack.printHand();
				blackjack.clearHand();
				counter2++;
			}else{
				cout << endl << "No 21, Try Again" << endl;
				blackjack.printHand();
				blackjack.clearHand();

			}
		}
			int cPercent2 = (counter2 * 100) / (416);
			cout << endl << "You played 416 hands and  had " << counter2 << " blackjacks" << endl;
			cout << endl << "Probability was " << cPercent2 << " percent" << endl;

}
