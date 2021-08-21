#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Who's Billy here!");

    sf::Font font;
    font.loadFromFile("../fonts/Pixelio_true.otf");
    sf::Text testText("Hello, I im Billy", font);
    testText.setFillColor(sf::Color::White);
    testText.setCharacterSize(50);
    testText.setPosition(960 - static_cast<float>(8 * testText.getString().getSize()), 540);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(testText);
        window.display();
    }

    return EXIT_SUCCESS;
}