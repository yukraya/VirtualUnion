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
        explicit EditorState(sf::RenderWindow &window, TileSet const &tileSet);
        virtual ~EditorState();

    //*Virtual Methods (HERITED)
        void update(float const &dFrame);
        void render(sf::RenderTarget *target = nullptr);

    private:
    //*Initialisation Functions
        void initTileMap();

    //*Attributes
       std::unique_ptr<TileMap> m_tileMap;
       Layer m_layer;
       Tile* m_tile;
};

#endif //EDITORSTATE_HPP