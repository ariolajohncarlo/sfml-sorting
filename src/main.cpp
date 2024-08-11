// sfml-sorting.cpp : Defines the entry point for the application.
//

#include "shapes/Bar.h"
#include "utils/RandomNumberGenerator.h"

#include <SFML/Graphics.hpp>

#include <vector>

int main()
{
    const int WINDOW_HEIGHT = 100;
    const int BAR_COUNT = 50;

    sf::RenderWindow window(sf::VideoMode(500, WINDOW_HEIGHT), "Bubble sort demo");
    RandomNumberGenerator rng(1, WINDOW_HEIGHT);
    const int INTERVAL = 10;
    std::vector<Bar> bars;

    for (int i = 0; i < BAR_COUNT; ++i)
    {
        auto height = static_cast<float>(rng.GenerateRandomNumber());
        Bar bar(height);

        bar.setPosition(INTERVAL * i, WINDOW_HEIGHT);
        bars.push_back(bar);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(const auto& bar : bars)
        {
            window.draw(bar);
        }

        window.display();
    }

    return 0;
}
