#ifndef WHO_IS_BILLY_HERE_TITLES_H
#define WHO_IS_BILLY_HERE_TITLES_H

#include <SFML/Graphics.hpp>
#include <main_menu_button.h>

class Titles final {
private:
    sf::Text text_;
    sf::Font font_;

    MainMenuButton* backButton_;
    sf::RenderWindow* window_;

    bool isOpen_ = false;
public:
    Titles() = delete;
    explicit Titles(sf::RenderWindow& window);
    ~Titles();
    void Draw(sf::RenderWindow& window) const noexcept;
    auto IsPressedBack(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool;
    auto IsOpen() const noexcept -> bool;
    void Close() noexcept;
    void MagnifyingButton(sf::RenderWindow& window) noexcept;
};

#endif //WHO_IS_BILLY_HERE_TITLES_H
