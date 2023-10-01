#include "..\include\Cat.h"

Cat::Cat(const sf::Texture& texture, sf::Vector2f pos)
	:m_pos(pos)
{
	m_cat.setTexture(&texture);
	m_cat.setPosition(pos);
	m_pos = pos;
	m_cat.setSize(sf::Vector2f(60, 60));
	m_direction = { 0.f,0.f };
}

void Cat::draw(sf::RenderWindow& window) const
{
	window.draw(m_cat);
}

sf::Vector2f Cat::getpos() const
{
	return m_cat.getPosition();
}

void Cat::setPos(sf::Vector2f pos)
{
	m_cat.setPosition(pos);
	m_pos = pos;
}

void Cat::setOrigion(sf::Vector2f pos)
{
	m_cat.setOrigin(pos);
}

void Cat::move(float delta)
{
	m_cat.move(m_direction * delta * catSpeed);
}

void Cat::setdircetion(sf::Vector2f dir)
{
	m_direction = dir;
}


