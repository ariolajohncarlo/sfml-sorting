#include "Application.h"
#include "RandomNumberGenerator.h"

#include <vector>
#include <thread>

namespace
{
    constexpr int WINDOW_HEIGHT = 600;
    constexpr int BAR_COUNT = 100;
    constexpr int INTERVAL = 10;
}

namespace app
{
    Application::Application() :
        m_window{sf::VideoMode(BAR_COUNT * 10, WINDOW_HEIGHT), "Bubble sort demo"},
        m_bars{GenerateBars()}
    {
    }

    void Application::Run()
    {
        while (m_window.isOpen())
        {
            sf::Event event;
            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window.close();
                }
            }

            BubbleSort();

            m_window.display();
        }
    }

    std::vector<shapes::Bar> Application::GenerateBars()
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

    void Application::BubbleSort()
    {
        for (int i = 0; i < (m_bars.size() - 1); ++i)
        {
            bool sorted = true;

            for (int j = 0; j < (m_bars.size() - i - 1); ++j)
            {
                auto& currentBar = m_bars[j];
                auto& nextBar = m_bars[j + 1];

                if (nextBar.GetHeight() < currentBar.GetHeight())
                {
                    std::swap(currentBar, nextBar);
                    sorted = false;

                    const auto windowHeight = m_window.getSize().y;
                    currentBar.setPosition(INTERVAL * j, windowHeight);
                    nextBar.setPosition(INTERVAL * (j + 1), windowHeight);

                    DisplayBars();

                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }
            }

            if (sorted)
            {
                break;
            }
        }
    }

    void Application::DisplayBars()
    {
        m_window.clear();

        for(const auto& bar : m_bars)
        {
            m_window.draw(bar);
        }

        m_window.display();
    }
}
