//
// Created by Kaled Frausto on 07/06/25.
//

#ifndef EPISODIO_HPP
#define EPISODIO_HPP

#include"../Video/Video.hpp"
#include <iostream>

class Episodio : public Video {

protected:
    int temporada;

public:
    Episodio(
        string id,
        string titulo,
        double duracion,
        int numeroDeCalificaciones,
        int sumCalificacion,
        double calificacion,
        string genero,
        int temporada
    );

    int getTemporada();
    void mostrarInfo() override;

    friend double operator +(Episodio& e1, Episodio& e2);
    friend double operator +(int& e1, Episodio& e2);
};



#endif //EPISODIO_HPP

