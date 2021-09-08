#include <SFML/Graphics.hpp>
#include "main_menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080),
                            "Who's Billy here!", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    MainMenu menu;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                menu.MagnifyButton(window);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                menu.NewGame(window, event);
                menu.Title(window, event);
                menu.Exit(window, event);
            }
        }

        window.clear();
        menu.Draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}