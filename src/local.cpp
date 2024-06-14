#include "local.hpp"

local::local(){
    nombre = "PREDEFINIDO";
    prioridad = utiles::generar_numero_aleatorio(PRIORIDAD_MAXIMA_LOCAL,PRIORIDAD_MAXIMA_LOCAL);
    posicion = mapa::generar_coordenada_aleatoria_valida();
    mapa::agregar_no_caminable(posicion);
}

pedido local::generar_pedido(){
    coordenada posicion_otro_local = mapa::generar_coordenada_aleatoria_valida(); //Deberiamos obtener la coordenada de otro local desde el diccionario (creo)
    return pedido(posicion, posicion_otro_local, prioridad);
    
}
