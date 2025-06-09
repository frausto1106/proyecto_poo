#include <iostream>
#include <fstream>
#include "clases/StreamingServ/StreamimgServ.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

int main() {
    StreamimgServ servicio;
    int opcionPrincipal;

    do {
        cout << "=========== MENÚ PRINCIPAL ===========\n";
        cout << "1 - Menú de Series\n";
        cout << "2 - Mostrar Catálogo de Películas\n";
        cout << "3 - Mostrar Películas por Calificación\n";
        cout << "4 - Calificar una Película\n";
        cout << "5 - Mostrar todos los videos\n";
        cout << "6 - Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcionPrincipal;
        cin.ignore(); 

        switch (opcionPrincipal) {
            case 1: {
                int opcionSerie;
                do {
                    opcionSerie = servicio.mostrarMenuSeries();
                    switch (opcionSerie) {
                        case 1:
                            servicio.mostrarCatalogo();
                            break;
                        case 2:
                            servicio.infoSerie();
                            break;
                        case 3:
                            servicio.mostrarEps("");
                            break;
                        case 4:
                            servicio.mostrarEpsPorTemporada();
                            break;
                        case 5:
                            servicio.mostrarEpsPorCalificacion();
                            break;
                        case 6:
                            servicio.calificarSerie();
                            break;
                        case 7:
                            servicio.calcularMaratonSerie();
                            break;
                        case 8:
                            servicio.menuCapitulo();
                            break;
                        case 9:
                            cout << "Regresando al menú principal...\n";
                            break;
                        default:
                            cout << "Opción no válida.\n";
                            break;
                    }
                    cout << "\n";
                } while (opcionSerie != 9);
                break;
            }
            case 2:
                servicio.mostrarCatalogoDePeliculas();
                break;
            case 3:
                servicio.mostrarPeliculasPorCalificacion();
                break;
            case 4:
                servicio.calificarPeli();
                break;
            case 5:
                servicio.mostrarTodosLosVideos();
                break;
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }

        cout << "\n";
    } while (opcionPrincipal != 6);

    return 0;
}