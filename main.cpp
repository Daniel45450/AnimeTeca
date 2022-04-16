#include <iostream>
#include <Anime.h>
#include <ContenedorAnimes.h>
#include <fstream>

using namespace std;

//menus
void menu();
void menuAnime();

//funciones principales
void agregarAnime(ContenedorAnimes & animes);
void seleccionarAnime(ContenedorAnimes & animes);
void administrarAnime(ContenedorAnimes & animes, Anime & a1);
void eliminarAnime(ContenedorAnimes & animes);
void mostrarAnimes(ContenedorAnimes & animes);

//funciones adm animes
void agregarCapitulo(Anime & a1);
void eliminarCapitulo(Anime & a1);
void mostrarCapitulos(const Anime & a1);
void cambiarEstado(Anime & a1);

//manejo archivo
void escribirArchivo(const ContenedorAnimes & animes);
void leerArchivo(ContenedorAnimes & animes);

int main()
{
    int opciones = 0;
    ContenedorAnimes animes;
    leerArchivo(animes);
    do{
        menu();
        cout << "Selecciona una opcion: ";
        cin >> opciones;
        switch(opciones) {
            case 1: agregarAnime(animes);
            break;
            case 2: seleccionarAnime(animes);
            break;
            case 3: eliminarAnime(animes);
            break;
            case 4: mostrarAnimes(animes);
            break;
            case 5:
                escribirArchivo(animes);
                cout  << "Saliendo.." << endl;
            break;
            default: cout << "Ingresa una opcion valida";
            break;
        }
    } while(opciones != 5);
    return 0;
}

void mostrarAnimes(ContenedorAnimes & animes) {
    list<Anime> listAnimes;
    animes.obtenerAnimes(listAnimes);
    list<Anime>::iterator it = listAnimes.begin();
    if(it != listAnimes.end()){
     cout << "------ Animes Agregados ------" <<endl;
     while(it != listAnimes.end()) {
        string estado;
        if(it->getEstado() == true) {
            estado = "Terminado";
        } else {
            estado = "En proceso";
        }
        cout << "-- " << it->getNombre() << " (" << it->getCantidadCapitulos() << ")"<< " " << estado <<endl;
        it++;
     }
    } else {
        cout << "Aun no hay animes agregados" << endl;
    }
}

void eliminarAnime(ContenedorAnimes & animes) {
    string animeNombre;
    cout << "Ingresa el nombre: " << endl;
    getline(cin.ignore(), animeNombre);
    Anime a1(animeNombre);
    animes.eliminarAnime(a1);
}

void cambiarEstado(Anime & anime) {
    int opcion =0;
    cout << "\n";
    cout << "--- Selecciona una opcion ---" << endl;
    cout << "1) Terminado" << endl;
    cout << "2) En proceso" << endl;
    cout << "\n";
    cin >> opcion;
    if(opcion == 1) {
        anime.setEstado(true);
    } else if(opcion == 2) {
        anime.setEstado(false);
    }

    cout << "Estado cambiado" <<endl;
}


void menu() {
    cout << endl;
    cout << "################################################" << endl;
    cout << "#================= ANIMETECA ==================#" << endl;
    cout << "#                                              #" << endl;
    cout << "# Opciones                                     #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 1) Agregar Anime                             #" << endl;
    cout << "# 2) Seleccionar Anime                         #" << endl;
    cout << "# 3) Eliminar Anime                            #" << endl;
    cout << "# 4) Mostrar Animes                            #" << endl;
    cout << "# 5) Salir                                     #" << endl;
    cout << "#                                              #" << endl;
    cout << "#==============================================#" << endl;
    cout << "################################################" << endl;
    cout << endl;
}

void agregarAnime(ContenedorAnimes & animes) {
    string animeNombre;
    cout << "Ingresa el nombre: " << endl;
    getline(cin.ignore(), animeNombre);
    Anime a1(animeNombre);
    animes.agregarAnime(a1);
    cout << "Anime agregado con exito" <<endl;
}

void seleccionarAnime(ContenedorAnimes & animes) {
    string nombreAnime;
    cout << "Ingresa el nombre del anime: " << endl;
    getline(cin.ignore(), nombreAnime);
    Anime a1(nombreAnime);
    bool encontrado = animes.recuperarAnime(a1);
    if(encontrado) {
        administrarAnime(animes, a1);
    } else {
        cout << "Ese anime no esta cargado" <<endl;
    }

}

void administrarAnime(ContenedorAnimes & animes, Anime & a1) {
    int opciones = 0;
    do{
        menuAnime();
        cout << "Selecciona una opcion" << endl;
        cin >> opciones;
        switch(opciones) {
            case 1: agregarCapitulo(a1);
            break;
            case 2: eliminarCapitulo(a1);
            break;
            case 3: mostrarCapitulos(a1);
            break;
            case 4: cambiarEstado(a1);
            break;
            case 5:
                animes.actualizarAnime(a1);
                cout  << "Saliendo.." << endl;
            break;
            default: cout << "Ingresa una opcion valida";
            break;
        }
    } while(opciones != 5);

}

void mostrarCapitulos(const Anime & a1) {
    list<int> capitulos;
    a1.obtenerCapitulos(capitulos);
    list<int>::iterator it = capitulos.begin();
    if(it != capitulos.end()) {
        cout << endl;
        cout << "------ CAPITULOS VISTOS ------" <<endl;
        while(it != capitulos.end()) {
            cout << "-- Capitulo: " << *it <<endl;
            it++;
        }
    } else {
        cout << "Aun no se han agregado capitulos a este anime" <<endl;
    }

}

void eliminarCapitulo(Anime & a1) {
    int capitulo;
    cout << "Ingresa el numero del capitulo: " << endl;
    cin >> capitulo;
    a1.eliminarCapitulo(capitulo);
    cout << "Capitulo Eliminado";
}

void agregarCapitulo(Anime & a1) {
    int capitulo;
    cout << "Ingresa el numero del capitulo: " << endl;
    cin >> capitulo;
    a1.agregarCapitulo(capitulo);
    cout << "Capitulo cargado";
}

void menuAnime() {
    cout << endl;
    cout << "################################################" << endl;
    cout << "#================= Adm Anime ==================#" << endl;
    cout << "#                                              #" << endl;
    cout << "# Opciones                                     #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 1) Agregar Capitulo                          #" << endl;
    cout << "# 2) Eliminar Capitulo                         #" << endl;
    cout << "# 3) Mostrar capitulos                         #" << endl;
    cout << "# 4) Cambiar estado                            #" << endl;
    cout << "# 5) Volver                                    #" << endl;
    cout << "#                                              #" << endl;
    cout << "#==============================================#" << endl;
    cout << "################################################" << endl;
    cout << endl;
}

void escribirArchivo(const ContenedorAnimes & animes) {
    ofstream archivo;
    string path = "C:\\Users\\danie\\Documents\\animes.txt";
    archivo.open(path, ios::out);
    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    } else {
        list<Anime> listaAnimes;
        animes.obtenerAnimes(listaAnimes);
        list<Anime>::iterator it = listaAnimes.begin();
        list<int>::iterator capitulosIterator;
        while(it != listaAnimes.end()) {
            archivo << it->getNombre() << ";";
            list<int> capitulos;
            it->obtenerCapitulos(capitulos);
            capitulosIterator = capitulos.begin();
            archivo << capitulos.size() << ";";
            while(capitulosIterator != capitulos.end()) {
                archivo << *capitulosIterator << ";";
                capitulosIterator++;
            }
            archivo << it->getEstado() << ";";
            archivo << "\n";
            it++;
        }
        archivo.close();
    }
}

void leerArchivo(ContenedorAnimes & animes) {
    ifstream archivo;
    string path = "C:\\Users\\danie\\Documents\\animes.txt";
    archivo.open(path, ios::in);
    if(archivo.fail()) {
        cout << "Error: Fallo la carga de animes... si es tu primera ejecucion ignorar este error" <<endl;
    } else {
        string linea;
        while(getline(archivo, linea)) {
            Anime anime;
            int posInicial =0;
            int posFinal = linea.find(";");

            string nombre = linea.substr(posInicial, posFinal);

            posInicial = posFinal +1;
            posFinal = linea.find(";", posInicial);

            int cantidadCapitulos = atoi(linea.substr(posInicial, posFinal).c_str());

            for(int i=0; i<cantidadCapitulos; i++) {
                posInicial = posFinal +1;
                posFinal = linea.find(";", posInicial);
                int numeroCapitulo = atoi(linea.substr(posInicial, posFinal).c_str());
                anime.agregarCapitulo(numeroCapitulo);
            }

            posInicial = posFinal + 1;
            posFinal = linea.find(";", posInicial);

            int estado = atoi(linea.substr(posInicial, posFinal).c_str());
            if(estado == 0) {
                anime.setEstado(false);
            } else {
                anime.setEstado(true);
            }
            anime.setNombre(nombre);
            animes.agregarAnime(anime);
        }

        archivo.close();
    }
}

