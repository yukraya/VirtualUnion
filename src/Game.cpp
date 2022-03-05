#include "Game.hpp"

//*Initialisation Functions
void Game::initWindow()
{
    m_window.create(sf::VideoMode(1080, 720), "Virtual");
    m_window.setFramerateLimit(120);
    m_window.setKeyRepeatEnabled(false);
}

void Game::initKeybinds()
{
    m_userControls["UP"] = sf::Keyboard::Key::Z;
    m_userControls["DOWN"] = sf::Keyboard::Key::S;
    m_userControls["LEFT"] = sf::Keyboard::Key::Q;
    m_userControls["RIGHT"] = sf::Keyboard::Key::D;

    m_keybinds["UP"] = false;
    m_keybinds["DOWN"] = false;
    m_keybinds["LEFT"] = false;
    m_keybinds["RIGHT"] = false;

    m_keybinds["LCLICK"] = false;
    m_keybinds["RCLICK"] = false;
}

void Game::initResources()
{
    m_tileSet.read(getProjectRootPath() + "/share/tileset/set.png");
}

void Game::initState()
{
    m_state.push(std::make_unique<EditorState>(m_window, m_tileSet));
}

//*Constructors & Destructors
Game::Game()
{
    m_close = false;
    initWindow();
    initKeybinds();
    initResources();
    initState();
}

Game::~Game()
{
    while(!(m_state.empty()))
    {
        m_state.pop();
    }
}

//*Internal Functions
void Game::resetKeybinds()
{
    for(std::map<std::string, bool>::iterator it {m_keybinds.begin()} ; it != m_keybinds.end() ; it++)
    {
        it->second = false;
    }
}

void Game::updateSFMLEvents()
{
    while(m_window.pollEvent(m_event))
    {
        if(m_event.type == sf::Event::Closed)
        {
            m_close = true;
        }

        if(m_window.hasFocus())
        {
            if(m_event.type == sf::Event::KeyPressed)
            {
                if(m_event.key.code == m_userControls.at("UP")) m_keybinds.at("UP") = true;
                if(m_event.key.code == m_userControls.at("DOWN")) m_keybinds.at("DOWN") = true;
                if(m_event.key.code == m_userControls.at("LEFT")) m_keybinds.at("LEFT") = true;
                if(m_event.key.code == m_userControls.at("RIGHT")) m_keybinds.at("RIGHT") = true;
            }
            if(m_event.type == sf::Event::MouseButtonPressed)
            {
                if(m_event.mouseButton.button == sf::Mouse::Right) m_keybinds.at("RCLICK") = true;
                if(m_event.mouseButton.button == sf::Mouse::Left) m_keybinds.at("LCLICK") = true;
            }
        }
    }
}

void Game::updateDFrame()
{
    m_dFrame = m_clock.restart().asSeconds();
}

void Game::updateState()
{
    if(!(m_state.empty()))
    {
        m_state.top()->update(m_dFrame);
    }
}

//*Methods
void Game::update()
{
    updateDFrame();
    resetKeybinds();
    updateSFMLEvents();
    updateState();
}

void Game::render()
{
    m_window.clear();

    m_state.top()->render();

    m_window.display();
}

void Game::run()
{
    while(!m_close)
    {
        update();
        render();
    }

    m_window.close();
}