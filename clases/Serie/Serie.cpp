//
// Created by Kaled Frausto on 07/06/25.
//
#include <iostream>
#include "Serie.hpp"

using namespace  std;
Serie::Serie(string nombre, string paisDeOrigen,string genero,string clasificacion):
    nombre(nombre), calificacion(0), numeroDeCalificaciones(0), sumCalificaciones(0), episodios{}, paisDeOrigen(paisDeOrigen), genero(genero), clasificacion(clasificacion) {}

void Serie::mostrarEpisodios() {
    for (int i = 0; i < episodios.size(); i++) {
        episodios[i].mostrarInfo();
        cout << endl;
    }
}

void Serie::agregarEpisodio(Episodio &ep) {
    episodios.push_back(ep);
    cout<<"episodio agregado exitosamente"<<endl;
}

void Serie::mostrarEpisodioPorTemporada(int temporada) {
    for (int i = 0; i < episodios.size(); i++) {
        if (episodios[i].getTemporada() ==  temporada) {
            episodios[i].mostrarInfo();
            cout << endl;
        }
    }
}

void Serie::mostrarInfo() {
    cout << "nombre: " << nombre << endl;
    cout << "calificacion: " << calificacion << endl;
    cout <<"pais de origen: " << paisDeOrigen << endl;
    cout<< "genero: "<< genero << endl;
    cout<<"clasificacion: "<<clasificacion << endl;
}

void Serie::calificar() {

    int calificacion;

    cout << "inserta la calificacion: "<<endl;
    cin>> calificacion;
    numeroDeCalificaciones++;
    sumCalificaciones += calificacion;

    this->calificacion = (sumCalificaciones /numeroDeCalificaciones);

}


