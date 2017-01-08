#include "Marcador.hpp"

Marcador::Marcador() {
    punts_j1 = punts_j2 = 0;
    assert(font.loadFromFile("assets/fonts/AnonymousPro-Regular.ttf"));
    assert(font_bold.loadFromFile("assets/fonts/AnonymousPro-Bold.ttf"));
    t_punts_j1.setFont(font);
    t_punts_j1.setPosition(POS_X, POS_Y);
    t_punts_j1.setFillColor(sf::Color::Black);
    t_punts_j1.setCharacterSize(FONT_SIZE);
    t_punts_j1.setString(std::to_string(punts_j1));
    t_punts_j2.setFont(font);
    std::string punts_j2Str = std::to_string(punts_j2);
    t_punts_j2.setPosition(WIDTH - POS_X - punts_j2Str.length() * FONT_SIZE,
            POS_Y);
    t_punts_j2.setFillColor(sf::Color::Black);
    t_punts_j2.setCharacterSize(FONT_SIZE);
    t_punts_j2.setString(punts_j2Str);
}

void Marcador::addPuntsJ1(int num) {
    punts_j1 += num;
    t_punts_j1.setString(std::to_string(punts_j1));
}

void Marcador::addPuntsJ2(int num) {
    punts_j2 += num;
    t_punts_j2.setString(std::to_string(punts_j2));
}

void Marcador::render(sf::RenderWindow& window) {
    if (paused) {
        sf::Text pausa;
        std::string pausaStr = "Pausa";
        pausa.setString(pausaStr);
        //pausa.setStyle(sf::Text::Bold);
        pausa.setFillColor(sf::Color::Black);
        pausa.setFont(font_bold);
        pausa.setCharacterSize(2 * FONT_SIZE);
        pausa.setPosition(WIDTH / 2 - pausaStr.length() / 2 * PAUSA_SIZE,
                HEIGHT / 2 - PAUSA_SIZE / 2);
        window.draw(pausa);
    }
    window.draw(t_punts_j1);
    window.draw(t_punts_j2);
}
