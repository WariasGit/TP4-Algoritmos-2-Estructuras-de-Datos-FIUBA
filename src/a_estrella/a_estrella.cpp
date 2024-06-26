#include "a_estrella.hpp"
#include <algorithm>

vertice* a_estrella::buscar_mejor_vertice() {
    vertice* mejor_vertice = nullptr;
    auto it = min_element(set_abierto.begin(), set_abierto.end(), vertice::menor);
    if (it != set_abierto.end()) {
        mejor_vertice = *it;
        set_abierto.erase(it);
    }
    return mejor_vertice;
}

vertice* a_estrella::buscar_vertice(std::vector<vertice*> set, coordenada posicion) {
    vertice* vertice_buscado = nullptr;
    auto coincide_posicion = [&posicion](vertice* v) { return *v == posicion; };
    auto it = std::find_if(set.begin(), set.end(), coincide_posicion);
    if (it != set.end()) {
        vertice_buscado = *it;
    }
    return vertice_buscado;
}

void a_estrella::limpiar_sets() {
    for (vertice* vertice: set_abierto) {
        delete vertice;
    }
    for (vertice* vertice: set_cerrado) {
        delete vertice;
    }
    set_abierto.clear();
    set_cerrado.clear();
}

std::stack<coordenada> a_estrella::reconstruir_camino(vertice* destino) {
    std::stack<coordenada> camino;
    vertice* vertice_actual = destino;

    while (vertice_actual != nullptr) {
        camino.push(vertice_actual->posicion);
        vertice_actual = vertice_actual->padre;
    }
    return camino;
}

std::stack<coordenada> a_estrella::obtener_camino_minimo(coordenada origen, coordenada destino, mapa& mapa_callejon,
                                                         int heuristica(vertice*, vertice*)) {
    limpiar_sets();

    vertice* inicio = new vertice(origen);
    vertice* fin = new vertice(destino);

    inicio->costo_origen = 0;
    inicio->padre = nullptr;
    inicio->distancia_destino = heuristica(inicio, fin);
    set_abierto.push_back(inicio);

    while (!set_abierto.empty()) {
        vertice* vertice_actual = buscar_mejor_vertice();
        if (*vertice_actual == destino) {
            return reconstruir_camino(vertice_actual);
        }

        set_cerrado.push_back(vertice_actual);
        for (auto vecino : mapa_callejon.obtener_vecinos_valido(vertice_actual->posicion)) {
            vertice* vecino_actual = buscar_vertice(set_cerrado, vecino);
            if (vecino_actual == nullptr) {
                vecino_actual = buscar_vertice(set_abierto, vecino);
                if (vecino_actual == nullptr) {
                    vecino_actual = new vertice(vecino, vertice_actual);
                    vecino_actual->costo_origen = vertice_actual->costo_origen + 1;
                    vecino_actual->distancia_destino = heuristica(vecino_actual, fin);
                    set_abierto.push_back(vecino_actual);
                } else {
                    int nuevo_costo = vertice_actual->costo_origen + 1;
                    if (nuevo_costo < vecino_actual->costo_origen) {
                        vecino_actual->costo_origen = nuevo_costo;
                        vecino_actual->padre = vertice_actual;
                    }
                }
            } else {
                int nuevo_costo = vertice_actual->costo_origen + 1;
                if (nuevo_costo < vecino_actual->costo_origen) {
                    vecino_actual->costo_origen = nuevo_costo;
                    vecino_actual->padre = vertice_actual;
                }
            }
        }
    }

    return {};