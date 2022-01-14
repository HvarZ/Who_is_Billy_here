#include "main_button.h"

[[maybe_unused]] MainButton::MainButton(const std::string& text, const sf::Vector2<float>& buttonPosition,
               const sf::Vector2<float>& buttonSize, const std::string& fileName, const sf::Color& textColor,
               unsigned int charSize) : isMagnifying(false) {
    font_.loadFromFile("../fonts/Pixelio_true.otf");
    frame_.loadFromFile(fileName);

    text_.setString(text);
    text_.setFont(font_);
    text_.setFillColor(textColor);
    text_.setCharacterSize(charSize);

    button_.setPosition(buttonPosition);
    button_.setSize(buttonSize);
    button_.setTexture(&frame_);
    normalSize_ = buttonSize;
    increasedSize_ = buttonSize * ButtonSettings::SIZE_COEFFICIENT;

    text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                      button_.getPosition().y + text_.getLocalBounds().height / 2);

}




[[maybe_unused]] void MainButton::MagnifyingAnimation() noexcept {
    if (isMagnifying){
        return;
    }
    sf::Vector2<float> difference = increasedSize_ - button_.getSize();
    button_.setSize(increasedSize_);
    button_.setPosition(button_.getPosition().x - difference.x / 2,
                        button_.getPosition().y - difference.y / 2);
    text_.setCharacterSize(ButtonSettings::INCREASED_CHAR_SIZE);
    text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                      button_.getPosition().y + text_.getLocalBounds().height / 2);
    isMagnifying = true;
}

[[maybe_unused]] void MainButton::ShrinkingAnimation() noexcept {
    if (!isMagnifying) {
        return;
    }
    sf::Vector2<float> difference = button_.getSize() - normalSize_;
    button_.setSize(normalSize_);
    button_.setPosition(button_.getPosition().x + difference.x / 2,
                        button_.getPosition().y + difference.y / 2);
    text_.setCharacterSize(ButtonSettings::CHAR_SIZE);
    text_.setPosition(button_.getPosition().x + button_.getSize().x / 2 - text_.getLocalBounds().width / 2,
                      button_.getPosition().y + text_.getLocalBounds().height / 2);
    isMagnifying = false;
}

[[maybe_unused]] void MainButton::Draw(sf::RenderWindow& window) const noexcept {
    window.draw(button_);
    window.draw(text_);
}




[[maybe_unused]] auto MainButton::IsOverMouse(sf::RenderWindow& window) const noexcept -> bool {
    return (sf::Mouse::getPosition(window).x < button_.getPosition().x + button_.getLocalBounds().width &&
        sf::Mouse::getPosition(window).x > button_.getPosition().x &&
        sf::Mouse::getPosition(window).y < button_.getPosition().y + button_.getLocalBounds().height &&
        sf::Mouse::getPosition(window).y > button_.getPosition().y);
}

[[maybe_unused]] auto MainButton::IsPressed(sf::RenderWindow &window, sf::Event& event) const noexcept -> bool {
    return IsOverMouse(window) && event.type == sf::Event::MouseButtonPressed;
}

