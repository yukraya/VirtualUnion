#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "TileSet.hpp"
#include "Tile.hpp"
#include "Grid.hpp"

class TileMap
{
    public:
    //*Constructors & Destructors
        explicit TileMap(TileSet const &tileSet, unsigned int id);
        explicit TileMap(TileSet const &tileSet, std::string const &directory);
        ~TileMap();


    private:
    //*Attributes
        TileSet const &m_tileSet;
        std::vector<std::unique_ptr<Grid<std::unique_ptr<Tile>>>> m_tileMap;
};

#endif //TILEMAP_HPP