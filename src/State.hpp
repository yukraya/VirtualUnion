#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <stack>

class State
{
    public:
    //*Constructors & Destructors
        explicit State(sf::RenderWindow &window);
        virtual ~State();

    //*Virtual Methods
        virtual void update(float const &dFrame) = 0;
        virtual void render(sf::RenderTarget *target = nullptr) = 0;

    protected:
    //*Attributes
        sf::RenderWindow &m_window;
};

#endif //STATE_HPP