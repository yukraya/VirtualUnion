#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"
#include "TileMap.hpp"

class EditorState
    :public State
{
    public:
    //*Constructors & Destructors
        explicit EditorState(sf::RenderWindow &window, TileSet const &tileSet);
        virtual ~EditorState();

    //*Virtual Methods (HERITED)
        void update(float const &dFrame);
        void render(sf::RenderTarget *target = nullptr);

    private:
        TileMap m_tileMap;
};

#endif //EDITORSTATE_HPP