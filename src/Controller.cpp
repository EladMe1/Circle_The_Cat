	#include "..\include\Controller.h"
#include <iostream>
#include <chrono>
#include <thread>

	Controller::Controller():m_pressingCounter(0)
	{
		

		if (!m_font.loadFromFile("Amadeus.ttf"))	// if font couldn't be loaded
		{
			perror("cant load font");
			exit(EXIT_FAILURE);
		}

		m_cat = std::make_unique<Cat>(Resources::instance().getCat(),sf::Vector2f(X_FIRST_CAT, Y_FIRST_CAT));
		m_Timer.setStyle(sf::Text::Bold);
		m_Timer.setCharacterSize(40);
		m_Timer.setPosition(500, 900);
		m_Timer.setFont(m_font);
		m_Timer.setFillColor(sf::Color::Yellow);
		m_Timer.setString(m_scoreString.str());
	}

	void Controller::run(bool &back)
	{
		auto myWindow = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Circle the cat",sf::Style::Close|sf::Style::Resize);
		createGraph();
		
		auto gameClock = sf::Clock();
		auto delta = gameClock.restart();
	
		while (myWindow.isOpen())
		{
			
			m_scoreString.str("");
			m_scoreString << m_pressingCounter;
			m_Timer.setString(m_scoreString.str());


			myWindow.clear(sf::Color::White);
			m_myGraphView.draw(myWindow);
			m_cat->draw(myWindow);
			myWindow.draw(m_Timer);
			myWindow.display();
		
			for (auto event = sf::Event{};  myWindow.pollEvent(event);)
			{
						switch (event.type)
						{
						case sf::Event::Closed:
						{
							myWindow.close();
							back = true;
							return;
							break;
						}
						case sf::Event::MouseButtonPressed:
						{
							const auto location = myWindow.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
							switch (event.mouseButton.button)
							{
								case sf::Mouse::Button::Left:
								{
									increament();
									m_myGraphView.makeDark(location);
									m_neighbours = m_myGraphView.didectNeighbors(m_cat->getpos());
									setCatLocation();
									m_neighbours.clear();
									m_myGraphView.clearNeighbors();
									break;
								}
							}
						}

					}
				}

			checkIfCatOutOfBound();
			if (isOutOfBound)
			{
				float delta = 0.1f;
				m_cat->move(delta);
				lose();
				back = true;
				return;
			}
		
		}
	}

	void Controller::createGraph()
	{
		bool iseven = true;
		int xPlace = X_FIRST;
		int yPlace = Y_FIRST;
		int tileSize = TILE_SIZE;
		bool tile = false;
		int counter = 0;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				sf::Vector2f pos(xPlace, yPlace);
				int random = rand() % 11;
				if ((random == 3 || random == 9 || random == 7) && counter <= 4)
				{
					counter++;
					tile = true;
				}
				else
				{
					tile = false;
				}
				Tile temp(Resources::instance().getTile(),pos,tile);
				m_myGraphView.pushtotile(temp,pos,tile);
				xPlace += tileSize;
			}
			iseven = !iseven;
			if (iseven)
				xPlace = X_FIRST;
			else
				xPlace = X_ODD_FIRST;
			yPlace += Y_NEXT;
		}
	
	}


	std::pair<bool, std::string> Controller::checkIfBoarder(const sf::Vector2f& pos)
	{

		if (pos.x == LEFT_BORDER1 || pos.x == LEFT_BORDER2)
			return std::pair<bool, std::string>(true, "left");			
		else if(pos.x == RIGHT_BORDER1 || pos.x == RIGHT_BORDER2)
			return std::pair<bool, std::string>(true, "right");
		 else if (pos.y == HEIGHTS_BORDER)
			return std::pair<bool, std::string>(true, "up");
		else if (pos.y == LOWERS_BORDER)
			return std::pair<bool, std::string>(true, "down");
		else
		{
			return std::pair<bool, std::string>(false,"in boarder");
		}

	}

	void Controller::moveOutWindow(std::pair<bool, std::string> pair)
	{
		if (pair.second == "left")
		{
			m_cat->setdircetion(sf::Vector2f(-1.f, 0.f));
		}
		else if (pair.second == "right")
		{
			m_cat->setdircetion(sf::Vector2f(1.f, 0.f));
			
		}
		else if (pair.second == "up")
		{			
			m_cat->setdircetion(sf::Vector2f(0.f, -1.f));
		}
		else {
			if (pair.second == "down")
			{
				m_cat->setdircetion(sf::Vector2f(0.f, 1.f));
			}
		}
	}

	void Controller::setCatLocation()
	{
		for (auto& neighbor : m_neighbours)
		{
			if (!neighbor.second->ispressed())
			{
				auto pos = neighbor.second->getPos();
				m_cat->setPos(pos);		
			}
		}
	}

	void Controller::checkIfCatOutOfBound()
	{
		auto catPos = m_cat->getpos();
		auto pair = checkIfBoarder(catPos);
		if (pair.first == true)
		{
			isOutOfBound = true;
			moveOutWindow(pair);
		}
	}

	void Controller::increament()
	{
		m_pressingCounter++;
	}

	void Controller::lose()
	{
		auto window = sf::RenderWindow(sf::VideoMode(500, 500), "oops..");

		if (!m_font.loadFromFile("Amadeus.ttf"))	// if font couldn't be loaded
		{
			perror("cant load font");
			exit(EXIT_FAILURE);
		}

		while (window.isOpen())
		{
			window.clear();
			window.display();
			m_scoreString.str(" you lose!");
			m_scoreString << m_pressingCounter;

			for (auto event = sf::Event{}; window.pollEvent(event);)
			{
				switch (event.type)
				{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				}
			}
		}
	}
