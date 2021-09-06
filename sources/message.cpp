#include <message.h>



Message::Message(sf::RenderWindow& window, const std::string &question) noexcept : ptrWindow_(&window), isOpen_(true) {
    font_.loadFromFile("../fonts/Pixelio_true.otf");
    question_.setString(question);
    question_.setFont(font_);
    question_.setCharacterSize(70);
    question_.setPosition(sf::Vector2f(static_cast<float>(ptrWindow_->getSize().x) / 2 - question_.getLocalBounds().width / 2 ,
                                       static_cast<float>(ptrWindow_->getSize().y) / 3 - question_.getLocalBounds().height / 2));

    buttons_.reserve(2);
    buttons_.emplace_back(std::string("Yes"),
                          sf::Vector2f{static_cast<float>(ptrWindow_->getSize().x) / 3 - ButtonSettings::BUTTON_SIZE.x / 2,
                                       2 * static_cast<float>(ptrWindow_->getSize().y) / 3});
    buttons_.emplace_back(std::string("No"),
                          sf::Vector2f{2 * static_cast<float>(ptrWindow_->getSize().x) / 3 - ButtonSettings::BUTTON_SIZE.x / 2,
                                       2 * static_cast<float>(ptrWindow_->getSize().y) / 3});
}

void Message::Draw(sf::RenderWindow& window) noexcept {
    window.draw(question_);
    for (const auto& button : buttons_) {
        button.Draw(window);
    }
}

void Message::Close() noexcept {
    isOpen_ = false;
}

auto Message::IsPressedYes(sf::RenderWindow& window, sf::Event& event) const noexcept -> bool {
    return event.type == sf::Event::MouseButtonPressed && buttons_[0].IsOverMouse(window);
}

auto Message::IsPressedNo(sf::RenderWindow &window, sf::Event &event) const noexcept -> bool {
    return event.type == sf::Event::MouseButtonPressed && buttons_[1].IsOverMouse(window);
}


void Message::MagnifyButton(sf::RenderWindow &window) noexcept {
    for (auto& button : buttons_) {
        if (button.IsOverMouse(window)) {
            button.MagnifyingAnimation();
        }
        else {
            button.ShrinkingAnimation();
        }
    }
}

auto Message::IsOpen() const noexcept -> bool {
    return isOpen_;
}




