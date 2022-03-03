#include "Tile.hpp"

//*Constructors & Destructors
Tile::Tile(sf::Texture const &texture, sf::IntRect const &rectangle)
    :m_sprite(texture, rectangle)
{

}

Tile::~Tile()
{
    
}

//*Methods
sf::Vector2f Tile::getPosition() const
{
    return m_sprite.getPosition();
}

void Tile::setPosition(sf::Vector2f const &position)
{
    m_sprite.setPosition(position);
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget *target)
{
    target->draw(m_sprite);
}