#include "juego.hpp"
#include "utiles.hpp"

void juego::jugar(bool &terminar_juego){
    std::string opcion_elegida;
    int opcion;
    do
    {
        limpiar_pantalla();
        mostrar_menu_acciones_juego();
        std::cin >> opcion_elegida << std::endl;
        std::cout << std::endl;
        opcion = utiles::validar_ingreso_opcion(opcion_elegida);
        realizar_jugada(opcion, terminar_juego);
    }
    while (opcion_elegida!=SALIR && !terminar_juego);
    terminar_juego = true;
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
    system(LIMPIAR)
}


void juego::mostrar_autores(){
    
}

void juego::continuar_juego(){
    string continuar;
    cout << "\nPresione una tecla para continuar..."<< endl;
    cin.get();
    cin.get();
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
    jugador = std::nullopt;
    tablero = std::nullopt;
    ingresar_menu_principal();
}


void juego::ingresar_menu_principal(){
    std::string valor_ingresado;
    int opcion = INICIO;
    while (opcion!=SALIR_MENU_PRINCIPAL && estado_del_juego == EN_CURSO)
    {
        mostrar_opciones_menu_principal();
        std::cin>> valor_ingresado << std::endl;
        std::cout << std::endl;
        opcion = utiles::validar_ingreso_opcion(valor_ingresado);
        limpiar_pantalla();
        if (opcion==JUGAR)
        {
            iniciar_juego();
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



void juego::iniciar_juego(){
    //arbol
    //heap
    jugador.emplace();
    tablero.emplace(filas_mapa, columnas_mapa);
    bool terminar_juego = false;
    if (terminar_juego)
    {
        estado_del_juego = FINALIZADO;
    }
    else
    {
        jugar(terminar_juego);
    }
}


void juego::realizar_jugada(opcion, terminar_juego){
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