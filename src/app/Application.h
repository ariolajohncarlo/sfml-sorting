#pragma once

#include "Bar.h"

#include <SFML/Graphics.hpp>
#include <vector>

namespace app
{
    class Application
    {
    public:
        Application();
        void Run();

    private:
        sf::RenderWindow m_window;
        std::vector<shapes::Bar> m_bars;

        std::vector<shapes::Bar> GenerateBars();
        void BubbleSort();
        void DisplayBars();
    };
}
