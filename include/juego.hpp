#ifndef AYED_TPG_1C2024_JUEGO_HPP
#define AYED_TPG_1C2024_JUEGO_HPP

#include <iostream>
#include "coordenada.hpp"
#include "mapa.hpp"
#include <optional>
#include "personaje.hpp"

#ifdef __linux__
#define LIMPIAR "clear"
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__

enum OPCIONES_MENU_PRINCIPAL{
    INICIO = 0,
    JUGAR = 1,
    CREDITOS = 2,
    SALIR_MENU_PRINCIPAL = 3,
};

enum CARACTERISTICAS_JUEGO {
    LOCALES_MAXIMOS = 4,
    FILAS = 18,
    COLUMNAS = 24,
};

enum OPCIONES_MENU_JUEGO {
    CONTINUAR = 0,
    GENERAR_NUEVO_PEDIDO_ALEATORIO = 1,
    ENTREGAR_PEDIDO = 2,
    MOSTRAR_SENDEROS_CONEXIONES = 3,
    SALIR = 4,
};

enum ESTADO_DEL_JUEGO {
    EN_CURSO = 1,
    FINALIZADO = -1
};


class juego {
private:
int estado_del_juego;
size_t tope_locales;
size_t filas_mapa;
size_t columnas_mapa;
//Arbol de locales
//heap de pedidos
std::optional<personaje> jugador;
std::optional<mapa> tablero;

/*
* Pre:
* Post: Muesta las opciones de juego, valida las entradas y realiza las acciones correspondientes.
*/
void jugar(bool terminar_juego);

/*
* Pre:
* Post: Muestra las opciones del primer menu (principal).
*/
void mostrar_opciones_menu_principal();

/*
* Pre:
* Post: Muestra el segundo menu, con las opciones de juego.
*/
void mostrar_menu_acciones_juego();

/*
* Pre:
* Post: 
*/
void limpiar_pantalla();

/*
* Pre:
* Post: Muesta a los participantes del desarrollo.
*/
void mostrar_autores();

/*
* Pre:
* Post:
*/
void continuar_juego();

/*
* Pre:
* Post: Muestra un mensaje de despedida.
*/
void mensaje_de_salida();

public:
    /*
     * Constructor. No inicia el tablero ni el personaje.
     */
    juego();

    /*
     * Pre:
     * Post: Se ejecutan las funciones del menu.
     */
    void ingresar_menu_principal();

    /*
     * Pre:
     * Post: Se inicia el juego, inicia el tablero, el personaje y las estructuras de datos.
     */
    void iniciar_juego();

    /*
     * Pre: La accion debe ser valida.
     * Post:
     */
    void realizar_jugada(int accion, bool &terminar_juego);

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
     * Destructor.
     */
    ~juego();

};


#endif