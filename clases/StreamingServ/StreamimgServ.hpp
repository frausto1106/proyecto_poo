//
// Created by Kaled Frausto on 08/06/25.
//

#ifndef STREAMIMGSERV_HPP
#define STREAMIMGSERV_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "../Serie/Serie.hpp"
#include "../Episodio/Episodio.hpp"
#include "../Video/Video.hpp"
#include "../Pelicula/Pelicula.hpp"

using namespace std;


class StreamimgServ {
    vector<Serie> Series;
    vector<Pelicula> Peliculas;

public:
    StreamimgServ();

    int mostrarMenuSeries();

    void mostrarCatalogo();

    void infoSerie();

    void mostrarEps(string input);

    void mostrarEpsPorTemporada();

    void calificarSerie();

    void mostrarEpsPorCalificacion();

    void calcularMaratonSerie();

    void menuCapitulo();

    void mostrarCatalogoDePeliculas();

    void mostrarPeliculasPorCalificacion();

    void calificarPeli();

    void duracionPeli();

    void mostrarTodosLosVideos();

    int menuSeries();
    void menuPeliculas();



};



#endif //STREAMIMGSERV_HPP
