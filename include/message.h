#ifndef WHO_IS_BILLY_HERE_MESSAGE_H
#define WHO_IS_BILLY_HERE_MESSAGE_H

#include <main_menu_button.h>
#include <vector>
#include <SFML/Graphics.hpp>

class Message final {
private:
    std::vector<MainMenuButton> buttons_;

    sf::Font font_;
    sf::Text question_;

    bool isOpen_ = false;
public:
    Message() = delete;
    explicit Message(const std::string& question) noexcept;
    void Draw(sf::RenderWindow& window) noexcept;

    auto IsOpen() const noexcept -> bool;
    auto IsPressedYes(sf::Event& event) const noexcept -> bool;
    auto IsPressedNo(sf::Event& event) const noexcept -> bool;

};

#endif //WHO_IS_BILLY_HERE_MESSAGE_H
