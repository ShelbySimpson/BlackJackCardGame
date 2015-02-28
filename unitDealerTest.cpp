#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"


using namespace std;

int main(){
  int start = 0;
  Deck deck = Deck(1,"aDeck");
  Deck *dptr = &deck;
  Dealer dealer = Dealer(dptr);
  Player player = Player("aDeck");
  Card *card;

  //test shuffleDeck(). A test to see that the deck has been shuffled, so a unshuffled deck is printed and then shuffled and printed.
  cout << endl << "Test shuffleDeck(),clearDeck(). Order - print, shuffle, print" << endl;
  cout << endl << "Press 1 to start testing - " << endl;
  cin >> start;
  deck.printDeck();
  dealer.shuffleDeck();
  deck.printDeck();
  cout << endl << "-----shuffleDeck() test finished--------------------------" << endl;

  //Test clearHand(), getHandTotal().  deal cards then print, get total, clear hand and print again.
  cout << endl << "****Test dealOneSelf() and clearHand(). Order - deal one, deal another, print hand, clear hand, print hand****" << endl;
  cout << endl << "Press 1 to start next test - " << endl;
  cin >> start;
  dealer.dealOneSelf();
  dealer.dealOneSelf();
  dealer.printHand();
  cout << endl << "Get hand total - " << dealer.getHandTotal() << endl;
  dealer.clearHand();
  cout << endl << "Hand has been cleared  - ";
  dealer.printHand();
  cout << endl << "-----dealOneSelf(), clearHand() test finished -----------------" << endl;

  //Test dealOne()
  cout << endl << "****Test dealOne(). Order - deal one, print card, deal another, print card****" << endl;
  cout << endl << "Press 1 to start next test - " << endl;
  cin >> start;
  Card *cardOne = dealer.dealOne();
  cout << endl << "Card 1 - " << endl;
  cardOne->printCard();
  Card *cardTwo = dealer.dealOne();
  cout << endl << "Card 2 - " << endl;
  cardTwo->printCard();
  cout << "------ dealOne() test finished------" << endl;

  //Test showHand(), show hand will only show first card if _showHand value is 0 and all cards if 1.
  //Test by print before and after the _showHand var has been changed.
  cout << endl << "****Test showHand(). Order - deal dealer 4 cards, show hand, change show hand value, show hand****" << endl;
  cout << endl << "Press 1 to start next test - " << endl;
  cin >> start;
  dealer.dealOneSelf();
  dealer.dealOneSelf();
  dealer.dealOneSelf();
  dealer.dealOneSelf();
  cout << endl << "Should just show first card - " << endl;
  dealer.showHand();
  dealer.setShowHand(1);
  cout << endl << "Should show entire hand(4 cards) - " << endl;
  dealer.showHand();
  cout << endl << "---------test showHand() finished--------------------------------------" << endl;

  //Test clearDeck(), newDeck(). Print after each use of function to ensure they are working correctly
  cout << endl << "****Test clearDeck(),newDeck(). Order - print deck, clear deck, print deck, new deck, print deck****" << endl;
  cout << endl << "Press 1 to start next test - " << endl;
  cin >> start;
  cout << endl << "Print deck - " << endl;
  deck.printDeck();
  cout << endl << "Clear deck and print deck to check if empty - " << endl;
  dealer.clearDeck();
  deck.printDeck();
  cout << endl << "make a new deck and print - " << endl;
  dealer.newDeck();
  deck.printDeck();

  //Test getters and setters by setting them and then calling the getters with cout << ...
  cout << endl << "****Test setBust(),getBust(),setShowhand(),getShowHand()****" << endl;
  cout << "Order - set _bust, print,set _bust, print, set _showHand, print, set _showHand, print" << endl;
  cout << endl << "Press 1 to start next test - " << endl;
  cin >> start;
  dealer.setBust(0);
  cout << "_bust should be 0 - " << dealer.getBust() << endl;
  dealer.setBust(1);
  cout<< "_bust should be 1 - " << dealer.getBust() << endl;
  dealer.setShowHand(1);
  cout << endl << "_showHand should be 1 - " << dealer.getShowHand() << endl;
  dealer.setShowHand(0);
  cout << endl << "_showHand should be 0 - " << dealer.getShowHand() << endl;
















}
