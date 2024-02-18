#include "Game.h"
#include "Player.h"
#include "Asteroid.h"

std::vector<GameObject*> Game::objects{};
float Game::asteroid_spawn_timer{};

void Game::begin(sf::RenderWindow& window) {
	objects.push_back(new Player());
	objects.push_back(new Asteroid(Asteroid::getDirection(), Asteroid::getPosition(window)));

	float asteroid_spawn_timer = ASTEROID_SPAWN_TIMER;
}

void Game::update(float delta_time, sf::RenderWindow& window) {
    window.clear();
    asteroid_spawn_timer -= delta_time;

    for (size_t i = 0; i < objects.size(); i++) {
        objects[i]->update(delta_time);
        objects[i]->render(window);

        // delete bullet when it goes off-screen
        if (dynamic_cast<Bullet*>(objects[i]) != nullptr && static_cast<Bullet*>(objects[i])->isExpired()) {
            delete objects[i];
            objects.erase(objects.begin() + i);
            i--;
        }
    }

    if (asteroid_spawn_timer <= 0.0f) {
        // spawn new asteroids on a set timer
        objects.push_back(new Asteroid(Asteroid::getDirection(), Asteroid::getPosition(window)));
        asteroid_spawn_timer = ASTEROID_SPAWN_TIMER;
    }
}