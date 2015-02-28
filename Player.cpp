#include <iostream>
#include <string>
#include "Player.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

Player::Player(string dkName)
	: _name(""), myHand(dkName),bust(0),stay(0)
		{}

Player::~Player(){}
	


void Player::hits(Card *card){
	//add card and then determine if busted.
	myHand.addCard(card);
	if(getHandValue()  > 21){
		bust = 1;
	}	
}

void Player::stays(){
	stay = 1;
}

int Player::getBust(){
	return bust;
}

void Player::resetBust(){
	bust = 0;
}

void Player::resetStay(){
	stay = 0;
}

void Player::printHand(){
	myHand.printHand();
}

void Player::setName(string name){
	//Not allowing more then ten chars for a name
	//Need output to be readable.
	if(name.length() < 11 && name.length() > 0){
		_name = name;
	}else{
		cout << endl << "Name is too long, ten characters is the limit." << endl;
	}

	
}

void Player::clearHand(){
	myHand.clearHand();
}

int Player::getHandValue(){
	myHand.getHandTotal();
}

string Player::getName(){
	return _name;
}	

int Player::getStays(){
	return stay;
}
