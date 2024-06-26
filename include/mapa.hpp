#ifndef AYED_TPG_1C2024_MAPA_HPP
#define AYED_TPG_1C2024_MAPA_HPP

#include <list>
#include "coordenada.hpp"
#include "matriz.hpp"

/* Esta clase es la encargada de decirle a a_estrella si la posición de un vecino es válida o no.
 * Queda a criterio del grupo como implementarla. La idea es que a_estrella no tenga detalles de
 * implementación de posibles casilleros, clientes, paredes, locales, etc.
 * Adicionalmente, la pueden utilizar para otras partes del TP.
 * TIP: Tienen una matriz ya implementada como parte de la plantilla del TP. */


class mapa {
private:
    // Matriz de booleanos que indica si una posición es caminable o no.
    matriz<bool> matriz_caminable;

public:
    // Pre: -
    // Post: Crea un mapa con todas las posiciones, inicialmente, caminables.
    mapa(size_t filas, size_t columnas);

    // Pre: -
    // Post: Devuelve true si la posición del vecino es válida (es decir, es una coordenada válida y es caminable).
    bool es_vecino_valido(coordenada posicion);

    // Pre: -
    // Post: Agrega la posición del vecino como no caminable.
    void agregar_no_caminable(coordenada posicion);

    // Pre: -
    // Post: Devuelve una lista con los vecinos válidos, es decir, caminables.
    std::list<coordenada> obtener_vecinos_valido(coordenada posicion);

    // Pre: -
    // Post: Devuelve una lista con todos los vecinos.
    std::list<coordenada> obtener_vecinos(coordenada posicion);
};


#endif