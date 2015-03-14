#include "Card.h"
#include <iostream>

using namespace std;

//Card constructor sets the 3 card attributes.
Card::Card(int value, int suit){
	setValue(value);
	setSuit(suit);
	setName();
}

//Card destructor
Card::~Card(){
}


//Sets the value of the card, aces can be 1 or 14.
void Card::setValue(int value){
	if(value > 0 && value <= 14){
		_value = value;
	}else{
		//Error in value sets value as 0.
		_value = 0;
	}
}

//Changes value of an ace depending on other card. 1 to 14 or 14 to 1.
void Card::changeAceValue(){
	if(_value == 1){
		_value = 14;
	}else if(_value == 14){
		_value = 1;
	}else{
		cout << "error invalid value for an ace";
	}
}

//Depending on dealt suit value a suit name is given.
//When a deck is being created it will give each card a suit int value.
void Card::setSuit(int suit){


	switch(suit)
	{
		case 1 :
			_suit = "Heart"; 
			break;
		case 2 :
			_suit = "Diamond";
			break;
		case 3 :	
			_suit = "Club";
			break;
		case 4 :
			_suit = "Spade";
			break;
		default :
			_suit = "Invalid Suit";
	}

}

//Set name of card based on cards value. Ace can have value of 1 or 14.
void Card::setName(){

		switch(_value)
		{
			case 11 :
				_name = "Jack"; 
				break;
			case 12 :
				_name = "Queen";
				break;
			case 13 :	
				_name = "King";
				break;
			case 14 :	
				_name = "Ace";
				break;
			case 1 :
				_name = "Ace";
				break;
			case 2 :
				_name = "Two"; 
				break;
			case 3 :
				_name = "Three";
				break;
			case 4 :
				_name = "Four";
				break;
			case 5 :
				_name = "Five"; 
				break;
			case 6 :
				_name = "Six";
				break;
			case 7 :
				_name = "Seven";
				break;
			case 8 :
				_name = "Eight"; 
				break;
			case 9 :
				_name = "Nine";
				break;
			case 10 :
				_name = "Ten";
				break;
			default :
				_name = "Invalid Name";
		}
}	

//Get Value
int Card::getValue(){
	//Card total points var
	int total = 0;
	//Determine if card is an ace high/low, face card or other.
	if(_value < 10){
		total = _value;
	}else if(_value < 14){
		total = 10;
	}else{
		total = 11;
	}
	return total;
}

//get Suit
string Card::getSuit(){
	return _suit;
}
//get Name
string Card::getName(){
	return _name;
}

//Print card's value suit and name.
void Card::printCard(){
	if(_value != 0 && _suit != "Invalid Suit" && _name !="Invalid Name"){
		//cout << "Value: " << getValue() << " | Suit: " << _suit << " | Name: " << _name << endl;
		cout << _name << " of " << _suit << "s" << endl;
	}else{
		cout << "This card does not belong to the deck, dispose of it. Please recycle!!!" << endl;	
	}
}
