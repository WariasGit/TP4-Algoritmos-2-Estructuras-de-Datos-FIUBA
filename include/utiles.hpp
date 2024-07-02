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
    /*
    * Pre: Los objetos `primer_pedido` y `segundo_pedido` deben ser válidos y estar correctamente inicializados.
    * Post: Devuelve `true` si la prioridad del `primer_pedido` es mayor que la del `segundo_pedido`.
    */
bool comparar_pedidos(pedido primer_pedido, pedido segundo_pedido);

    /*
    * Pre:
    * Post: Devuelve `true` si `nombre1` es menor que `nombre2` al compararlos lexicográficamente (alfabeticamente).
    */
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
     * Pre: La lista `NOMBRE_LOCALES` debe contener al menos un nombre.
     * Post: Devuelve un nombre aleatorio de la lista `NOMBRE_LOCALES`.
     */
    static std::string obtener_nombre_aleatorio();

    /*
     * Pre: `path_dot` debe ser una ruta válida a un archivo .dot existente.
     *       `path_png` debe ser una ruta válida donde se guardará el archivo .jpg resultante.
     * Post: Se ejecuta un comando para convertir el archivo .dot a .jpg.
     *        Se imprime un mensaje de exito o error, segun corresponda.
     */
    static void convertir_dot_a_jpg(const std::string& path_dot, const std::string& path_png);
};


#endif
