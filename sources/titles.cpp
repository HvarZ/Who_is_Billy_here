#include <titles.h>

Titles::Titles(sf::RenderWindow& window) :
    backButton_(new MainMenuButton("", sf::Vector2f(50, 50), sf::Vector2f(490, 105),
                std::string("../textures/main_menu_textures/arrow.png"))),
                                            window_(&window),
                                            isOpen_(true){
    font_.loadFromFile("../fonts/Pixelio_true.otf");
    text_.setFont(font_);
    text_.setString("Main artist - Another One \nMian programmer - KaparZo ");
    text_.setFillColor(sf::Color::White);
    text_.setCharacterSize(50);
    text_.setPosition(static_cast<float>(window_->getSize().x) / 3 - text_.getLocalBounds().width / 2,
                      static_cast<float>(window_->getSize().y) / 2);
}

Titles::~Titles() {
    delete backButton_;
}

void Titles::Draw(sf::RenderWindow &window) const noexcept {
    window.draw(text_);
    backButton_->Draw(window);
}

auto Titles::IsOpen() const noexcept -> bool {
    return isOpen_;
}

auto Titles::IsPressedBack(sf::RenderWindow &window, sf::Event &event) const noexcept -> bool {
    return event.type == sf::Event::MouseButtonPressed && backButton_->IsOverMouse(window);
}

void Titles::Close() noexcept {
    isOpen_ = false;
}

void Titles::MagnifyingButton(sf::RenderWindow& window) noexcept {
    if (backButton_->IsOverMouse(window)) {
        backButton_->MagnifyingAnimation();
    }
    else {
        backButton_->ShrinkingAnimation();
    }
}
