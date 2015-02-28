#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Deck.h"
#include "Card.h"

using namespace std;

//Constuctor. Param determines how many sets of cards you want in a deck.
Deck::Deck(int numSets, string name){
	_name = name;
	_numSets = numSets;
	if(numSets < 1 || numSets > 16){
		cout << "A deck can only have 1-16 sets of cards. Try Again!"<< endl;
		exit(1);
	}

	gatherCards();
}

Deck::~Deck(){
		disposeCards();
}

void Deck::gatherCards(){
	Card *card;
	//Create deck by putting cards into _deck vector.
	int finished = 0;
	while(finished != _numSets){
		for(int i=1; i<5; i++){
			for(int j=2; j<15; j++){
				card = new Card(j,i);
				_deck.push_back(card);
			}
		}
		finished++;
		}
}

void Deck::disposeCards(){
	int deckSize = _deck.size();
	for(int i = 0; i<deckSize; i++){
		delete  _deck[i];
	}
	_deck.clear();
}

//Shuffle deck.
void Deck::shuffleDeck(){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(_deck.begin(),_deck.end(),default_random_engine(seed));
}

int Deck::deckCount(){
	return _deck.size();
}

//Deal one card.
Card * Deck::dealOne(){
	Card *topCard = _deck.front();
	//For Now the Card will be removed from vector later on dealt cards
	//card will be dealt with by appropriate class.
	_deck.erase(_deck.begin());
	return topCard;
}

//Get name
string Deck::getName(){
	return _name;
}

//Prints every card in the deck.
void Deck::printDeck(){
	int dkSize = _deck.size();
	if (dkSize != 0){
	for(int i=0; i<dkSize; i++){
	_deck[i]->printCard();
	}
	}else{
		cout << endl << "Empty deck" << endl;
	}
}

