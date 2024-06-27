[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/POWrYz7V)
# AyED / AYP2 - TPG 1c2024

<p align="center">
   <img src="Banner.jpg" alt="TPG: El bullicio del Callejon Aurum"><br>
</p>

## Nombre del grupo: **_Grafosaurios_**

##### Integrantes:

##### - ARIAS, WALTER - 106428

##### - SERRANTES, BRYAN - 110158

##### - SICILIANO, FRANCO - 108157

##### - WANG, RICARDO - 107235

##### - ZAJIC, GISELA - 108735

### Documentos:

1. [Informe de complejidad algorítmica](https://docs.google.com/document/d/1_Dic8CRacDmOSMqlIWvmwBsQT9cFlZpGu1GJta4eUcQ/edit?usp=drive_link)
2. [Video de demostración del programa](https://drive.google.com/file/d/1CAw3r_xDD2zvo9aVyiTtaDfbxiqet_XQ/view?usp=sharing)

### Compilación

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

> // COMPLETAR CON LINEA DE COMPILACIÓN //

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

Para distribuciones de Linux, se pueden utilizar los scripts presentes en el directorio raíz para compilar y ejecutar
la suite de tests. Requiere:

1. [g++](https://gcc.gnu.org/)
2. [CMake](https://cmake.org/)
3. [Valgrind](https://valgrind.org/)

Que se pueden instalar por terminal:

> sudo apt-get install // PROGRAMA //

### **_Descripción de ramas:_**

1. **_main:_** Rama principal del proyecto. Contiene el código final y los archivos de documentación.
2. **_develop:_** Rama de desarrollo. Contiene el código en desarrollo unificado de los integrantes del equipo, con el juego completado con sus funcionalidades.
3. **_feature/busqueda-a-star:_** Rama de desarrollo de la funcionalidad del algoritmo A* para el primer minijuego.
4. **_feature/heap:_** Rama de desarrollo del heap de máximos, útil para establecer la prioridad con la que se van a entregar los pedidos en el juego.
5. **_feature/arbol_generador:_** Rama de la implementación de generar el árbol expansión máximo  y de la clase visualizar, que consiste en mostrar el resultado del método obtener_aem(), para el segundo minijuego.
6. **_feature/diciconario:_** Rama en la cual se desarrolla la estructura de datos diccionario con el proposito de almacenar los datos pertinentes y asi poder acceder a estos mediante una clave.
7. **_feature/Clase_juego: _** Encapsula la lógica del manejo general del juego y la jugabilidad.Gestiona eventos de usuario, actualiza estados y renderiza elementos gráficos en la ventana de SFML.