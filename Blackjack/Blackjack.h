#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "deck.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>


class Blackjack
{
public:
	enum EffectStatus
	{
		standEffect,
		hitEffect,
		doubleEffect,
		noEffect
	};
private:
	Deck m_deck;
	Gambler m_gambler;
	Dealer m_dealer;

	Entity m_background;
	Entity m_dealerPays;
	Entity m_nbOfCardsLogo;
	TextEntity m_dealerPoints;
	TextEntity m_gamblerPoints;
	TextEntity m_bank;
	TextEntity m_nbOfCards;
	Button m_stand;
	Button m_hit;
	Button m_double_;
	bool m_status;

public:
	Blackjack();

	void startGame(sf::RenderWindow&);
	bool setBet(sf::RenderWindow&);
	void shuffleDeck();
	void drawGameElements(sf::RenderWindow&, EffectStatus);
	void reset(sf::RenderWindow&);

private:
	void drawBetElements(sf::RenderWindow&, Entity&, TextButton*);
	bool checkMoney(sf::RenderWindow&, Entity&, TextButton*);
	bool checkMouseEvent(sf::RenderWindow&, sf::Vector2f, TextButton*, Entity&);
	void stand(sf::RenderWindow&);
	bool hit(sf::RenderWindow&);
	void double_(sf::RenderWindow&);
	void dealerHit(sf::RenderWindow&);
	void bust();
	void win(sf::RenderWindow&);
	void push(sf::RenderWindow&);
	void blackjack(sf::RenderWindow&);
	void gameSetup(sf::RenderWindow&);
};

#endif
