#ifndef WHO_IS_BILLY_HERE_MESSAGE_H
#define WHO_IS_BILLY_HERE_MESSAGE_H

#include <main_menu_button.h>

class Message final {
private:
    sf::RenderWindow window_;

    MainMenuButton yesButton_;
    MainMenuButton noButton_;

    sf::Text question_;

public:
    Message() = delete;
    explicit Message(const std::string& question) noexcept;
    void Draw(sf::RenderWindow& window) noexcept;

    auto IsPressedYes() const noexcept -> bool;
    auto IsPressedNo() const noexcept -> bool;

};

#endif //WHO_IS_BILLY_HERE_MESSAGE_H
