#include <textbox.h>


TextBox::TextBox(sf::RenderWindow& window, const std::string &comment, const int limit) : window_(&window), limit_(limit) {
    font_.loadFromFile("../fonts/Pixelio_true.otf");

    comment_.setString(comment);
    comment_.setFont(font_);
    comment_.setCharacterSize(80);
    comment_.setFillColor(sf::Color::White);

    textBox_.setFont(font_);
    textBox_.setCharacterSize(80);
    textBox_.setFillColor(sf::Color::White);

    texture_.loadFromFile("../textures/main_menu_textures/frame_black_background.png");

    frame_.setSize(sf::Vector2f(840, 180));
    frame_.setTexture(&texture_);
    frame_.setPosition(static_cast<float>(window_->getSize().x) / 2 - frame_.getSize().x / 2,
                       static_cast<float>(window_->getSize().y) / 2 - frame_.getSize().x / 2);
    comment_.setPosition(static_cast<float>(window.getSize().x) / 2 - comment_.getLocalBounds().width / 2,
                         frame_.getPosition().y - static_cast<float>(window.getSize().y) / 8);
    textBox_.setPosition(frame_.getPosition().x + frame_.getSize().x - textBoxAdaptedSize_,
                         frame_.getPosition().y + 0.2f * frame_.getSize().y);

    isOpen_ = true;
}

void TextBox::InputLogic(int charTyped) {
    if (charTyped != Keys::DELETE &&
        charTyped != Keys::ENTER &&
        charTyped != Keys::ESCAPE) {
        text_ << static_cast<char>(charTyped);
        textBoxAdaptedSize_ = textBox_.getLocalBounds().width / 2;
        textBox_.setPosition(frame_.getPosition().x + frame_.getSize().x / 2 - textBoxAdaptedSize_,
                             frame_.getPosition().y + 0.2f * frame_.getSize().y);
    }
    else if (charTyped == Keys::DELETE && text_.str().length() > 0) {
        DeleteLastChar();
    }
    else if (charTyped == Keys::ENTER && text_.str().length() > 3) {
        isEntered_ = true;
    }
    textBox_.setString(text_.str() + "_");
    textBoxAdaptedSize_ = textBox_.getLocalBounds().width / 2;
    textBox_.setPosition(frame_.getPosition().x + frame_.getSize().x / 2 - textBoxAdaptedSize_,
                         frame_.getPosition().y + 0.2f * frame_.getSize().y);

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
    textBoxAdaptedSize_ = textBox_.getLocalBounds().width / 2;
    textBox_.setPosition(frame_.getPosition().x + frame_.getSize().x / 2 - textBoxAdaptedSize_,
                         frame_.getPosition().y + 0.2f * frame_.getSize().y);
}

void TextBox::Draw(sf::RenderWindow &window) const noexcept {
    window.draw(frame_);
    window.draw(comment_);
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

auto TextBox::IsEntered() const noexcept -> bool {
    return isEntered_;
}

auto TextBox::GetString() const noexcept -> std::string {
    return textBox_.getString();
}

void TextBox::Close() noexcept {
    isOpen_ = false;
}
