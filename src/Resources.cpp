#include "Resources.h"





Resources::Resources()
{	
	loadresources(); 
}

Resources::~Resources()
{
}

Resources& Resources::instance()
{	
	static Resources inst;
	return inst;
}

const Texture& Resources::getTile() const
{
	return m_textures[TILE_TEXTURE];
}

const Texture& Resources::getCat() const
{
	return m_textures[CAT_TEXTURE];
}


void Resources::loadresources()
{
	loadtextures();
}


void Resources::loadtextures()
{


	int NUM_OF_PICTURES = 10;

	m_textures.resize(NUM_OF_PICTURES);

	m_textures[0].loadFromFile("resources/tile.png");
	m_textures[1].loadFromFile("resources/cat.png");
	
}













