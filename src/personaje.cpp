#include "personaje.hpp"

personaje::personaje() {
    posicion = coordenada(- UN_INDICE, - UN_INDICE);
    simbolo_jugador = static_cast<size_t>(JUGADOR);
}

personaje::personaje(coordenada posicion){
    this->posicion = posicion;
    simbolo_jugador = static_cast<size_t>(JUGADOR);
}

coordenada personaje::obtener_posicion(){
    return posicion;
}

int personaje::obtener_simbolo(){
    return simbolo_jugador;
}

void personaje::establecer_posicion(coordenada posicion_nueva){
    posicion = posicion_nueva;
}
