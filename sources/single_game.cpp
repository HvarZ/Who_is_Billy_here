#include <single_game.h>

SingleGame::SingleGame(sf::RenderWindow &window)
    : textBoxNickname_(new TextBox(window, "Enter you nickname")),
      backButton_(new BackButton), window_(&window), isOpen_(true) {
  gems_.emplace_back("../textures/gems_textures/builders.png", 100, 100);
}

void SingleGame::Draw() {
  for (auto& gem : gems_) {
    gem.draw(*window_);
  }
}

auto SingleGame::GetBackButton() const noexcept -> BackButton & {
  return *backButton_;
}

auto SingleGame::GetTextBox() const noexcept -> TextBox & {
  return *textBoxNickname_;
}

void SingleGame::SetOpen(const bool open) noexcept { isOpen_ = open; }

auto SingleGame::IsOpen() const noexcept -> bool { return isOpen_; }
