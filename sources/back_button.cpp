#include <back_button.h>

BackButton::BackButton() :
backButton_(new MainButton("", sf::Vector2f(50, 50), sf::Vector2f(490, 105),
                               std::string("../textures/main_menu_textures/arrow.png"))) {}


auto BackButton::IsPressed(sf::RenderWindow &window, sf::Event &event) const noexcept -> bool {
    return backButton_->IsPressed(window, event);
}

void BackButton::Magnifying(sf::RenderWindow& window) {
    if (backButton_->IsOverMouse(window)) {
        backButton_->MagnifyingAnimation();
    }
    else {
        backButton_->ShrinkingAnimation();
    }
}

void BackButton::Draw(sf::RenderWindow &window) const {
    backButton_->Draw(window);
}
