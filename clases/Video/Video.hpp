//
// Created by Kaled Frausto on 07/06/25.
//
#include <iostream>
#ifndef VIDEO_HPP
#define VIDEO_HPP

using namespace std;



class Video {
protected:
    string id;
    string titulo;
    double duracion;
    int numeroDeCalificaciones;
    double calificacion;
    string genero;
    int sumCalificacion;

    Video(string id, string titulo, double duracion, string genero);
public:
    virtual  void mostrarInfo() = 0;
    virtual double calcularDuracion();
    void calificar();

};



#endif //VIDEO_HPP
