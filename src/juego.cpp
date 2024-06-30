#include "juego.hpp"
#include "utiles.hpp"
#include "heuristica.hpp"


juego::juego(){
    vitalidad_del_callejon = CERO;
    pedidos_entregados = CERO;
    monedas = utiles::generar_numero_aleatorio(static_cast<size_t>(MONEDAS_MINIMAS_INICIO), static_cast<size_t>(MONEDAS_MAXIMAS_INICIO));
    caminos_minimos = a_estrella();

    mostrar_camino = false;
    tablero = mapa(FILAS, COLUMNAS);
    jugador = personaje(tablero.generar_coordenada_aleatoria_valida());
    window.create(sf::VideoMode(800, 600), "Mi Juego");
}

void juego::inicializar_juego() {
    tablero.agregar_casillero(jugador.obtener_posicion(), jugador.obtener_simbolo());
    inicializar_locales();
    inicializar_locales();
    inicializar_clientes();
    generar_pedidos_iniciales();
}

void juego::actualizar_juego() {
    if (pedidos_entregados== PEDIDOS_PARA_GANAR || vitalidad_del_callejon >= VITALIDAD_PARA_GANAR){
        window.close();
    }else{
        sf::Time tiempo_transcurrido;
        tiempo_transcurrido = reloj.getElapsedTime();
        if (tiempo_transcurrido >= TIEMPO_ENTRE_PEDIDOS) {
            generar_pedido_aleatorio();
            reloj.restart();
            vitalidad_del_callejon += VITALIDAD_MINIMA;
        }
    }
}

void juego::manejar_eventos_ventana(sf::Event event) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            pedido pedido_actual = pedidos.front();
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    mover_jugador(DIRECCION::ARRIBA);
                    break;
                case sf::Keyboard::Down:
                    mover_jugador(DIRECCION::ABAJO);
                    break;
                case sf::Keyboard::Left:
                    mover_jugador(DIRECCION::IZQUIERDA);
                    break;
                case sf::Keyboard::Right:
                    mover_jugador(DIRECCION::DERECHA);
                    break;
                case sf::Keyboard::A:
                    // Necesito el pedido de mejor prioridad
                    calcular_camino_minimo(pedido_actual.obtener_posicion_inicio(), pedido_actual.obtener_posicion_destino());
                    break;
                case sf::Keyboard::E:
                    mostrar_camino = !mostrar_camino;
                    std::cout << "E" << std::endl;
                    break;
                case sf::Keyboard::D:
                    //mostrar_arbol_expandido();
                    break;
                case sf::Keyboard::Q:
                    tomar_pedido();
                    entregar_pedido();
                    break;
                case sf::Keyboard::X:
                    window.close();
                    break;
                default:
                    break;
            }
        }
}


void juego::jugar(){
    inicializar_juego();
    sf::Event event;
    window.display();
    while (window.isOpen()) {
        while (window.pollEvent(event)){
            manejar_eventos_ventana(event);
            actualizar_juego();
            window.clear();
            mostrar_mapa();
            if (mostrar_camino) {
                visualizar_camino_minimo(camino_minimo_actual);
            }
            window.display();
        }
    }
}

void juego::mover_jugador(DIRECCION direccion) {
    coordenada posicion_actual_jugador = jugador.obtener_posicion();
    int fila_posicion_jugador = posicion_actual_jugador.x();
    int columna_posicion_jugador = posicion_actual_jugador.y();
    switch (direccion) {
        case DIRECCION::ARRIBA:
            fila_posicion_jugador -= 1;
            break;
        case DIRECCION::ABAJO:
            fila_posicion_jugador += 1;
            break;
        case DIRECCION::IZQUIERDA:
            columna_posicion_jugador -= 1;
            break;
        case DIRECCION::DERECHA:
            columna_posicion_jugador += 1;
            break;
    }
    coordenada nueva_posicion = coordenada(fila_posicion_jugador, columna_posicion_jugador);
    if(tablero.es_vecino_valido(nueva_posicion)){
        tablero.agregar_casillero(posicion_actual_jugador, CAMINABLE);
        jugador.set_posicion(nueva_posicion);
        tablero.agregar_casillero(jugador.obtener_posicion(), jugador.obtener_simbolo());
    }
}

void juego::tomar_pedido() {
    if (!jugador.tiene_pedido() && !pedidos.empty()){
        pedido& primer_pedido = pedidos.front();
        if (distancia_manhattan(jugador.obtener_posicion(), primer_pedido.obtener_posicion_inicio()) == DISTANCIA_MANHATTAN_PEDIDO) {
            jugador.set_lleva_pedido();
            jugador.set_pedido(primer_pedido);
            pedidos.erase(pedidos.begin());
            monedas += utiles::generar_numero_aleatorio(MONEDAS_MAXIMAS_POR_PEDIDO_TOMADO);
            vitalidad_del_callejon += utiles::generar_numero_aleatorio(VITALIDAD_MINIMA);
        }
    }
}

void juego::entregar_pedido() {
    if (jugador.tiene_pedido()){
        pedido pedido_actual = jugador.obtener_pedido();
        if (distancia_manhattan(jugador.obtener_posicion(),pedido_actual.obtener_posicion_destino()) == DISTANCIA_MANHATTAN_PEDIDO){
            jugador.set_lleva_pedido();
            monedas += utiles::generar_numero_aleatorio(MONEDAS_MINIMAS_POR_PEDIDO_ENTREGADO, MONEDAS_MAXIMAS_POR_PEDIDO_ENTREGADO);
            pedidos_entregados ++;
            vitalidad_del_callejon += utiles::generar_numero_aleatorio(VITALIDAD_MINIMA,VITALIDAD_MAXIMA);
        }
    }
}

void juego::mostrar_mapa(){
    window.clear(sf::Color(4,19,26));
    tablero.dibujar_mapa(window);
}

void juego::mostrar_arbol_expandido(){
    //minijuego secundario
}

void juego::calcular_camino_minimo(coordenada local_inicio, coordenada local_destino) {
    camino_minimo_actual = caminos_minimos.obtener_camino_minimo(local_inicio, local_destino, tablero,
                                                                 distancia_manhattan_vertice);
}

void juego::visualizar_camino_minimo(std::stack<coordenada>& camino) {
    std::stack<coordenada> camino_copia = camino; // Hacemos una copia del stack original
    sf::Color colorCamino(255, 255, 0, 192);
    while (!camino_copia.empty()) {
        coordenada punto = camino_copia.top();
        camino_copia.pop();
        sf::RectangleShape casillero(sf::Vector2f(TAMANIO_CASILLERO, TAMANIO_CASILLERO));
        casillero.setPosition(float(punto.y()) * TAMANIO_CASILLERO, float(punto.x()) * TAMANIO_CASILLERO);
        casillero.setFillColor(colorCamino);
        window.draw(casillero);
    }

}

void juego::inicializar_locales() {
    size_t cantidad = utiles::generar_numero_aleatorio(LOCALES_MINIMOS, LOCALES_MAXIMOS);
    for(size_t i = 0; i < cantidad; i++){
        coordenada posicion_nueva = tablero.generar_coordenada_aleatoria_valida();
        local nuevo_local = local(posicion_nueva);
        locales.push_back(nuevo_local);
        tablero.agregar_casillero(nuevo_local.obtener_posicion(), nuevo_local.obtener_simbolo());
    }
}

void juego::generar_pedidos_iniciales() {
    for (auto& local_origen : locales) {
        for (auto& local_destino : locales) {
            if (distancia_manhattan(local_origen.obtener_posicion(), local_destino.obtener_posicion()) != CERO) {
                pedido pedido_nuevo = local_origen.generar_pedido(local_destino.obtener_posicion());
                pedidos.push_back(pedido_nuevo);
            }
        }
    }
}

void juego::inicializar_clientes() {
    size_t cantidad = utiles::generar_numero_aleatorio(CLIENTES_MINIMOS, CLIENTES_MAXIMOS);
    for(size_t i = 0; i < cantidad; i++){
        coordenada cliente_nuevo = tablero.generar_coordenada_aleatoria_valida();
        tablero.agregar_casillero(cliente_nuevo, CLIENTE);
    }
}

void juego::generar_pedido_aleatorio() {
    size_t indice_local_inicio;
    size_t indice_local_destino;
    do {
        indice_local_inicio = utiles::generar_numero_aleatorio(locales.size() -1);
        indice_local_destino = utiles::generar_numero_aleatorio(locales.size() -1);
    }
    while (indice_local_destino == indice_local_inicio);
    local& local_inicio = locales[indice_local_inicio];
    local& local_destino = locales[indice_local_destino];
    pedido nuevo_pedido = local_inicio.generar_pedido(local_destino.obtener_posicion());
    pedidos.push_back(nuevo_pedido);
}

int juego::distancia_manhattan(coordenada a, coordenada b) {
    return abs(a.x() - b.x()) + abs(a.y() - b.y());
}