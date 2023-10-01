#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile(const sf::Texture& texture ,sf::Vector2f pos,bool press);
	void draw(sf::RenderWindow& window) const;
	void makeDark();
	void makeyellow();
	sf::FloatRect getGloubalBounds() const;
	void radar();
	sf::RectangleShape& getRadar();
	sf::Vector2f getOrigion() const;
	sf::Vector2f getPos() const;
	bool ispressed();
private:
	bool m_isPressed;
	sf::RectangleShape m_tile;
	sf::Vector2f m_pos;
	sf::RectangleShape m_Radar;     
};