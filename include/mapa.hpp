#ifndef AYED_TPG_1C2024_MAPA_HPP
#define AYED_TPG_1C2024_MAPA_HPP

#include "coordenada.hpp"
#include <iostream>
#include <fstream>
#include "utiles.hpp"
#include <string>
#include <sstream>


/* Esta clase es la encargada de decirle a a_estrella si la posición de un vecino es válida o no.
 * Queda a criterio del grupo como implementarla. La idea es que a_estrella no tenga detalles de
 * implementación de posibles casilleros, clientes, paredes, locales, etc.
 * Adicionalmente, la pueden utilizar para otras partes del TP.
 * TIP: Tienen una matriz ya implementada como parte de la plantilla del TP. */

enum CONSTANTES_MAPA{
    UN_INDICE = 1,
};

class mapa {
public:
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
    void agregar_casilleros_caminables(size_t fila, size_t columna);

    /*
    * Pre: 
    * Post: Devuelve una coordenada valida.
    */
    static coordenada generar_coordenada_aleatoria_valida();
};

#endif