#ifndef ENTITY_H
#define ENTITY_H 

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Entity
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	Entity(){}
	Entity(const char*);
	Entity(const char*, sf::Vector2f);
	Entity(const char*, sf::IntRect);
	void drawEntity(sf::RenderWindow&);
	void setScale(sf::Vector2f);
	void setPosition(const sf::Vector2f);
	void move(sf::Vector2f);
	sf::FloatRect getGlobalBounds();

	Entity& operator=(Entity&);
	
};

class TextEntity
{
private:
	int m_characterSize;
	sf::Text m_text;
	sf::Vector2f m_position;
	sf::Font m_font;
public:
	TextEntity(sf::Vector2f, int = 52);
	void setString(std::string);
	void drawText(sf::RenderWindow&);
	void effect();
	void endEffect();
	sf::FloatRect getGlobalBounds() { return m_text.getGlobalBounds(); }
	
	
};

class Button
{
private:
	Entity m_image;
	Entity m_effect;
	sf::FloatRect m_boundingBox;
public:
	Button(const char*, const char*, sf::Vector2f);
	sf::FloatRect& getBoundingBox() { return m_boundingBox; }
	void drawImage(sf::RenderWindow&);
	void drawEffect(sf::RenderWindow&);
};

class TextButton
{
private:
	
	TextEntity m_image;
	sf::FloatRect m_boundingBox;

public:
	TextButton(std::string, sf::Vector2f);
	sf::FloatRect& getBoundingBox() { return m_boundingBox; }
	void drawText(sf::RenderWindow&);
	void effect();
	void endEffect();
};
#endif