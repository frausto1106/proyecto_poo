//
// Created by Kaled Frausto on 08/06/25.
//

#include "StreamimgServ.hpp"
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

#include "../Serie/Serie.hpp"
#include "../Episodio/Episodio.hpp"
#include "../Video/Video.hpp"
#include "../Pelicula/Pelicula.hpp"

using json = nlohmann::json;

StreamimgServ::StreamimgServ() {
    try {
        ifstream file("bucket.json");

        if (!file.is_open()) {
            cerr << "Error al abrir bucket.json\n";
            return;
        }

        json data;
        file >> data;

        Series.clear();
        Peliculas.clear();

        for (size_t i = 0; i < data["series"].size(); ++i) {
            const auto& s = data["series"][i];
            vector<Episodio> episodiosVec;

            for (size_t j = 0; j < s["episodios"].size(); ++j) {
                const auto& ep = s["episodios"][j];
                Episodio episodio(
                    ep["id"].get<string>(),
                    ep["titulo"].get<string>(),
                    ep["duracion"].get<double>(),
                    ep.value("numeroDeCalificaciones", 0),
                    ep.value("sumCalificaciones", 0),
                    ep.value("calificacion", 0.0),
                    ep["genero"].get<string>(),
                    ep["temporada"].get<int>()
                );
                episodiosVec.push_back(episodio);
            }

            Serie serie(
                s["id"].get<string>(),
                s["nombre"].get<string>(),
                s.value("calificacion", 0.0),
                s.value("numeroDeCalificaciones", 0),
                s.value("sumCalificaciones", 0),
                s["paisDeOrigen"].get<string>(),
                s["genero"].get<string>(),
                s["clasificacion"].get<string>(),
                episodiosVec
            );

            Series.push_back(serie);
        }

        for (size_t i = 0; i < data["peliculas"].size(); ++i) {
            const auto& p = data["peliculas"][i];
            Pelicula pelicula(
                p["id"].get<string>(),
                p["titulo"].get<string>(),
                p["duracion"].get<double>(),
                p.value("numeroDeCalificaciones", 0),
                p.value("sumCalificaciones", 0),
                p.value("calificacion", 0.0),
                p["genero"].get<string>(),
                p["clasificacion"].get<string>(),
                p["paisDeOrigen"].get<string>(),
                p.value("duracionCreditos", 0.0)
            );
            Peliculas.push_back(pelicula);
        }

    } catch (const nlohmann::json::exception& e) {
        cerr << "Error de JSON: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error general: " << e.what() << endl;
    }
}

int StreamimgServ::mostrarMenuSeries() {
    int opc;
    cout << "============== MENU DE SERIES ==============\n";
    cout << "1- Mostrar Catálogo\n";
    cout << "2- Información de una serie\n";
    cout << "3- Mostrar capítulos\n";
    cout << "4- Buscar capítulos por temporada\n";
    cout << "5- Buscar capítulos por calificación\n";
    cout << "6- Calificar serie\n";
    cout << "7- Calcular maratón\n";
    cout << "8- Acceder al menú de un capítulo\n";
    cout << "9- Salir\n";
    cin >> opc;
    cin.ignore();
    return opc;
}

void StreamimgServ::mostrarCatalogo() {
    for (size_t i = 0; i < Series.size(); ++i) {
        Series[i].mostrarInfo();
    }
}

void StreamimgServ::infoSerie() {
    string input;
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, input);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == input || Series[i].getNombre() == input) {
            Series[i].mostrarInfo();
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::mostrarEps(string input) {
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, input);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == input || Series[i].getNombre() == input) {
            Series[i].mostrarEpisodios();
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::mostrarEpsPorTemporada() {
    string input;
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, input);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == input || Series[i].getNombre() == input) {
            Series[i].mostrarEpisodioPorTemporada();
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::calificarSerie() {
    string input;
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, input);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == input || Series[i].getNombre() == input) {
            Series[i].calificar();
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::mostrarEpsPorCalificacion() {
    string input;
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, input);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == input || Series[i].getNombre() == input) {
            Series[i].mostrarEpisodioPorCalificacion();
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::calcularMaratonSerie() {
    string input;
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, input);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == input || Series[i].getNombre() == input) {
            Series[i].calucularMaraton();
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::menuCapitulo() {
    string serieInput, capituloInput;
    cout << "Introduce el ID o nombre de la serie: ";
    getline(cin, serieInput);

    for (size_t i = 0; i < Series.size(); ++i) {
        if (Series[i].getId() == serieInput || Series[i].getNombre() == serieInput) {
            cout << "Introduce el ID del capítulo: ";
            getline(cin, capituloInput);

            for (size_t j = 0; j < Series[i].getEpisodios().size(); ++j) {
                if (Series[i].getEpisodios()[j].getId() == capituloInput || Series[i].getEpisodios()[j].getTitulo() == capituloInput) {
                    while (true) {
                        int opc;
                        cout << "==== MENU DEL CAPÍTULO ====\n";
                        cout << "1- Mostrar info\n";
                        cout << "2- Calificar capítulo\n";
                        cout << "3- Salir\n";
                        cin >> opc;
                        cin.ignore();

                        if (opc == 1) {
                            Series[i].getEpisodios()[j].mostrarInfo();
                        } else if (opc == 2) {
                            Series[i].getEpisodios()[j].calificar();
                        } else if (opc == 3) {
                            return;
                        } else {
                            cout << "Opción no válida.\n";
                        }
                    }
                }
            }
            cout << "Capítulo no encontrado.\n";
            return;
        }
    }
    cout << "Serie no encontrada.\n";
}

void StreamimgServ::mostrarCatalogoDePeliculas() {
    for (size_t i = 0; i < Peliculas.size(); ++i) {
        Peliculas[i].mostrarInfo();
    }
}

void StreamimgServ::mostrarPeliculasPorCalificacion() {
    int cal;
    cout << "Mostrar películas por calificación (1-5): ";
    cin >> cal;
    cin.ignore();

    for (size_t i = 0; i < Peliculas.size(); ++i) {
        if (Peliculas[i].getCalificacion() == cal) {
            Peliculas[i].mostrarInfo();
        }
    }
}

void StreamimgServ::calificarPeli() {
    string input;
    cout << "Introduce el ID o nombre de la película: ";
    getline(cin, input);

    for (size_t i = 0; i < Peliculas.size(); ++i) {
        if (Peliculas[i].getId() == input || Peliculas[i].getTitulo() == input) {
            Peliculas[i].calificar();
            return;
        }
    }
    cout << "Película no encontrada.\n";
}

void StreamimgServ::duracionPeli() {
    string input;
    cout << "Introduce el ID o nombre de la película: ";
    getline(cin, input);

    for (size_t i = 0; i < Peliculas.size(); ++i) {
        if (Peliculas[i].getId() == input || Peliculas[i].getTitulo() == input) {
            cout<<"duracion total en minutos: "<<Peliculas[i].calcularDuracion()<<endl;

            return;
        }
    }
    cout << "Película no encontrada.\n";
}

void StreamimgServ::mostrarTodosLosVideos() {


    for (size_t i = 0; i < Peliculas.size(); ++i) {
        Peliculas[i].mostrarInfo();
    }

    for (size_t i = 0; i < Series.size(); ++i) {
        for (size_t j = 0; j < Series[i].getEpisodios().size(); ++j) {
            Series[i].getEpisodios()[j].mostrarInfo();
        }
    }
}
