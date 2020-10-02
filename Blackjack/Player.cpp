#include "Player.h"


Player::Player() : m_myCards{}, m_nbOfCards{ 0 }, m_valueOfCards{0}
{
}

sf::Vector2f Player::m_cardImageScale = sf::Vector2f(0.25f, 0.25f);

void Player::getACard(Deck& d)
{
}

void Player::drawMyCards(sf::RenderWindow& w)
{
	for (int i{ 0 }; i < m_nbOfCards; i++)
		m_myCards.at(i).getCardImg().drawEntity(w);
}

void Player::reset()
{
	m_nbOfCards = 0;
	m_valueOfCards = 0;
}

std::ostream& operator<< (std::ostream& out, Player p)
{
	if (p.m_nbOfCards == 0)
	{
		std::cout << "empty";
		return out;
	}
	else
	{
		for (int i{ 0 }; i < p.m_nbOfCards; i++)
			out << p.m_myCards.at(i) << std::endl;
		return out;
	}
}

Gambler::Gambler() : Player(), m_money{ 1000 }, m_betChoices{ 10,20,30,50,70,100,250,500,750,1000 }, m_currentBet{ m_betChoices[0] }
{
}
sf::Vector2f Gambler::m_cardImagePosition = sf::Vector2f(600.f, 600.f);

void Gambler::resetPosition()
{
	m_cardImagePosition = sf::Vector2f(600.f, 600.f);
}

void Gambler::setBet(char type)
{
	static int count{ 0 };
	if (type == '+')
	{
		if (m_currentBet == m_betChoices[g_numberOfBets - 1])
		{
			count = 0;
			m_currentBet = m_betChoices[count];
		}
		else
			m_currentBet = m_betChoices[++count];
	}
	else if (type == '-')
	{
		if (m_currentBet == m_betChoices[0])
		{
			count = g_numberOfBets - 1;
			m_currentBet = m_betChoices[count];
		}
		else
			m_currentBet = m_betChoices[--count];
	}
}



void Gambler::getACard(Deck& d)
{
	m_myCards.at(m_nbOfCards) = d.pickCard();
	m_valueOfCards += m_myCards.at(m_nbOfCards).getCardValue();
	m_myCards.at(m_nbOfCards).getCardImg().setScale(m_cardImageScale);
	if (m_nbOfCards != 0)
	{
		m_cardImagePosition += sf::Vector2f(25.f, 0.f);
		m_myCards.at(m_nbOfCards).getCardImg().setPosition(m_cardImagePosition);
		for (int i{ 1 }; i <= m_nbOfCards; i++)
			m_myCards.at(m_nbOfCards - i).getCardImg().move(sf::Vector2f(-25.f, 0.f));
	}
	else
		m_myCards.at(m_nbOfCards).getCardImg().setPosition(m_cardImagePosition);
	++m_nbOfCards;
}


std::ostream& operator<< (std::ostream &out, Gambler p)
{
	out << "money: " << p.m_money << " bet: " << p.m_currentBet;
	return out;
}


Dealer::Dealer() : Player()
{
}

sf::Vector2f Dealer::m_cardImagePosition = sf::Vector2f(600.f, 50.f);
void Dealer::resetPosition()
{
	m_cardImagePosition = sf::Vector2f(600.f, 50.f);
}

void Dealer::getACard(Deck& d)
{
	m_myCards.at(m_nbOfCards) = d.pickCard();
	m_valueOfCards += m_myCards.at(m_nbOfCards).getCardValue();
	m_myCards.at(m_nbOfCards).getCardImg().setScale(m_cardImageScale);
	if (m_nbOfCards != 0)
	{
		m_cardImagePosition += sf::Vector2f(25.f, 0.f);
		m_myCards.at(m_nbOfCards).getCardImg().setPosition(m_cardImagePosition);
		for (int i{ 1 }; i <= m_nbOfCards; i++)
			m_myCards.at(m_nbOfCards - i).getCardImg().move(sf::Vector2f(-25.f, 0.f));
	}
	else
		m_myCards.at(m_nbOfCards).getCardImg().setPosition(m_cardImagePosition);
	++m_nbOfCards;
}