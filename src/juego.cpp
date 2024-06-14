#include "juego.hpp"
#include "utiles.hpp"

void juego::jugar(){
    std::string opcion_elegida;
    int opcion;
    do
    {
        limpiar_pantalla();
        mostrar_menu_acciones_juego();
        std::cin >> opcion_elegida;
        std::cout << std::endl;
        opcion = utiles::validar_ingreso_opcion(opcion_elegida, GENERAR_NUEVO_PEDIDO_ALEATORIO, SALIR);
        realizar_jugada(opcion);
    }
    while (std::stoi(opcion_elegida)!=SALIR);
    estado_del_juego = FINALIZADO;
}


void juego::mostrar_opciones_menu_principal(){
    limpiar_pantalla();
    //imprimir
}


void juego::mostrar_menu_acciones_juego(){
    limpiar_pantalla();
    //imprimir
}


void juego::limpiar_pantalla(){
    system(LIMPIAR);
}


void juego::mostrar_autores(){
    
}

void juego::continuar_juego(){
    std::string continuar;
    std::cout << "\nPresione una tecla para continuar..."<< std::endl;
    std::cin.get();
    std::cin.get();
}


void juego::mensaje_de_salida(){

}




juego::juego(){
    estado_del_juego = EN_CURSO;
    tope_locales = LOCALES_MAXIMOS;
    filas_mapa = FILAS;
    columnas_mapa = COLUMNAS;
    //arbol
    //heap
    jugador = personaje();
    tablero = mapa(filas_mapa, columnas_mapa);
    ingresar_menu_principal();
}


void juego::ingresar_menu_principal(){
    std::string valor_ingresado;
    int opcion = INICIO;
    while (opcion!=SALIR_MENU_PRINCIPAL && estado_del_juego == EN_CURSO)
    {
        mostrar_opciones_menu_principal();
        std::cin>> valor_ingresado;
        std::cout << std::endl;
        opcion = utiles::validar_ingreso_opcion(valor_ingresado, INICIO, SALIR_MENU_PRINCIPAL);
        limpiar_pantalla();
        if (opcion==JUGAR)
        {
            jugar();
        }
        else if (opcion==CREDITOS)
        {
            mostrar_autores();
            continuar_juego();
            limpiar_pantalla();
        } 
    }
    limpiar_pantalla();
    mensaje_de_salida();
}

void juego::realizar_jugada(int opcion){
    switch (opcion)
    {
    case GENERAR_NUEVO_PEDIDO_ALEATORIO:
        /* code */
        break;
    case ENTREGAR_PEDIDO:
        //
        break;
    case MOSTRAR_SENDEROS_CONEXIONES:
        //
        break;
    case SALIR:
        //
        break;
    default:
        break;
    }
}


void juego::mostrar_mapa(){
    //Interactuar con el mapa y mostrar el contenido de la matriz
}

void juego::mostrar_arbol_expandido(){
    //minijuego secundario
}