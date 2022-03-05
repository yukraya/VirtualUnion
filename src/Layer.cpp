#include "Layer.hpp"

//*Constructors & Destructors
Layer::Layer()
{

}

Layer::~Layer()
{
    clear();
}

//*Virtual Method (HERITED)
void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(std::vector<sf::Drawable const *>::const_iterator it {m_drawableList.begin()} ; it != m_drawableList.end() ; it++)
    {
        target.draw(*(*(it)), states);
    }
}

//*Methods
void Layer::clear()
{
    while(!(m_drawableList.empty()))
    {
        m_drawableList.front() = nullptr;
        m_drawableList.pop_back();
    }
}

void Layer::add(sf::Drawable const &item)
{
    m_drawableList.push_back(&item);
}
