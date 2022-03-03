#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <cassert>

class Tile
{
    public:
    //*Constructors & Destructors
        explicit Tile(sf::Texture const &texture, sf::IntRect const &rectangle);
        ~Tile();

    //*Methods
        sf::Vector2f getPosition() const;
        void setPosition(sf::Vector2f const &position);

        void update();
        void render(sf::RenderTarget *target);

    private:
    //*Attributes
        sf::Sprite m_sprite;

};

#endif //TILE_HPP