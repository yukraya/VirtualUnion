#ifndef TILESET_HPP
#define TILESET_HPP

#include "Tile.hpp"

class TileSet
{
    public:
    //*Constructors & Destructors
        explicit TileSet();
        explicit TileSet(std::string const &directory);
        ~TileSet();

    //*Integrated Assignment Operator
        Tile const & operator[](unsigned int const &value) const;

    //*Methods
        void read(std::string const &directory);

        int getTileCount() const;

    private:
    //*Attributes
        sf::Texture m_texture;
        std::map<unsigned int, std::unique_ptr<Tile>> m_tileset;
        unsigned int m_tileCount;
        
};

#endif //TILESET_HPP