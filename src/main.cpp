// sfml-sorting.cpp : Defines the entry point for the application.
//

#include "shapes/Bar.h"
#include "utils/RandomNumberGenerator.h"

#include <SFML/Graphics.hpp>

#include <vector>

namespace
{
    constexpr int WINDOW_HEIGHT = 600;
    constexpr int BAR_COUNT = 100;
    constexpr int INTERVAL = 10;
}

std::vector<Bar> GenerateBars()
{
    RandomNumberGenerator rng(1, WINDOW_HEIGHT);

    std::vector<Bar> bars;

    for (int i = 0; i < BAR_COUNT; ++i)
    {
        auto height = static_cast<float>(rng.GenerateRandomNumber());
        Bar bar(height);

        bar.setPosition(INTERVAL * i, WINDOW_HEIGHT);
        bars.push_back(bar);
    }

    return bars;
}

void DisplayBars(sf::RenderWindow& window, std::vector<Bar>& bars)
{
    window.clear();

    for(const auto& bar : bars)
    {
        window.draw(bar);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(BAR_COUNT * 10, WINDOW_HEIGHT), "Bubble sort demo");
    std::vector<Bar> bars = GenerateBars();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        DisplayBars(window, bars);

        window.display();
    }

    return 0;
}
