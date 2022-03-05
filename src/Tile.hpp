#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <cassert>

class Tile
    :public sf::Drawable
{
    public:
    //*Constructors & Destructors
        explicit Tile() = delete;
        explicit Tile(sf::Texture const &texture, sf::IntRect const &rectangle);
        explicit Tile(Tile const &tile) = default;
        ~Tile();

    //*Copy Assignment Operator
        Tile& operator=(Tile const &tile);

    //*Comparison Operator
        friend bool operator==(Tile const &lhs, Tile const &rhs);
        friend bool operator!=(Tile const &lhs, Tile const &rhs);

    //*Virtual Method (HERITED)
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //*Methods
        sf::Vector2f getPosition() const;
        void setPosition(sf::Vector2f const &position);

        void setTexture(sf::Texture const &texture);
        sf::Texture const * getTexture() const;

        void update();
        void render(sf::RenderTarget &target) const;

    private:
    //*Attributes
        sf::Sprite m_sprite;
};

#endif //TILE_HPP