#ifndef WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H
#define WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H

#pragma once

#include <SFML/Graphics.hpp>
#include <utility>


namespace ButtonSettings {
    const float SIZE_COEFFICIENT = 1.2f;
    const unsigned int CHAR_SIZE = 50;
    const unsigned int INCREASED_CHAR_SIZE = 60;
    const sf::Vector2<float> BUTTON_SIZE(490, 105);
}

class MainMenuButton final {
private:
    sf::RectangleShape button_;
    sf::Text text_;

    sf::Texture frame_;
    sf::Font font_;

    sf::Vector2<float> increasedSize_;
    sf::Vector2<float> normalSize_;

    bool isMagnifying = false;
public:
    // Constructors
    MainMenuButton() = delete;
    [[maybe_unused]] explicit MainMenuButton(const std::string& text, const sf::Vector2<float>& buttonPosition,
           const sf::Vector2<float>& buttonSize = ButtonSettings::BUTTON_SIZE, const sf::Color& textColor = sf::Color::White,
           unsigned int charSize = ButtonSettings::CHAR_SIZE);

    // Methods
    [[maybe_unused]] void MagnifyingAnimation() noexcept;
    [[maybe_unused]] void ShrinkingAnimation() noexcept;
    [[maybe_unused]] void Draw(sf::RenderWindow& window) const noexcept;
    [[maybe_unused]] auto IsOverMouse(sf::RenderWindow& window) const noexcept -> bool;
    [[maybe_unused]] auto IsPressed(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool;
};

#endif //WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H
