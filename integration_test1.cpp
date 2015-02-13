#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"

using namespace std;

//Integration - Deck Tests are tested as an integration test being that printCard() needs to be used to test the deck class methods.
int main(){
	cout << endl << "Deck Tests: ----------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	cout << "***Test: shuffle() A deck consisting of one set will be created,printed, shuffled and printed again. ***" << endl;
	Deck adeck(1,"aDeck");
	Card *card;
	adeck.printDeck();
	cout<< endl << "Shuffled deck - " << endl;
	adeck.shuffleDeck();
	adeck.printDeck();

	cout << endl << "***Deal one card, print card, shuffle then deal one and printCard. -*** " <<endl;
	cout << endl << "Card one - " << endl;
	card = adeck.dealOne();
	card->printCard();
	cout << endl << "Shuffle and deal card two - " << endl;
	adeck.shuffleDeck();
	card = adeck.dealOne();
	card->printCard();
	cout << endl << "Call deckCount() -" << endl << " Amount of cards in deck: " << adeck.deckCount()<< endl << endl;
	cout << endl << "***Print Deck to check that the two dealt cards are not in the deck.***" << endl;
	cout << "Amount of sets in a deck can be changed in test code to insure that this" << endl << "also works with more than one set." << endl << endl;
	adeck.printDeck();
	int userIn;
	cout << endl << "***Test: creating deck(s). The printDeck() method will be called to insure that a deck was created.*** " << endl << endl;
	cout << "Enter the amount of decks you want printed out:" << endl;
	cin >> userIn;
	Deck deck(userIn, "deck");
	deck.printDeck();
	if(userIn > 0 && userIn < 17){
	int amount = 52*userIn;
	cout << endl << "You should have " << amount  << " cards." << endl;
	cout << endl << "You have " << deck.deckCount() << " cards." << endl;
	}

	cout << "-------------------------------------------------------------------------------" << endl << endl;
}
