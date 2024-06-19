#ifndef AYED_TPG_1C2024_HEAP_HPP
#define AYED_TPG_1C2024_HEAP_HPP

#include <vector>
#include <cstdlib>
#include <exception>

class heap_exception : public std::exception {
};

template<typename T, bool comp(T, T)>
class heap {
private:
    std::vector<T> datos;

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

    //Pre: El indice debe ser menor que la cantidad de datos.
    //Post: Realiza la cantidad de upheaps necesarios para acomodar el heap y devuelve esa cantidad.
    size_t contar_upheaps(size_t& indice);

    //Pre: El indice debe ser menor que la cantidad de datos.
    //Post: Realiza la cantidad de downheaps necesarios para acomodar el heap y devuelve esa cantidad.
    size_t contar_downheaps(size_t& indice);
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

template <typename T, bool (*comp)(T, T)>
size_t heap<T, comp>::contar_upheaps(size_t& indice){
    size_t upheaps = 0;
    size_t pos_padre = (indice-1)/2;
    while (indice > 0 && datos[pos_padre] < datos[indice]){
        swap(pos_padre, indice);
        upheaps++;
        indice = pos_padre;
        pos_padre = (indice-1)/2;
    }
    return upheaps;
}

template <typename T, bool (*comp)(T, T)>
size_t heap<T, comp>::contar_downheaps(size_t &indice){
    size_t downheaps = 0;
    size_t pos_hijo_izq = (indice*2)+1;
    size_t pos_hijo_der = (indice*2)+2;
    size_t pos_mayor = indice;
    while((pos_hijo_der < datos.size() && datos[pos_hijo_der] > datos[pos_mayor]) || (pos_hijo_izq < datos.size() && datos[pos_hijo_izq] > datos[pos_mayor])){

        if (pos_hijo_der < datos.size() && datos[pos_hijo_der] > datos[pos_mayor]){
            pos_mayor = pos_hijo_der;
        }
        if (pos_hijo_izq < datos.size() && datos[pos_hijo_izq] > datos[pos_mayor]){
            pos_mayor = pos_hijo_izq;
        }

        if(pos_mayor != indice){
            swap(pos_mayor, indice);
            downheaps++;
            indice = pos_mayor;
            pos_hijo_izq = (indice*2)+1;
            pos_hijo_der = (indice*2)+2;
        }
    }
    return downheaps;
}

template <typename T, bool (*comp)(T, T)>
heap<T, comp>::heap(){

}

template <typename T, bool (*comp)(T, T)>
void heap<T, comp>::swap(size_t indice_1, size_t indice_2){
    if(indice_1 < datos.size() && indice_2 < datos.size()){
        T aux = datos[indice_2];
        datos[indice_2] = datos[indice_1];
        datos[indice_1] = aux;
    }
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::upheap(size_t& indice) {

    size_t pos_padre = (indice-1)/2;
    while (indice > 0 && datos[pos_padre] < datos[indice]){
        swap(pos_padre, indice);
        upheaps++;
        indice = pos_padre;
        pos_padre = (indice-1)/2;
    }
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::downheap(size_t& indice) {

    size_t pos_hijo_izq = (indice*2)+1;
    size_t pos_hijo_der = (indice*2)+2;
    size_t pos_mayor = indice;
    while((pos_hijo_der < datos.size() && datos[pos_hijo_der] > datos[pos_mayor]) || (pos_hijo_izq < datos.size() && datos[pos_hijo_izq] > datos[pos_mayor])){

        if (pos_hijo_der < datos.size() && datos[pos_hijo_der] > datos[pos_mayor]){
            pos_mayor = pos_hijo_der;
        }
        if (pos_hijo_izq < datos.size() && datos[pos_hijo_izq] > datos[pos_mayor]){
            pos_mayor = pos_hijo_izq;
        }

        if(pos_mayor != indice){
            swap(pos_mayor, indice);
            indice = pos_mayor;
            pos_hijo_izq = (indice*2)+1;
            pos_hijo_der = (indice*2)+2;
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
    size_t cant_upheaps = 0;
    if(vacio()){
        datos.push_back(dato);
    }
    else{
        datos.push_back(dato);
        size_t pos_dato_nuevo = datos.size() - 1;
        cant_upheaps = contar_upheaps(pos_dato_nuevo);
    }
    return cant_upheaps;
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::baja_complejidad() {
    size_t cant_downheaps = 0;
    if(!vacio()){
        size_t pos_eliminado = 0;
        size_t pos_ultimo = datos.size() - 1;
        swap(pos_eliminado,pos_ultimo);
        cant_downheaps = contar_downheaps(pos_eliminado);
        datos.pop_back();
    }
    return cant_downheaps;
}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::primero() {
    T primer_dato;
    if (!vacio()){
        primer_dato = datos.front(); 
    }
    return primer_dato;
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
    while (!vacio()){
        baja();
    }
}

#endif