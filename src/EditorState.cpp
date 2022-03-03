#include "EditorState.hpp"

//*Constructors & Destructors
EditorState::EditorState(sf::RenderWindow &window)
    :State(window)
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