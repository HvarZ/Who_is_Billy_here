#include <main_menu.h>
#include <message.h>


MainMenu::MainMenu() noexcept {
    fontNameGame_.loadFromFile("../fonts/Pixelio_true.otf");
    nameGame_.setFont(fontNameGame_);
    nameGame_.setString(MainMenuSettings::NAME_GAME);
    nameGame_.setRotation(MainMenuSettings::ANGLE_NAME_GAME);
    nameGame_.setPosition(MainMenuSettings::X_POSITION_NAME_GAME, MainMenuSettings::Y_POSITION_NAME_GAME);
    nameGame_.setCharacterSize(MainMenuSettings::CHAR_SIZE);

    buttons_.reserve(MainMenuSettings::NUMBER_BUTTONS);
    for (int yPosition = MainMenuSettings::START_POSITION_FOR_FIRST_BUTTON, i = 0;
         i < MainMenuSettings::NUMBER_BUTTONS;
        ++i, yPosition += MainMenuSettings::STEP_BETWEEN_BUTTONS) {
        buttons_.emplace_back(MainMenuSettings::buttonsNames_[i],
                  sf::Vector2f{MainMenuSettings::X_POSITION_BUTTONS, static_cast<float>(yPosition)});
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

void MainMenu::Exit(sf::RenderWindow &window, sf::Event& event) const noexcept {
    if (buttons_[ButtonNames::Exit].IsPressed(window, event)) {
        Message message(window, "Are you sure about that?");
        sf::Event click{};
        while (window.waitEvent(click)) {
            if (message.IsPressedYes(window, click)) {
                window.close();
            }
            if (message.IsPressedNo(window, click)) {

                break;
            }
            if (event.type == sf::Event::MouseMoved) {
                message.MagnifyButton(window);
            }
            message.Draw(window);
        }
    }
}