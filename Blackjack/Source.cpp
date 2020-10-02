#include <iostream>
#include "deck.h"
#include "Player.h"
#include "Blackjack.h"


int main()
{ 
	
	sf::RenderWindow window{ sf::VideoMode(1400, 900), "Blackjack", sf::Style::Close };
	window.setPosition(sf::Vector2i(250, 50));
	sf::Event event;
	Blackjack game;
		
	
	game.drawGameElements(window, Blackjack::noEffect);
	window.display();
	game.shuffleDeck();
	
	while (window.isOpen() && game.setBet(window))
	{
		game.drawGameElements(window, Blackjack::noEffect);
		window.display();
		game.startGame(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		game.reset(window);
		Gambler::resetPosition();
		Dealer::resetPosition();
	}
	if (window.isOpen())
		window.close();

	return 0;
}