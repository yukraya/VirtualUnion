#include "MapLoader.hpp"

//*Constructors & Destructors
MapLoader::MapLoader()
{
    m_size.x = 0;
    m_size.y = 0;
    m_mapOpacity = 100;
}

MapLoader::MapLoader(std::string const &directory)
{
    m_size.x = 0;
    m_size.y = 0;
    m_mapOpacity = 100;
    read(directory);
}
MapLoader::~MapLoader()
{

}

//*Integrated Assignment Operator
Grid<int> const & MapLoader::operator[](std::size_t const &y) const
{
    assert(y < m_map.size() && "");
    return *(m_map[y]);
}

//*Methods
void MapLoader::read(std::string const &directory)
{
    m_file.open(directory);

    if(m_file)
    {
        m_file >> m_size.x >> m_size.y >> m_mapOpacity;

        for(std::size_t i {0} ; i < 10 ; i++) //10 layers
        {
            std::cout << "Adding Layer : " << i << std::endl;
            m_map.push_back(std::make_unique<Grid<int>>(m_size.x, m_size.y));

            for(std::size_t j {0} ; j < m_size.y ; j++)
            {
                for(std::size_t k {0} ; k < m_size.x ; k++)
                {
                    m_file >> m_map[i]->operator()(k, j);
                }
            }
        }
    }
    else
    {
        std::cout << "Error loading " << directory << std::endl;
    }

    m_file.close();
}