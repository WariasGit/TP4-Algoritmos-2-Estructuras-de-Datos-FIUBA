#ifndef AYED_TPG_1C2024_MAPA_HPP
#define AYED_TPG_1C2024_MAPA_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <fstream>
#include "utiles.hpp"
#include <list>
#include "coordenada.hpp"
#include "constantes.hpp"
#include "matriz.hpp"


/* Esta clase es la encargada de decirle a a_estrella si la posición de un vecino es válida o no.
 * Queda a criterio del grupo como implementarla. La idea es que a_estrella no tenga detalles de
 * implementación de posibles casilleros, clientes, paredes, locales, etc.
 * Adicionalmente, la pueden utilizar para otras partes del TP.
 * TIP: Tienen una matriz ya implementada como parte de la plantilla del TP. */

class mapa {
private:
    matriz<int > matriz_mapa;
public:
    /*
    * NOTA: Este contructor está solamente por temas de C++, (default-constructible). No tiene sentido usarlo.
    */
    mapa();

    /*
    * Constructor
    */
    mapa(size_t  filas, size_t columnas);

    // Pre: -
    // Post: Devuelve true si la posición del vecino es válida (es decir, es una coordenada válida y es caminable).
    bool es_vecino_valido(coordenada posicion);

    // Pre:
    // Post: Procesa el archivo y carga en la matriz las entradas correspondientes al callejon.
    void cargar_callejon(std::string path_archivo);

    /*
    * Pre:
    * Post: Agrega rn la matriz, la posicion (fila,columna) como caminable (True).
    */
    void agregar_casilleros_caminables(int fila, int columna);

    /*
    * Pre:
    * Post:
    */
    void agregar_casillero(coordenada posicion, int valor);

    /*
    * Pre:
    * Post: Devuelve una coordenada valida.
    */
    coordenada generar_coordenada_aleatoria_valida();

    /*
    * Pre:
    * Post: Devuelve una coordenada valida.
    */
    static coordenada generar_coordenada_aleatoria_valida(mapa& mapa);

    /*
    * Pre:
    * Post:
    */
    void dibujar_mapa(sf::RenderWindow& window);

    // Pre: -
    // Post: Devuelve una lista con los vecinos válidos, es decir, caminables.
    std::list<coordenada> obtener_vecinos_valido(coordenada posicion);

    // Pre: -
    // Post: Devuelve una lista con todos los vecinos.
    std::list<coordenada> obtener_vecinos(coordenada posicion);
};

#endif