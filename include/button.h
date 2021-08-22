#ifndef WHO_IS_BILLY_HERE_BUTTON_H
#define WHO_IS_BILLY_HERE_BUTTON_H

#include <SFML/Graphics.hpp>
#include <utility>

class Button final {
private:
    sf::RectangleShape button_;
    sf::Text text_;
    sf::Font font_;
public:
    Button() = default;

    Button(const std::string& text, const sf::Vector2<float>& buttonPosition,
           const sf::Vector2<float>& buttonSize, const sf::Color& textColor = sf::Color::Green,
           unsigned int&& charSize = 50) {
        text_.setString(text);

        font_.loadFromFile("../fonts/Pixelio_true.otf");
        text_.setFont(font_);
        text_.setFillColor(textColor);
        text_.setCharacterSize(charSize);

        button_.setPosition(buttonPosition);
        button_.setSize(buttonSize);

        text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                          button_.getPosition().y + button_.getSize().y / 2 - text_.getLocalBounds().height / 2);

    }

    void SetFont(const sf::Font& font) noexcept {
        text_.setFont(font);
    }

    void setColor(const sf::Color& color) noexcept {
        button_.setFillColor(color);
    }


    void Draw(sf::RenderWindow& window) const noexcept {
        window.draw(button_);
        window.draw(text_);
    }


    void setSize(const sf::Vector2<float>& newSize) {
        button_.setSize(newSize);
    }

    auto IsOverMouse(sf::RenderWindow& window) const noexcept -> bool {
        auto mouseX = sf::Mouse::getPosition(window).x;
        auto mouseY = sf::Mouse::getPosition(window).y;

        auto btnPosX = button_.getPosition().x;
        auto btnPosY = button_.getPosition().y;

        auto btnXPosWidth = btnPosX + button_.getLocalBounds().width;
        auto btnYPosHeight = btnPosY + button_.getLocalBounds().height;

        if (mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY) {
            return true;
        }

        return false;
    }

};

#endif //WHO_IS_BILLY_HERE_BUTTON_H
