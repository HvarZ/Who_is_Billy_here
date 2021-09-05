#include <message.h>



Message::Message(const std::string &question) noexcept : isOpen_(true) {
    font_.loadFromFile("../fonts/Pixelio_true.otf");
    question_.setString(question);
    question_.setFont(font_);
    question_.setCharacterSize(70);

    buttons_.emplace_back("Yes",
                          sf::Vector2<float>{1500.f, 500.f},
                          sf::Vector2<float>{150.f, 100.f});
    buttons_.emplace_back("No",
                          sf::Vector2<float>{1920.f, 1080.f},
                          sf::Vector2<float>{150.f, 100.f});
}

void Message::Draw(sf::RenderWindow& window) noexcept {
    window.clear();
    window.draw(question_);
    //for (const auto& button : buttons_) {
    //    button.Draw(window);
    //}
    window.display();
}

auto Message::IsOpen() const noexcept -> bool {
    return isOpen_;
}

auto Message::IsPressedYes(sf::Event& event) const noexcept -> bool {
    return event.type == sf::Event::MouseButtonPressed;
}



