cmake_minimum_required(VERSION 3.22)
project(AyED_TPG_1c2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

# Opciones del compilador
add_compile_options(-Wall -Werror -Wconversion)

# Directorios de inclusión
include_directories(include)
include_directories(include/a_estrella)
include_directories(include/aem)

# Archivos fuente
set(ARCHIVOS_FUENTE
        src/a_estrella/vertice.cpp
        src/a_estrella/a_estrella.cpp
        src/a_estrella/coordenada.cpp
        src/mapa.cpp
        src/aem/grafo.cpp
        include/aem/grafo.hpp
        include/aem/visualizador.hpp
        src/aem/visualizador.cpp
        src/aem/arista.cpp
        src/juego.cpp
        include/personaje.hpp
        src/personaje.cpp
        src/local.cpp
        src/pedido.cpp
        src/utiles.cpp
        src/aem/visualizador.cpp
)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

find_package(Boost REQUIRED COMPONENTS graph)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions(${Boost_DEFINITIONS})
else()
    message(FATAL_ERROR "Boost no encontrado. Asegúrate de que esté instalado correctamente.")
endif()

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG e4fdb87e76b9fc4b01c54ad81aea19d6e994b994
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# Add executable
add_executable(${PROJECT_NAME} ${ARCHIVOS_FUENTE} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

# Enlazar con las bibliotecas de SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio sfml-network ${Boost_LIBRARIES} ${FREETYPE_LIBRARIES})

# Tests
add_executable(diccionario_test tests/diccionario/diccionario_test.cpp)
add_executable(heap_test tests/heap/heap_test.cpp)
add_executable(grafo_test tests/grafo/grafo_test.cpp)

# Enlazar con las bibliotecas de SFML y Boost para los tests
target_link_libraries(diccionario_test gtest gtest_main sfml-graphics sfml-window sfml-system sfml-audio sfml-network ${Boost_LIBRARIES} ${FREETYPE_LIBRARIES})
target_link_libraries(heap_test gtest gtest_main sfml-graphics sfml-window sfml-system sfml-audio sfml-network ${Boost_LIBRARIES} ${FREETYPE_LIBRARIES})
target_link_libraries(grafo_test gtest gtest_main sfml-graphics sfml-window sfml-system sfml-audio sfml-network ${Boost_LIBRARIES} ${FREETYPE_LIBRARIES})

# Add sources to the test targets
target_sources(diccionario_test PRIVATE ${ARCHIVOS_FUENTE})
target_sources(heap_test PRIVATE ${ARCHIVOS_FUENTE})
target_sources(grafo_test PRIVATE ${ARCHIVOS_FUENTE})

# Enable testing
enable_testing()
add_test(NAME diccionario_test COMMAND diccionario_test)
add_test(NAME heap_test COMMAND heap_test)
add_test(NAME grafo_test COMMAND grafo_test)