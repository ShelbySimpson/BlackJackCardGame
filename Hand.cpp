#include <iostream>
#include "Hand.h"
#include "Card.h"

using namespace std;

//Constructor
Hand::Hand(string assocDeck){
	_assocDeck = assocDeck;
}

int Hand::addCard(Card *card){
	int bSize =_hand.size();
	//Push card to _hand vector.
	_hand.push_back(card);
	int aSize = _hand.size();
	//Check to see that card was put into hand.
	if(bSize != aSize){
		return 1;
	}else{
		return 0;
	}
}

string Hand::getAssocDeck(){
	return _assocDeck;
}

void Hand::printHand(){
	if(_hand.empty()){
		cout << endl << "Empty Hand" << endl << endl;
	}else{
	//loop through vector to print all acards.
	for(int i =0; i<_hand.size(); i++){
		Card *card = _hand[i];
		card->printCard();
	}	
   }
}

//Get total point from card in hand.
int Hand::getHandTotal(){
	int vSize = _hand.size();
	//Card total points var
	int total = 0;
	for(int i=0; i<vSize; i++){
	//Determine if card is an ace high/low, face card or other.
	total += _hand[i]->getValue();
}	
	return total;
}

//Empty Hand/free vector elements.
void Hand::clearHand(){
	Card *card;
	int vSize = _hand.size();
	for(int i=0; i<vSize; i++){
		delete  _hand[i];
	}
		_hand.clear();
}

//Placeholder method for change ace.
int Hand::changeAceHandValue(int pos){
	if(pos > _hand.size() - 1){
		cout << endl << "Not a valid position, nothing was changed" << endl;
		return -1;
	}
	if(_hand[pos]->getValue() == 1 || _hand[pos]->getValue() == 11){
		_hand[pos]->changeAceValue();
	}else{
		cout << endl << "*** Card is not an Ace.*** " << endl;
	}
}

void Hand::printFirstCard(){
	_hand[0]->printCard();
}

