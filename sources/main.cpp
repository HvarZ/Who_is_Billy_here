#include <SFML/Graphics.hpp>
#include "button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Who's Billy here!", sf::Style::Fullscreen);
    Button button("New game", {200, 100}, {400, 200});
    sf::Font font;
    font.loadFromFile("../fonts/Pixelio_true.otf");
    sf::Text testText("Hello, I im Billy", font);
    testText.setFillColor(sf::Color::White);
    testText.setCharacterSize(50);
    testText.setPosition(static_cast<float>(window.getSize().x) / 2 - (testText.getLocalBounds().width / 2),
                         static_cast<float>(window.getSize().y) / 2 - testText.getLocalBounds().height / 2);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                if (button.IsOverMouse(window)) {
                    button.setSize({440, 220});
                } else {
                    button.setSize({400, 200});
                }
            }
        }

        window.clear();
        window.draw(testText);
        button.Draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}