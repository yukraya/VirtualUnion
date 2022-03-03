#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"

class EditorState
    :public State
{
    public:
    //*Constructors & Destructors
        explicit EditorState(sf::RenderWindow &window);
        virtual ~EditorState();

    //*Virtual Methods (HERITED)
        void update(float const &dFrame);
        void render(sf::RenderTarget *target = nullptr);

    private:
};

#endif //EDITORSTATE_HPP