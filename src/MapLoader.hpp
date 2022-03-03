#ifndef MAPLOADER_HPP
#define MAPLOADER_HPP

#include "Grid.hpp"

class MapLoader
{
    public:
    //*Constructors & Destructors
        explicit MapLoader();
        explicit MapLoader(std::string const &directory);
        ~MapLoader();

    //*Integrated Assignment Operator
        Grid<int> const & operator[](std::size_t const &y) const;

    //*Methods
        void read(std::string const &directory);

    private:
    //*Attributes
        std::vector<std::unique_ptr<Grid<int>>> m_map;
        std::ifstream m_file;

        Size m_size;
        unsigned int m_mapOpacity;
};

#endif //MAPLOADER_HPP