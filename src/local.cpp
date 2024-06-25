#include "local.hpp"

local::local() {
    nombre = "";
    posicion = coordenada(-1,-1);
}

local::local(coordenada posicion){
    nombre = utiles::obtener_nombre_aleatorio();
    prioridad = utiles::generar_numero_aleatorio(PRIORIDAD_MINIMA_LOCAL,PRIORIDAD_MAXIMA_LOCAL);
    this->posicion = posicion;
}

pedido local::generar_pedido(coordenada posicion_local_destino){
    coordenada posicion_otro_local = posicion_local_destino;
    return pedido(posicion, posicion_otro_local, prioridad);
}
