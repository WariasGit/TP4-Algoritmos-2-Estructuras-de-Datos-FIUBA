#include "mapa.hpp"

bool mapa::es_vecino_valido(coordenada posicion) {
    auto fila = static_cast<size_t>(posicion.y());
    auto columna = static_cast<size_t>(posicion.x());

    if (fila < 1 || fila >= matriz_caminable.filas()) {
        return false;
    }

    if (columna < 1 || columna >= matriz_caminable.columnas()) {
        return false;
    }

    return matriz_caminable.elemento(fila, columna);
}

mapa::mapa(size_t filas, size_t columnas) {
    matriz_caminable = matriz<bool>(filas, columnas, true);
}

void mapa::agregar_no_caminable(coordenada posicion) {
    auto fila = static_cast<size_t>(posicion.y());
    auto columna = static_cast<size_t>(posicion.x());
    matriz_caminable.elemento(fila, columna) = false;
}

std::list<coordenada> mapa::obtener_vecinos_valido(coordenada posicion) {
    std::list<coordenada> vecinos;

    for (auto vecino : obtener_vecinos(posicion)) {
        if (es_vecino_valido(vecino)) {
            vecinos.push_back(vecino);
        }
    }

    return vecinos;
}

std::list<coordenada> mapa::obtener_vecinos(coordenada posicion) {
    std::list<coordenada> vecinos;
    vecinos.emplace_back(posicion.x() - 1, posicion.y());
    vecinos.emplace_back(posicion.x() + 1, posicion.y());
    vecinos.emplace_back(posicion.x(), posicion.y() - 1);
    vecinos.emplace_back(posicion.x(), posicion.y() + 1);
    return vecinos;
}