#pragma once

#include <SFML/Graphics.hpp>
constexpr auto catSpeed = 20.f;

class Cat {
public:
	Cat(const sf::Texture& texture, sf::Vector2f pos);
	void draw(sf::RenderWindow& window) const;
	sf::Vector2f getpos() const;
	void setPos(sf::Vector2f pos);
	void setOrigion(sf::Vector2f pos);
	void move(float delta);
	void setdircetion(sf::Vector2f pos);
private:
	sf::Vector2f m_pos;
	sf::RectangleShape m_cat;
	sf::Vector2f m_direction;
};