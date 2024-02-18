#pragma once

#include "Global.h"
#include "GameObject.h"

constexpr float ASTEROID_WIDTH = 60.0f;
constexpr float ASTEROID_HEIGHT = 40.0f;

constexpr float ASTEROID_SPIN = 25.0f;
constexpr float ASTEROID_SPEED = 100.0f;
constexpr float ASTEROID_SPAWN_TIMER = 3.0f;

class Asteroid : public GameObject {
public:
    Asteroid(sf::Vector2f direction, sf::Vector2f position);

    void update(float delta_time) override;

    void render(sf::RenderWindow& window);

    static sf::Vector2f getDirection();

    static sf::Vector2f getPosition(sf::RenderWindow& window);

private:
    sf::VertexArray array;
    sf::Vector2f direction;
};

