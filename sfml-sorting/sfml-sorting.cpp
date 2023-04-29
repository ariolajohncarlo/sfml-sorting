// sfml-sorting.cpp : Defines the entry point for the application.
//

#include "sfml-sorting.h"
#include "RandomNumberGenerator.h"
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    const int WINDOW_HEIGHT = 100;
    sf::RenderWindow window(sf::VideoMode(500, WINDOW_HEIGHT), "Bubble sort demo");
    RandomNumberGenerator rng(1, WINDOW_HEIGHT);
    const int INTERVAL = 10;
    std::vector<sf::RectangleShape> rectangles;

    for (int i = 0; i < 50; ++i)
    {
        auto height = static_cast<float>(rng.GenerateRandomNumber());
        sf::RectangleShape rectangle(sf::Vector2f{10, height});
        rectangle.setOutlineColor(sf::Color::White);
        rectangle.setOutlineThickness(1);
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setPosition(INTERVAL * i, WINDOW_HEIGHT);
        rectangle.setOrigin(sf::Vector2f{0, height});
        rectangles.push_back(rectangle);
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
        for(const auto& rectangle : rectangles)
        {
            window.draw(rectangle);
        }
        window.display();
    }

    return 0;
}
