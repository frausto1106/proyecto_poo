//
// Created by Kaled Frausto on 07/06/25.
//

#ifndef SERIE_HPP
#define SERIE_HPP
#include <iostream>
#include <vector>
#include "../Episodio/Episodio.hpp"
using namespace std;

class Serie {
private:
    string id;
    string nombre;
    double calificacion;
    int numeroDeCalificaciones;
    int sumCalificaciones;
    string paisDeOrigen;
    string genero;
    string clasificacion;
    vector<Episodio> episodios;

public:
    Serie(
        string id,
        string nombre,
        double calificacion,
        int numeroDeCalificaciones,
        int sumCalificaciones,
        string paisDeOrigen,
        string genero,
        string clasificacion,
        vector<Episodio> episodios
    );


    void mostrarEpisodios();
    string getNombre();
    vector<Episodio> getEpisodios();
    string getId();
    void agregarEpisodio(Episodio ep);
    void mostrarEpisodioPorTemporada();

    void mostrarEpisodioPorCalificacion();

    void mostrarInfo();
    void calificar();

    void calucularMaraton();
};



#endif //SERIE_HPP


