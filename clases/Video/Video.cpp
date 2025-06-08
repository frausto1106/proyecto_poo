//
// Created by Kaled Frausto on 07/06/25.
//

#include "Video.hpp"
using namespace std;


Video::Video(
    string id,
    string titulo,
    double duracion,
    int numeroDeCalificaciones,
    int sumCalificacion,
    double calificacion,
    string genero
) :
    id(id),
    titulo(titulo),
    duracion(duracion),
    numeroDeCalificaciones(numeroDeCalificaciones),
    sumCalificacion(sumCalificacion),
    calificacion(calificacion),
    genero(genero)
{}

double Video::calcularDuracion() {
return duracion;

};
void Video::calificar() {

    int cal;

    cout << "introduce la calificacion: "<<endl ;
    cin >> cal;
    numeroDeCalificaciones++;
    sumCalificacion += cal;

    calificacion = (sumCalificacion /numeroDeCalificaciones);

};
