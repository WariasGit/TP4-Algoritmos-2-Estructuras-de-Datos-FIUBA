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


coordenada pedido::obtener_posicion_inicio() {
    return local_inicio;
}

coordenada pedido::obtener_posicion_destino() {
    return local_destino;
}

size_t pedido::obtener_prioridad_pedido() {
    return prioridad_pedido;
}

bool pedido::esta_entregado() {
    return entregado;
}

void pedido::set_entregado() {
    this->entregado = !entregado;
}

pedido &pedido::operator=(const pedido &otro_pedido) {
    if (this != &otro_pedido) {
        local_inicio = otro_pedido.local_inicio;
        local_destino = otro_pedido.local_destino;
        peso_paquete = otro_pedido.peso_paquete;
        prioridad_pedido = otro_pedido.prioridad_pedido;
        entregado = otro_pedido.entregado;
    }
    return *this;
}
