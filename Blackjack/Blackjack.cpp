#include "Blackjack.h"

Blackjack::Blackjack(): m_background{ "Images\\z-background01.jpg" }, 
						m_dealerPays("Images\\z-dealer-pays.png", sf::Vector2f(410, 400)),
						m_nbOfCardsLogo{"Images\\z-cardsLogo03.png", sf::Vector2f(1250, 23)},
						m_dealerPoints{ sf::Vector2f(1090.f, 180.f) }, 
						m_gamblerPoints{ sf::Vector2f(1090.f, 740.f) }, 
						m_bank{ sf::Vector2f(1130, 844), 42} ,
						m_nbOfCards{ sf::Vector2f(1320, 30), 32 },
						m_stand{ "Images\\z-stand.png", "Images\\z-stand-effect.png", sf::Vector2f(100, 100) }, 
						m_hit{ "Images\\z-hit.png", "Images\\z-hit-effect.png", sf::Vector2f(100, 400) },
						m_double_{ "Images\\z-double.png", "Images\\z-double-effect.png", sf::Vector2f(100, 700) }, 
						m_status{ true }
{
	m_nbOfCardsLogo.setScale(sf::Vector2f(0.1f, 0.1f));
	m_dealerPoints.setString("0");
	m_gamblerPoints.setString("0");
	m_bank.setString(std::to_string(m_gambler.getMoney()));
	m_nbOfCards.setString("52");
}

void Blackjack::shuffleDeck()
{
	m_deck.shuffle();
}

void Blackjack::drawBetElements(sf::RenderWindow& w, Entity& backg, TextButton* betch)
{
	backg.drawEntity(w);
	for (int i{ 0 }; i < g_numberOfBets; i++)
	{
		(betch + i)->drawText(w);
	}
}

void increaseIndex(int& i)
{
	if (i == g_numberOfBets - 1)
		i = 0;
	else
		++i;
}
void decreaseIndex(int& i)
{
	if (i == 0)
		i = g_numberOfBets - 1;
	else
		--i;
}
/**************************************************************************** WORK IN PROGRESS :| ************************************************************************************

bool Blackjack::checkMoney(sf::RenderWindow& window, Entity& background, TextButton* betch)
{
	drawBetElements(window, background, betch);
	window.display();
	if (m_gambler.getBet() > m_gambler.getMoney())
	{
		sf::RenderWindow w(sf::VideoMode(300, 150), "Game over", sf::Style::None);
		Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
		background.drawEntity(w);
		TextEntity text(sf::Vector2f(50, 50), 36);
		if (m_gambler.getBet() == *(m_gambler.getBetChoises()) || m_gambler.getMoney() < *(m_gambler.getBetChoises()))
		{
			text.setString("Game over");
			text.drawText(w);
			w.display();
			sf::sleep(sf::milliseconds(3000));
			w.close();
			return false;
		}
		else
		{
			text.setString("Not enough money");
			text.drawText(w);
			w.display();
			sf::sleep(sf::milliseconds(3000));
			w.close();
			return true;
		}
	}
	m_gambler.setMoney(m_gambler.getMoney() - m_gambler.getBet());
	m_bank.setString(std::to_string(m_gambler.getMoney()));
	window.close();
	return true;
}

bool Blackjack::checkMouseEvent(sf::RenderWindow& window, sf::Vector2f mousePosition,TextButton* betch, Entity& background)
{
	
	if ((betch + 0)->getBoundingBox().contains(mousePosition))
	{
		(betch + 0)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(0);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 1)->getBoundingBox().contains(mousePosition))
	{
		(betch + 1)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(1);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 2)->getBoundingBox().contains(mousePosition))
	{
		(betch + 2)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(2);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 3)->getBoundingBox().contains(mousePosition))
	{
		(betch + 3)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(3);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 4)->getBoundingBox().contains(mousePosition))
	{
		(betch + 4)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(4);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 5)->getBoundingBox().contains(mousePosition))
	{
		(betch + 5)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(5);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 6)->getBoundingBox().contains(mousePosition))
	{
		(betch + 6)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(6);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 7)->getBoundingBox().contains(mousePosition))
	{
		(betch + 7)->effect();
		drawBetElements(window, background, betch);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					m_gambler.setBet(7);
					if (!checkMoney(window, background, betch))
						return false;
					else
						return true;
				}
		}
	}
	else if ((betch + 8)->getBoundingBox().contains(mousePosition))
	{
	(betch + 8)->effect();
	drawBetElements(window, background, betch);
	window.display();
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				m_gambler.setBet(8);
				if (!checkMoney(window, background, betch))
					return false;
				else
					return true;
			}
	}
	}
	else if ((betch + 9)->getBoundingBox().contains(mousePosition))
	{
	(betch + 9)->effect();
	drawBetElements(window, background, betch);
	window.display();
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				m_gambler.setBet(9);
				if (!checkMoney(window, background, betch))
					return false;
				else
					return true;
			}
	}
	}
	else
	{
	for (int i{ 0 }; i < g_numberOfBets; ++i)
		(betch + i)->endEffect();
	drawBetElements(window, background, betch);
	window.display();
	}
	return true;
}
*/

bool Blackjack::setBet(sf::RenderWindow& w)
{
	sf::Event event;
	sf::RenderWindow window{ sf::VideoMode(1400, 300), "Bet", sf::Style::None };
	Entity background("Images\\z-background07.jpg");

	TextButton betChoises[g_numberOfBets]{	TextButton(std::to_string(*(m_gambler.getBetChoises() + 0)), sf::Vector2f(130, 125)),
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 1)), sf::Vector2f(230, 125)),
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 2)), sf::Vector2f(330, 125)), 
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 3)), sf::Vector2f(450, 125)), 
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 4)), sf::Vector2f(560, 125)), 
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 5)), sf::Vector2f(680, 125)),
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 6)), sf::Vector2f(810, 125)),
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 7)), sf::Vector2f(940, 125)), 
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 8)), sf::Vector2f(1070, 125)), 
											TextButton(std::to_string(*(m_gambler.getBetChoises() + 9)), sf::Vector2f(1200, 125)) };
	
	drawBetElements(window, background, betChoises);
	window.display();
	
	while (window.isOpen())
	{
		sf::Vector2f mousePosition{ sf::Mouse::getPosition(window) };
/*
		if (!checkMouseEvent(window, mousePosition, betChoises, background))
		{
			window.close();
			return false;
		}
*/
		static int index{ 0 };
		betChoises[index].effect();
		m_gambler.setBet(index);
		drawBetElements(window, background, betChoises);
		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					m_gambler.setBet('+');
					betChoises[index].endEffect();
					increaseIndex(index);
					betChoises[index].effect();
					drawBetElements(window, background, betChoises);
					window.display();
					break;
				case sf::Keyboard::Left:
					m_gambler.setBet('-');
					betChoises[index].endEffect();
					decreaseIndex(index);
					betChoises[index].effect();
					drawBetElements(window, background, betChoises);
					window.display();
					break;
				case sf::Keyboard::Enter:
					if (m_gambler.getBet() > m_gambler.getMoney())
					{
						sf::RenderWindow w(sf::VideoMode(300, 150), "Game over", sf::Style::None);
						Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
						background.drawEntity(w);
						TextEntity text(sf::Vector2f(50, 50), 36);
						if (m_gambler.getBet() == *(m_gambler.getBetChoises()) || m_gambler.getMoney() < *(m_gambler.getBetChoises()))
						{
							text.setString("Game over");
							text.drawText(w);
							w.display();
							sf::sleep(sf::milliseconds(3000));
							w.close();
							return false;
						}
						else
						{
							text.setString("Not enough\n\t money");
							text.drawText(w);
							w.display();
							sf::sleep(sf::milliseconds(3000));
							w.close();
							break;
						}
					}
					m_gambler.setMoney(m_gambler.getMoney() - m_gambler.getBet());
					m_bank.setString(std::to_string(m_gambler.getMoney()));
					window.close();
					break;
				case sf::Keyboard::Escape:
					window.close();
				}

			}
			
		}
		while (w.pollEvent(event))
			if (event.type == event.Closed)
			{
				window.close();
				w.close();
				return false;
			}

	}

	return true;

}

void Blackjack::drawGameElements(sf::RenderWindow& w, EffectStatus status)
{
	m_background.drawEntity(w);
	m_nbOfCardsLogo.drawEntity(w);
	m_dealerPays.drawEntity(w);
	m_dealerPoints.drawText(w);
	m_gamblerPoints.drawText(w);
	m_bank.drawText(w);
	m_nbOfCards.drawText(w);
	m_gambler.drawMyCards(w);
	m_dealer.drawMyCards(w);

	switch (status)
	{
	case standEffect:
		m_stand.drawEffect(w);
		m_hit.drawImage(w);
		m_double_.drawImage(w);
		break;
	case hitEffect:
		m_stand.drawImage(w);
		m_hit.drawEffect(w);
		m_double_.drawImage(w);
		break;
	case doubleEffect:
		m_stand.drawImage(w);
		m_hit.drawImage(w);
		m_double_.drawEffect(w);
		break;
	case noEffect:
		m_stand.drawImage(w);
		m_hit.drawImage(w);
		m_double_.drawImage(w);
		break;
	}

}

void Blackjack::stand(sf::RenderWindow& w)
{
	while (m_dealer.getValueOfCards() < 17)
	{
		dealerHit(w);
		sf::sleep(sf::milliseconds(1000));
	}
	if (m_dealer.getValueOfCards() <= 21)
	{
		if (m_gambler.getValueOfCards() < m_dealer.getValueOfCards())
			bust();
		else if (m_gambler.getValueOfCards() == m_dealer.getValueOfCards())
			push(w);
		else
			win(w);
	}
	else
		win(w);
}

bool Blackjack::hit(sf::RenderWindow& w)
{
	m_gambler.getACard(m_deck);
	if (m_gambler.getTheLastCardValue() == 11 && m_gambler.getValueOfCards() - 11 > 10)
			m_gambler.setValueOfCards(10);

	m_nbOfCards.setString(std::to_string(52 - m_deck.getTopCard()));
	m_gamblerPoints.setString(std::to_string(m_gambler.getValueOfCards()));
	drawGameElements(w, Blackjack::noEffect);
	w.display();
	if (m_gambler.getValueOfCards() > 21)
	{
		bust();
		return false;
	}
	return true;
}

void Blackjack::double_(sf::RenderWindow& w)
{
	if (m_gambler.getBet() > m_gambler.getMoney())
	{
		sf::RenderWindow w(sf::VideoMode(300, 150), "Game over", sf::Style::None);
		Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
		background.drawEntity(w);
		TextEntity text(sf::Vector2f(15, 50), 30);
		text.setString("Not enough money");
		text.drawText(w);
		w.display();
		sf::sleep(sf::milliseconds(3000));
		w.close();
		return;
		}
	m_gambler.setMoney(m_gambler.getMoney() - m_gambler.getBet());
	m_bank.setString(std::to_string(m_gambler.getMoney()));
	m_gambler.doubleBet();
	if (!hit(w))
		return;
	stand(w);
}

void Blackjack::dealerHit(sf::RenderWindow& w)
{
	m_dealer.getACard(m_deck);
	if (m_dealer.getTheLastCardValue() == 11 && m_dealer.getValueOfCards() - 11 > 10)
		m_dealer.setValueOfCards(10);
	m_nbOfCards.setString(std::to_string(52 - m_deck.getTopCard()));
	m_dealerPoints.setString(std::to_string(m_dealer.getValueOfCards()));
	drawGameElements(w, Blackjack::noEffect);
	w.display();
}

void Blackjack::bust()
{
	sf::RenderWindow w(sf::VideoMode(300, 150), "You lose", sf::Style::None);
	Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
	background.drawEntity(w);
	TextEntity text(sf::Vector2f(50, 50));
	text.setString("You lose");
	text.drawText(w);
	w.display();
	sf::sleep(sf::milliseconds(3000));
	w.close();
	m_status = !m_status;
}

void Blackjack::win(sf::RenderWindow& window)
{
	sf::RenderWindow w(sf::VideoMode(300, 150), "You win", sf::Style::None);
	Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
	background.drawEntity(w);
	TextEntity text(sf::Vector2f(50, 50));
	text.setString("You win");
	text.drawText(w);
	w.display();
	sf::sleep(sf::milliseconds(3000));
	w.close();
	m_gambler.setMoney(m_gambler.getMoney() + 2 * m_gambler.getBet());
	m_bank.setString(std::to_string(m_gambler.getMoney()));
	drawGameElements(window, Blackjack::noEffect);
	window.display();
	m_status = !m_status;
}

void Blackjack::push(sf::RenderWindow& window)
{
	sf::RenderWindow w(sf::VideoMode(300, 150), "Push", sf::Style::None);
	Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
	background.drawEntity(w);
	TextEntity text(sf::Vector2f(60, 50));
	text.setString("Push");
	text.drawText(w);
	w.display();
	sf::sleep(sf::milliseconds(3000));
	w.close();
	m_gambler.setMoney(m_gambler.getMoney() + m_gambler.getBet());
	m_bank.setString(std::to_string(m_gambler.getMoney()));
	drawGameElements(window, Blackjack::noEffect);
	window.display();
	m_status = !m_status;
}
void Blackjack::blackjack(sf::RenderWindow& window)
{
	sf::RenderWindow w(sf::VideoMode(300, 150), "Blackjack", sf::Style::None);
	Entity background("Images\\z-background07.jpg", sf::IntRect(550, 75, 300, 150));
	background.drawEntity(w);
	TextEntity text(sf::Vector2f(50, 50));
	text.setString("Blackjack");
	text.drawText(w);
	w.display();
	sf::sleep(sf::milliseconds(3000));
	w.close();
	m_gambler.setMoney(m_gambler.getMoney() + 2.5 * m_gambler.getBet());
	m_bank.setString(std::to_string(m_gambler.getMoney()));
	drawGameElements(window, Blackjack::noEffect);
	window.display();
	m_status = !m_status;
	}

void Blackjack::gameSetup(sf::RenderWindow& w)
{
	drawGameElements(w, Blackjack::noEffect);
	w.display();

	sf::sleep(sf::milliseconds(1000));
	dealerHit(w);

	sf::sleep(sf::milliseconds(1000));
	hit(w);

	sf::sleep(sf::milliseconds(1000));
	hit(w);

	m_status = true;
	if (m_gambler.getValueOfCards() == 21)
	{
		sf::sleep(sf::milliseconds(1000));
		dealerHit(w);
		if (m_dealer.getValueOfCards() == 21)
			push(w);
		else
			blackjack(w);
	}
}

void Blackjack::startGame(sf::RenderWindow& window)
{
	sf::Event event;
	gameSetup(window);
		
	while (m_status)
	{
		sf::Vector2f mousePosition{ sf::Mouse::getPosition(window) };
		
		if (m_stand.getBoundingBox().contains(mousePosition))
		{
			drawGameElements(window, Blackjack::standEffect);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::MouseButtonPressed)
					if (event.mouseButton.button == sf::Mouse::Left)
						stand(window);
			}
		}
		else if (m_hit.getBoundingBox().contains(mousePosition))
				{
					drawGameElements(window, Blackjack::hitEffect);
					window.display();
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::MouseButtonPressed)
							if (event.mouseButton.button == sf::Mouse::Left)
								hit(window);
					}
				}
		else if (m_double_.getBoundingBox().contains(mousePosition))
				{
					drawGameElements(window, Blackjack::doubleEffect);
					window.display();
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::MouseButtonPressed)
							if (event.mouseButton.button == sf::Mouse::Left)
								double_(window);
					}
				}
		else
		{
			drawGameElements(window, Blackjack::noEffect);
			window.display();
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
					{
						window.close();
						m_status = !m_status;
					}
		}

		
	}
}

void Blackjack::reset(sf::RenderWindow& w)
{
	m_gambler.reset();
	m_gamblerPoints.setString(std::to_string(m_gambler.getValueOfCards()));
	m_dealer.reset();
	m_dealerPoints.setString(std::to_string(m_dealer.getValueOfCards()));
	drawGameElements(w, Blackjack::noEffect);
	w.display();
	if (m_deck.getTopCard() >= m_deck.getCutCard())
	{
		m_deck.shuffle();
		m_deck.newCutCard();
		m_deck.resetTopCard();
	}
}


