#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card{
	public:
		//Constructor
		Card(int value, int suit); 

		//Destructor		
		~Card();
		
		//Change Value for Ace depending on other card
		void changeAceValue();

		// 4 suits heart,diamonds,spades,clubs
		std::string  getSuit();

		//Values 1 to 14. Ace would be one and King would be 13.
		int  getValue();

		//Get Name of Card. Ace,One Two... King
		std::string getName();		
	
		//Shows cards' suit, value and name.
		void printCard();

	private:
		std::string _name; //example - king or  queen
		std::string _suit; //card's suit
		int _value; //card's value
		
		void setName();	//Set the name of Card
		void setSuit(int suit); //set Card's suit
		void setValue(int value); //Set Card's value
};

#endif
