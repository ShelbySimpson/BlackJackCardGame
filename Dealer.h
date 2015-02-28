#ifndef DEALER_H_
#define DEALER_H_

#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <string>

class Dealer{
    public:
    //Constructor-
    Dealer(Deck *deck);

    //destructor
    ~Dealer();

    //Deal One-
    Card *dealOne();

    //helper-
    void printHand();

    int getHandTotal();

    //dealer gets card-
    void dealOneSelf();

    //Dealer logic
    void dealSelf();

    //empty hand vector-
    void clearHand();

    //empty deck vector-
    void clearDeck();

    //Show either first card or all cards-
    void showHand();

    //create new cards for vector-
    void newDeck();

    //shuffle-
    void shuffleDeck();

    //change showHand var-
    int getShowHand();

    //return bust value-
    int getBust();

    //change hand visibility-
    void setShowHand(int tf);

    //change bust state-
    void setBust(int tf);

    private:

    //dealer's deck
    Deck *_deck;

    //show hand, init set to false
    int _showHand;

    //dealer's hand
    Hand hand;

    //bust
    int _bust;



};




#endif
