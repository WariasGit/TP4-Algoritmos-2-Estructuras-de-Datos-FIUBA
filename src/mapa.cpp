#include "mapa.hpp"

bool mapa::es_vecino_valido(coordenada posicion) {
    // TODO: Implementar.
}

void mapa::cargar_callejon(std::string path_archivo){
    std::ifstream archivo(path_archivo);
    std::string linea;
    char delimitador = ',';
    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            std::stringstream stream(linea);
            std::string FILA, COLUMNA;
            getline(stream, FILA, delimitador);
            getline(stream, COLUMNA, delimitador);
            size_t fila = std::stoul(FILA);
            size_t columna = std::stoul(COLUMNA);
            agregar_casilleros_caminables(fila, columna);
        }
        archivo.close();
    }
    else
    {
        std::cerr << "Error al abrir el archivo: " << path_archivo << std::endl;
    }
}

void mapa::agregar_casilleros_caminables(size_t fila, size_t columna){
    matriz_caminable.elemento(fila, columna) = true;
}

coordenada mapa::generar_coordenada_aleatoria_valida(){
    size_t fila, columna;
    do
    {
        fila = utiles::generar_numero_aleatorio(matriz_caminable.filas() - UN_INDICE);
        columna = utiles::generar_numero_aleatorio(matriz_caminable.columnas() - UN_INDICE);
    } while (!matriz_caminable.elemento(fila, columna));
    return coordenada(static_cast<int>(fila), static_cast<int>(columna));
}
