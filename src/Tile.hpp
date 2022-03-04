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
        explicit Tile() = delete;
        explicit Tile(sf::Texture const &texture, sf::IntRect const &rectangle);
        explicit Tile(Tile const &tile) = default;
        ~Tile();

    //*Comparison Operator
        friend bool operator==(Tile const &lhs, Tile const &rhs);
        friend bool operator!=(Tile const &lhs, Tile const &rhs);

    //*Methods
        sf::Vector2f getPosition() const;
        void setPosition(sf::Vector2f const &position);

        void update();
        void render(sf::RenderTarget *target) const;

    private:
    //*Attributes
        sf::Sprite m_sprite;
};

#endif //TILE_HPP