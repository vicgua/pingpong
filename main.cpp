#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "Pala.hpp"
#include "Pilota.hpp"
#include "Marcador.hpp"
#include "Title.hpp"
#include "Random.hpp"

bool paused;
bool show_title;

std::default_random_engine Random::gen;

using kbd = sf::Keyboard; // Alias per a sf::Keyboard

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),
            "PONG");
    window.setKeyRepeatEnabled(false);
    Random::init();
    Title title;
    Marcador marcador;
    Pilota pilota(&marcador);
    Pala j1(Pala::POS_X);
    Pala j2(WIDTH - Pala::POS_X - Pala::DX);
    paused = true;
    show_title = true;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            paused = !paused;
                            break;
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::F4: // Alt-F4
                            if (event.key.alt)
                                window.close();
                            break;
                        default:
                            // No fer res (siencia advertències d'alguns
                            // compiladors.
                            ;
                    }
                    break;
                default:
                    ;
            }
        }
        if (show_title) {
            if (!paused) show_title = false;
            else {
                title.render(window);
                continue;
            }
        }
        if (kbd::isKeyPressed(kbd::W) &&
                !kbd::isKeyPressed(kbd::S)) {
            if (kbd::isKeyPressed(kbd::LShift))
                j1.move(-5 * Pala::MOV);
            else
                j1.move(-Pala::MOV);
        }
        if (kbd::isKeyPressed(kbd::S) &&
                !kbd::isKeyPressed(kbd::W)) {
            if (kbd::isKeyPressed(kbd::LShift))
                j1.move(5 * Pala::MOV);
            else
                j1.move(Pala::MOV);
        }

        if (kbd::isKeyPressed(kbd::I) &&
                !kbd::isKeyPressed(kbd::K)) {
            if (kbd::isKeyPressed(kbd::RShift))
                j2.move(-5 * Pala::MOV);
            else
                j2.move(-Pala::MOV);
        }
        if (kbd::isKeyPressed(kbd::K) &&
                !kbd::isKeyPressed(kbd::I)) {
            if (kbd::isKeyPressed(kbd::RShift))
                j2.move(5 * Pala::MOV);
            else
                j2.move(Pala::MOV);
        }

        window.clear(sf::Color::White);
        pilota.render(window, j1, j2);
        j1.render(window);
        j2.render(window);
        marcador.render(window);
        window.display();
    }
}
