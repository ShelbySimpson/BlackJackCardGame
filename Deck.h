#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <string>

class Card;

class Deck{
	public:
		//Constructor
		//Param - sets of cards needed(52 in a set).
		Deck(int numSets, std::string name);
		//Destructor
		~Deck();	
		//Print a deck which can consist of more than one set of cards.
		void printDeck();

		//Random shuffle of the deck.		
		void shuffleDeck();
		
		//Deals one card off the top of the deck.
		Card * dealOne();
		
		//Amount of cards in a deck.
		int deckCount();

		//Get Name
		std::string getName();

		//Set up deck based on _numSets var
		void gatherCards();

		//clear card vector
		void disposeCards();

	private:
		
		//Vector to hold deck of cards.
		std::vector<Card *> _deck;
		
		//Deck name
		std::string _name;
		
		//number of sets in deck
		int _numSets;
};

#endif
