#include "utiles.hpp"

int utiles::validar_ingreso_opcion(std::string input, int minimo, int maximo){
    while (!(es_numero_valido(input, minimo, maximo)))
    {
        if(!es_numerico(input))
        {
            std::cout << "Ingrese un valor numerico valido." << std::endl;
        } 
        else
        {
            std::cout << "Fuera de rango, ingrese una opcion valida." << std::endl;
        }
    }
    std::cout << "Ingreso la opcion: " << input << std::endl;
    return (stoi(input));
    
}

bool utiles::es_numerico(std::string input){
    size_t i = 0;
    bool es_numero = true;
    while (es_numero && i < size_t(input.length()) ) {
        if ( !(isdigit(input[i])) ) {
            es_numero = false;
        }
        i++;
    }
    return es_numero;
}

bool utiles::es_numero_valido(std::string input, int opcion_min, int opcion_max){
    bool es_valido = true;
    if (!es_numerico(input))
    {
        es_valido = false;
    }
    else if (stoi(input)<=opcion_min || stoi(input)>=opcion_max)
    {
        es_valido = false;
    }
    return es_valido;
    
}

size_t utiles::generar_numero_aleatorio(size_t minimo, size_t maximo){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(minimo, maximo);
    return dis(gen);
}

size_t utiles::generar_numero_aleatorio(size_t maximo){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(INICIA_EN_CERO, maximo);
    return dis(gen);
}

std::string utiles::obtener_nombre_aleatorio() {
    size_t indice_aleatorio = utiles::generar_numero_aleatorio(static_cast<size_t>(CANTIDAD_NOMBRES));
    return NOMBRE_LOCALES[indice_aleatorio];
}

bool comparar_pedidos( pedido primer_pedido,  pedido segundo_pedido){
    return primer_pedido.obtener_prioridad_pedido() > segundo_pedido.obtener_prioridad_pedido();
}

bool comparar_nombres(std::string nombre1, std::string nombre2) {
    return nombre1 < nombre2;
}

void utiles::convertir_dot_a_jpg(const std::string& path_dot, const std::string& path_png) {
    // Uso la libreria Graphviz
    std::string command = "dot -Tjpg " + path_dot + " -o " + path_png;
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "El archivo .dot ha sido convertido a .png exitosamente y guardado en '" << path_png << "'." << std::endl;
    } else {
        std::cerr << "Error al convertir el archivo .dot a .jpg." << std::endl;
    }
}
