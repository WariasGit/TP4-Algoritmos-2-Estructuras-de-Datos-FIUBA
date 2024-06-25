#ifndef AYED_TPG_1C2024_PERSONAJE_HPP
#define AYED_TPG_1C2024_PERSONAJE_HPP

#include <iostream>
#include "coordenada.hpp"
#include "utiles.hpp"
#include "mapa.hpp"
#include "constantes.hpp"

class personaje{
private:
    coordenada posicion;
    int simbolo_jugador;
public:
    /*
    * NOTA: Este contructor está solamente por temas de C++, (default-constructible). No tiene sentido usarlo.
    */
    personaje();

    /*
    * Constructor
    */
    personaje(coordenada posicion);

    /*
    * Pre:
    * Post:
    */
    coordenada obtener_posicion();

    /*
    * Pre:
    * Post:
    */
    int obtener_simbolo();

    /*
    * Pre:
    * Post:
    */
    void establecer_posicion(coordenada posicion_nueva);
};

#endif