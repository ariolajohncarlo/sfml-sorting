// sfml-sorting.cpp : Defines the entry point for the application.
//

#include "shapes/Bar.h"
#include "utils/RandomNumberGenerator.h"
#include<algorithm>
#include<thread>
#include<chrono>
#include <SFML/Graphics.hpp>

#include <vector>


void bubbleSort(std::vector<Bar>& bars, sf::RenderWindow& window, const int INTERVAL) {
    for (int i = 0; i < bars.size() - 1; ++i) {
        bool sorted = true;
        for (int j = 0; j < bars.size() - i - 1; ++j) {
            if (bars[j + 1].getSize().y > bars[j].getSize().y) {
                std::swap(bars[j + 1], bars[j]);
                sorted = false;
                // bar position update
                bars[j].setPosition(INTERVAL * j,  window.getSize().y);
                bars[j + 1].setPosition(INTERVAL * (j + 1),  window.getSize().y);

                window.clear();
                for (const auto& bar : bars) {
                    window.draw(bar);
                }
                window.display();

                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
        if(sorted) break;
    }
}


int main()
{
    const int WINDOW_HEIGHT = 400;
    const int BAR_COUNT = 50;
    const int BAR_WIDTH = 10.0f;
    const int GAP = 5;
    sf::RenderWindow window(sf::VideoMode(BAR_COUNT * BAR_WIDTH + (BAR_COUNT-1)*GAP, WINDOW_HEIGHT), "Bubble sort demo");
    RandomNumberGenerator rng(1, WINDOW_HEIGHT);
    const int INTERVAL = BAR_WIDTH + GAP;
    std::vector<Bar> bars;
    for (int i = 0; i < BAR_COUNT; ++i)
    {
        auto height = static_cast<float>(rng.GenerateRandomNumber());
        Bar bar(height);
        bar.setPosition(INTERVAL * i , WINDOW_HEIGHT);
        bars.push_back(bar);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter) {
                    bubbleSort(bars, window, INTERVAL);
                }
            }
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
