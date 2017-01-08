#include "Pala.hpp"

Pala::Pala(float x) {
    shape = new sf::RectangleShape(sf::Vector2<float>(DX, DY));
    shape->setPosition(x, (HEIGHT - DY) / 2);
    shape->setFillColor(sf::Color(153, 102, 51));
}

Pala::~Pala() {
    delete shape;
}

void Pala::move(double a) {
    if (paused) return;
    if (shape->getPosition().y + a < 0 ||
            shape->getPosition().y + DY + a > HEIGHT)
        return;
    shape->move(0, a);
}

void Pala::render(sf::RenderWindow& window) {
    window.draw(*shape);
}