#ifndef WHO_IS_BILLY_HERE_MESSAGE_H
#define WHO_IS_BILLY_HERE_MESSAGE_H

#include <main_menu_button.h>
#include <vector>
#include <SFML/Graphics.hpp>

class Message final {
private:
    std::vector<MainMenuButton> buttons_;
    sf::RenderWindow* ptrWindow_;

    sf::Font font_;
    sf::Text question_;

    bool isOpen_ = false;
public:
    Message() = delete;
    explicit Message(sf::RenderWindow& window, const std::string& question,
                     const std::vector<std::string>& answers) noexcept;
    void Draw(sf::RenderWindow& window) noexcept;

    void Close() noexcept;
    auto IsOpen() const noexcept -> bool;
    auto IsPressedYes(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool;
    auto IsPressedNo(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool;
    void MagnifyButton(sf::RenderWindow& window) noexcept;
};

#endif //WHO_IS_BILLY_HERE_MESSAGE_H
