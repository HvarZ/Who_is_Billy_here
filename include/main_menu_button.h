#ifndef WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H
#define WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H

#include <SFML/Graphics.hpp>
#include <utility>

#define SIZE_COEFFICIENT 1.2f

class MainMenuButton final {
private:
    sf::RectangleShape button_;
    sf::Text text_;

    sf::Font font_;

    sf::Vector2<float> increasedSize_;
    sf::Vector2<float> normalSize_;

    const unsigned int increasedCharSize_ = 60;
    const unsigned int normalCharSize_ = 50;
public:
    MainMenuButton() = default;

    MainMenuButton(const std::string& text, const sf::Vector2<float>& buttonPosition,
           const sf::Vector2<float>& buttonSize, const sf::Color& textColor = sf::Color::Green,
           unsigned int charSize = 50) {
        text_.setString(text);

        font_.loadFromFile("../fonts/Pixelio_true.otf");
        text_.setFont(font_);
        text_.setFillColor(textColor);
        text_.setCharacterSize(charSize);

        button_.setPosition(buttonPosition);
        button_.setSize(buttonSize);
        normalSize_ = buttonSize;
        increasedSize_ = {buttonSize * SIZE_COEFFICIENT};

        text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                          button_.getPosition().y + button_.getSize().y / 2 - text_.getLocalBounds().height / 2);

    }

    void SetFont(const sf::Font& font) noexcept {
        text_.setFont(font);
    }

    void SetColor(const sf::Color& color) noexcept {
        button_.setFillColor(color);
    }

    void SetPosition(const sf::Vector2<float>& newPosition) noexcept {
        button_.setPosition(newPosition);
    }

    void MagnifyingAnimation() {
        sf::Vector2<float> difference = increasedSize_ - button_.getSize();
        button_.setSize(increasedSize_);
        button_.setPosition(button_.getPosition().x - difference.x / 2,
                            button_.getPosition().y - difference.y / 2);
        text_.setCharacterSize(increasedCharSize_);
        text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                          button_.getPosition().y + button_.getSize().y / 2 - text_.getLocalBounds().height / 2);
    }

    void ShrinkingAnimation() {
        sf::Vector2<float> difference = button_.getSize() - normalSize_;
        button_.setSize(normalSize_);
        button_.setPosition(button_.getPosition().x + difference.x / 2,
                            button_.getPosition().y + difference.y / 2);
        text_.setCharacterSize(normalCharSize_);
        text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                          button_.getPosition().y + button_.getSize().y / 2 - text_.getLocalBounds().height / 2);
    }

    void Draw(sf::RenderWindow& window) const noexcept {
        window.draw(button_);
        window.draw(text_);
    }



    void SetSize(const sf::Vector2<float>& newSize) {
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

#endif //WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H
