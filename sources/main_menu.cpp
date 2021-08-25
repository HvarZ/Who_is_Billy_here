#include <main_menu.h>

MainMenu::MainMenu() noexcept {
    buttons_.reserve(NUMBER_BUTTONS);
    for (int yPosition = 500, i = 0; i < NUMBER_BUTTONS; ++i, yPosition += 200) {
        buttons_.emplace_back(buttonsNames_[i],
                  sf::Vector2f{X_POSITION_BUTTONS, static_cast<float>(yPosition)});
    }
}



void MainMenu::DrawButtons(sf::RenderWindow& window) const noexcept {
    for (const auto& button : buttons_) {
        button.Draw(window);
    }
}

void MainMenu::DrawMainAnimation(sf::RenderWindow& window) const noexcept {

}