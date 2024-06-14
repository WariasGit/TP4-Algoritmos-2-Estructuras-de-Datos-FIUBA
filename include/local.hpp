#ifndef AYED_TPG_1C2024_LOCAL_HPP
#define AYED_TPG_1C2024_LOCAL_HPP

#include <iostream>
#include "pedido.hpp"
#include "coordenada.hpp"
#include "utiles.hpp"
#include "mapa.hpp"

enum PRIORIDAD_LOCALES {
    PRIORIDAD_MINIMA_LOCAL = 1,
    PRIORIDAD_MAXIMA_LOCAL = 10,
};

class local{
private:
    std::string nombre;
    size_t prioridad;
    coordenada posicion;
public:

    /*
    * Pre:
    * Post: Constructor
    */
    local();

    /*
    * Pre:
    * Post: Crea pedidos
    */
    pedido generar_pedido();

};



#endif