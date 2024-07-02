#ifndef AYED_TPG_1C2024_LOCAL_HPP
#define AYED_TPG_1C2024_LOCAL_HPP

#include <iostream>
#include "pedido.hpp"
#include "coordenada.hpp"
#include "utiles.hpp"
#include "mapa.hpp"
#include "constantes.hpp"


class local{
private:
    std::string nombre;
    size_t prioridad;
    coordenada posicion;
    int simbolo_local;
public:

    /*
    * NOTA: Este contructor está solamente por temas de C++, (default-constructible). No tiene sentido usarlo.
    */
    local();

    /*
    * Pre:
    * Post: Constructor
    */
    local(coordenada posicion_nueva);

    /*
    * Pre:
    * Post: Devuelve un objeto `pedido` que tiene como posición de inicio la posición del local actual y como posición de destino `posicion_local_destino`.
    */
    pedido generar_pedido(coordenada posicion_local_destino);

    /*
    * Pre:
    * Post: Devuelve el nombre del local como un std::string.
    */
    const std::string obtener_nombre();

    /*
    * Pre:
    * Post: Devuelve el símbolo del local como un entero.
    */
    int obtener_simbolo();

    /*
    * Pre:
    * Post: Devuelve la posición del local como una instancia de `coordenada`.
    */
    coordenada obtener_posicion();
};



#endif
