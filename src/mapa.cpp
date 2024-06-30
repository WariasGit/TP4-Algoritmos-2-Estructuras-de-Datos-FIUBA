#include "mapa.hpp"

mapa::mapa() {
    matriz_mapa = matriz<int>();
}

mapa::mapa(size_t filas, size_t columnas) {
    matriz_mapa = matriz<int>(filas, columnas, NO_CAMINABLE);
    cargar_callejon(PATH_ARCHIVO_CALLEJON);
}

bool mapa::es_vecino_valido(coordenada posicion) {
    if (posicion.x() < CERO || posicion.y() < CERO ||
        posicion.x() >= FILAS || posicion.y() >= COLUMNAS) {
        return false;
    }
    int& valor = matriz_mapa.elemento(static_cast<size_t>(posicion.x()), static_cast<size_t>(posicion.y()));
    if (valor == CAMINABLE || valor == JUGADOR) {
        return true;
    }
    return false;
}

void mapa::cargar_callejon(const std::string& path_archivo){
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
            int fila = std::stoi(FILA);
            int columna = std::stoi(COLUMNA);
            agregar_casilleros_caminables(fila, columna);
        }
        archivo.close();
    }
    else
    {
        std::cerr << "Error al abrir el archivo: " << path_archivo << std::endl;
    }
}

void mapa::agregar_casilleros_caminables(int fila, int columna){
    matriz_mapa.elemento(static_cast<size_t>(fila), static_cast<size_t>(columna)) = CAMINABLE;
}

void mapa::agregar_casillero(coordenada posicion, int valor){
    matriz_mapa.elemento(static_cast<size_t>(posicion.x()), static_cast<size_t >(posicion.y())) = valor;
}


coordenada mapa::generar_coordenada_aleatoria_valida(){
    size_t fila, columna;
    do
    {
        fila = utiles::generar_numero_aleatorio(FILAS - UN_INDICE);
        columna = utiles::generar_numero_aleatorio(COLUMNAS - UN_INDICE);
    } while (matriz_mapa.elemento(fila, columna) != CAMINABLE);
    return coordenada(static_cast<int>(fila), static_cast<int>(columna));
}

coordenada mapa::generar_coordenada_aleatoria_valida( mapa &mapa) {
    size_t fila, columna;
    do {
        fila = utiles::generar_numero_aleatorio(FILAS - UN_INDICE);
        columna = utiles::generar_numero_aleatorio(COLUMNAS - UN_INDICE);
    } while (mapa.matriz_mapa.elemento(fila, columna) != CAMINABLE);
    return coordenada(static_cast<int>(fila), static_cast<int>(columna));
}


void mapa::dibujar_mapa(sf::RenderWindow& window) {
    auto color_no_caminable = sf::Color(158, 158, 158);
    auto color_caminable = sf::Color(139, 195, 74);
    auto color_jugador = sf::Color(33, 150, 243);
    auto color_local = sf::Color(244, 67, 54);
    auto color_camino = sf::Color(255, 152, 0);
    auto color_cliente = sf::Color(255, 255,51);
    sf::RectangleShape casillero(sf::Vector2f(TAMANIO_CASILLERO, TAMANIO_CASILLERO));
    for (size_t fila = 0; fila < FILAS; ++fila) {
        for (size_t columna = 0; columna < COLUMNAS; ++columna) {
            int& valor = matriz_mapa.elemento(fila, columna);
            casillero.setPosition(float(columna) * TAMANIO_CASILLERO, float(fila) * TAMANIO_CASILLERO);
            switch (valor) {
                case NO_CAMINABLE:
                    casillero.setFillColor(color_no_caminable);
                    break;
                case CAMINABLE:
                    casillero.setFillColor(color_caminable);
                    break;
                case JUGADOR:
                    casillero.setFillColor(color_jugador);
                    break;
                case LOCAL:
                    casillero.setFillColor(color_local);
                    break;
                case CAMINO:
                    casillero.setFillColor(color_camino);
                    break;
                case CLIENTE:
                    casillero.setFillColor(color_cliente);
                    break;
                default:
                    casillero.setFillColor(sf::Color::White);
                    break;
            }
            casillero.setOutlineThickness(1.f);
            casillero.setOutlineColor(sf::Color::Black);
            window.draw(casillero);
        }
    }
}


std::list<coordenada> mapa::obtener_vecinos_valido(coordenada posicion) {
    std::list<coordenada> vecinos;

    for (auto vecino : obtener_vecinos(posicion)) {
        if (es_vecino_valido(vecino)) {
            vecinos.push_back(vecino);
        }
    }

    return vecinos;
}

std::list<coordenada> mapa::obtener_vecinos(coordenada posicion) {
    std::list<coordenada> vecinos;
    vecinos.emplace_back(posicion.x() - 1, posicion.y());
    vecinos.emplace_back(posicion.x() + 1, posicion.y());
    vecinos.emplace_back(posicion.x(), posicion.y() - 1);
    vecinos.emplace_back(posicion.x(), posicion.y() + 1);
    return vecinos;
}



