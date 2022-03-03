#include "TileMap.hpp"

//*Constructors & Destructors
TileMap::TileMap(TileSet const &tileSet, unsigned int id)
    :m_tileSet{tileSet}
{

}

TileMap::TileMap(TileSet const &tileSet, std::string const &directory)
    :m_tileSet{tileSet}
{

}

TileMap::~TileMap()
{

}