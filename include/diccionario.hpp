#ifndef AYED_TPG_1C2024_DICCIONARIO_HPP
#define AYED_TPG_1C2024_DICCIONARIO_HPP

#include <exception>
#include <cstdlib>
#include <vector>
#include <queue>
#include "nodo.hpp"
#include <stack>

class diccionario_exception : public std::exception {
};

template<typename c, typename T, bool comp(c, c)>
class diccionario {
private:
    // comp es la función de comparación para las claves.
    // La clave debe implementar el operator==().
    nodo<c, T, comp>* Raiz;
    std::size_t cantidad_datos;

    // Pre: Nodo puede ser nullptr.
    // Post: Devuelve el nodo con la clave y dato insertados, incrementando la cantidad de datos si es un nuevo nodo.
    nodo<c, T, comp>* alta_recursiva(nodo<c, T, comp>* nodo, c clave, T dato);

    // Pre: Nodo puede ser nullptr.
    // Post: Devuelve el nodo con la clave eliminada, decrementando la cantidad de datos si se eliminó un nodo.
    nodo<c, T, comp>* baja_recursiva(nodo<c, T, comp>* nodo, c clave);

    // Pre: Nodo no puede ser nullptr.
    // Post: Devuelve el nodo con el valor mínimo.
    nodo<c, T, comp>* encontrar_minimo(nodo<c, T, comp>* nodo);

    // Pre: Nodo puede ser nullptr.
    // Post: Llena el vector resultado con los datos en orden inorder.
    void inorder_recursivo(nodo<c, T, comp>* nodo, std::vector<T>& resultado);

    // Pre: Nodo puede ser nullptr.
    // Post: Llena el vector resultado con los datos en orden preorder.
    void preorder_recursivo(nodo<c, T, comp>* nodo, std::vector<T>& resultado);

    // Pre: Nodo puede ser nullptr.
    // Post: Llena el vector resultado con los datos en orden postorder.
    void postorder_recursivo(nodo<c, T, comp>* nodo, std::vector<T>& resultado);

    // Pre: Nodo puede ser nullptr.
    // Post: Llena el vector resultado con los datos en orden de nivel dado.
    void ancho_recursivo(nodo<c, T, comp>* nodo, int nivel, std::vector<T>& resultado);

    // Pre: Nodo puede ser nullptr.
    // Post: Devuelve la altura del nodo.
    int altura(nodo<c, T, comp>* nodo);
    
public:
    // Constructor.
    diccionario();

    // Pre: La clave no puede existir en el árbol.
    // Post: Agrega el dato asociado a la clave al árbol. Si no hay datos, crea una nueva raíz.
    void alta(c clave, T dato);

    // Pre: -
    // Post: Elimina el dato asociado a la clave del árbol. Si no existe, no hace nada.
    // NOTA: El caso de baja con dos hijos se resuelve con sucesor inmediato. Se puede hacer swap del dato.
    void baja(c clave);

    // Pre: La clave debe existir en el árbol.
    // Post: Devuelve una referencia al valor asociado a la clave.
    T& operator[](c clave);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    std::vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    std::vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    std::vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho.
    std::vector<T> ancho();

    // Pre: -
    // Post: Ejecuta el método/función en cada valor del árbol.
    /* NOTA: No abusar de este método, está solamente para simplificar algunas cosas,
     * como liberar la memoria de los nodos de usar punteros o imprimir por pantalla el contenido.
     * Pueden usar cualquier recorrido. */
    void ejecutar(void funcion(T));

    // Pre: -
    // Post: Devuelve la cantidad de datos en el árbol.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el árbol está vacío.
    bool vacio();

    // El constructor de copia está deshabilitado.
    diccionario(const diccionario& abb) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const diccionario& abb) = delete;

    // Destructor.
    ~diccionario();
};

template<typename c, typename T, bool (* comp)(c, c)>
diccionario<c, T, comp>::diccionario() {
    Raiz = nullptr;
    cantidad_datos = 0;
}


template<typename c, typename T, bool comp(c, c)>
nodo<c, T, comp>* diccionario<c, T, comp>::alta_recursiva(nodo<c, T, comp>* Nodo, c clave, T dato) {
    if (!Nodo) {
        cantidad_datos++;
        return new nodo<c, T, comp>(clave, dato);
    }

    if (comp(clave, Nodo->clave)) {
        Nodo->hijo_izquierdo = alta_recursiva(Nodo->hijo_izquierdo, clave, dato);
    } else if (comp(Nodo->clave, clave)) {
        Nodo->hijo_derecho = alta_recursiva(Nodo->hijo_derecho, clave, dato);
    } else {
        throw diccionario_exception();
    }

    return Nodo;
}

template<typename c, typename T, bool (* comp)(c, c)>
void diccionario<c, T, comp>::alta(c clave, T dato) {
    Raiz = alta_recursiva(Raiz, clave, dato);
}

template<typename c, typename T, bool comp(c, c)>
nodo<c, T, comp>* diccionario<c, T, comp>::baja_recursiva(nodo<c, T, comp>* Nodo, c clave) {
    if (!Nodo) throw diccionario_exception();

    if (comp(clave, Nodo->clave)) {
        Nodo->hijo_izquierdo = baja_recursiva(Nodo->hijo_izquierdo, clave);
    } else if (comp(Nodo->clave, clave)) {
        Nodo->hijo_derecho = baja_recursiva(Nodo->hijo_derecho, clave);
    } else {
        if (!Nodo->hijo_izquierdo) {
            nodo<c, T, comp>* Temp = Nodo->hijo_derecho;
            delete Nodo;
            cantidad_datos--;
            return Temp;
        } else if (!Nodo->hijo_derecho) {
            nodo<c, T, comp>* Temp = Nodo->hijo_izquierdo;
            delete Nodo;
            cantidad_datos--;
            return Temp;
        }

        nodo<c, T, comp>* Temp = encontrar_minimo(Nodo->hijo_derecho);
        Nodo->clave = Temp->clave;
        Nodo->dato = Temp->dato;
        Nodo->hijo_derecho = baja_recursiva(Nodo->hijo_derecho, Temp->clave);
    }
    return Nodo;
}


template<typename c, typename T, bool (* comp)(c, c)>
void diccionario<c, T, comp>::baja(c clave) {
    Raiz = baja_recursiva(Raiz, clave);
}

template<typename c, typename T, bool (* comp)(c, c)>
T& diccionario<c, T, comp>::operator[](c clave) {
    nodo<c, T, comp>* Actual = Raiz;

    while (Actual != nullptr) {
        if (clave == Actual->clave) {
            return Actual->dato;
        } else if (comp(clave, Actual->clave)) {
            Actual = Actual->hijo_izquierdo;
        } else {
            Actual = Actual->hijo_derecho;
        }
    }

    throw diccionario_exception();
}


template<typename c, typename T, bool comp(c, c)>
nodo<c, T, comp>* diccionario<c, T, comp>::encontrar_minimo(nodo<c, T, comp>* Nodo) {
    while (Nodo && Nodo->hijo_izquierdo) {
        Nodo = Nodo->hijo_izquierdo;
    }
    return Nodo;
}


template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::inorder_recursivo(nodo<c, T, comp>* Nodo, std::vector<T>& resultado) {
    if (Nodo) {
        inorder_recursivo(Nodo->hijo_izquierdo, resultado);
        resultado.push_back(Nodo->dato);
        inorder_recursivo(Nodo->hijo_derecho, resultado);
    }
}


template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::inorder() {
    std::vector<T> resultado;
    inorder_recursivo(Raiz, resultado);
    return resultado;
}


template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::preorder_recursivo(nodo<c, T, comp>* Nodo, std::vector<T>& resultado) {
    if (Nodo) {
        resultado.push_back(Nodo->dato);
        preorder_recursivo(Nodo->hijo_izquierdo, resultado);
        preorder_recursivo(Nodo->hijo_derecho, resultado);
    }
}


template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::preorder() {
    std::vector<T> resultado;
    preorder_recursivo(Raiz, resultado);
    return resultado;
}


template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::postorder_recursivo(nodo<c, T, comp>* Nodo, std::vector<T>& resultado) {
    if (Nodo) {
        postorder_recursivo(Nodo->hijo_izquierdo, resultado);
        postorder_recursivo(Nodo->hijo_derecho, resultado);
        resultado.push_back(Nodo->dato);
    }
}


template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::postorder() {
    std::vector<T> resultado;
    postorder_recursivo(Raiz, resultado);
    return resultado;
}


template<typename c, typename T, bool comp(c, c)>
int diccionario<c, T, comp>::altura(nodo<c, T, comp>* Nodo) {
    if (!Nodo) return 0;
    int altura_izquierda = altura(Nodo->hijo_izquierdo);
    int altura_derecha = altura(Nodo->hijo_derecho);
    return std::max(altura_izquierda, altura_derecha) + 1;
}


template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::ancho_recursivo(nodo<c, T, comp>* Nodo, int nivel, std::vector<T>& resultado) {
    if (!Nodo) return;
    if (nivel == 1) {
        resultado.push_back(Nodo->dato);
    } else if (nivel > 1) {
        ancho_recursivo(Nodo->hijo_izquierdo, nivel - 1, resultado);
        ancho_recursivo(Nodo->hijo_derecho, nivel - 1, resultado);
    }
}


template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::ancho() {
    std::vector<T> resultado;
    int h = altura(Raiz);
    for (int i = 1; i <= h; i++) {
        ancho_recursivo(Raiz, i, resultado);
    }
    return resultado;
}

template<typename c, typename T, bool (* comp)(c, c)>
void diccionario<c, T, comp>::ejecutar(void (* funcion)(T)) {
    std::vector<T> in_order = inorder();
    for (auto& dato : in_order) {
        funcion(dato);
    }
}

template<typename c, typename T, bool (* comp)(c, c)>
std::size_t diccionario<c, T, comp>::tamanio() {
    return cantidad_datos;
}

template<typename c, typename T, bool (* comp)(c, c)>
bool diccionario<c, T, comp>::vacio() {
    return (cantidad_datos == 0);
}

template<typename c, typename T, bool (* comp)(c, c)>
diccionario<c, T, comp>::~diccionario() {
    if (Raiz == nullptr) return;

    std::stack<nodo<c, T, comp>*> Pila;
    Pila.push(Raiz);

    while (!Pila.empty()) {
        nodo<c, T, comp>* Actual = Pila.top();
        Pila.pop();

        if (Actual->hijo_izquierdo != nullptr) {
            Pila.push(Actual->hijo_izquierdo);
        }
        if (Actual->hijo_derecho != nullptr) {
            Pila.push(Actual->hijo_derecho);
        }

        delete Actual;
    }
}

#endif