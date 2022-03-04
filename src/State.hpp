#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <stack>
#include "TileSet.hpp"

class State
{
    public:
    //*Constructors & Destructors
        explicit State() = delete;
        explicit State(sf::RenderWindow &window, TileSet const &tileSet);
        virtual ~State();

    //*Virtual Methods
        virtual void update(float const &dFrame) = 0;
        virtual void render(sf::RenderTarget *target = nullptr) = 0;

    protected:
    //*Attributes
        sf::RenderWindow &m_window;
        TileSet const &m_tileSet;
};

#endif //STATE_HPP