#ifndef AYED_TPG_1C2024_PERSONAJE_HPP
#define AYED_TPG_1C2024_PERSONAJE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "coordenada.hpp"
#include "utiles.hpp"
#include "mapa.hpp"
#include "constantes.hpp"
#include "pedido.hpp"

class personaje{
private:
    coordenada posicion;
    int simbolo_jugador;
    bool lleva_un_pedido;
    pedido pedido_actual;
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
    pedido obtener_pedido();

    /*
    * Pre:
    * Post:
    */
    bool tiene_pedido();

    /*
    * Pre:
    * Post:
    */
    void set_lleva_pedido();

    /*
    * Pre:
    * Post:
    */
    void set_pedido(pedido pedico_nuevo);


    /*
    * Pre:
    * Post:
    */
    void set_posicion(coordenada posicion_nueva);

};

#endif