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
    Episodio(std::string id, std::string nombre, double duracion,
             int numeroDeCalificaciones, double sumCalificacion, double calificacion,
             std::string genero, int temporada);

    int getTemporada();


    void mostrarInfo() override;
    friend double operator +(Episodio& ep1, Episodio& ep2);
    friend double operator +(Episodio& ep1, double ep2);
};



#endif //EPISODIO_HPP

