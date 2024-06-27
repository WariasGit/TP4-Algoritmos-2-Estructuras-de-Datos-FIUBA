#include "personaje.hpp"

personaje::personaje() {
    posicion = coordenada(- UN_INDICE, - UN_INDICE);
    simbolo_jugador = static_cast<size_t>(JUGADOR);

}

personaje::personaje(coordenada posicion){
    this->posicion = posicion;
    simbolo_jugador = static_cast<size_t>(JUGADOR);
    lleva_un_pedido = false;
}

coordenada personaje::obtener_posicion(){
    return posicion;
}

int personaje::obtener_simbolo(){
    return simbolo_jugador;
}

pedido personaje::obtener_pedido() {
    return pedido_actual;
}

bool personaje::tiene_pedido() {
    return lleva_un_pedido;
}

void personaje::set_lleva_pedido() {
    this->lleva_un_pedido = !lleva_un_pedido;
}

void personaje::set_posicion(coordenada posicion_nueva){
    posicion = posicion_nueva;
}

void personaje::set_pedido(pedido pedido_nuevo) {
    this->pedido_actual = pedido_nuevo;
}


