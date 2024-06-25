#ifndef AYED_TPG_1C2024_JUEGO_HPP
#define AYED_TPG_1C2024_JUEGO_HPP

#include <iostream>
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


#ifdef __linux__
#define LIMPIAR "clear"
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__

class juego {
private:
    int estado_del_juego;
    int vitalidad_del_callejon;
    int pedidos_entregados;
    size_t monedas;
    std::vector<local> locales;
    std::vector<pedido> pedidos;
    a_estrella caminos_minimos;
    std::stack<coordenada> camino_minimo_actual;
    personaje jugador;
    mapa tablero;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text menuText;

    /*
    * Pre:
    * Post:
    */
    void mover_jugador(DIRECCION direccion);

    /*
    * Pre:
    * Post:
    */
    void cargar_posicion_jugador_en_mapa();


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

    void calcular_camino_minimo(coordenada inicio, coordenada destino);
    void visualizar_camino_minimo(std::stack<coordenada>& camino);


public:
    /*
     * Constructor.
     */
    juego();


    /*
    * Pre:
    * Post:
    */
    void actualizar_juego();

    /*
    * Pre:
    * Post:
    */
    void manejar_eventos_ventana();

    /*
    * Pre:
    * Post: Muesta las opciones de juego, valida las entradas y realiza las acciones correspondientes.
    */
    void jugar();

};


#endif