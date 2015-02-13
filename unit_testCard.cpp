#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"
#include <string>

using namespace std;


int main(){
  
  	//Test to check both setValue(), setName  and setSuit() work together. They all  called in the Card constructor.	
	cout << "Test: setValue(), setName(), setSuit()."  << endl << "Test should print every card possible, including Aces high and low." << endl << endl;
	for(int i=1; i < 5; i++){
		for(int j=1; j<=14; j++){
			Card card(j,i);
			card.printCard();
		}
	}
	

	
	cout << endl << "---------------------------------------------------------------------" << endl;
	//TEST setValue(): 
	//Test good and bad intputs.
	//Values should only  be 1 to 13.
	cout << "***Test: setValue() (which also tests setName()) from -4 to 18. Suit is constant at 2(Diamond).***" << endl << endl;	
	for(int i = -4; i <= 18; i++){
			Card card(i,2);
			card.printCard();
	}	
	
	cout << "---------------------------------------------------------------------" << endl;
	//TEST setSuit(): 
	//Test good and bad intputs.
	//Suits should only  be 1 to 4.
	cout << "***Test: setSuit() from -4 to 8. Value is constant at two.***" << endl << endl;	
	for(int i = -4; i <= 8; i++){
			Card card(2,i);
			card.printCard();
	}
	
		
	cout << "---------------------------------------------------------------------" << endl;
	
	cout << "***Test: getValue() from -4 to 18***" << endl << endl;
	for(int i = -4; i <= 18; i++){
			Card card(i,4);
			int cardV = card.getValue();
			if(cardV != 0){
				cout << "getValue(): " << cardV << endl;
		}else{
				cout << "Not a valid value for a blackjack card, dispose of it. Please recycle." << endl;
		}
				
	}

	
	cout << "---------------------------------------------------------------------" << endl;
	cout << "***Test: getSuit() from -4 to 8***" << endl << endl;
	for(int i = -4; i <= 8; i++){
			Card card(4,i);
			string cardSu = card.getSuit();
			if(cardSu != "Invalid Suit"){
				cout << "getSuit(): " << cardSu << endl;
		}else{
				cout << "Not a valid suit for a blackjack card, dispose of it. Please recycle." << endl;
		}
				
	}

	
	cout << "---------------------------------------------------------------------" << endl;
	cout << "***Test: getName() from -4 to 18***" << endl << endl;
	for(int i = -4; i <= 18; i++){
			Card card(i,3);
			string cardNa = card.getName();
			if(cardNa != "Invalid Name"){
				cout << "getName(): " << cardNa << endl;
		}else{
				cout << "Not a valid name for a blackjack card, dispose of it. Please recycle." << endl;
		}
				
	}

	
		
	cout << "---------------------------------------------------------------------" << endl;
	cout << "***Test: changeAceValue() Changes value 1 to 11 or 11 to 1.***" << endl << endl;
	Card cardOne(1,2);
	cout << "Ace value 1 changes to 11 - " << endl;
	cout << cardOne.getValue() << endl;
	cardOne.changeAceValue();
	cout << cardOne.getValue() << endl;

	
	cout << "Ace value 11 changes to 1 - " << endl;
	cout << cardOne.getValue() << endl;
	cardOne.changeAceValue();
	cout << cardOne.getValue() << endl;

	cout << "---------------------------------------------------------------------" << endl << endl;










}

	
