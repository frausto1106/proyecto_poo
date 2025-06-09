//
// Created by Bruno Gonzalez on 07/06/25.
//

#include "Pelicula.hpp"
#include <iostream>
using namespace std;

Pelicula::Pelicula(
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
)
    : Video(id, titulo, duracion, numeroDeCalificaciones, sumCalificacion, calificacion, genero),
      clasificacion(clasificacion),
      paisDeOrigen(paisDeOrigen),
      duracionCreditos(duracionCreditos)
{}

void Pelicula::mostrarInfo() {
    cout << endl;
    cout << "---------------PELICULA------------: "<< endl;
    cout << "titulo: " << titulo << endl;
    cout << "id: " << id << " ,duracion: " << duracion << " ,genero: " << genero << " ,clasificacion: " << clasificacion << " ,pais de origen: " << paisDeOrigen << " ,duracion de creditos: " << duracionCreditos<< endl;
}

int Pelicula::getCalificacion() {
    return calificacion;
}

double Pelicula::calcularDuracion() {
    return duracion + duracionCreditos;
}
