#include "EditorState.hpp"

//*Initialisation Functions
void EditorState::initView()
{
    m_visibleTileCount.x = 11;
    m_visibleTileCount.y = 10;
    m_mainView.reset(sf::FloatRect(0.f, 0.f, 32.f * m_visibleTileCount.x, 32.f * m_visibleTileCount.y));
    m_mainView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

    m_window.setView(m_mainView);
}

void EditorState::initSprite()
{
    m_selectSprite.setSize(sf::Vector2f(32.f, 32.f));
    m_selectSprite.setFillColor(sf::Color::Transparent);
    m_selectSprite.setOutlineThickness(-2.f);
    m_selectSprite.setOutlineColor(sf::Color(126, 36, 36));

    layer.add(m_selectSprite);
}

//*Constructors & Destructors
EditorState::EditorState(sf::RenderWindow &window, TileSet const &tileSet, std::map<std::string, bool> const &keybinds)
    :State(window, tileSet, keybinds), m_tileMap(m_tileSet, getProjectRootPath() + "/share/editor/default.config")
{
    initView();
    initSprite();
}

EditorState::~EditorState()
{
    
}

//*Functions
void EditorState::updateMousePosition()
{
    m_mouseWindowPosition = sf::Mouse::getPosition(m_window);
    m_mouseMainViewPosition = m_window.mapPixelToCoords(m_mouseWindowPosition, m_mainView);

    if(m_mouseMainViewPosition.x >= 0 && m_mouseMainViewPosition.y >= 0)
    {
        m_mouseGridPosition.x = static_cast<unsigned int>(m_mouseMainViewPosition.x) / 32;
        m_mouseGridPosition.y = static_cast<unsigned int>(m_mouseMainViewPosition.y) / 32;
    }
}

void EditorState::updateKeybinds()
{
    if(m_keybinds.at("USCROLL") && m_visibleTileCount.x > 1.f && m_visibleTileCount.y > 1.f)
    {
        m_visibleTileCount.x = m_visibleTileCount.x - 1;
        m_visibleTileCount.y = m_visibleTileCount.y - 1;
    }

    if(m_keybinds.at("DSCROLL") && m_visibleTileCount.x < 15.f && m_visibleTileCount.y < 20.f)
    {
        m_visibleTileCount.x = m_visibleTileCount.x + 1;
        m_visibleTileCount.y = m_visibleTileCount.y + 1;
    }

    if(m_keybinds.at("LCLICK"))
    {
        m_tileMap.setTile(0, m_mouseGridPosition, 9);
    }
}

void EditorState::updateSelectPosition()
{
    m_selectSprite.setPosition(static_cast<float>(m_mouseGridPosition.x) * 32.f, static_cast<float>(m_mouseGridPosition.y) * 32.f);
}

void EditorState::updateView()
{
    m_mainView.reset(sf::FloatRect(0.f, 0.f, 32.f * m_visibleTileCount.x, 32.f * m_visibleTileCount.y));
    m_mainView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    m_window.setView(m_mainView);
}

//*Methods
void EditorState::update(float const &dFrame)
{
    updateMousePosition();
    updateKeybinds();
    updateView();
    updateSelectPosition();
}

void EditorState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = &m_window;
    }

    m_tileMap.render(*target);
    target->draw(layer);
}