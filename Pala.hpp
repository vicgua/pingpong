#ifndef PALA_HPP
#define PALA_HPP

#include <SFML/Graphics.hpp>

#include "common.hpp"

class Pala {
    // La classe Pilota necessita accedir a `shape` per detectar col·lisions.
    friend class Pilota;
public:
    Pala(float x);
    ~Pala();
    void move(double a);
    void render(sf::RenderWindow& window);
    constexpr static float MOV = 0.15;
    constexpr static float DX = 15;
    constexpr static float POS_X = 15 + DX;
private:
    sf::RectangleShape* shape;
    constexpr static float DY = 70;
};

#endif /* PALA_HPP */

