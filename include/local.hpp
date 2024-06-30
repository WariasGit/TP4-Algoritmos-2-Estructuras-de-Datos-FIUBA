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
    * Post: Crea pedidos
    */
    pedido generar_pedido(coordenada posicion_local_destino);

    /*
    * Pre:
    * Post:
    */
    const std::string obtener_nombre();

    /*
    * Pre:
    * Post:
    */
    int obtener_simbolo();

    /*
    * Pre:
    * Post:
    */
    coordenada obtener_posicion();
};



#endif