#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
class Hand;

class Player{
	public:
		//Constructor
		Player(std::string dkName);
		//Destructor
		~Player();
		//Set name of player
		void setName(std::string name);
		//Get name of player
		std::string getName();
		//hit, add one card to hand
		void hits(Card *card);
		//Decline to add cards
		void stays();
		//Print hand
		void printHand();
		//Get total of card in hand
		int getHandValue();
		//clear hand which frees up memory
		void clearHand();
		//Determine if player has busted.
		int getBust();
		//get stay value
		int getStays();
		//Reset bust
		void resetBust();
		//Reset stay
		void resetStay();
		//find ace in hand
		int findHighAce();
		//change ace value
		void changeAceValue(int pos);

	private: 
		
		std::string _name;//Name
		//Ptr for player's hand
		Hand myHand;
		
		int stay;
		int bust;
};		

#endif
