#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Layer
    :public sf::Drawable
{
    public:
    //*Constructors & Destructors
        explicit Layer();
        ~Layer();

    //*Virtual Method (HERITED)
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //*Methods
        void clear();
        void add(sf::Drawable const &item);
        //void remove(sf::Drawable const &item);

    private:
    //*Attributes
        std::vector<Drawable const *> m_drawableList;
};


#endif //LAYER_HPP