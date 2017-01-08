#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <chrono>
#include <random>
#include <stdexcept>
#include <iostream>

class Random {
public:

    static void init() {
        unsigned int seed =
                std::chrono::system_clock::now().time_since_epoch().count();
        gen = std::default_random_engine(seed);
    }

    template <typename T = double>
    static T genReal(T min, T max) {
		if (min > max) {
			std::uniform_real_distribution<T> dist(max, min);
			return dist(gen);
		} else {
			std::uniform_real_distribution<T> dist(min, max);
			return dist(gen);
		}
    }

    static bool genBool(double probTrue = 0.5) {
        double r;
        do {
            r = genReal<double>(0, 1);
            if (r < probTrue)
                return false;
            if (r > probTrue)
                return true;
        } while (r == probTrue);
        throw std::runtime_error("Arribat a un codi que no hauria de ser "
                "executat"); // Per evitar advertències d'alguns compiladors
    }

private:
    static std::default_random_engine gen;
};

#endif /* RANDOM_HPP */

