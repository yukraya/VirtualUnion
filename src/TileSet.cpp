#include "TileSet.hpp"

//*Constructors & Destructors
TileSet::TileSet()
{
    m_tileCount = 0;
}

TileSet::TileSet(std::string const &directory)
{
    m_tileCount = 0;
    read(directory);
}

TileSet::~TileSet()
{
    m_tileset.clear();
}

//*Integrated Assignment Operator
Tile const & TileSet::operator[](unsigned int const &value) const
{
    assert(value < m_tileCount);
    return *(m_tileset.at(value));
}

//*Methods
void TileSet::read(std::string const &directory)
{
    if(m_texture.loadFromFile(directory))   
    {
        for(unsigned int i {0} ; i < m_texture.getSize().x / 32 ; i++)
        {
            std::cout << "New Tile : " << i << std::endl;
            std::cout << "Texture size x : " << m_texture.getSize().x << std::endl;
            m_tileset[i] = std::make_unique<Tile>(m_texture, sf::IntRect(sf::Vector2i(32 * i, 0) , sf::Vector2i(32, 32)));
            m_tileCount++;
        }
    }
    else
    {
        std::cout << "Error loading " << directory << std::endl;
    }
}

int TileSet::getTileCount() const
{
    return m_tileCount;
}