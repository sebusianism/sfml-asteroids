#pragma once

#include "Global.h"
#include "GameObject.h"
#include "Bullet.h"

constexpr float PLAYER_WIDTH = 50.0f;
constexpr float PLAYER_HEIGHT = 40.0f;

constexpr float TURN_SPEED = 200.0f;
constexpr float PLAYER_SPEED = 500.0f;

class Player : public GameObject {
public:
    Player();

    void render(sf::RenderWindow& window) override;

    void update(float delta_time) override;

private:
    sf::VertexArray array;
    float shoot_timer;
};
