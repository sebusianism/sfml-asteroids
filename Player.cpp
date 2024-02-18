#include "Player.h"
#include "Game.h"

Player::Player()
    : GameObject(sf::Vector2f(600, 450), -90), array(sf::LinesStrip, 5), shoot_timer() {
    array[0].position = sf::Vector2f(20, 0);
    array[1].position = sf::Vector2f(-30, -20);
    array[2].position = sf::Vector2f(-15, 0);
    array[3].position = sf::Vector2f(-30, 20);
    array[4].position = array[0].position;

    for (size_t i = 0; i < array.getVertexCount(); i++) {
        array[i].color = sf::Color::White;
    }
}

void Player::render(sf::RenderWindow& window){
    window.draw(array, sf::Transform().translate(position).rotate(angle));
}

void Player::update(float delta_time) {
    shoot_timer -= delta_time;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        double rad = angle * (M_PI / 180.0f);

        position.x += cos(rad) * PLAYER_SPEED * delta_time;
        position.y += sin(rad) * PLAYER_SPEED * delta_time;

        position.x = std::min(std::max(position.x, PLAYER_WIDTH / 2.0f),
            SCREEN_WIDTH - PLAYER_WIDTH / 2.0f);
        position.y = std::min(std::max(position.y, PLAYER_HEIGHT / 2.0f),
            SCREEN_HEIGHT - PLAYER_HEIGHT / 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        double rad = angle * (M_PI / 180.0f);

        position.x -= cos(rad) * PLAYER_SPEED * delta_time;
        position.y -= sin(rad) * PLAYER_SPEED * delta_time;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        angle -= TURN_SPEED * delta_time;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        angle += TURN_SPEED * delta_time;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shoot_timer <= 0.0f) {
        shoot_timer = BULLET_DELAY;
        double rad = angle * (M_PI / 180.0f);
        Game::objects.push_back(new Bullet(position, sf::Vector2f(cos(rad), sin(rad))));
    }
}
