#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"
#include "TileMap.hpp"
#include "SystemFunctions.hpp"
#include "Layer.hpp"

class EditorState
    :public State
{
    public:
    //*Constructors & Destructors
        explicit EditorState() = delete;
        explicit EditorState(sf::RenderWindow &window, TileSet const &tileSet, std::map<std::string, bool> const &keybinds);
        virtual ~EditorState();

    //*Virtual Methods (HERITED)
        void update(float const &dFrame);
        void render(sf::RenderTarget *target = nullptr);

    private:
    //*Initialisation Functions
        void initView();
        void initSprite();

    //*Functions
        void updateMousePosition();
        void updateKeybinds();
        void updateSelectPosition();
        void updateView();

    //*Attributes
       TileMap m_tileMap;
       sf::View m_mainView;
       sf::RectangleShape m_selectSprite;
       Layer layer;
       sf::Vector2i m_mouseWindowPosition;
       sf::Vector2f m_mouseMainViewPosition;
       sf::Vector2u m_mouseGridPosition;
       sf::Vector2f m_visibleTileCount;
};

#endif //EDITORSTATE_HPP