#ifndef HEURISTICA_HPP
#define HEURISTICA_HPP

#include "vertice.hpp"

// Heurística de la distancia de Manhattan.
int distancia_manhattan(vertice* a, vertice* b) {
    return abs(a->obtener_posicion().x() - b->obtener_posicion().x()) + abs(a->obtener_posicion().y() - b->obtener_posicion().y());
}

#endif
