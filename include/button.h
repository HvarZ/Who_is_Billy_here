#ifndef WHO_IS_BILLY_HERE_BUTTON_H
#define WHO_IS_BILLY_HERE_BUTTON_H

#include <SFML/Graphics.hpp>
#include <utility>

class Button final {
private:
    sf::RectangleShape button_;
    sf::Text text_;
public:
    Button() = default;

    Button(const std::string& text, const sf::Vector2<float>& size, const sf::Color& textColor = sf::Color::White, unsigned int&& charSize = 30) {
        text_.setString(text);
        text_.setFillColor(textColor);
        text_.setCharacterSize(charSize);
        button_.setPosition(sf::Vector2f(100, 200));
        button_.setSize(size);

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


    void setSize(const float coefficient) {
        button_.setSize(sf::Vector2<float>(2 * button_.getSize().x, 2 * button_.getSize().y));
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
