#include "ContenedorAnimes.h"
#include <iostream>

ContenedorAnimes::ContenedorAnimes()
{
    //ctor
}

ContenedorAnimes::~ContenedorAnimes()
{
    //dtor
}
void ContenedorAnimes::agregarAnime(Anime& anime)
{
    this->animes.insert(anime);
}

bool ContenedorAnimes::recuperarAnime(Anime & anime)
{
    set<Anime>::iterator it = this->animes.find(anime);
    if(it != this->animes.end()) {
        anime = *it;
        return true;
    } else return false;
}

void ContenedorAnimes::actualizarAnime(Anime & anime)
{
    set<Anime>::iterator it = this->animes.find(anime);
    if(it != this->animes.end()) {
        this->animes.erase(it);
        this->animes.insert(anime);
        cout << "Actualizado con exito" << endl;
    } else {
        cout << "Error: No se pudieron actualizar los datos" << endl;
    }
}


void ContenedorAnimes::eliminarAnime(Anime& anime)
{
    set<Anime>::iterator it = this->animes.find(anime);
    if(it != this->animes.end()) {
        this->animes.erase(it);
    } else {
        cout << "Ese anime no existe " <<endl;
    }
}


void ContenedorAnimes::obtenerAnimes(list<Anime>& animes) const
{
    set<Anime>::const_iterator it = this->animes.begin();
    while(it != this->animes.end()){
        animes.push_back(*it);
        it++;
    }
}




