#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"


using namespace std;
Player::Player(Deck *deck,Hand *hand){
	//Name will be set after game determine num of players
	_name = "";
	myHand = hand;
	myDeck = deck;
	//No way to bust on first two cards so bust = 0.
	bust = 0;
	//Player will choose to stay
	stay = 0;
}

Player::~Player(){}
	


int Player::hits(){
	//add card and then determine if busted.
	myHand->addCard(myDeck->dealOne());
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


void Player::printHand(){
	myHand->printHand();
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
	myHand->clearHand();
}

int Player::getHandValue(){
	myHand->getHandTotal();
}

string Player::getName(){
	return _name;
}	

int Player::getStays(){
	return stay;
}
