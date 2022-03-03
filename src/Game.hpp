#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Game
{
    public:
    //*Constructors & Destructors
        explicit Game();
        ~Game();

    //*Methods
        void run();

    private:
    //*Initialisation Functions
        void initWindow();
        void initKeybinds();

    //*Internal Functions
        void resetKeybinds();
        void updateSFMLEvents();

        void update();
        void render();

    //*Attributes
        sf::RenderWindow *m_window;
        sf::Event m_event;

        std::map<std::string, bool> m_keybinds;
        std::map<std::string, sf::Keyboard::Key> m_userControls;

        bool m_close;
};

#endif //GAME_HPP