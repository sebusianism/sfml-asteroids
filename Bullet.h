#pragma once

#include "GameObject.h"

constexpr float BULLET_SPEED = 800.0f;
constexpr float BULLET_DELAY = 0.2f;
constexpr float BULLET_LIFESPAN = 3.0f;

class Bullet : public GameObject {
public:
    Bullet(sf::Vector2f position, sf::Vector2f direction);

    void update(float delta_time) override;

    void render(sf::RenderWindow& window) override;

    bool isExpired() const;

private:
    sf::Vector2f direction;
    sf::CircleShape shape;
    float lifetime;
};

