#ifndef TITLE_HPP
#define TITLE_HPP

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "common.hpp"
#include "Marcador.hpp"

class Title {
public:
    Title();
    void render(sf::RenderWindow& window);
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif /* TITLE_HPP */

