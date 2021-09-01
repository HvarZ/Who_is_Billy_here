#ifndef WHO_IS_BILLY_HERE_MAIN_MENU_H
#define WHO_IS_BILLY_HERE_MAIN_MENU_H

#include <vector>
#include <array>
#include <string>

#include <message.h>
#include <main_menu_button.h>

#include <SFML/Graphics.hpp>


namespace MainMenuSettings {
    const std::array<std::string, 5> buttonsNames_ = {"New game", "Load",
                                                      "Leaderboard", "Titles", "Exit"};

    const int X_POSITION_BUTTONS = 500;
    const int NUMBER_BUTTONS = 5;
    const float ANGLE_NAME_GAME = -45.f;
    const float X_POSITION_NAME_GAME = 1920.f;
    const float Y_POSITION_NAME_GAME = 1080.f;
    const int START_POSITION_FOR_FIRST_BUTTON = 500.f;
    const int STEP_BETWEEN_BUTTONS = 200.f;
    const unsigned int CHAR_SIZE = 80;
    const std::string NAME_GAME = "Who's Billy here?";
}

enum ButtonNames {
    NewGame = 0,
    Load = 1,
    Leaderboard = 2,
    Titles = 3,
    Exit = 4
};


class MainMenu final {
private:
    sf::Text nameGame_;
    sf::Font fontNameGame_;
    std::vector<MainMenuButton> buttons_;
    sf::Texture background_;


public:
    MainMenu() noexcept;

    void DrawMainAnimation(sf::RenderWindow& window) const noexcept;
    void Draw(sf::RenderWindow& window) const noexcept;
    void MagnifyButton(sf::RenderWindow& window) noexcept;
    void Exit(sf::RenderWindow &window, sf::Event& event) const noexcept;
};

#endif //WHO_IS_BILLY_HERE_MAIN_MENU_H
