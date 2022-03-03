#include "EditorState.hpp"

//*Constructors & Destructors
EditorState::EditorState(sf::RenderWindow &window, TileSet const &tileSet)
    :State(window, tileSet)
{

}

EditorState::~EditorState()
{
    
}

//*Methods
void EditorState::update(float const &dFrame)
{
    
}

void EditorState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = &m_window;
    }
}