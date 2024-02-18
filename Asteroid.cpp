#include "Asteroid.h"
#include "Global.h"
#include <random>

Asteroid::Asteroid(sf::Vector2f direction, sf::Vector2f position)
    : GameObject(position, 0), direction(direction), array(sf::LinesStrip, 15) {
        array[0].position = sf::Vector2f(-20, 0);
        array[1].position = sf::Vector2f(-25, 5);
        array[2].position = sf::Vector2f(-15, 10);
        array[3].position = sf::Vector2f(-10, 20);
        array[4].position = sf::Vector2f(0, 15);
        array[5].position = sf::Vector2f(10, 20);
        array[6].position = sf::Vector2f(20, 10);
        array[7].position = sf::Vector2f(25, 5);
        array[8].position = sf::Vector2f(20, 0);
        array[9].position = sf::Vector2f(25, -5);
        array[10].position = sf::Vector2f(15, -15);
        array[11].position = sf::Vector2f(10, -20);
        array[12].position = sf::Vector2f(0, -15);
        array[13].position = sf::Vector2f(-10, -20);
        array[14].position = array[0].position;

        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].color = sf::Color::White;
        }

        float scale = static_cast<float>(rand()) / RAND_MAX * 3.0f + 1.0f;
        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].position *= scale;
        }
    }

void Asteroid::update(float delta_time) {
    position += ASTEROID_SPEED * direction * delta_time;
    angle += ASTEROID_SPIN * delta_time;

    if (position.x < ASTEROID_WIDTH / 2.0f) {
        direction.x = abs(direction.x);
    }
    else if (position.x > SCREEN_WIDTH - ASTEROID_WIDTH / 2.0f) {
        direction.x = -abs(direction.x);
    }

    if (position.y < ASTEROID_HEIGHT / 2.0f) {
        direction.y = abs(direction.y);
    }
    else if (position.y > SCREEN_HEIGHT - ASTEROID_HEIGHT / 2.0f) {
        direction.y = -abs(direction.y);
    }
}

void Asteroid::render(sf::RenderWindow& window) {
    window.draw(array, sf::Transform().translate(position).rotate(angle));
}

sf::Vector2f Asteroid::getDirection() {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<float> dist(0.0f, 2.0f * M_PI);

    float angle = dist(gen);
    return sf::Vector2f(cos(angle), sin(angle));
}

sf::Vector2f Asteroid::getPosition(sf::RenderWindow& window) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<float> x_dist(0.0f, static_cast<float>(window.getSize().x));
    std::uniform_real_distribution<float> y_dist(0.0f, static_cast<float>(window.getSize().y));

    float x = x_dist(gen);
    float y = y_dist(gen);

    return sf::Vector2f(x, y);
}
