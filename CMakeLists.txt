cmake_minimum_required(VERSION 3.22)
project(AyED_TPG_1c2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)
include_directories(include/a_estrella)
include_directories(include/aem)

# Si crean otros archivos .cpp, los tienen que agregar acá de la forma:
#   directorio/archivo.cpp
set(ARCHIVOS_FUENTE
        include/diccionario.hpp
        include/heap.hpp
        include/nodo.hpp
        include/matriz.hpp
        src/a_estrella/vertice.cpp
        include/a_estrella/vertice.hpp
        src/a_estrella/a_estrella.cpp
        include/a_estrella/a_estrella.hpp
        src/a_estrella/coordenada.cpp
        include/a_estrella/coordenada.hpp
        src/mapa.cpp
        include/mapa.hpp
        src/aem/grafo.cpp
        include/aem/grafo.hpp
        src/aem/arista.cpp
        include/aem/arista.hpp
        include/juego.hpp
        src/juego.cpp

        include/personaje.hpp
        src/personaje.cpp
        include/local.hpp
        src/local.cpp
        include/pedido.hpp
        src/pedido.cpp
        include/utiles.hpp
        src/utiles.cpp
        include/constantes.hpp
        include/heuristica.hpp
)

add_executable(AyED_TPG_1c2024
        ${ARCHIVOS_FUENTE}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

# Encontrar y configurar SFML
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML" CACHE PATH "Directorio donde se encuentran los módulos de SFML")

# Busca y configura SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Enlazar con las bibliotecas de SFML
target_link_libraries(AyED_TPG_1c2024 sfml-graphics sfml-window sfml-system)

add_subdirectory(tests/diccionario)
add_subdirectory(tests/heap)
add_subdirectory(tests/grafo)

target_sources(diccionario_test PRIVATE ${ARCHIVOS_FUENTE})
target_sources(heap_test PRIVATE ${ARCHIVOS_FUENTE})
target_sources(grafo_test PRIVATE ${ARCHIVOS_FUENTE})