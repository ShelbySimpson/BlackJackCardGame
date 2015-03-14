#include "Dealer.h"

using namespace std;

//constructor
Dealer::Dealer(Deck *deck) :
		_deck(deck), hand(deck->getName()), _showHand(0), _bust(0) {
}

//destructor
Dealer::~Dealer(){
	_deck->disposeCards();
}

//deal card to players
Card *Dealer::dealOne() {
	return _deck->dealOne();
}

//deal card to dealer
void Dealer::dealOneSelf() {
	hand.addCard(_deck->dealOne());
}

//dealer hand value
int Dealer::getHandTotal(){
	return hand.getHandTotal();
}

//print cards in hand vector
void Dealer::printHand() {
	hand.printHand();
}

//clear hand vector
void Dealer::clearHand(){
	hand.clearHand();
}

//clear cards from deck vector
void Dealer::clearDeck(){
	_deck->disposeCards();
}

//get new unshuffled(ordered) deck.
void Dealer::newDeck(){
	_deck->gatherCards();
}

//Can either show first card or
//whole hand based on _showHand
void Dealer::showHand() {
	if (_showHand) {
		hand.printHand();
	} else {
		hand.printFirstCard();
	}

}

//shuffle
void Dealer::shuffleDeck(){
	_deck->shuffleDeck();
}

//deal dealer until bust or hand == 17 to 21
void Dealer::dealSelf(){
	setShowHand(1);
	while(hand.getHandTotal() < 17){
		dealOneSelf();
		if(hand.getHandTotal() > 21){
			_bust = 1;
		}
	}
}

//_showHand getter
int Dealer::getShowHand(){
	if(_showHand){
		return 1;
	}else{
		return 0;
	}
}

//_showHand setter
void Dealer::setShowHand(int tf){
	if(tf != 0 && tf != 1){
		cout << endl << "Error. Invalid Input." << endl;
	}
	_showHand = tf;
}

//_bust getter
int Dealer:: getBust(){
	return _bust;
}
//_bust setter
void Dealer::setBust(int tf){
	_bust = tf;
}

int Dealer::findHighAce(){
	int highAce = hand.findHighAce();
	return highAce;
}

void Dealer::changeAceValue(int pos){
	hand.changeAceHandValue(pos);
}

