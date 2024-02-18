#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject(sf::Vector2f position, float angle)
        : position(position), angle(angle) {};

    virtual void update(float delta_time) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    sf::Vector2f position;
    float angle;
};
