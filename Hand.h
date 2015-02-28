#ifndef HAND_H
#define HAND_H

#include <vector> 
#include <string>

class Card;

class Hand{
	public:
		//Contructor.
		Hand(std::string assocDeck);
		//Returns 0 if card was not added, 1 if it was added.
		int addCard(Card *card);
		//Print cards in _hand vector.
		void printHand();
		int getHandTotal();

		//print top card
		void printFirstCard();

		//Clears cards out of _hand vector.
		void clearHand();

		//get deck associated to hand.
		std::string getAssocDeck();

		//temp placeholder
		int changeAceHandValue(int pos);

	private:
		//Associated deck
		std::string _assocDeck;
		//Vector to hold hand.
		std::vector<Card *>_hand;
};

#endif
