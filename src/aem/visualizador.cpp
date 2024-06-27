#include "aem/visualizador.hpp"
#include "aem/grafo.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>


visualizador::visualizador(const grafo& g) : g(g) {}

std::pair<size_t, size_t> visualizador::obtener_vertices(const arista& ar) const{
    return const_cast<arista&>(ar).obtener_vertices();
}

int visualizador::obtener_peso(const arista& ar) const{
    return const_cast<arista&>(ar).obtener_peso();
}

void visualizador::visualizar_aem(const std::string& nombre_archivo) const {
    // Definir el tipo de grafo de Boost.
    using GrafoBoost = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
                                             boost::no_property, boost::property<boost::edge_weight_t, int>>;

    GrafoBoost bg;
    std::vector<arista> aem = const_cast<grafo&>(g).obtener_aem();

    for (arista& ar : aem) {
        auto vertices = obtener_vertices(ar);
        int peso = obtener_peso(ar);
        boost::add_edge(vertices.first, vertices.second, peso, bg);
    }

    escribir_archivo_dot(nombre_archivo, bg);
    mostrar_archivo_dot(nombre_archivo);
}

void visualizador::escribir_archivo_dot(const std::string& nombre_archivo, const boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>>& bg) const {
    std::ofstream archivo(nombre_archivo);
    boost::write_graphviz(archivo, bg, boost::default_writer(),
                          boost::make_label_writer(boost::get(boost::edge_weight, bg)));
    archivo.close();
}

void visualizador::mostrar_archivo_dot(const std::string& nombre_archivo) const {
    std::ifstream archivo_lectura(nombre_archivo);
    if (archivo_lectura.is_open()) {
        std::string linea;
        while (std::getline(archivo_lectura, linea)) {
            std::cout << linea << std::endl;
        }
        archivo_lectura.close();
    } else {
        std::cerr<< "No se pudo abrir el archivo "<< nombre_archivo<< std::endl;
    }
}

  
  

