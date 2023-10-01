#include "..\include\ViewGraph.h"
const int number_of_neigbors = 5;

ViewGraph::ViewGraph()
{
	m_texture.resize(10);
	sf::Texture texture;
	m_texture[0].loadFromFile("resources/tile.png");
}


void ViewGraph::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles[i]->draw(window);
	}
}


void ViewGraph::pushtotile(const Tile &t, const sf::Vector2f &pos,bool press)
{
	m_tiles.push_back(std::make_unique<Tile>(Resources::instance().getTile(), pos,press));
}

void ViewGraph::makeDark(sf::Vector2f pos)
{
	
	for (auto &i :m_tiles)
	{
		if (i->getGloubalBounds().contains(pos))
		{
			i->makeDark();
		}
	}
}

void ViewGraph::pushBackNeighbor(std::pair<int, std::shared_ptr<Tile>>& neighbor)
{
	m_neighbors.insert(neighbor);
}

void ViewGraph::clearNeighbors()
{
	m_neighbors.clear();
}

std::shared_ptr<Tile> ViewGraph::getTileByPos(sf::Vector2f pos) const
{
	for (auto& tile : m_tiles)
	{
		if (tile->getGloubalBounds().contains(pos))
		{
			return tile;
		}
	}
}

std::map<int, std::shared_ptr<Tile>> ViewGraph::didectNeighbors(sf::Vector2f pos)
{
	for (auto& tile : m_tiles)
	{
		if (tile->getGloubalBounds().contains(pos))
		{
			for (size_t rotate = 0; rotate < 5; rotate++)
			{
				tile->radar();

				for (auto& other : m_tiles)
				{
					if (tile != other)
					{
						if (tile->getRadar().getGlobalBounds().intersects(other->getGloubalBounds()))
						{
							auto pair = std::pair<int, std::shared_ptr<Tile>>(rotate, other);
							m_neighbors.insert(pair);
						}
					}
				}
			}

			return m_neighbors;

		}
	}
	return m_neighbors;
}


