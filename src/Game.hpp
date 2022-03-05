#ifndef GAME_HPP
#define GAME_HPP

#include "SystemFunctions.hpp"
#include "EditorState.hpp"

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
        void initState();
        void initResources();

    //*Internal Functions
        void resetKeybinds();
        void updateSFMLEvents();
        void updateDFrame();
        void updateState();

        void update();
        void render();

    //*Attributes
        sf::RenderWindow m_window;
        sf::Event m_event;
        sf::Clock m_clock;
        float m_dFrame;

        std::map<std::string, bool> m_keybinds;
        std::map<std::string, sf::Keyboard::Key> m_userControls;

        bool m_close;

        std::stack<std::unique_ptr<State>> m_state;
        TileSet m_tileSet;
};

#endif //GAME_HPP