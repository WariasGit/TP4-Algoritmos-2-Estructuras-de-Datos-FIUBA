#ifndef AYED_TPG_1C2024_VISUALIZADOR_HPP
#define AYED_TPG_1C2024_VISUALIZADOR_HPP

#include "grafo.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <string>
#include <iostream>
#include <fstream>

class visualizador {
private:
    const grafo& g;

    // Pre: -.
    // Post: Devuelve el parametro con la cualificacion de constante.
    std::pair<size_t, size_t> obtener_vertices(const arista& ar) const;

    // Pre: -.
    // Post: Devuelve el parametro con la cualificacion de constante.
    int obtener_peso(const arista& ar) const;

    // Pre: El nombre de archivo recibido debe tener extension .dot.
    // Post: Escribe el grafo en el archivo en formato Graphviz.
    void escribir_archivo_dot(const std::string& nombre_archivo, const boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>>& bg) const;
    
    // Pre: El nombre de archivo recibido debe tener extension .dot.
    // Post: Muestra el contenido del archivo.dot.
    void mostrar_archivo_dot(const std::string& nombre_archivo) const;

    // Nota: Esta clase esta dedicado para mostrar y permitir la visualizacion del metodo void grafo::obtener_aem()
    // Para más detalles, ver en el enlace: https://www.boost.org/doc/libs/1_75_0/libs/graph/doc/index.html
public:
    // Constructor.
    visualizador(const grafo& g);

    // Pre: -.
    // Post: Muestra el árbol de expansión mínimo por consola y genera un archivo .dot.
    void visualizar_aem(const std::string& nombre_archivo) const;
};

#endif