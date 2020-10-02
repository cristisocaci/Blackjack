#include "Entity.h"



Entity::Entity(const char* s)
{
	
	if (!m_texture.loadFromFile(s))
		std::cerr << "Failed to load from file"<<std::endl;
	m_sprite.setTexture(m_texture);
}

Entity::Entity(const char* s, sf::Vector2f p) : Entity(s)
{
	setPosition(p);
}

Entity::Entity(const char* s, sf::IntRect rect)
{
	if (!m_texture.loadFromFile(s, rect))
		std::cerr << "Failed to load from file" << std::endl;
	m_sprite.setTexture(m_texture);
}

void Entity::drawEntity(sf::RenderWindow& w)
{
	w.draw(m_sprite);
}

void Entity::setScale(sf::Vector2f s)
{
	m_sprite.setScale(s);
}

void Entity::setPosition(sf::Vector2f p)
{
	m_sprite.setPosition(p);
}

void Entity::move(const sf::Vector2f p)
{
	m_sprite.move(p);
}

sf::FloatRect Entity::getGlobalBounds()
{
	return m_sprite.getGlobalBounds();
}

Entity& Entity::operator=(Entity& e)
{
	sf::Context context;

	m_texture = e.m_texture;
	m_sprite.setTexture(m_texture);
	return *this;
}


TextEntity::TextEntity(sf::Vector2f p, int s ) : m_position{ p }, m_characterSize{ s }
{
	m_font.loadFromFile("OpenSans-Regular.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(m_characterSize);
	m_text.setPosition(m_position);
}

void TextEntity::setString(std::string s)
{
	m_text.setString(s);
}

void TextEntity::drawText(sf::RenderWindow& w)
{
	w.draw(m_text);
}

void TextEntity::effect()
{
	m_text.setFillColor(sf::Color(255,243,0));
	m_text.setStyle(sf::Text::Bold);
}
void TextEntity::endEffect()
{
	m_text.setFillColor(sf::Color(255, 255, 255));
	m_text.setStyle(sf::Text::Regular);
}

Button::Button(const char* image, const char* effect, sf::Vector2f p) : m_image{ Entity(image, p) }, m_effect(Entity(effect, p)), m_boundingBox{ m_image.getGlobalBounds() }
{
}

void Button::drawImage(sf::RenderWindow& w)
{
	m_image.drawEntity(w);
}
void Button::drawEffect(sf::RenderWindow& w)
{
	m_effect.drawEntity(w);
}

TextButton::TextButton(std::string s, sf::Vector2f p) : m_image{ TextEntity(p) }, m_boundingBox{ m_image.getGlobalBounds() }
{
	m_image.setString(s);
}

void TextButton::drawText(sf::RenderWindow& w)
{
		m_image.drawText(w);
}
void TextButton::effect()
{
	m_image.effect();
}
void TextButton::endEffect()
{
	m_image.endEffect();
}