#include "Pilota.hpp"

Pilota::Pilota(Marcador* marcador) {
    shape = new sf::CircleShape(RADI);
    shape->setFillColor(sf::Color(51, 204, 51));
    if (!s_buffer.loadFromFile("assets/sounds/pong.wav"))
        throw std::runtime_error(no_asset);
    sound.setBuffer(s_buffer);
    this->marcador = marcador;
    ultima_col_j1 = ultima_col_j2 = false;
    reset();
}

Pilota::~Pilota() {
    delete shape;
}

void Pilota::render(sf::RenderWindow& window, const Pala& j1, const Pala& j2) {
    move(j1, j2);
    window.draw(*shape);
}

void Pilota::reset() {
    double angle;
    do
        angle = Random::genReal<double>(0, 2 * M_PI); while (angle == M_PI || angle == (3 / 4) * M_PI);
    vx = V_0 * cos(angle);
    vy = V_0 * sin(angle);
    shape->setPosition((WIDTH - RADI) / 2, (HEIGHT - RADI) / 2);
}

double Pilota::normRad(double a) {
    while (a < 0)
        a += 2 * M_PI;
    return fmod(a, 2 * M_PI);
}

void Pilota::move(const Pala& j1, const Pala& j2) {
    if (paused) return;
    sf::Vector2<float> pos = shape->getPosition();

    if (Random::genBool(0.01)) { // Canvia de velocitat ocasionalment
        double v = sqrt(vx * vx + vy * vy);
        double angle = normRad(atan2(vy, vx));
        double a = Random::genReal(1.2 * A, -A); // Accelera més que frena
        if (v + a <= V_MAX && v + a >= V_0) {
            v += a;
            vx = v * cos(angle);
            vy = v * sin(angle);
        }
    }

    // Si es surt, inverteix la direcció
    if (pos.y + vy + RADI <= 0) {
        vy *= -1;
        pos = shape->getPosition();
        sound.play();
    } else if (pos.y + vy + RADI >= HEIGHT) {
        vy *= -1;
        pos = shape->getPosition();
        sound.play();
    }
    if (pos.x + vx + RADI <= 0) {
        vx *= -1;
        marcador->addPuntsJ2();
        reset();
    } else if (pos.x + vx + RADI >= WIDTH) {
        vx *= -1;
        marcador->addPuntsJ1();
        reset();
    }

    if (colisio(j1, vx, vy)) {
        if (!ultima_col_j1) {
            ultima_col_j1 = true;
            vx *= -1;
            sound.play();
        }
    } else
        ultima_col_j1 = false;
    if (colisio(j2, vx, vy)) {
        if (!ultima_col_j2) {
            ultima_col_j2 = true;
            vx *= -1;
            sound.play();
        }
    } else
        ultima_col_j2 = false;
    shape->move(vx, vy);
}

bool Pilota::colisio(const Pala& jugador, double vx, double vy) {
    sf::Vector2<float> pos = shape->getPosition() + shape->getOrigin()
            + sf::Vector2f(vx, vy);
    sf::Vector2<float> pos_pala = jugador.shape->getPosition()
            + jugador.shape->getOrigin();
    return (pos.x + RADI >= pos_pala.x && pos.x - RADI <= pos_pala.x + Pala::DX
            && pos.y + RADI >= pos_pala.y
            && pos.y - RADI <= pos_pala.y + Pala::DY);
}
