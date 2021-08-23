#ifndef WHO_IS_BILLY_HERE_MAIN_MENU_H
#define WHO_IS_BILLY_HERE_MAIN_MENU_H

#include <array>
#include <main_menu_button.h>

#include <SFML/Graphics.hpp>


class MainMenu final {
private:
    MainMenuButton newGameButton_;
    MainMenuButton resultTableButton_;
    MainMenuButton titlesButton_;
    MainMenuButton exitButton_;
    sf::Sprite background_;
    sf::Sprite mainAnimation_;

public:
    MainMenu() noexcept;

    void DrawMainAnimation() const noexcept;
    void DrawButtons() const noexcept;
};

#endif //WHO_IS_BILLY_HERE_MAIN_MENU_H
