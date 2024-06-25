#include "juego.hpp"
#include "utiles.hpp"


juego::juego(){
    estado_del_juego = EN_CURSO;
    vitalidad_del_callejon = CERO;
    pedidos_entregados = CERO;
    monedas = utiles::generar_numero_aleatorio(static_cast<size_t>(MONEDAS_MINIMAS_INICIO), static_cast<size_t>(MONEDAS_MAXIMAS_INICIO));
    caminos_minimos = a_estrella();
    //std::stack<coordenada> empty;
    
    tablero = mapa(FILAS, COLUMNAS);
    jugador = personaje(tablero.generar_coordenada_aleatoria_valida());
    window.create(sf::VideoMode(800, 600), "Mi Juego");
    cargar_posicion_jugador_en_mapa();
}

void juego::actualizar_juego() {
    // Actualiza la lógica del juego aquí
    // Por ejemplo, verificar el estado del juego y realizar las acciones necesarias
    if (estado_del_juego == FINALIZADO) {
        window.close();
    }
}

void juego::manejar_eventos_ventana(){
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    if (event.type == sf::Event::KeyPressed) 
    {
        switch (event.key.code) 
        {
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
                //realizar_accion_a();
                break;
            case sf::Keyboard::E:
                //realizar_accion_e();
                break;
            case sf::Keyboard::D:
                //realizar_accion_d();
                break;
            case sf::Keyboard::X:
                //realizar_accion_x();
                break;
            case sf::Keyboard::Q:
                //realizar_accion_q();
                break;
            default:
                break;
        }
    }
}

void juego::jugar(){
    while (window.isOpen()) 
    {
        manejar_eventos_ventana();
        actualizar_juego();
        mostrar_mapa();
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
    if(tablero.es_vecino_valido(nueva_posicion))
    {
        tablero.agregar_casillero(posicion_actual_jugador, CAMINABLE);
        jugador.establecer_posicion(nueva_posicion);
        cargar_posicion_jugador_en_mapa();
    }
}

void juego::cargar_posicion_jugador_en_mapa()
{
    tablero.agregar_casillero(jugador.obtener_posicion(), jugador.obtener_simbolo());
}

void juego::mostrar_mapa()
{
    window.clear();
    tablero.dibujar_mapa(window);
    window.display();
}

void juego::mostrar_arbol_expandido(){
    //minijuego secundario
}

void juego::calcular_camino_minimo(coordenada local_inicio, coordenada local_destino) {
    //camino_minimo_actual = caminos_minimos.obtener_camino_minimo(local_inicio, local_destino, tablero);
}

void juego::visualizar_camino_minimo(std::stack<coordenada>& camino) {
    sf::VertexArray line(sf::LinesStrip);
    sf::Color colorCamino(255, 255, 0);
    while (!camino.empty()) {
        coordenada punto = camino.top();
        camino.pop();
        float tamanioCasillero = 20.f;
        line.append(sf::Vertex(sf::Vector2f(float(punto.x()) * tamanioCasillero, float(punto.y()) * tamanioCasillero), colorCamino));
        std::cout << "Punto: (" << punto.x() << ", " << punto.y() << ")" << std::endl; // Para debug
    }
    window.draw(line);
}


