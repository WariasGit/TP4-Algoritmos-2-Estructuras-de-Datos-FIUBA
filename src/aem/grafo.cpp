#include <iostream>
#include "aem/grafo.hpp"

grafo::grafo(size_t cantidad_vertices) {
    matriz_adyacencia = matriz(cantidad_vertices, INFINITO);
    for (size_t i = 0; i < matriz_adyacencia.columnas(); i++) {
        matriz_adyacencia.elemento(i, i) = 0;
    }
}

void grafo::agregar_vertice() {
    size_t vertices = matriz_adyacencia.columnas() + 1;
    matriz_adyacencia.redimensionar(vertices, vertices);
    for (size_t i = 0; i < vertices - 1; i++) {
        eliminar_arista(vertices - 1, i);
        eliminar_arista(i, vertices - 1);
    }
}

void grafo::modificar_arista(size_t origen, size_t destino, int peso) {
    size_t vertices = matriz_adyacencia.columnas();
    if (origen < vertices && destino < vertices) {
        matriz_adyacencia.elemento(origen, destino) = peso;
    } else {
        std::cout << "ERROR: Los vértices no son válidos. No se cambió el camino." << std::endl;
    }
}

void grafo::eliminar_arista(size_t origen, size_t destino) {
    modificar_arista(origen, destino, INFINITO);
}

void grafo::aislar_vertice(size_t vertice) {
    size_t vertices = matriz_adyacencia.columnas();
    if (vertice < vertices) {
        for (size_t i = 0; i < vertices; i++) {
            if (i != vertice) {
                eliminar_arista(i, vertice);
                eliminar_arista(vertice, i);
            }
        }
    } else {
        std::cout << "ERROR: El vértice no es válido. No se aisló." << std::endl;
    }
}

grafo::grafo(const grafo& grafo1) {
    matriz_adyacencia = grafo1.matriz_adyacencia;
}

grafo& grafo::operator=(const grafo& grafo1) {
    if (this != &grafo1) {
        matriz_adyacencia = grafo1.matriz_adyacencia;
    }
    return *this;
}

size_t grafo::buscar_vertice_maximo(const std::vector<bool>& vertices_visitados, 
                                const std::vector<int>& pesos_maximos) {
    int peso_maximo = INFINITO;
    size_t vertice_maximo = -1;
    for (size_t i = 0; i < matriz_adyacencia.filas(); ++i) {
        if (!vertices_visitados[i] && pesos_maximos[i] > peso_maximo) {
            peso_maximo = pesos_maximos[i];
            vertice_maximo = i;
        }
    }
    return vertice_maximo;
}

void grafo::actualizar_vertices(size_t vertice_maximo, const std::vector<bool>& vertices_visitados, 
                                std::vector<int>& pesos_maximos, 
                                std::vector<int>& vertices_maximo_asociado) {
    for (size_t i = 0; i < matriz_adyacencia.filas(); ++i) {
        int peso_actual = matriz_adyacencia.elemento(vertice_maximo, i);

        if (!vertices_visitados[i] && peso_actual > pesos_maximos[i]) {
            pesos_maximos[i] = peso_actual;
            vertices_maximo_asociado[i] = vertice_maximo;
        }
    }
}

void grafo::imprimir_aristas(const std::vector<arista>& aem) {
    if (aem.size() < 2) {
        std::cout<< "No hay arista. "<< std::endl;
    } else {
        for (size_t i = 0; i < aem.size(); i++) {
        arista arista_1 = aem[i];
        std::pair<int, int> coordenada = arista_1.obtener_vertices();
        std::cout << "Peso: " << arista_1.obtener_peso() << ", Vertices: (" << coordenada.first << ", " << coordenada.second << ")" << std::endl;
        }
    }
}


std::vector<arista> grafo::obtener_aem() {
    std::vector<arista> aem_res;

    int cantidad_vertice = matriz_adyacencia.filas();
    int vertice_nulo = -1;

    if (cantidad_vertice < 2) {
        imprimir_aristas(aem_res);
        return aem_res;
    }
    std::vector<bool> vertices_visitados(cantidad_vertice, false);
    std::vector<int> pesos_maximos(cantidad_vertice, INFINITO);
    std::vector<int> vertices_maximo_asociado(cantidad_vertice, vertice_nulo);

    pesos_maximos[0] = 0;
    vertices_maximo_asociado[0] = 0;

    for (size_t i = 0; i < cantidad_vertice; ++i) {
        size_t vertice_maximo = buscar_vertice_maximo(vertices_visitados, pesos_maximos);

        if (vertice_maximo != vertice_nulo) {
            vertices_visitados[vertice_maximo] = true;

            if (vertices_maximo_asociado[vertice_maximo] != vertice_maximo) {
                std::pair<int,int> par_de_vertice = {vertices_maximo_asociado[vertice_maximo], vertice_maximo};
                int peso_arista = pesos_maximos[vertice_maximo];
                aem_res.push_back(arista(par_de_vertice, peso_arista));
            }

            actualizar_vertices(vertice_maximo,vertices_visitados, pesos_maximos, vertices_maximo_asociado);
        }
    }
    imprimir_aristas(aem_res);

    return aem_res;
}
