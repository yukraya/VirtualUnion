#include "Tile.hpp"

//*Constructors & Destructors
Tile::Tile(sf::Texture const &texture, sf::IntRect const &rectangle)
    :m_sprite(texture, rectangle)
{

}

Tile::~Tile()
{
    
}

Tile& Tile::operator=(Tile const &tile)
{
    m_sprite.setTextureRect(tile.m_sprite.getTextureRect());
    return *this;
}

//*Comparison Operator
bool operator==(Tile const &lhs, Tile const &rhs)
{
    return lhs.m_sprite.getTextureRect() == rhs.m_sprite.getTextureRect();
}

bool operator!=(Tile const &lhs, Tile const &rhs)
{
    return !(lhs == rhs);
}

//*Virtual Methods (HERITED)
void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
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

void Tile::setTexture(sf::Texture const &texture)
{
    m_sprite.setTexture(texture);
}

sf::Texture const * Tile::getTexture() const
{
    return m_sprite.getTexture();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget &target) const
{
    target.draw(m_sprite);
}