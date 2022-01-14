#include <gem.h>

Gem::Gem(const std::string &fileName, const size_t cost, const int64_t profit_)
    : button_(new MainButton("", sf::Vector2f(100, 100),
                             sf::Vector2f(256, 144), fileName)) {}

void Gem::draw(sf::RenderWindow &window) noexcept { button_->Draw(window); }

void Gem::update() noexcept {}
