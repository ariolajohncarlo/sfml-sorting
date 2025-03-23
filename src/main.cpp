// main.cpp : Defines the entry point for the application.
//

#include "shapes/Bar.h"
#include "utils/RandomNumberGenerator.h"

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <chrono>
#include <thread>
#include <vector>

namespace
{
    constexpr int WINDOW_HEIGHT = 600;
    constexpr int BAR_COUNT = 100;
    constexpr int INTERVAL = 10;
}

std::vector<shapes::Bar> GenerateBars()
{
    RandomNumberGenerator rng(1, WINDOW_HEIGHT);

    std::vector<shapes::Bar> bars;

    for (int i = 0; i < BAR_COUNT; ++i)
    {
        auto height = static_cast<float>(rng.GenerateRandomNumber());
        shapes::Bar bar(height);

        bar.setPosition(INTERVAL * i, WINDOW_HEIGHT);
        bars.push_back(bar);
    }

    return bars;
}

void DisplayBars(sf::RenderWindow& window, std::vector<shapes::Bar>& bars)
{
    window.clear();

    for(const auto& bar : bars)
    {
        window.draw(bar);
    }

    window.display();
}

void BubbleSort(sf::RenderWindow& window, std::vector<shapes::Bar>& bars)
{
    for (int i = 0; i < (bars.size() - 1); ++i)
    {
        bool sorted = true;

        for (int j = 0; j < (bars.size() - i - 1); ++j)
        {
            auto& currentBar = bars[j];
            auto& nextBar = bars[j + 1];

            if (nextBar.GetHeight() < currentBar.GetHeight())
            {
                std::swap(currentBar, nextBar);
                sorted = false;

                const auto windowHeight = window.getSize().y;
                currentBar.setPosition(INTERVAL * j, windowHeight);
                nextBar.setPosition(INTERVAL * (j + 1), windowHeight);

                DisplayBars(window, bars);

                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }

        if (sorted)
        {
            break;
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(BAR_COUNT * 10, WINDOW_HEIGHT), "Bubble sort demo");
    std::vector<shapes::Bar> bars = GenerateBars();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        BubbleSort(window, bars);

        window.display();
    }

    return 0;
}
