#ifndef AYED_TPG_1C2024_JUEGO_HPP
#define AYED_TPG_1C2024_JUEGO_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>
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
#include "diccionario.hpp"
#include "utiles.hpp"


class juego {
private:
    size_t vitalidad_del_callejon;
    int pedidos_entregados;
    int pedidos_totales;
    size_t monedas;
    diccionario<std::string, local, comparar_nombres> locales;
    heap<pedido, comparar_pedidos> pedidos;
    grafo grafo_locales;
    a_estrella caminos_minimos;
    std::stack<coordenada> camino_minimo_actual;
    bool mostrar_camino;
    bool mostrar_aem;
    personaje jugador;
    mapa tablero;
    sf::RenderWindow window;
    sf::Clock reloj;

    /*
    * Pre: Recibe una direccion
    * Post: Desplaza al jugador en la direccion indicada
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
    * Post: Se genera el arbol de expancion maxima y se guarda en archivos .dot y .png
    */
    void generar_arbol_expandido();

    /*
    * Pre:
    * Post: Muesta los senderos y conexiones de los locales.
    */
    void mostrar_arbol_expandido();

    /*
    * Pre: Recibe dos coordenadas
    * Post: Calcula el camino minimo, con el algoritmo A*, entre esas dos coordenadas.
    */
    void calcular_camino_minimo(coordenada inicio, coordenada destino);

    /*
    * Pre:
    * Post: Muestra por pantalla el camino, tomando las coordenadas del stack.
    */
    void visualizar_camino_minimo(std::stack<coordenada>& camino);

    /*
    * Pre:
    * Post: Inicia una cantidad aleatoria de locales.
    */
    void inicializar_locales();

    /*
    * Pre:
    * Post: Inicia los primeros pedidos, con los primeros locale generados.
    */
    void generar_pedidos_iniciales();

    /*
    * Pre:
    * Post: Inicia los locales a modo de obstaculos.
    */
    void inicializar_clientes();

    /*
    * Pre:
    * Post: Genera un pedido aleatorio entre los locales.
    */
    void generar_pedido_aleatorio();

    /*
    * Pre:
    * Post: Devuelve la distancia Manhattan entre las dos coordenadas.
    */
    int distancia_manhattan(coordenada a, coordenada b);

public:
    /*
     * Constructor.
     */
    juego();

    /*
    * Pre:
    * Post: Inicializa los componentes del juego.
    */
    void inicializar_juego();


    /*
    * Pre:
    * Post: Actualiza el estado del juego.
    */
    void actualizar_juego();

    /*
    * Pre:
    * Post: Realiza las acciones correspondientes a los eventos del teclado.
    */
    void manejar_eventos_ventana(sf::Event event);

    /*
    * Pre:
    * Post: Realiza las acciones correspondientes al juego.
    */
    void jugar();

};


#endif