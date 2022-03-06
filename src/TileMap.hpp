#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "TileSet.hpp"
#include "Tile.hpp"
#include "Grid.hpp"
#include "MapLoader.hpp"
#include "SystemFunctions.hpp"

class TileMap
{
    public:
    //*Constructors & Destructors
        explicit TileMap(TileSet const &tileSet, unsigned int id);
        explicit TileMap(TileSet const &tileSet, std::string const &directory);
        ~TileMap();

    //*Methods
        void setTile(unsigned int const &tile, sf::Vector2u position, std::size_t const &layer);

        void drawLayer(sf::RenderTarget &target, std::size_t layer) const;
        void render(sf::RenderTarget &target) const;


    private:
    //*Initilisation Functions
        void loadingTileMap();

    //*Attributes
        TileSet const &m_tileSet;
        MapLoader m_mapLoader;
        Size m_tileMapSize;

        std::vector<Grid<std::unique_ptr<Tile>>> m_tileMap;
};

#endif //TILEMAP_HPP