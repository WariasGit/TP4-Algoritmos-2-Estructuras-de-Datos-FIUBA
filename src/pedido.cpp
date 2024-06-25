#include "pedido.hpp"

pedido::pedido() {
    local_inicio = coordenada();
    local_destino = coordenada();
    peso_paquete = CERO;
    prioridad_pedido = peso_paquete;
    entregado = true;
}

pedido::pedido(coordenada inicio, coordenada destino, size_t prioridad_del_local){
    local_inicio = inicio;
    local_destino = destino;
    peso_paquete = utiles::generar_numero_aleatorio(PESO_MINIMO, PESO_MAXIMO);
    prioridad_pedido = peso_paquete * prioridad_del_local;
    entregado = false;
}


