#include "Bar.h"

namespace
{
    const float DEFAULT_WIDTH = 10.0f;
}

namespace shapes
{
    Bar::Bar(float height) :
        RectangleShape(sf::Vector2f{DEFAULT_WIDTH, height})
    {
        this->setFillColor(sf::Color::Green);
        this->setOrigin(sf::Vector2f{0, height});
    }

    float Bar::GetHeight() const
    {
        return getSize().y;
    }
}
