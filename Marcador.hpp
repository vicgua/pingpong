#ifndef MARCADOR_HPP
#define MARCADOR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdexcept>
#include <string>

#include "common.hpp"

class Marcador {
public:
    Marcador();
    void addPuntsJ1(int num = 1);
    void addPuntsJ2(int num = 1);
    void render(sf::RenderWindow& window);
    static constexpr int FONT_SIZE = 18; // En píxels
    static constexpr int PAUSA_SIZE = 2 * FONT_SIZE;
    static constexpr float POS_X = 10;
    static constexpr float POS_Y = 10;
private:
    int punts_j1, punts_j2;
    sf::Text t_punts_j1, t_punts_j2;
    sf::Font font;
    sf::Font font_bold;
};

#endif /* MARCADOR_HPP */