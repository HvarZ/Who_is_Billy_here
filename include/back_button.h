#ifndef WHO_IS_BILLY_HERE_BACK_BUTTON_H
#define WHO_IS_BILLY_HERE_BACK_BUTTON_H

#include <main_button.h>
#include <memory>

class BackButton final {
private:
    std::unique_ptr<MainButton> backButton_;

public:
    BackButton();

    auto IsPressed(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool;
    void Magnifying(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window) const;
};

#endif //WHO_IS_BILLY_HERE_BACK_BUTTON_H
