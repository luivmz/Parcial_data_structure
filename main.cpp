#include <iostream>
#include <string>

using namespace std;

const int MAX_PLATAFORMAS = 100;
const int MAX_CONTENIDOS = 100;

struct PlataformaStreaming {
    string nombre;
    string tipoContenido;
    int numeroSuscriptores;
    string funcionalidades;
    string paisOrigen;
    float precioSuscripcion;
};

struct ContenidoStreaming {
    string titulo;
    string tipo;
    int duracion;
    string genero;
    int anioLanzamiento;
    PlataformaStreaming* plataformaAsociada;
};

void inscribirPlataforma(PlataformaStreaming plataformas[], int &numPlataformas);
void mostrarPlataformas(PlataformaStreaming plataformas[], int numPlataformas);
void buscarPlataforma(PlataformaStreaming plataformas[], int numPlataformas);
void inscribirContenido(ContenidoStreaming contenidos[], int &numContenidos, PlataformaStreaming plataformas[], int numPlataformas);
void mostrarContenidos(ContenidoStreaming contenidos[], int numContenidos);
void menuPlataformas(PlataformaStreaming plataformas[], int &numPlataformas);
void menuContenido(ContenidoStreaming contenidos[], int &numContenidos, PlataformaStreaming plataformas[], int numPlataformas);

int main() {
    PlataformaStreaming plataformas[MAX_PLATAFORMAS];
    ContenidoStreaming contenidos[MAX_CONTENIDOS];
    int numPlataformas = 0, numContenidos = 0;

    char opcion;
    do {
        cout << "--------------------------------------\n";
        cout << "|           Menu Principal           |\n";
        cout << "--------------------------------------\n";
        cout << "| [A]. Gestionar Plataformas         |\n";
        cout << "| [B]. Gestionar Contenidos          |\n";
        cout << "| [C]. Salir                         |\n";
        cout << "--------------------------------------\n";
        cout << "Seleccione una opcion (A, B, C): ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A':
                menuPlataformas(plataformas, numPlataformas);
                break;
            case 'B':
                menuContenido(contenidos, numContenidos, plataformas, numPlataformas);
                break;
            case 'C':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    } while (opcion != 'C');

    return 0;
}

void inscribirPlataforma(PlataformaStreaming plataformas[], int &numPlataformas) {
    if (numPlataformas >= MAX_PLATAFORMAS) {
        cout << "No se pueden inscribir mas plataformas.\n";
        return;
    }

    PlataformaStreaming plataforma;

    cin.ignore();  // Limpiar 
    cout << "\tIngrese nombre de la plataforma: ";
    getline(cin, plataforma.nombre);
    cout << "\tIngrese tipo de contenido (musica, video, series): ";
    getline(cin, plataforma.tipoContenido);
    cout << "\tIngrese numero de suscriptores: ";
    cin >> plataforma.numeroSuscriptores;
    cin.ignore();
    cout << "\tIngrese funcionalidades: ";
    getline(cin, plataforma.funcionalidades);
    cout << "\tIngrese pais de origen: ";
    getline(cin, plataforma.paisOrigen);
    cout << "\tIngrese precio de suscripcion mensual (S/.): ";
    cin >> plataforma.precioSuscripcion;

    plataformas[numPlataformas] = plataforma;
    numPlataformas++;

    cout << "Plataforma inscripta con exito.\n";
}

void mostrarPlataformas(PlataformaStreaming plataformas[], int numPlataformas) {
    if (numPlataformas == 0) {
        cout << "No hay plataformas disponibles.\n";
        return;
    }

    for (int i = 0; i < numPlataformas; ++i) {
        cout << "\tPlataforma " << i + 1 << ": " << plataformas[i].nombre << "\n";
        cout << "\tTipo de contenido: " << plataformas[i].tipoContenido << "\n";
        cout << "\tNumero de suscriptores: " << plataformas[i].numeroSuscriptores << "\n";
        cout << "\tFuncionalidades: " << plataformas[i].funcionalidades << "\n";
        cout << "\tPais de origen: " << plataformas[i].paisOrigen << "\n";
        cout << "\tPrecio de suscripcion: $" << plataformas[i].precioSuscripcion << "\n\n";
    }
}

void buscarPlataforma(PlataformaStreaming plataformas[], int numPlataformas) {
    if (numPlataformas == 0) {
        cout << "No hay plataformas disponibles.\n";
        return;
    }

    string nombreBusqueda;
    cin.ignore();
    cout << "\tIngrese el nombre de la plataforma a buscar: ";
    getline(cin, nombreBusqueda);

    for (int i = 0; i < numPlataformas; ++i) {
        if (plataformas[i].nombre == nombreBusqueda) {
            cout << "\tPlataforma encontrada: " << plataformas[i].nombre << "\n";
            cout << "\tTipo de contenido: " << plataformas[i].tipoContenido << "\n";
            cout << "\tNumero de suscriptores: " << plataformas[i].numeroSuscriptores << "\n";
            cout << "\tFuncionalidades: " << plataformas[i].funcionalidades << "\n";
            cout << "\tPais de origen: " << plataformas[i].paisOrigen << "\n";
            cout << "\tPrecio de suscripcion: $" << plataformas[i].precioSuscripcion << "\n\n";
            return;
        }
    }
    cout << "Plataforma no encontrada.\n";
}

void inscribirContenido(ContenidoStreaming contenidos[], int &numContenidos, PlataformaStreaming plataformas[], int numPlataformas) {
    if (numContenidos >= MAX_CONTENIDOS) {
        cout << "No se pueden inscribir mas contenidos.\n";
        return;
    }
    if (numPlataformas == 0) {
        cout << "No hay plataformas disponibles para asociar el contenido.\n";
        return;
    }

    ContenidoStreaming contenido;

    cin.ignore();
    cout << "\tIngrese titulo del contenido: ";
    getline(cin, contenido.titulo);
    cout << "\tIngrese tipo de contenido (serie, pelicula, album): ";
    getline(cin, contenido.tipo);
    cout << "\tIngrese duracion en minutos: ";
    cin >> contenido.duracion;
    cin.ignore();
    cout << "\tIngrese genero: ";
    getline(cin, contenido.genero);
    cout << "\tIngrese anio de lanzamiento: ";
    cin >> contenido.anioLanzamiento;

    cout << "\tSeleccione la plataforma asociada (numero):\n";
    for (int i = 0; i < numPlataformas; ++i) {
        cout << i + 1 << ". " << plataformas[i].nombre << "\n";
    }
    int seleccion;
    cin >> seleccion;
    contenido.plataformaAsociada = &plataformas[seleccion - 1];

    contenidos[numContenidos] = contenido;
    numContenidos++;

    cout << "Contenido inscripto con exito.\n";
}

void mostrarContenidos(ContenidoStreaming contenidos[], int numContenidos) {
    if (numContenidos == 0) {
        cout << "No hay contenidos disponibles.\n";
        return;
    }

    for (int i = 0; i < numContenidos; ++i) {
        cout << "\tContenido " << i + 1 << ": " << contenidos[i].titulo << "\n";
        cout << "\tTipo: " << contenidos[i].tipo << "\n";
        cout << "\tDuracion: " << contenidos[i].duracion << " minutos\n";
        cout << "\tGenero: " << contenidos[i].genero << "\n";
        cout << "\tAnio de lanzamiento: " << contenidos[i].anioLanzamiento << "\n";
        cout << "\tPlataforma asociada: " << contenidos[i].plataformaAsociada->nombre << "\n\n";
    }
}

void menuPlataformas(PlataformaStreaming plataformas[], int &numPlataformas) {
    int opcion;
    do {
        cout << "--------------------------------------\n";
        cout << "|        Gestion de Plataformas      |\n";
        cout << "--------------------------------------\n";
        cout << "| [1]. Inscribir Plataforma          |\n";
        cout << "| [2]. Mostrar Plataformas           |\n";
        cout << "| [3]. Buscar Plataforma             |\n";
        cout << "| [4]. Volver al menu principal      |\n";
        cout << "--------------------------------------\n";
        cout << "Seleccione una opcion (1, 2, 3, 4): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                inscribirPlataforma(plataformas, numPlataformas);
                break;
            case 2:
                mostrarPlataformas(plataformas, numPlataformas);
                break;
            case 3:
                buscarPlataforma(plataformas, numPlataformas);
                break;
            case 4:
                cout << "Volviendo al menu principal.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    } while (opcion != 4);
}

void menuContenido(ContenidoStreaming contenidos[], int &numContenidos, PlataformaStreaming plataformas[], int numPlataformas) {
    int opcion;
    do {
        cout << "--------------------------------------\n";
        cout << "|        Gestion de Contenidos       |\n";
        cout << "--------------------------------------\n";
        cout << "| [1]. Inscribir Contenido           |\n";
        cout << "| [2]. Mostrar Contenidos            |\n";
        cout << "| [3]. Volver al menu principal      |\n";
        cout << "--------------------------------------\n";
        cout << "Seleccione una opcion (1, 2, 3): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                inscribirContenido(contenidos, numContenidos, plataformas, numPlataformas);
                break;
            case 2:
                mostrarContenidos(contenidos, numContenidos);
                break;
            case 3:
                cout << "Volviendo al menu principal.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    } while (opcion != 3);
}
