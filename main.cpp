#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Asteroids");
    sf::Clock clock;
    
    Game::begin(window);

    while (window.isOpen())
    {
        sf::Event event;
        float delta_time = clock.restart().asSeconds();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Game::update(delta_time, window);

        window.display();
    }

    return 0;
}