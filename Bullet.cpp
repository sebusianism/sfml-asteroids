#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
    : shape(5.0f), direction(direction), GameObject(position, 0.0f), lifetime(BULLET_LIFESPAN) {};

void Bullet::update(float delta_time){
    position += direction * BULLET_SPEED * delta_time;
    lifetime -= delta_time;

    if (position.x < 0 || position.x > 1200 || position.y < 0 || position.y > 900) {
        lifetime = 0;
    }
}

void Bullet::render(sf::RenderWindow& window) {
    window.draw(shape, sf::Transform().translate(position));
}

bool Bullet::isExpired() const {
    return lifetime <= 0.0f;
}

