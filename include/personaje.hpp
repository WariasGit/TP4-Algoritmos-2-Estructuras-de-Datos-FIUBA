#ifndef AYED_TPG_1C2024_PERSONAJE_HPP
#define AYED_TPG_1C2024_PERSONAJE_HPP

#include <iostream>
#include "coordenada.hpp"
#include "utiles.hpp"

class personaje{
private:
    coordenada posicion;
public:
    personaje();
    personaje(coordenada posicion);
    void caminar(std::string tecla);
};

#endif