#include <string>
class Deck;
class Hand;

class Player{
	public:
		//Constructor
		Player(Deck *deck,Hand *hand);
		//Destructor
		~Player();
		//Set name of player
		void setName(std::string name);
		//Get name of player
		std::string getName();
		//hit, add one card to hand
		int hits();
		//Decline to add cards
		void stays();
		//Print hand
		void printHand();
		//Get total of card in hand
		int getHandValue();
		//clear hand which free up memory
		void clearHand();
		//Determine if player has busted.
		int getBust();
		//get stay value
		int getStays();
		//Reset bust
		void resetBust();

	private: 
		
		std::string _name;//Name
		//Ptr for player's hand
		Hand *myHand;
		//Ptr for player's deck
		Deck *myDeck;
		
		int stay;
		int bust;
};		
