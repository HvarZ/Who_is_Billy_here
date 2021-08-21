#ifndef WHO_IS_BILLY_HERE_BUTTON_H
#define WHO_IS_BILLY_HERE_BUTTON_H

#include <SFML/Graphics.hpp>
#include <utility>

class Button {
private:
    sf::RectangleShape button_;
    sf::Text text_;
public:
    Button() = default;

    Button(std::string&& text, sf::Vector2&& size, sf::Color&& textColor, unsigned int&& charSize) {
        text_.setString(std::move(text));
        text_.setFillColor(std::move(textColor));
        text_.setCharacterSize(std::move(charSize));

        button_.setSize(std::move(size));

    }

    void SetFont(const sf::Font& font) noexcept {
        text_.setFont(font);
    }

    void SetFont(sf::Font&& font) noexcept {
        text_.setFont(std::move(font));
    }

    void Draw(sf::RenderWindow& window) const noexcept {
        window.draw(button_);
        window.draw(text_);
    }

};

#endif //WHO_IS_BILLY_HERE_BUTTON_H
