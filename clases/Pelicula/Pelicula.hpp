//
// Created by Kaled Frausto on 07/06/25.
//

#ifndef PELICULA_HPP
#define PELICULA_HPP
#include <iostream>
#include "../Video/Video.hpp"


using namespace std;

class Pelicula: public Video {
protected:
    string clasificacion;
    string paisDeOrigen;
    double duracionCreditos;

public:
    Pelicula(
        string id,
        string titulo,
        double duracion,
        int numeroDeCalificaciones,
        int sumCalificacion,
        int calificacion,
        string genero,
        string clasificacion,
        string paisDeOrigen,
        double duracionCreditos
    );

    void mostrarInfo() override;

    int getCalificacion();

    double calcularDuracion() override;
};



#endif //PELICULA_HPP
