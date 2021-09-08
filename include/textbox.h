#ifndef WHO_IS_BILLY_HERE_TEXTBOX_H
#define WHO_IS_BILLY_HERE_TEXTBOX_H

#pragma once

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>
#include <algorithm>

namespace Keys {
    const int DELETE = 8;
    const int ENTER = 13;
    const int ESCAPE = 27;
}

class TextBox final {
private:
    sf::Text textBox_;
    std::ostringstream text_;

    sf::Font font_;
    sf::RectangleShape frame_;
    sf::Texture texture_;

    const int limit_ = 20;

    bool isOpen_ = false;

public:
    TextBox();

    auto IsOpen() const noexcept -> bool;

    void Draw(sf::RenderWindow& window) const noexcept;
    void EnterText(sf::Event& event);

private:
    void InputLogic(int charTyped);
    void DeleteLastChar();
};

#endif //WHO_IS_BILLY_HERE_TEXTBOX_H
