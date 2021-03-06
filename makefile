all:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp Dealer.h Dealer.cpp Game.h Game.cpp gameUnit.cpp -o gameUnit
unitCard:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp unit_testCard.cpp -o unitCard
integ1:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp integration_test1.cpp -o integ1
integ2:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp integration_test2.cpp -o integ2
integ3:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp playerInteg.cpp -o integ3 
unitPlayer:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp unitPlayer.cpp -o unitPlayer 
dealerInteg:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp Dealer.h Dealer.cpp dealerInteg.cpp -o dealerInteg
unitDealer:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp Dealer.h Dealer.cpp unitDealerTest.cpp -o unitDealer
testLogic:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp Dealer.h Dealer.cpp test_logic.cpp -o testLogic
gameUnit:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp Dealer.h Dealer.cpp Game.h Game.cpp gameUnit.cpp -o gameUnit
clean:
	rm -rf *o integ1 integ2 unitCard integ3 unitPlayer testDeal dealerInteg unitDealer gameUnit a.out 
