#ifndef WHO_IS_BILLY_HERE_MAIN_MENU_H
#define WHO_IS_BILLY_HERE_MAIN_MENU_H

#include <vector>
#include <array>
#include <main_menu_button.h>

#include <SFML/Graphics.hpp>

#define NUMBER_BUTTONS 5
#define X_POSITION_BUTTONS 500


class MainMenu final {
private:
    std::vector<MainMenuButton> buttons_;
    sf::Texture background_;

    MainMenuButton newGameButton_{"New game", {500, 500}};

    const std::array<std::string, 5> buttonsNames_ = {"New game", "Load",
                                                      "Leaderboard", "Titles", "Exit"};

public:
    MainMenu() noexcept;

    void DrawMainAnimation(sf::RenderWindow& window) const noexcept;
    void DrawButtons(sf::RenderWindow& window) const noexcept;
    void MagnifyButton(sf::RenderWindow& window) noexcept;
};

#endif //WHO_IS_BILLY_HERE_MAIN_MENU_H
