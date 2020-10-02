#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "Entity.h"
#include <iostream>
#include <stdlib.h>
#include <array>


class Player
{
protected:
	static sf::Vector2f m_cardImageScale;

	std::array<Card, 10> m_myCards;
	int m_nbOfCards;
	int m_valueOfCards;
public:
	Player();
	int getValueOfCards() { return m_valueOfCards; }
	int getTheLastCardValue() { return m_myCards.at(m_nbOfCards-1).getCardValue(); }
	void setValueOfCards(int i) { m_valueOfCards -= i; }
	virtual void getACard(Deck&);
	void drawMyCards(sf::RenderWindow&);
	void reset();
	friend std::ostream& operator<< (std::ostream&, Player);
};


class Dealer : public Player
{
private:
	static sf::Vector2f m_cardImagePosition;
public:
	Dealer();
	virtual void getACard(Deck&);
	static void resetPosition();
};


const int g_numberOfBets = 10;
class Gambler : public Player
{
private:
	static sf::Vector2f m_cardImagePosition;

	int m_money;
	int m_betChoices[g_numberOfBets];
	int m_currentBet;
public:
	Gambler();
	static void resetPosition();
	void setMoney(int money) { m_money = money; }
	int getMoney() { return m_money; }
	int getBet() { return m_currentBet; }
	void doubleBet(){ m_currentBet *= 2; }
	int* getBetChoises(){ return m_betChoices; }
	void setBet(char);
	void setBet(int i) { m_currentBet = m_betChoices[i]; }
	virtual void getACard(Deck&);
	
	
	friend std::ostream& operator<< (std::ostream&, Gambler);
};



#endif // !PLAYER_H
