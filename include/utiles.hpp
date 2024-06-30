#ifndef AYED_TPG_1C2024_UTILES_HPP
#define AYED_TPG_1C2024_UTILES_HPP

#include <iostream>
#include "coordenada.hpp"
#include <random>
#include "constantes.hpp"
#include "pedido.hpp"

enum UTILES{
    INICIA_EN_CERO = 0,
};

class pedido;

bool comparar_pedidos(pedido primer_pedido, pedido segundo_pedido);

bool comparar_nombres(std::string nombre1, std::string nombre2);

class utiles{
public:
    /*
    * Pre:
    * Post: Devuelve una opcion valida.
    */
    static int validar_ingreso_opcion(std::string input, int minimo, int maximo);

    /*
    * Pre:
    * Post: Devuelve true si el input es numerico.
    */
    static bool es_numerico(std::string input);

    /*
    * Pre:
    * Post: Devuelve true si el input corresponde a una opcion valida.
    */
    static bool es_numero_valido(std::string input, int opcion_min, int opcion_max);

    /*
    * Pre: Minimo y maximo deben ser valores validos. Minimo debe ser menor o igual que maximo.
    * Post: Devuelve un numero entero aleatorio en el rango [minimo, maximo]. 
    *       El numero aleatorio generado, sigue una distribucion uniforme dentro del rango.
    *       Cada llamada produce un resultado independiente del resto de llamadas.
    */
    static size_t generar_numero_aleatorio(size_t minimo, size_t maximo);

    /*
    * Pre: Maximo debe ser un valor valido y mayor a cero.
    * Post: Devuelve un numero entero aleatorio en el rango [cero, maximo]. 
    *       El numero aleatorio generado, sigue una distribucion uniforme dentro del rango.
    *       Cada llamada produce un resultado independiente del resto de llamadas.
    */
    static size_t generar_numero_aleatorio(size_t maximo);

    /*
     * Pre:
     * Post:
     */
    static std::string obtener_nombre_aleatorio();

    /*
     * Pre:
     * Post:
     */
    static void convertir_dot_a_jpg(const std::string& path_dot, const std::string& path_png);
};


#endif