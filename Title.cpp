#include "Title.hpp"

Title::Title() {
    if (!texture.loadFromFile("assets/images/Title.png"))
        throw std::runtime_error(no_asset);
    sprite.setTexture(texture);
}

void Title::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();
}


