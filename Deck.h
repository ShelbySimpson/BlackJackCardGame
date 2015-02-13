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

	private:
		
		//Vector to hold deck of cards.
		std::vector<Card *> _deck;
		
		//Deck name
		std::string _name;
		
};
