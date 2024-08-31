#include "local.hpp"

local::local() {
    nombre = "";
    posicion = coordenada(-1,-1);
    prioridad = CERO;
}

local::local(coordenada posicion_nueva){
    nombre = utiles::obtener_nombre_aleatorio();
    prioridad = utiles::generar_numero_aleatorio(PRIORIDAD_MINIMA_LOCAL,PRIORIDAD_MAXIMA_LOCAL);
    posicion = posicion_nueva;
    simbolo_local = LOCAL;
}

pedido local::generar_pedido(coordenada posicion_local_destino){
    coordenada posicion_otro_local = posicion_local_destino;
    return pedido(posicion, posicion_otro_local, prioridad);
}

const std::string local::obtener_nombre() {
    return nombre;
}

int local::obtener_simbolo() {
    return simbolo_local;
}

coordenada local::obtener_posicion() {
    return posicion;
}
