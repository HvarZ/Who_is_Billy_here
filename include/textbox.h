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
    sf::RenderWindow* window_;

    sf::Text comment_;
    sf::Text textBox_;
    std::ostringstream text_;

    sf::Font font_;
    sf::RectangleShape frame_;
    sf::Texture texture_;

    int limit_;
    float textBoxAdaptedSize_ = 0.f;

    bool isOpen_ = false;

public:
    TextBox() = delete;
    explicit TextBox(sf::RenderWindow& window, const std::string& comment, int limit = 18);

    auto IsOpen() const noexcept -> bool;
    void Close() noexcept;

    void Draw(sf::RenderWindow& window) const noexcept;
    void EnterText(sf::Event& event);

private:
    void InputLogic(int charTyped);
    void DeleteLastChar();
};

#endif //WHO_IS_BILLY_HERE_TEXTBOX_H
