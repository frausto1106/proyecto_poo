//
// Created by Kaled Frausto on 07/06/25.
//

#include "Video.hpp"
using namespace std;


Video::Video(string id, string titulo, double duracion, string genero)
    : id(id), titulo(titulo), duracion(duracion), genero(genero),numeroDeCalificaciones(0), calificacion(0.0), sumCalificacion(0) {}

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
