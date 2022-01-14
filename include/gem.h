#ifndef WHO_IS_BILLY_HERE_GEM_H
#define WHO_IS_BILLY_HERE_GEM_H

#include <memory>
#include "main_button.h"

class Gem {
private:
  std::unique_ptr<MainButton> button_;
  size_t cost_;
  int64_t profit_;

public:
  explicit Gem(const std::string& fileName, const size_t cost, const int64_t
                                                              profit_);

  void update() noexcept;
  void draw(sf::RenderWindow& window) noexcept;
};

#endif // WHO_IS_BILLY_HERE_GEM_H
