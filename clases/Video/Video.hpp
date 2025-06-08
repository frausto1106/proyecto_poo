//
// Created by Kaled Frausto on 07/06/25.
//
#include <iostream>
#include <string>
#ifndef VIDEO_HPP
#define VIDEO_HPP

using namespace std;

class Video {
protected:
    string id;
    string titulo;
    double duracion;
    int numeroDeCalificaciones;
    int calificacion;
    string genero;
    int sumCalificacion;

    Video(string id, string titulo, double duracion, int numeroDeCalificaciones, int sumCalificacion, int calificacion,
          string genero);

public:
    virtual  void mostrarInfo() = 0;



    virtual double calcularDuracion();
    void calificar();
    double getDuracion();


    int getCalificacion();

    string getTitulo();

    string getId();
};




#endif //VIDEO_HPP
