#include "deck.h"

Card::Card(const char* s) : m_cardImage(s)
{
}


int Card::getCardValue()
{
	switch (m_rank)
	{
	case Card::TWO:		return 2;
	case Card::THREE:	return 3;
	case Card::FOUR:	return 4;
	case Card::FIVE:	return 5;
	case Card::SIX:		return 6;
	case Card::SEVEN:	return 7;
	case Card::EIGHT:	return 8;
	case Card::NINE:	return 9;
	case Card::TEN:
	case Card::JACK:
	case Card::QUEEN:
	case Card::KING:
						return 10;
	case Card::ACE:		return 11;
	default:			return -1;

	}
}

Entity& Card::getCardImg()
{
	return m_cardImage;
}
std::ostream& operator<< (std::ostream& out, Card c)
{
	switch (c.m_suits)
	{
	case Card::CLUBS:
		out << "suits: CLUBS, rank: " << c.m_rank;
		break;
	case Card::DIAMONDS:
		out << "suits: DIAMONDS, rank: " << c.m_rank;
		break;
	case Card::HEARTS:
		out << "suits: HEARTS, rank: " << c.m_rank;
		break;
	case Card::SPADES:
		out << "suits: SPADES, rank: " << c.m_rank;
		break;
	}
	
	return out;
}

Deck::Deck() : m_cutCard{random()}, m_topCard{0},
		     m_cards{"Images\\z-cards\\2C.jpg", "Images\\z-cards\\3C.jpg", "Images\\z-cards\\4C.jpg", "Images\\z-cards\\5C.jpg", 
					"Images\\z-cards\\6C.jpg", "Images\\z-cards\\7C.jpg", "Images\\z-cards\\8C.jpg", "Images\\z-cards\\9C.jpg", 
					"Images\\z-cards\\10C.jpg", "Images\\z-cards\\JC.jpg", "Images\\z-cards\\QC.jpg", "Images\\z-cards\\KC.jpg",
					"Images\\z-cards\\AC.jpg", 

					"Images\\z-cards\\2D.jpg", "Images\\z-cards\\3D.jpg", "Images\\z-cards\\4D.jpg", 
					"Images\\z-cards\\5D.jpg", "Images\\z-cards\\6D.jpg", "Images\\z-cards\\7D.jpg", "Images\\z-cards\\8D.jpg", 
					"Images\\z-cards\\9D.jpg", "Images\\z-cards\\10D.jpg", "Images\\z-cards\\JD.jpg", "Images\\z-cards\\QD.jpg",
					"Images\\z-cards\\KD.jpg", "Images\\z-cards\\AD.jpg", 

					"Images\\z-cards\\2H.jpg", "Images\\z-cards\\3H.jpg", 
					"Images\\z-cards\\4H.jpg", "Images\\z-cards\\5H.jpg", "Images\\z-cards\\6H.jpg", "Images\\z-cards\\7H.jpg", 
					"Images\\z-cards\\8H.jpg", "Images\\z-cards\\9H.jpg", "Images\\z-cards\\10H.jpg", "Images\\z-cards\\JH.jpg",
					"Images\\z-cards\\QH.jpg", "Images\\z-cards\\KH.jpg", "Images\\z-cards\\AH.jpg", 
	
					"Images\\z-cards\\2S.jpg", 
					"Images\\z-cards\\3S.jpg", "Images\\z-cards\\4S.jpg", "Images\\z-cards\\5S.jpg", "Images\\z-cards\\6S.jpg", 
					"Images\\z-cards\\7S.jpg", "Images\\z-cards\\8S.jpg", "Images\\z-cards\\9S.jpg", "Images\\z-cards\\10S.jpg",
					"Images\\z-cards\\JS.jpg", "Images\\z-cards\\QS.jpg", "Images\\z-cards\\KS.jpg", "Images\\z-cards\\AS.jpg" }
{
	

	int i = 0;
	for (int ii=0; ii<4; ii++)
	{
		for (int jj=0; jj<13; jj++)
		{
			m_cards.at(i).m_rank = static_cast<Card::cardRank>(jj);
			m_cards.at(i).m_suits = static_cast<Card::cardSuits>(ii);
			i++;
		}
	}

}

Card& Deck::pickCard()
{
	return m_cards.at(m_topCard++);
}

Card& Card::operator= (Card& c)
{
	m_suits = c.m_suits;
	m_rank = c.m_rank;
	m_cardImage = c.m_cardImage;
	return *this;
}


int Deck::random()
{
	return rand() % 52;
}

void Deck::newCutCard()
{
	m_cutCard = random();
}


void Deck::printDeck()
{
	int nr = 1;
	for (const auto &local_deck : m_cards)
	{
		switch (local_deck.m_suits)
		{
		case Card::CLUBS:
			std::cout << "Card " << nr << ": suits: CLUBS, rank: " << local_deck.m_rank << std::endl;
			break;
		case Card::DIAMONDS:
			std::cout << "Card " << nr << ": suits: DIAMONDS, rank: " << local_deck.m_rank << std::endl;
			break;
		case Card::HEARTS:
			std::cout << "Card " << nr << ": suits: HEARTS, rank: " << local_deck.m_rank << std::endl;
			break;
		case Card::SPADES:
			std::cout << "Card " << nr << ": suits: SPADES, rank: " << local_deck.m_rank << std::endl;
			break;
		}
		nr++;
	}
}

void Deck::swap(int a, int b)
{
	Card inter;
	inter = m_cards[a];
	m_cards[a] = m_cards[b];
	m_cards[b] = inter;
}


void Deck::shuffle()
{
	srand(static_cast<unsigned int>(clock()));
	
	
	sf::RenderWindow w(sf::VideoMode(300, 150), "Shuffle", sf::Style::None);
	Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
	background.drawEntity(w);
	TextEntity text(sf::Vector2f(60, 50));
	text.setString("Shufflig");
	text.drawText(w);
	w.display();

	for (int i = 0; i < 104; i++)
	{
		int a = random();
		int b = random();
		swap(a, b);
	}
	sf::sleep(sf::milliseconds(3000));
	w.close();

}

Card& Deck::operator[] (int index)
{
	return m_cards.at(index);
}
