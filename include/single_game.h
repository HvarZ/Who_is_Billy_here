#ifndef WHO_IS_BILLY_HERE_SINGLE_GAME_H
#define WHO_IS_BILLY_HERE_SINGLE_GAME_H

#include <textbox.h>
#include <back_button.h>
#include <memory>

class SingleGame final {
private:
    std::unique_ptr<TextBox> textBoxNickname_;
    std::unique_ptr<BackButton> backButton_;

    sf::RenderWindow* window_;

    bool isOpen_ = false;

public:
    SingleGame() = delete;
    explicit SingleGame(sf::RenderWindow& window);

    void Draw(sf::RenderWindow& window);
    [[nodiscard]] auto GetBackButton() const noexcept -> BackButton&;
    [[nodiscard]] auto GetTextBox() const noexcept -> TextBox&;
    auto IsOpen() const noexcept -> bool;

    void Close() noexcept;

};

#endif //WHO_IS_BILLY_HERE_SINGLE_GAME_H
