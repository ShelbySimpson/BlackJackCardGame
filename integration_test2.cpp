#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
using namespace std;

int main(){

	cout << "These tests end up also testing the interaction between the deck,card and hand class." << endl;
	cout << endl << "--------------------------------------------Test addCard() ------------------------------------------------ " << endl;

	Deck aDeck(1,"aDeck");
	cout << endl << "Test getName(),(aDeck) - " << endl; 
	cout << endl << "This is the deck name - " << aDeck.getName() << endl;

	aDeck.shuffleDeck();
	Hand aHand("aDeck");


	cout << endl << "Deal Card(hand count 1), print hand and shuffle deck." << endl;
	if(aHand.addCard(aDeck.dealOne())){
	aHand.printHand();
	aDeck.shuffleDeck();
	}else{
		cout << endl << "Card was not added to hand " << endl;
	}
	cout << endl << "Deal Card(hand count 2), print hand and shuffle deck." << endl;
	if(aHand.addCard(aDeck.dealOne())){
	aHand.printHand();
	aDeck.shuffleDeck();
	}else{
		cout << endl << "Card was not added to hand " << endl;
	}
	cout << endl << "Deal Card(hand count 3), print hand and shuffle deck." << endl;
	if(aHand.addCard(aDeck.dealOne())){
	aHand.printHand();
	aDeck.shuffleDeck();
	}else{
		cout << endl << "Card was not added to hand " << endl;
	}
	cout << endl << "Deal Card(hand count 4), print hand and shuffle deck." << endl;
	if(aHand.addCard(aDeck.dealOne())){
	aHand.printHand();
	aDeck.shuffleDeck();
	}else{
		cout << endl << "Card was not added to hand " << endl;
	}
	cout << endl << "Deal Card(hand count 5), print hand and shuffle deck." << endl;
	if(aHand.addCard(aDeck.dealOne())){
	aHand.printHand();
	aDeck.shuffleDeck();
	}else{
		cout << endl << "Card was not added to hand " << endl;
	}
		int position;
		cout << endl << "---------------Test changeAceHandValue() ------------------------------------" << endl;
		cout << endl << "If hand contains an Ace you can change value by position. From left right(top to bottom) 0,1,2,... " << endl; 
		cin >> position;
		aHand.changeAceHandValue(position);
		cout << endl << "Changed hand value then printHand() and getHandTotal()- " << endl;
		aHand.printHand();
		cout << endl << "Total - " << aHand.getHandTotal() << endl;
		cout << endl << "-------------------------------- Test getHandTotal() -------------------------------------------------" << endl;
		cout << endl << " This test also tests interaction between the card, deck and the hand class." << endl;
		cout << endl << "Deal 2nd hand - " << endl;
		Hand hand2("aDeck");
		cout << endl << "Test assocDeck(), hand 2 should be associated to aDeck - " << endl;
		cout << hand2.getAssocDeck() << endl << endl;
		cout << endl << "Test 2nd hand from the same deck. Deal 5 print 2nd hand get hand total and shuffle." << endl;
		for(int i = 0; i<5; i++){
			hand2.addCard(aDeck.dealOne());
		}
		hand2.printHand();
		cout << endl << "Card total from hand 2 - " << endl;
		int handTotal = hand2.getHandTotal();
		cout << handTotal << endl;
		aDeck.shuffleDeck();

		Hand hand3("aDeck");
		cout << endl << "Test assocDeck(), hand 3 is associated to aDeck - " << endl;
		cout << hand3.getAssocDeck() << endl << endl;
		cout << endl << "Deal a 3rd hand with five cards, print it out and get total - " << endl; 
		for(int i = 0; i<5; i++){
			hand3.addCard(aDeck.dealOne());
		}
		int handTotal3 = hand3.getHandTotal();
		cout << "Hand 3 - " << endl;
		hand3.printHand();
		cout << endl << "Card total from hand 3 - " << endl;
		cout << handTotal3 << endl;
		aDeck.shuffleDeck();
		cout << endl << "Print deck. Deck has been dealt 3 hands 5 cards each. Deck card count should be 37 " << endl;
		aDeck.printDeck();

		cout << endl << "------------------------- Test clearHand() and for Memory leaks----------------------------------------" << endl;
		cout << "This test also tests interaction between the card, deck and hand classes." << endl;
		cout << endl << "Clear hand 3, print hand 3, and shuffle - ";
		hand3.clearHand();
		hand3.printHand();
		aDeck.shuffleDeck();
		
		cout << endl << "Add a card to hand 3 and then print hand 3 - " << endl;
		hand3.addCard(aDeck.dealOne());
		hand3.printHand();
		cout << endl << "Print Deck, cards in deck should be 36 - " << endl;
		aDeck.printDeck();

		cout << endl << "------------------------------------Probability --------------------------------------- " << endl;
		
		cout << endl << "Choose the number of sets you would like to use in test.\nThe number entered will be the amount of sets in the deck for both blackjack and 5 Card Charlie tests - " << endl;
		int numSets;
		cin >> numSets;
		cout << endl << "Build deck,shuffle, build hand, deal cards, print hand - " << endl;
		Deck pDeck(numSets, "pDeck");
		pDeck.shuffleDeck();
		cout << endl << "Test getName(),(pDeck) - " << endl; 
		cout << endl << "This is the deck name - " << pDeck.getName() << endl;
		Card *card;
		int counter = 0;
		cout << endl << "Blackjack probability - " << endl;
		int deals = (numSets * 52) / 2;
		//Deal 2 cards until deck is empty
		for(int i = 0; i < deals; i++){
			cout << endl << "Hand - " << endl;
			int total = 0;
			card = pDeck.dealOne();
			card->printCard();
			total += card->getValue();
			card = pDeck.dealOne();
			card->printCard();
			total += card->getValue();
			
			if(total == 21){
				counter++;
				cout << "****Blackjack****" << endl;
			}
		}
			int numHands = numSets/2;
			int percent = (counter * 100) / (26 * numSets);
			cout << endl << "You had - " << counter << " blackjacks" << endl;
			cout << endl << "You played " << (numSets*52)/2 << " hands. You had a blackjack aproximately " << percent << " percent of the time." << endl;
		cout << endl << "--------------------------------------------------------------------------------------------------------" << endl;	
		cout << endl << "Probability, 5 card Charlie. Test probability and changeAceValue - " << endl << endl;
		cout << endl << "By default aces are high, to make aces low enter 1, else hit any key to continue - " << endl;
		Deck pDeck2(numSets, "pDeck2");
		cout << endl << "Test getName(),(pDeck2) - " << endl; 
		cout << endl << "This is the deck name - " << pDeck2.getName() << endl;
		pDeck2.shuffleDeck();	
		int aceVal = 0;
		cin >> aceVal;
		int bustCounter = 0;
			int deal5 = (numSets * 52 / 5);
		//Deal 5 cards until deck is empty
		for(int i = 0; i < deal5; i++){
			int total2 = 0;
			card = pDeck2.dealOne();
			if(aceVal == 1 && (card->getValue() == 1 || card->getValue() == 11)){
				card->changeAceValue();
			}
			total2 += card->getValue();	
			card->printCard();
			card = pDeck2.dealOne();
			if(aceVal == 1 && (card->getValue() == 1 || card->getValue() == 11)){
				card->changeAceValue();
			}
			total2 += card->getValue();	
			card->printCard();
			card = pDeck2.dealOne();
			if(aceVal == 1 && (card->getValue() == 1 || card->getValue() == 11)){
				card->changeAceValue();
			}
			total2 += card->getValue();	
			card->printCard();
			card = pDeck2.dealOne();
			if(aceVal == 1 && (card->getValue() == 1 || card->getValue() == 11)){
				card->changeAceValue();
			}
			total2 += card->getValue();	
			card->printCard();
			card = pDeck2.dealOne();
			if(aceVal == 1 && (card->getValue() == 1 || card->getValue() == 11)){
				card->changeAceValue();
			}
			total2 += card->getValue();	
			card->printCard();
			
			if(total2 > 21){
				bustCounter++;
				cout << endl << "You Busted! Bust count - " << bustCounter << endl << endl;
			}else{
				cout << endl << " ********You did not bust********" << endl << endl;
				}

		}
			
			string highLow;
			if(aceVal == 1){
				highLow = "low";	
			}else{
				highLow = "high";
			}
			int cPercent = (bustCounter * 100) / ((numSets * 52)/5);
			cout << endl << "You played " << (numSets *52)/5 << " hands and busted on " << bustCounter << " of them." << endl;
			cout << "With aces " << highLow << " you busted aproximately " << cPercent << " percent of the time" << endl << endl;


		cout << endl;
}
