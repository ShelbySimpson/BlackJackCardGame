#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

int main(){
	Deck deck(1,"deck");
	Deck *deckptr = &deck;
	Hand hand("deck");
	Hand *handptr = &hand;
	Player player = Player(deckptr,handptr);

	cout << endl << "*** Test Constructor ***" << endl;
	cout << endl << "---- stay and bust should = 0,name = empty" << endl;
	cout << endl << "getName() - " << player.getName() << endl;
	cout << endl << "getBust() - " << player.getBust() << endl;
	cout << endl << "getStay() - " << player.getStays() << endl;	

	cout << endl << "*** Test setName(),getName ***" << endl;
	cout << endl << "-----Name the player Shelby  then  getName()------" << endl;
	player.setName("Shelby");
	cout << endl << "Player's name is - " << player.getName() << endl;

	cout << endl << "----Name the player supercalifragic to check that names over 10 chars are not allowed. ----" << endl;
	player.setName("supercalifragic");
	cout << endl;
	
	cout << endl << "The rest of the functions in this class will be tested with integration testing due to how" << endl;
	cout << "the functions work with the rest of the classes." << endl << endl;
	
}
