#include "TileMap.hpp"

//*Constructors & Destructors
TileMap::TileMap(TileSet const &tileSet, unsigned int id)
    :m_tileSet{tileSet}
{
    m_mapLoader.read("../share/map/map" + std::to_string(id) + ".config");
}

TileMap::TileMap(TileSet const &tileSet, std::string const &directory)
    :m_tileSet{tileSet}
{
    m_mapLoader.read(directory);
}

TileMap::~TileMap()
{

}