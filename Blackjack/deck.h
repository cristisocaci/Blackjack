#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Entity.h"
#include <array>

class Card
{
public:
	enum cardRank
	{
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE
	};
	enum cardSuits
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};
private:
	cardSuits m_suits;
	cardRank m_rank;
	Entity m_cardImage;

public:
	Card() {};
	Card(const char*);
	int getCardValue();
	Entity& getCardImg();

	Card& operator= (Card&);
	friend std::ostream& operator<< (std::ostream&, Card);
	friend class Deck;
	
};

class Deck
{
private:	
	std::array<Card, 52> m_cards;
	int m_cutCard;
	int m_topCard;
public:
	
	Deck();
	Card& pickCard();
	int random();
	int getCutCard() { return m_cutCard; }
	int getTopCard() { return m_topCard; }
	void newCutCard();
	void resetTopCard() { m_topCard = 0; }
	void printDeck();
	void swap(int, int);
	void shuffle();

	Card& operator [] (int);
	
};

#endif
