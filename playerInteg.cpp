#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

int main(){
	Deck deck(1,"deck");
	Deck *deckptr = &deck;
	Hand hand("deck");
	Hand *handptr = &hand;
	Player player(deckptr,handptr);
	player.setName("Shelby");
	deck.shuffleDeck();

	cout << endl << "*** Test printHand() and getValue ***" << endl;
	cout << endl << "Hand - "<< endl; 
	player.hits();
	player.hits();
	player.printHand();
	cout << endl << "Value of hand - " << player.getHandValue()<< endl;

	cout << endl << "*** Test to see if hand busts ***" << endl; 
	while(player.getBust() != 1){
		player.hits();
		player.printHand();
		deck.shuffleDeck();
		cout << "Hand value - " << player.getHandValue() << " Bust status - " << player.getBust() << endl << endl;
	}
	
	cout << "*** Test clear() ***" << endl;
	cout << "Print current hand, clear hand, print hand, add a card and print hand again" << endl << endl;
	player.printHand();	
	player.clearHand();
	player.printHand();
	player.hits();
	player.printHand();
	cout << endl;

	cout << endl << "*** Test stay() ***" << endl;
	cout << endl << "Chose a number between 15-19 to stay() on" << endl;
	Deck deck2(16,"deck2");
	Deck *deckptr2 = &deck2;
	Hand hand2("deck2");
	Hand *handptr2 = &hand2;
	Player player2(deckptr2,handptr2);
	player2.setName("Shelby");
	deck2.shuffleDeck();
	int pstay = 0;
	int stay;
	cin >> stay;
	while(stay != pstay){
		player2.hits();
		player2.hits();
		cout << "Two cards dealt, hand value - " << player2.getHandValue() << endl;
	while(!player2.getBust() || player.getStays() == 1){
		if(player2.getHandValue() == stay){
			player2.stays();
			pstay = stay;
			cout << endl << "stay status - " << player2.getStays() << endl << endl;
			break;
		}
		player2.hits();
		cout << "hit, get value - " << player2.getHandValue() << endl;
	}
		player2.resetBust();
		player2.clearHand();
	}

	cout << endl << "--------------------------- Test Multiple players ----------------------------------------" << endl;
	cout << endl << "Shelby, Bob and Annie are going to play together - " << endl;
	Deck mDeck(1,"mDeck");
	Deck *mDptr = &mDeck;
	Hand Shelbyh("mDeck");
	Hand bobh("mDeck");
	Hand annieh("mDeck");
	Hand *sHptr = &Shelbyh;
	Hand *bHptr = &bobh;
	Hand *aHptr = &annieh;
	Player shelby = Player(mDptr,sHptr); 
	Player bob = Player(mDptr,bHptr);
	Player annie = Player(mDptr,aHptr);

	mDeck.shuffleDeck();
	cout << endl << "Shelby dealt two cards - " << endl;
	shelby.hits();
	shelby.hits();
	shelby.printHand();
	cout << endl << "hits() printHand() - " << endl;	
	shelby.hits();
	shelby.printHand();
	if(shelby.getBust()){
		cout << "You have busted!" << endl;
	}
	cout << endl << "Bob - " << endl;
	bob.hits();
	bob.hits();
	bob.printHand();
	cout << endl << "hits() printHand() - " << endl;	
	bob.hits();
	bob.printHand();
	if(bob.getBust()){
		cout << endl << "You have busted!" << endl;
	}
	cout << endl << "Annie - " << endl;
	annie.hits();
	annie.hits();
	annie.printHand();
	cout << endl << "hits() printHand() - " << endl;	
	annie.hits();
	annie.printHand();
	if(annie.getBust()){
		cout << endl << "You have busted!" << endl;
	}
	cout << endl << "Print Deck to show that all players are playing from the same deck - " << endl;
	mDeck.printDeck();

	cout << endl << "------------------------- 5 card Charlie probability ----------------------------------------" << endl;
	Deck chDeck(16,"chDeck");
	chDeck.shuffleDeck();
	Hand chHand("chDeck");
	Hand *chHptr = &chHand;
	Deck *chDptr = &chDeck;
	Player charlie(chDptr,chHptr);
	int counter = 0;
	
	for(int i=0; i<830; i= i+5){
		cout << "i value - " << i << endl;
		charlie.hits();
		charlie.hits();
		charlie.hits();
		charlie.hits();
		charlie.hits();
		cout << endl << "Check for 5 card charlie - " << endl;
		if(!charlie.getBust()){
			cout << endl << "****Five Card Charlie!!!***" << endl;
			charlie.printHand();
			charlie.clearHand();
			counter++;
			charlie.resetBust();
		}else{
			cout << "Busted" << endl << endl;
			charlie.printHand();
			charlie.clearHand();
			charlie.resetBust();
		}
		
	}
		int cPercent = (counter * 100) / (166);
		cout << endl << "You played 166 hands and had  " << counter << " five card charlies" << endl;
		cout << endl << "Probability was - " << cPercent << " percent" << endl;


		cout << endl << "------------------------- Blackjack Probability ----------------------------------------" << endl;
		int wait = 0;
		cout << endl << "Hit 1 to begin Blackjack Probability" << endl;
		cin >> wait;
		Deck bkjDeck(16,"bkjDeck");
		bkjDeck.shuffleDeck();
		Hand bkjHand("bkjDeck");
		Hand *bkjHptr = &bkjHand;
		Deck *bkjDptr = &bkjDeck;
		Player blackjack(bkjDptr,bkjHptr);
		int counter2 = 0;
		
		for(int i=0; i<832; i=i+2){
			blackjack.hits();
			blackjack.hits();
			if(blackjack.getHandValue() == 21){
				cout << endl << "****Black jack!!!****" << endl;
				blackjack.printHand();
				blackjack.clearHand();
				counter2++;
			}else{
				cout << endl << "No 21, Try Again" << endl;
				blackjack.printHand();
				blackjack.clearHand();
				
			}
		}
			int cPercent2 = (counter2 * 100) / (416);
			cout << endl << "You played 416 hands and  had " << counter2 << " blackjacks" << endl;
			cout << endl << "Probability was " << cPercent2 << " percent" << endl;

}
