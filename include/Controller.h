#pragma once

#include <SFML/Graphics.hpp>
#include "ViewGraph.h"
#include "Tile.h"
#include "Const.h"
#include "Cat.h"
#include <math.h>
#include <stdlib.h>

class Controller {
public:
	Controller();
	void run(bool &back);
	void createGraph();
	std::pair<bool, std::string> checkIfBoarder(const sf::Vector2f &pos);
	void moveOutWindow(std::pair<bool, std::string> pair);
	void setCatLocation();
	void checkIfCatOutOfBound();
	void increament();
	void lose();
private:
	bool isOutOfBound = false;
	ViewGraph m_myGraphView;
	std::unique_ptr<Cat> m_cat;
	std::map<int, std::shared_ptr<Tile>> m_neighbours;
	sf::Text m_Timer;                     
	std::ostringstream m_scoreString;     
	sf::Clock m_Clock;                    
	sf::Font m_font;	
	int m_pressingCounter;
};