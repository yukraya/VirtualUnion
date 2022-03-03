#ifndef GRID_HPP
#define GRID_HPP

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

struct Size
{
    std::size_t x;
    std::size_t y;
};

template<typename T>
class Grid
{
    private:
    //*Attributes
        std::vector<std::vector<T>> m_grid;
        Size m_size;

    public:
    //*Constructors & Destructors
        Grid()
        {
            m_size.x = 0;
            m_size.y = 0;
        }

        Grid(std::size_t x, std::size_t y)
            :m_grid(x)
        {
            m_size.x = x;
            m_size.y = y;

            for(std::size_t i {0} ; i < m_size.x ; i++)
            {
                m_grid[i].resize(y);
            }
        }

        ~Grid()
        {

        }

    //*Integrated Assignment Operator
        T& operator()(unsigned int const &x, unsigned int const &y)
        {
            assert(x < m_size.x && y < m_size.y && "Higher than array size");
            return m_grid[x][y];
        }

    //*Methods
        void pushBot(std::size_t size)
        {
            assert(size > 0 && "Size is lower than 0");
            for(std::size_t i {0} ; i < m_size.x ; i++)
            {
                for(std::size_t j {0} ; j < size ; j++)
                {
                    m_grid[i].push_back();
                }
            }
             m_size.y += size;
        }
        void pushRight(std::size_t size)
        {
            assert(size > 0 && "Size is lower than 0");
            for(std::size_t i {0} ; i < size ; i++)
            {
                m_grid.push_back(std::vector<T>(m_size.y));
            }

            m_size.x += size;
        }

        void draw()
        {
            for(std::size_t i {0} ; i < m_size.y ; i++)
            {
                for(std::size_t j {0} ; j < m_size.x ; j++)
                {
                    std::cout << m_grid[j][i];
                }
                std::cout << std::endl;
            }
        }

        Size getSize()
        {
            return m_size;
        }
};

#endif //GRID_HPP