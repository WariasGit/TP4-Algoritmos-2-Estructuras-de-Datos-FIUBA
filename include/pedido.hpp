#ifndef AYED_TPG_1C2024_PEDIDO_HPP
#define AYED_TPG_1C2024_PEDIDO_HPP

#include <iostream>
#include "coordenada.hpp"
#include "utiles.hpp"
#include "constantes.hpp"



class pedido{
private:
    coordenada local_inicio;
    coordenada local_destino;
    size_t peso_paquete;
    size_t prioridad_pedido;
    bool entregado;
public:

    pedido();

    /*
    * Pre:
    * Post: Constructor.
    */
    pedido(coordenada inicio, coordenada destino, size_t prioridad_del_local);
};


#endif