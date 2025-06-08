//
// Created by Kaled Frausto on 07/06/25.
//

#include "Episodio.hpp"
#include <iostream>

using namespace std;


Episodio::Episodio(std::string id, std::string nombre, double duracion,
                   int numeroDeCalificaciones, double sumCalificacion, double calificacion,
                   std::string genero, int temporada)
    : Video(id, nombre, duracion, numeroDeCalificaciones, sumCalificacion, calificacion, genero),
      temporada(temporada)
{}

int Episodio::getTemporada() {
    return temporada;
}




void Episodio::mostrarInfo()  {

    cout<<"-----------episodio-----------"<<endl;
    cout<<"titulo: "<< titulo <<endl;
    cout << "id: "<< id << ", duracion: "<< duracion<<", genero: "<<genero<< ", temporada: "<<temporada<<endl;
}


double operator +(Episodio& ep1, Episodio& ep2){
    return ep1.getDuracion() + ep2.getDuracion();
}

double operator +(Episodio& ep1, double ep2){
    return ep2 + ep1.getDuracion();
}