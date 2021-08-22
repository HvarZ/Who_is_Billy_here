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

    [[maybe_unused]] MainMenuButton(const std::string& text, const sf::Vector2<float>& buttonPosition,
           const sf::Vector2<float>& buttonSize, const sf::Color& textColor = sf::Color::Green,
           unsigned int charSize = 50);

    [[maybe_unused]] void SetFont(const sf::Font& font) noexcept;

    [[maybe_unused]] void SetColor(const sf::Color& color) noexcept;

    [[maybe_unused]] void SetPosition(const sf::Vector2<float>& newPosition) noexcept;

    [[maybe_unused]] void MagnifyingAnimation() noexcept;

    [[maybe_unused]] void ShrinkingAnimation() noexcept;

    [[maybe_unused]] void Draw(sf::RenderWindow& window) const noexcept;

    [[maybe_unused]] void SetSize(const sf::Vector2<float>& newSize) noexcept;

    [[maybe_unused]] auto IsOverMouse(sf::RenderWindow& window) const noexcept -> bool;

};

#endif //WHO_IS_BILLY_HERE_MAIN_MENU_BUTTON_H
