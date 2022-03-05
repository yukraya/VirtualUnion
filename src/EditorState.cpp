#include "EditorState.hpp"

//*Initialisation Functions
void EditorState::initTileMap()
{
    
}

//*Constructors & Destructors
EditorState::EditorState(sf::RenderWindow &window, TileSet const &tileSet)
    :State(window, tileSet)
{
    initTileMap();
}

EditorState::~EditorState()
{
    
}

//*Methods
void EditorState::update(float const &dFrame)
{
    //m_tileMap->setTile(0, sf::Vector2u(5, 2), 9);
}

void EditorState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = &m_window;
    }
    //target->draw(m_layer);
}