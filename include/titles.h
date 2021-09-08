#ifndef WHO_IS_BILLY_HERE_TITLES_H
#define WHO_IS_BILLY_HERE_TITLES_H

#include <memory>

#include <SFML/Graphics.hpp>
#include <back_button.h>

class Titles final {
private:
    sf::Text text_;
    sf::Font font_;

    std::unique_ptr<BackButton> backButton_;
    sf::RenderWindow* window_;

    bool isOpen_ = false;
public:
    Titles() = delete;
    explicit Titles(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window) const noexcept;
    auto IsOpen() const noexcept -> bool;
    void Close() noexcept;
    auto GetBackButton() const noexcept -> BackButton&;
};

#endif //WHO_IS_BILLY_HERE_TITLES_H
