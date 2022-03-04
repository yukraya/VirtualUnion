#include "EditorState.hpp"

//*Constructors & Destructors
EditorState::EditorState(sf::RenderWindow &window, TileSet const &tileSet)
    :State(window, tileSet), m_tileMap(tileSet, 0)
{

}

EditorState::~EditorState()
{
    
}

//*Methods
void EditorState::update(float const &dFrame)
{
    m_tileMap.setTile(0, sf::Vector2u(5, 2), 9);
}

void EditorState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = &m_window;
    }
    m_tileMap.render(target);
}