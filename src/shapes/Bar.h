#pragma once

#include <SFML/Graphics.hpp>

namespace shapes
{
    class Bar : public sf::RectangleShape
    {
    public:
        Bar(float height);
        float GetHeight() const;
    };
}
