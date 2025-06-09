//
// Created by Kaled Frausto on 07/06/25.
//
#include <iostream>
#include "Serie.hpp"
#include "../Video/Video.hpp"

using namespace  std;
Serie::Serie(
    string id,
    string nombre,
    double calificacion,
    int numeroDeCalificaciones,
    int sumCalificaciones,
    string paisDeOrigen,
    string genero,
    string clasificacion,
    vector<Episodio> episodios
):
    id(id),
    nombre(nombre),
    calificacion(calificacion),
    numeroDeCalificaciones(numeroDeCalificaciones),
    sumCalificaciones(sumCalificaciones),
    genero(genero),
    paisDeOrigen(paisDeOrigen),
    clasificacion(clasificacion),
    episodios(episodios)
{}


void Serie::mostrarEpisodios() {
    for (int i = 0; i < episodios.size(); i++) {
        episodios[i].mostrarInfo();
        cout << endl;
    }
}

void Serie::agregarEpisodio(Episodio ep) {
    episodios.push_back(ep);
    cout<<"episodio agregado exitosamente"<<endl;
}

void Serie::mostrarEpisodioPorTemporada() {
    while (true){

        int temp;
        cout<<"introduce la temporada: " <<endl;
        cin>>temp;
        cin.ignore(); 

        for (int i = 0; i < episodios.size(); i++) {
            if (episodios[i].getTemporada() ==  temp) {
                episodios[i].mostrarInfo();
                cout << endl;
                return;
            }
        }
        cout<<"no se encontro esa temporada"<<endl;
        string opc;
        cout<<"salir? [S/N]"<<endl;
        cin>>opc;
        if (opc=="s") {
            break;
        }
    }

}

void Serie::mostrarEpisodioPorCalificacion() {
    while (true){

        int cal;
        cout<<"introduce la calificacion (1-5): " <<endl;
        cin>>cal;
        cin.ignore(); 

        if (cal<1 || cal>5) {
            cout<<"introduce una calificacion valida"<<endl;
            return;
        }

        for (int i = 0; i < episodios.size(); i++) {
            if (episodios[i].getCalificacion() ==  cal) {
                episodios[i].mostrarInfo();
                cout << endl;
                return;
            }
        }
        cout<<"no se encontraron espisodios con ese score"<<endl;
        string opc;
        cout<<"salir? [S/N]"<<endl;
        cin>>opc;
        cin.ignore(); 
        if (opc=="s") {
            break;
        }
    }

}


void Serie::mostrarInfo() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout <<"-----------SERIE-----------"<<endl;
    cout << "id: " << id << endl;
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

void Serie::calucularMaraton() {
    double tiempo = 0;
    for (int i = 0; i< episodios.size(); i++) {
        tiempo = episodios[i] + tiempo;
    }

    cout<<"la serie durá "<<tiempo<<" en total";

}
vector<Episodio> Serie::getEpisodios() {
    return episodios;
}


string Serie::getNombre() {
    return nombre;
}

string Serie::getId() {
    return id;
}




