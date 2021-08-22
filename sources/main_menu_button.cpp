#include "main_menu_button.h"

[[maybe_unused]] MainMenuButton::MainMenuButton(const std::string& text, const sf::Vector2<float>& buttonPosition,
               const sf::Vector2<float>& buttonSize, const sf::Color& textColor,
               unsigned int charSize) {
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

[[maybe_unused]] void MainMenuButton::SetFont(const sf::Font& font) noexcept {
    text_.setFont(font);
}

[[maybe_unused]] void MainMenuButton::SetColor(const sf::Color& color) noexcept {
    button_.setFillColor(color);
}

[[maybe_unused]] void MainMenuButton::SetPosition(const sf::Vector2<float>& newPosition) noexcept {
    button_.setPosition(newPosition);
}

[[maybe_unused]] void MainMenuButton::MagnifyingAnimation() noexcept {
    sf::Vector2<float> difference = increasedSize_ - button_.getSize();
    button_.setSize(increasedSize_);
    button_.setPosition(button_.getPosition().x - difference.x / 2,
                        button_.getPosition().y - difference.y / 2);
    text_.setCharacterSize(increasedCharSize_);
    text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                      button_.getPosition().y + button_.getSize().y / 2 - text_.getLocalBounds().height / 2);
}

[[maybe_unused]] void MainMenuButton::ShrinkingAnimation() noexcept {
    sf::Vector2<float> difference = button_.getSize() - normalSize_;
    button_.setSize(normalSize_);
    button_.setPosition(button_.getPosition().x + difference.x / 2,
                        button_.getPosition().y + difference.y / 2);
    text_.setCharacterSize(normalCharSize_);
    text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                      button_.getPosition().y + button_.getSize().y / 2 - text_.getLocalBounds().height / 2);
}

[[maybe_unused]] void MainMenuButton::Draw(sf::RenderWindow& window) const noexcept {
    window.draw(button_);
    window.draw(text_);
}



[[maybe_unused]] void MainMenuButton::SetSize(const sf::Vector2<float>& newSize) noexcept {
    button_.setSize(newSize);
}

[[maybe_unused]] auto MainMenuButton::IsOverMouse(sf::RenderWindow& window) const noexcept -> bool {
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
