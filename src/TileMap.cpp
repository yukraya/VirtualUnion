#include "TileMap.hpp"

//*Initialisation Functions
void TileMap::loadingTileMap()
{
    m_tileMapSize = m_mapLoader.getLayerSize();
    for(std::size_t i {0} ; i < m_mapLoader.getSize() ; i++)
    {
        m_tileMap.push_back(std::make_unique<Grid<std::unique_ptr<Tile>>>(m_mapLoader.getLayerSize().x, m_mapLoader.getLayerSize().y));
        for(std::size_t j {0} ; j < m_mapLoader.getLayerSize().y ; j++)
        {
            for(std::size_t k {0} ; k < m_mapLoader.getLayerSize().x ; k++)
            {
                m_tileMap[i]->operator()(k, j) = std::make_unique<Tile>(m_tileSet[m_mapLoader[i](k, j)]);
                m_tileMap[i]->operator()(k, j)->setPosition(sf::Vector2f(k *32, j * 32));
            }
        }
    }
}

//*Constructors & Destructors
TileMap::TileMap(TileSet const &tileSet, unsigned int id)
    :m_tileSet{tileSet}
{
    m_mapLoader.read("../share/map/map" + std::to_string(id) + ".config");
    loadingTileMap();
}

TileMap::TileMap(TileSet const &tileSet, std::string const &directory)
    :m_tileSet{tileSet}
{
    m_mapLoader.read(directory);
}

TileMap::~TileMap()
{

}

//*Methods
void TileMap::setTile(unsigned int const &tile, sf::Vector2u position, std::size_t const &layer)
{
    if(*(m_tileMap[layer]->operator()(position.x, position.y)) != m_tileSet[tile])
    {
        m_tileMap[layer]->operator()(position.x, position.y).reset();
        m_tileMap[layer]->operator()(position.x, position.y) = std::make_unique<Tile>(m_tileSet[tile]);
        m_tileMap[layer]->operator()(position.x, position.y)->setPosition(sf::Vector2f((float)position.x * 32.f, (float)position.y * 32.f));
    }
}

void TileMap::setTile(Tile const &tile, sf::Vector2u position, std::size_t const &layer)
{
    if(*(m_tileMap[layer]->operator()(position.x, position.y)) != tile)
    {
        m_tileMap[layer]->operator()(position.x, position.y).reset();
        m_tileMap[layer]->operator()(position.x, position.y) = std::make_unique<Tile>(tile);
        m_tileMap[layer]->operator()(position.x, position.y)->setPosition(sf::Vector2f((float)position.x * 32.f, (float)position.y * 32.f));
    }
}

void TileMap::drawLayer(sf::RenderTarget *target, std::size_t layer) const
{
    assert(layer < m_tileMap.size());
    for(std::size_t j {0} ; j < m_tileMapSize.y ; j++)
    {
        for(std::size_t k {0} ; k < m_tileMapSize.x ; k++)
        {
            m_tileMap[layer]->operator()(k, j)->render(target);
        }
    }
}

void TileMap::render(sf::RenderTarget *target) const
{
    for(std::size_t i {0} ; i < m_tileMap.size() ; i++)
    {
        drawLayer(target, i);
    }
}