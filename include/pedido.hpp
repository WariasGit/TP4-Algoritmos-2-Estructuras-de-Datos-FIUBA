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
    /*
    * Pre:
    * Post: Constructor.
    */
    pedido();

    /*
    * Pre:
    * Post: Constructor.
    */
    pedido(coordenada inicio, coordenada destino, size_t prioridad_del_local);

    /*
    * Pre:
    * Post: Devuelve la coordenada de inicio del pedido es la posicion de un local valido del juego.
    */
    coordenada obtener_posicion_inicio();

    /*
    * Pre:
    * Post: Devuelve la coordenada de destino del pedido, es la posicion de un local valido del juego.
    */
    coordenada obtener_posicion_destino();

    /*
    * Pre:
    * Post: Devuelve la prioridad del pedido.
    */
    size_t obtener_prioridad_pedido();

    /*
    * Pre:
    * Post: Devuelve true si el pedido está entregado, false en caso contrario.
    */
    bool esta_entregado();

    /*
    * Pre:
    * Post:  Cambia el estado de entrega del pedido, estado de entrega del pedido se invierte.
    */
    void set_entregado();

    /*
    * Pre:
    * Post: Operador de asignación.
    */
    pedido& operator=(const pedido& otro);
};


#endif
