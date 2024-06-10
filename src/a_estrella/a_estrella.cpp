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
    // TODO: Implementar.
}

std::stack<coordenada> a_estrella::obtener_camino_minimo(coordenada origen, coordenada destino, mapa& mapa_callejon,
                                                         int heuristica(vertice*, vertice*)) {
    // TODO: Implementar.
}
