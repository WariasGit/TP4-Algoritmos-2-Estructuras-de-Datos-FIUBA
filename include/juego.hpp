#ifndef AYED_TPG_1C2024_JUEGO_HPP
#define AYED_TPG_1C2024_JUEGO_HPP

#include <iostream>

#include <stack>
#include <vector>
#include <SFML/Graphics.hpp>
#include <optional>
#include "coordenada.hpp"
#include "mapa.hpp"
#include "personaje.hpp"
#include "constantes.hpp"
#include "pedido.hpp"
#include "local.hpp"
#include "a_estrella.hpp"
#include "arista.hpp"
#include "grafo.hpp"
#include "visualizador.hpp"
#include "heap.hpp"
//#include "diccionario.hpp"


class juego {
private:
    size_t vitalidad_del_callejon;
    int pedidos_entregados;
    size_t monedas;
    std::vector<local> locales;
    //diccionario<local, utiles::comparar_claves> locales;
    heap<pedido, comparar_pedidos> pedidos;
    a_estrella caminos_minimos;
    std::stack<coordenada> camino_minimo_actual;
    bool mostrar_camino;
    personaje jugador;
    mapa tablero;
    sf::RenderWindow window;
    sf::Clock reloj;

    /*
    * Pre:
    * Post:
    */
    void mover_jugador(DIRECCION direccion);

    /*
    * Pre: El jugador debe estar cerca del local de inicio.
    * Post: El jugador toma el pedido.
    */
    void tomar_pedido();

    /*
    * Pre: El jugador debe estar cerca del local de destino.
    * Post: El jugador entrega el pedido.
    */
    void entregar_pedido();

    /*
    * Pre:
    * Post: Imprime el juego por pantalla.
    */
    void mostrar_mapa();

    /*
    * Pre:
    * Post: Muesta los senderos y conexiones de los locales.
    */
    void mostrar_arbol_expandido();

    /*
    * Pre:
    * Post:
    */
    void calcular_camino_minimo(coordenada inicio, coordenada destino);

    /*
    * Pre:
    * Post:
    */
    void visualizar_camino_minimo(std::stack<coordenada>& camino);

    /*
    * Pre:
    * Post:
    */
    void inicializar_locales();

    /*
    * Pre:
    * Post:
    */
    void generar_pedidos_iniciales();

    /*
    * Pre:
    * Post:
    */
    void inicializar_clientes();

    /*
    * Pre:
    * Post:
    */
    void generar_pedido_aleatorio();

    /*
    * Pre:
    * Post:
    */
    int distancia_manhattan(coordenada a, coordenada b);

public:
    /*
     * Constructor.
     */
    juego();

    /*
    * Pre:
    * Post:
    */
    void inicializar_juego();


    /*
    * Pre:
    * Post:
    */
    void actualizar_juego();

    /*
    * Pre:
    * Post:
    */
    void manejar_eventos_ventana(sf::Event event);

    /*
    * Pre:
    * Post: Realiza las acciones correspondientes.
    */
    void jugar();

};


#endif