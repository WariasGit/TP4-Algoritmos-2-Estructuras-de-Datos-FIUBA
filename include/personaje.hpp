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
    * Post: Devuelve la posicion del jugador.
    */
    coordenada obtener_posicion();

    /*
    * Pre:
    * Post: Devuelve el simbolo que representa al jugador en el mapa.
    */
    int obtener_simbolo();

    /*
    * Pre:
    * Post: Devuelve el pedido actual del jugador.
    */
    pedido obtener_pedido();

    /*
    * Pre:
    * Post: Devuelve true si el jugador tomo un pedido para entregar.
    */
    bool tiene_pedido();

    /*
    * Pre:
    * Post: Modifica el valor de `lleva_un_pedido`, el cual alternará entre true y false.
    */
    void set_lleva_pedido();

    /*
    * Pre: El objeto `pedido_nuevo` debe ser un objeto válido de tipo `pedido`.
    * Post: El atributo `pedido_actual` del objeto `personaje` se establece con el valor del objeto `pedido_nuevo`.
    */
    void set_pedido(pedido pedico_nuevo);


    /*
    * Pre: El objeto posicicon_nueva debe ser un objeto de tipo coordenada valido.
    * Post: Actualiza la posicion del personaje a posicion_nueva.
    */
    void set_posicion(coordenada posicion_nueva);

};

#endif
