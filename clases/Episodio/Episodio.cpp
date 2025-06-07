//
// Created by Kaled Frausto on 07/06/25.
//

#include "Episodio.hpp"
#include <iostream>

using namespace std;


Episodio::Episodio(int temporada, string id, string titulo, double duracion, string genero): Video(id, titulo, duracion, genero), temporada(temporada){}


int Episodio::getTemporada() {
    return temporada;
}


void Episodio::mostrarInfo() override {
    cout<<"titulo: "<< titulo <<endl;
    cout << "id: "<< id << "duracion: "<< duracion<<"genero: "<<genero<< "temporada: "<<temporada;
}
double operator +(Episodio &ep1, Episodio &ep2){
    return ep1.duracion + ep2.duracion;
}

double operator +(Episodio &ep1, double &ep2){
    return ep1.duracion + ep2;
}