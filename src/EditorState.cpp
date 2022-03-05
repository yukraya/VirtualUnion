#include "EditorState.hpp"

//*Initialisation Functions
void EditorState::initTileMap()
{
    m_tileMap = std::make_unique<TileMap>(m_tileSet, getProjectRootPath() + "/share/editor/default.config");
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
    m_tileMap->setTile(0, sf::Vector2u(5, 2), 9);
}

void EditorState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = &m_window;
    }
    m_tileMap->render(*target);
}