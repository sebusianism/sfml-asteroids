#pragma once

#include <vector>
#include "GameObject.h"

class Game {
public:
	static std::vector<GameObject*> objects;

	static void begin(sf::RenderWindow& window);
	static void update(float delta_time, sf::RenderWindow& window);

private:
	static float asteroid_spawn_timer;
};

