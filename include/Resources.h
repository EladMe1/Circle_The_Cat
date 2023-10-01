#pragma once


#include <fstream>
#include <sstream>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Const.h"


using std::cout;
using std::endl;
using sf::Font;
using sf::Texture;
using std::ifstream;
using std::vector;
using std::ostringstream;
using sf::SoundBuffer;

class Resources
{
public:
	~Resources();
	static Resources& instance();
	const Texture& getTile() const;
	const Texture& getCat() const;
	void loadresources();
	void loadtextures();
private:
	Resources();                                   
	Resources(const Resources&) = default;
	Resources& operator= (const Resources&) = default;	
	vector<sf::Texture> m_textures;		               //game figures textures
	sf::Font m_font;                                  //font for the text messeges
	ostringstream m_scoreToolbar;                    //string for toolbar text massages
};