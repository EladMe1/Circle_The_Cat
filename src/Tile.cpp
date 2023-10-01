#include "..\include\Tile.h"
#include <iostream>

Tile::Tile(const sf::Texture& texture,sf::Vector2f pos,bool press)
	:m_pos(pos),m_isPressed(press)
{
	m_tile.setTexture(&texture);
	m_tile.setPosition(pos);
	m_tile.setOrigin(m_tile.getScale().x/2,m_tile.getScale().y/2);
	m_tile.setSize(sf::Vector2f(60,60));
	m_Radar.setFillColor(sf::Color::Red.Transparent);
	m_Radar.setPosition(m_tile.getPosition().x + m_tile.getSize().x / 2, m_tile.getPosition().y + m_tile.getSize().y / 2);
	m_Radar.setOrigin(m_tile.getOrigin().x/2,m_tile.getOrigin().y/2);
	m_Radar.setSize({2,70});
	
	if (this->m_isPressed)
		this->makeDark();
}

void Tile::draw(sf::RenderWindow& window) const
{
	window.draw(m_tile);
	window.draw(m_Radar);
}

void Tile::makeDark()
{
	m_tile.setFillColor(sf::Color::Black);
	m_isPressed = true;
}

void Tile::makeyellow()
{
	m_tile.setFillColor(sf::Color::Yellow);
	m_isPressed = false;
}

sf::FloatRect Tile::getGloubalBounds() const
{
	return m_tile.getGlobalBounds();
}


void Tile::radar()
{
	//full circle
	m_Radar.rotate(30);
}

sf::RectangleShape& Tile::getRadar()
{
	return m_Radar;
}

sf::Vector2f Tile::getOrigion() const
{
	return m_tile.getOrigin();
}

bool Tile::ispressed()
{
	return m_isPressed;
}

sf::Vector2f Tile::getPos() const
{
	return m_tile.getPosition();
}

