//
// Created by Kaled Frausto on 07/06/25.
//

#ifndef SERIE_HPP
#define SERIE_HPP
#include <iostream>

#include "../Episodio/Episodio.hpp"
using namespace std;

class Serie {
private:
    string nombre;
    double calificacion;
    int numeroDeCalificaciones;
    int sumCalificaciones;
    string paisDeOrigen;
    string genero;
    string clasificacion;
    vector<&Episodio> episodios;

public:
    Serie(string nombre);
    void mostrarEpisodios();
    void agregarEpisodio(Episodio &ep);
    void mostrarEpisodioPorTemporada(int temporada);
    void mostrarInfo();
    void calificar();
};



#endif //SERIE_HPP
