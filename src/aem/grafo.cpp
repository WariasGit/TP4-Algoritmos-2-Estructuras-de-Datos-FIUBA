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

size_t grafo::buscar_arista_peso_maximo(const std::vector<bool>& vertices_visitados ,const std::vector<int>& senderos_mas_transitados) {
    int peso_maximo_actual = -INFINITO;
    size_t vertice_maximo = -1;
    for (size_t i = 0; i < matriz_adyacencia.columnas(); i++) {
        if (!vertices_visitados[i] && senderos_mas_transitados[i] > peso_maximo_actual) {
            peso_maximo_actual = senderos_mas_transitados[i];
            vertice_maximo = i;
        }
    }
    return vertice_maximo;
}

void grafo::actualizar(size_t vertice, std::vector<int>& senderos_mas_transitados, 
                    std::vector<int>& vertices_mas_transitados, 
                    const std::vector<bool>& vertice_visitado) {
    
    for (size_t i = 0; i < matriz_adyacencia.columnas(); ++i) {
        int peso_maximo = matriz_adyacencia.elemento(vertice, i);
        if (!vertice_visitado[i] && peso_maximo > senderos_mas_transitados[i]) {
            senderos_mas_transitados[i] = peso_maximo;
            vertices_mas_transitados[i] = vertice;
        }
    }
}
std::vector<arista> grafo::obtener_aem() {
    //TODO: Implementar.
    std::vector<arista> aem_res;

    matriz<int> matriz_1(matriz_adyacencia);
    size_t cantidad_vertice = matriz_adyacencia.columnas();

    if (cantidad_vertice <= 1) return aem_res;

    std::vector<bool> vertices_visitados(cantidad_vertice,false);
    std::vector<int> senderos_mas_transitados(cantidad_vertice,-INFINITO);
    std::vector<int> vertices_mas_transitados(cantidad_vertice,-1);

    for (size_t i = 0; i < cantidad_vertice - 1; i++) {
        if (vertices_visitados[i] == false) {
            size_t vertice_maximo = buscar_arista_peso_maximo(vertices_visitados,senderos_mas_transitados);
            vertices_visitados[i] = true;

            if (vertices_mas_transitados[i] != -1) {
                aem_res.push_back(arista({vertice_maximo,i},senderos_mas_transitados[i]));
            }

            actualizar(vertice_maximo,senderos_mas_transitados,vertices_mas_transitados,vertices_visitados);
        }
    }

    for (size_t i = 1; i < matriz_1.filas(); i++) {
        aem_res.emplace_back(std::make_pair(vertices_mas_transitados[i], i), 
        matriz_adyacencia.elemento(vertices_mas_transitados[i], i));
    }
    return aem_res;
}