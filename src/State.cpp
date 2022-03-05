#include "State.hpp"

//*Constructors & Destructors
State::State(sf::RenderWindow &window, TileSet const &tileSet, std::map<std::string, bool> const &keybinds)
    :m_window{window}, m_tileSet{tileSet}, m_keybinds{keybinds}
{
    
}

State::~State()
{

}