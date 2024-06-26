#ifndef AYED_TPG_1C2024_CONSTANTES_HPP
#define AYED_TPG_1C2024_CONSTANTES_HPP
#include <SFML/Graphics.hpp>

/*CLASE JUEGO*/
enum OPCIONES_MENU_PRINCIPAL{
    INICIO = 0,
    JUGAR = 1,
    CREDITOS = 2,
    SALIR_MENU_PRINCIPAL = 3,
};

enum CARACTERISTICAS_JUEGO {
    CLIENTES_MINIMOS = 1,
    CLIENTES_MAXIMOS = 4,
    LOCALES_MINIMOS = 2,
    LOCALES_MAXIMOS = 6,
    CERO = 0,
    UN_INDICE = 1,
    FILAS = 18,
    COLUMNAS = 24,
    DISTANCIA_MANHATTAN_PEDIDO = 1,
    VITALIDAD_MINIMA = 5,
    VITALIDAD_MAXIMA = 25,
    PEDIDOS_PARA_GANAR = 10,
    VITALIDAD_PARA_GANAR = 100,
};

enum COSTOS_MONEDAS {
    MONEDAS_MINIMAS_INICIO = 15,
    MONEDAS_MAXIMAS_INICIO = 45,
    MONEDAS_POR_CAMINO = 15,
    MONEDAS_MAXIMAS_POR_PEDIDO_TOMADO = 10,
    MONEDAS_MINIMAS_POR_PEDIDO_ENTREGADO = 5,
    MONEDAS_MAXIMAS_POR_PEDIDO_ENTREGADO = 20,
};

enum class DIRECCION {
    ARRIBA,
    ABAJO,
    IZQUIERDA,
    DERECHA,
};

const float TAMANIO_CASILLERO = 20.f;


/*CLASE MAPA*/
enum REPRESENTACIONES_MAPA{
    NO_CAMINABLE = 0,
    CAMINABLE = 1,
    JUGADOR = 2,
    LOCAL = 3,
    CAMINO = 4,
    CLIENTE = 5,
};


/*CLASE LOCAL*/
enum INDICES_LOCALES {
    CANTIDAD_NOMBRES = 15,
};

const std::string NOMBRE_LOCALES[CANTIDAD_NOMBRES] = {
        "Local Ace",
        "Bar Local",
        "Local Caf",
        "Del Local",
        "Local Eco",
        "Fit Local",
        "Local Gal",
        "Hex Local",
        "Local Ice",
        "Joy Local",
        "Local Kid",
        "Lot Local",
        "Local Mix",
        "Nut Local",
        "Local Oas"
};

enum PRIORIDAD_LOCALES {
    PRIORIDAD_MINIMA_LOCAL = 1,
    PRIORIDAD_MAXIMA_LOCAL = 10,
};


/*CLASE PEEDIDOS*/
enum PESOS_PAQUETES{
    PESO_MINIMO = 1,
    PESO_MAXIMO = 15,
};

const sf::Time TIEMPO_ENTRE_PEDIDOS = sf::seconds(15.f);

#define PATH_ARCHIVO_CALLEJON "callejon.csv"


#endif