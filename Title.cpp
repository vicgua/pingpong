#include "Title.hpp"

Title::Title() {
    assert(texture.loadFromFile("assets/images/Title.png"));
    sprite.setTexture(texture);
}

void Title::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();
}


