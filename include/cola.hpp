#ifndef AYED_TP3_1C2024_COLA_HPP
#define AYED_TP3_1C2024_COLA_HPP

#include <exception>
#include "nodo.hpp"

class cola_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro de la cola.
    // Usar de la forma "throw cola_exception();" cuando una precondición no se cumple.

    // Ejemplo:
    //     if (condición_de_error) {
    //         throw cola_exception();
    //     }
};

template<typename T>
class cola {
private:
    nodo<T>* primer_nodo;
    nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato de la cola.
    T primero();

    // Pre: La cola no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la cola.
    T baja();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    cola(const cola& c) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const cola& c) = delete;

    // Destructor.
    ~cola();
};

template<typename T>
cola<T>::cola() {

}

template<typename T>
void cola<T>::alta(T dato) {

}

template<typename T>
T cola<T>::primero() {

}

template<typename T>
T cola<T>::baja() {

}

template<typename T>
size_t cola<T>::tamanio() {

}

template<typename T>
bool cola<T>::vacio() {

}

template<typename T>
cola<T>::~cola() {

}

#endif