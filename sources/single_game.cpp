#include <single_game.h>

SingleGame::SingleGame(sf::RenderWindow &window) : textBoxNickname_(new TextBox(window, "Enter you nickname")),
backButton_(new BackButton), window_(&window), isOpen_(true) {}

void SingleGame::Draw(sf::RenderWindow &window) {
    textBoxNickname_->Draw(window);
    backButton_->Draw(window);
}

auto SingleGame::GetBackButton() const noexcept -> BackButton & {
    return *backButton_;
}

auto SingleGame::GetTextBox() const noexcept -> TextBox & {
    return *textBoxNickname_;
}

void SingleGame::Close() noexcept {
    isOpen_ = false;
}

auto SingleGame::IsOpen() const noexcept -> bool {
    return isOpen_;
}
