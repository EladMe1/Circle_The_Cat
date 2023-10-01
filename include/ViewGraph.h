#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Resources.h"

class ViewGraph {
public:
	ViewGraph();
	~ViewGraph() = default;
	void draw(sf::RenderWindow& window) const;
	void pushtotile(const Tile &t, const sf::Vector2f &pos,bool tile);
	void makeDark(sf::Vector2f pos);
	void pushBackNeighbor(std::pair<int, std::shared_ptr<Tile>>& neighbor);
	void clearNeighbors();
	std::shared_ptr<Tile> getTileByPos(sf::Vector2f pos) const;
	std::map<int, std::shared_ptr<Tile>> didectNeighbors(sf::Vector2f pos);
private:
	std::vector<std::shared_ptr<Tile>> m_tiles;
	std::vector<sf::Texture> m_texture;
	std::map<int, std::shared_ptr<Tile>> m_neighbors;
};