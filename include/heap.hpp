#ifndef AYED_TPG_1C2024_HEAP_HPP
#define AYED_TPG_1C2024_HEAP_HPP

#include <vector>
#include <cstdlib>
#include <exception>
#include <random>

class heap_exception : public std::exception {
};

template<typename T, bool comp(T, T)>
class heap {
private:
    std::vector<T> datos;

    //Pre: Necesita de dos cotas, una inferior y una superior.
    //Post: Devuelve un numero entero que va a estar entre las dos cotas dadas.
    int rand_int_gen(int cota_inf, int cota_sup);

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Intercambia de lugar los datos de los indices indicados.
    void swap(size_t indice_1, size_t indice_2);

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Realiza un "upheap" sobre los índices indicados.
    // (El dato "sube" en el heap.)
    void upheap(size_t& indice);

    // Post: El índice debe ser menor que la cantidad de datos.
    // Post: Realiza un "downheap" sobre el índice indicado.
    // (El dato "baja" en el heap, intercambiándose con el menor/mayor dato.)
    void downheap(size_t& indice);

    // NOTA: No es necesario que lancen excepciones en estos métodos porque son privados.
    // Deberían siempre asegurar que los índices pasados por parámetros son válidos.
    // Consideren cada caso con detenimiento.
    // Adicionalmente, tengan cuidado con el casteo de las variables, porque son size_t.
    // Hacer, por ejemplo, size_t i = 0; i - 1; produce un underflow.
public:
    // Constructor.
    heap();

    // Pre: -
    // Post: Agrega el dato al heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Método para el informe de complejidad algorítmica. Devuelve la cantidad de "upheaps".
    size_t alta_complejidad(T dato);

    // Método para el informe de complejidad algorítmica. Devuelve la cantidad de "downheaps".
    size_t baja_complejidad();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // Destructor.
    ~heap();
};

template<typename T, bool (* comp)(T, T)>
heap<T, comp>::heap() {

}

template<typename T, bool (*comp)(T,T)>
int heap<T, comp>::rand_int_gen(int cota_inf, int cota_sup){
    int rand_num;
    random_device rd;
    uniform_int_distribution<int> dist(cota_inf,cota_sup);
    rand_num = dist(rd);
    return rand_num;
}

template <typename T, bool (*comp)(T, T)>
void heap<T, comp>::swap(size_t indice_1, size_t indice_2)
{
    if(indice_1 < datos.size() && indice_2 < datos.size()){
        T aux = datos[indice_2];
        datos[indice_2] = datos[indice_1];
        datos[indice_1] = aux;
    }
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::upheap(size_t& indice) {
    while (indice > 0 && indice < datos.size()){
        size_t pos_padre = (indice-1)/2;
        if(datos[pos_padre] < datos[indice]){
            swap(pos_padre, indice);
            indice = pos_padre;
        }
    }
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::downheap(size_t& indice) {
    while(indice < datos.size() && indice > 0){
        size_t pos_hijo_izq = (indice*2)+1;
        size_t pos_hijo_der = (indice*2)+2;
        size_t pos_mayor;
        if (datos[pos_hijo_der] > datos[pos_hijo_izq]){
            pos_mayor = pos_hijo_der;
        }
        else{
            pos_mayor = pos_hijo_izq;
        }

        if(pos_mayor < datos.size() && datos[pos_mayor]){
            swap(pos_mayor, indice);
            indice = pos_mayor;
        }
    }
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::alta(T dato) {
    if(vacio()){
        datos.push_back(dato);
    }
    else{
        datos.push_back(dato);
        size_t pos_dato_nuevo = datos.size() - 1;
        upheap(pos_dato_nuevo);
    }
}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::baja() {
    T eliminado;
    if(!vacio()){
        eliminado = datos.front();
        size_t pos_eliminado = 0;
        size_t pos_ultimo = datos.size() - 1;
        swap(pos_eliminado,pos_ultimo);
        downheap(pos_eliminado);
        datos.pop_back();
    }
    return eliminado;
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::alta_complejidad(T dato) {
    return size_t;
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::baja_complejidad() {
    return size_t;
}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::primero() {
    if (!vacio()){
        return datos.front(); 
    }
}

template<typename T, bool (* comp)(T, T)>
bool heap<T, comp>::vacio() {
    return datos.empty();
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::tamanio() {
    return datos.size();
}

template<typename T, bool (* comp)(T, T)>
heap<T, comp>::~heap() {

}

#endif