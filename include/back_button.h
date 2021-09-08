#ifndef WHO_IS_BILLY_HERE_BACK_BUTTON_H
#define WHO_IS_BILLY_HERE_BACK_BUTTON_H

#include <main_menu_button.h>

class BackButton final {
private:
    MainMenuButton backButton_;

public:
    BackButton() = delete;
    explicit BackButton(sf::RenderWindow& window);

    auto IsPressed(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool;
    void Magnifying(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window) const;
};

#endif //WHO_IS_BILLY_HERE_BACK_BUTTON_H
