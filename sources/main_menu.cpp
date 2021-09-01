#include <main_menu.h>

MainMenu::MainMenu() noexcept {
    fontNameGame_.loadFromFile("../fonts/Pixelio_true.otf");
    nameGame_.setFont(fontNameGame_);
    nameGame_.setString("Who's Billy here?");
    nameGame_.setRotation(-45);
    nameGame_.setPosition(1920, 1080);
    nameGame_.setCharacterSize(50);

    buttons_.reserve(NUMBER_BUTTONS);
    for (int yPosition = 500, i = 0; i < NUMBER_BUTTONS; ++i, yPosition += 200) {
        buttons_.emplace_back(buttonsNames_[i],
                  sf::Vector2f{X_POSITION_BUTTONS, static_cast<float>(yPosition)});
    }
}



void MainMenu::Draw(sf::RenderWindow& window) const noexcept {
    for (const auto& button : buttons_) {
        button.Draw(window);
    }

    window.draw(nameGame_);
}

void MainMenu::MagnifyButton(sf::RenderWindow& window) noexcept {
    for (auto& button : buttons_) {
        if (button.IsOverMouse(window)) {
            button.MagnifyingAnimation();
        }
        else {
            button.ShrinkingAnimation();
        }
    }
}

void MainMenu::DrawMainAnimation(sf::RenderWindow& window) const noexcept {

}