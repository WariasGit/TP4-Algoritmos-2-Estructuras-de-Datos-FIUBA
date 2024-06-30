cmake_minimum_required(VERSION 3.22)
project(AyED_TPG_1c2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

# Opciones del compilador
add_compile_options(-Wall -Werror -Wconversion -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network)

# Directorios de inclusión
include_directories(include)
include_directories(include/a_estrella)
include_directories(include/aem)

# Configurar SFML
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
else()
  message(FATAL_ERROR "Could not find SFML library")
endif()

# Archivos fuente
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
        include/aem/visualizador.hpp
        src/aem/visualizador.cpp
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

# Añadir el ejecutable
add_executable(AyED_TPG_1c2024
        ${ARCHIVOS_FUENTE}
        main.cpp
)

# Enlazar con las bibliotecas de SFML
target_link_libraries(AyED_TPG_1c2024 sfml-graphics sfml-window sfml-system sfml-audio)

# FetchContent para Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG e4fdb87e76b9fc4b01c54ad81aea19d6e994b994
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# Añadir subdirectorios para las pruebas
add_subdirectory(tests/diccionario)
add_subdirectory(tests/heap)
add_subdirectory(tests/grafo)

# Enlazar los archivos fuente a los targets de prueba
target_sources(diccionario_test PRIVATE ${ARCHIVOS_FUENTE})
target_sources(heap_test PRIVATE ${ARCHIVOS_FUENTE})
target_sources(grafo_test PRIVATE ${ARCHIVOS_FUENTE})
