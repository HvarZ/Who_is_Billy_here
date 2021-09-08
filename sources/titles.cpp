#include <titles.h>

Titles::Titles(sf::RenderWindow& window) :
    backButton_(new BackButton), window_(&window), isOpen_(true) {
    font_.loadFromFile("../fonts/Pixelio_true.otf");
    text_.setFont(font_);
    text_.setString("Main artist - Another One \nMian programmer - KaparZo ");
    text_.setFillColor(sf::Color::White);
    text_.setCharacterSize(50);
    text_.setPosition(static_cast<float>(window_->getSize().x) / 3 - text_.getLocalBounds().width / 2,
                      static_cast<float>(window_->getSize().y) / 2);
}


void Titles::Draw(sf::RenderWindow &window) const noexcept {
    window.draw(text_);
    backButton_->Draw(window);
}

auto Titles::IsOpen() const noexcept -> bool {
    return isOpen_;
}


void Titles::Close() noexcept {
    isOpen_ = false;
}


auto Titles::GetBackButton() const noexcept -> BackButton& {
    return *backButton_;
}


