#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

#include "clases/Serie/Serie.hpp"
#include "clases/Episodio/Episodio.hpp"

using json = nlohmann::json;
using namespace std;

int main() {
    ifstream file("bucket.json");
    if (!file.is_open()) {
        cerr << "Error al abrir datos.json\n";
        return 1;
    }
    json data;
    file >> data;

    vector<Serie> series;

    for (const auto& s : data["series"]) {
        vector<Episodio> episodiosVec;
        for (const auto& ep : s["episodios"]) {
            Episodio episodio(
                ep["id"].get<string>(),
                ep["titulo"].get<string>(),
                ep["duracion"].get<double>(),
                ep["numeroDeCalificaciones"].get<int>(),
                ep["sumCalificaciones"].get<int>(),
                ep["calificacion"].get<double>(),
                ep["genero"].get<string>(),
                ep["temporada"].get<int>()
            );
            episodiosVec.push_back(episodio);
        }

        Serie serie(
            s["id"].get<string>(),
            s["nombre"].get<string>(),
            s["calificacion"].get<double>(),
            s["numeroDeCalificaciones"].get<int>(),
            s["sumCalificaciones"].get<int>(),
            s["paisDeOrigen"].get<string>(),
            s["genero"].get<string>(),
            s["clasificacion"].get<string>(),
            episodiosVec
        );

        series.push_back(serie);
    }

    for (int i = 0 ; i < series.size(); i++) {

       series[i].mostrarEpisodios();
    }

    return 0;
}