#include <textbox.h>

TextBox::TextBox() {
    font_.loadFromFile("../fonts/Pixelio_true.otf");

    textBox_.setFont(font_);
    textBox_.setCharacterSize(60);
    textBox_.setFillColor(sf::Color::White);

    texture_.loadFromFile("../textures/main_menu_textures/frame_black_background.png");

    frame_.setSize(sf::Vector2f(490, 105));
    frame_.setTexture(&texture_);
    frame_.setPosition(1000, 1000);

    isOpen_ = true;
}
void TextBox::InputLogic(int charTyped) {
    if (charTyped != Keys::DELETE &&
        charTyped != Keys::ENTER &&
        charTyped != Keys::ESCAPE) {
        text_ << static_cast<char>(charTyped);
    }
    else if (charTyped == Keys::DELETE) {
        if (text_.str().length() > 0) {
            DeleteLastChar();
        }
    }
    textBox_.setString(text_.str() + "_");

}

void TextBox::DeleteLastChar() {
    auto text = text_.str();
    std::string newText;

    for (size_t i = 0; i < text.length() - 1; ++i) {
        newText += text[i];
    }

    text_.str("");
    text_ << newText;

    textBox_.setString(text_.str());
}

void TextBox::Draw(sf::RenderWindow &window) const noexcept {
    window.draw(frame_);
    window.draw(textBox_);
}

void TextBox::EnterText(sf::Event &event) {
    int charTyped = event.text.unicode;
    if (charTyped < 128) {
        if (text_.str().length() < limit_) {
            InputLogic(charTyped);
        }
        else if (charTyped == Keys::DELETE) {
            DeleteLastChar();
        }
    }
}

auto TextBox::IsOpen() const noexcept -> bool {
    return isOpen_;
}
