all:
	g++ -Wextra -pedantic -std=c++11 Card.h Card.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp playerInteg.cpp -o integ3 
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
clean:
	rm -rf *o integ1 integ2 unitCard integ3 unitPlayer a.out 
