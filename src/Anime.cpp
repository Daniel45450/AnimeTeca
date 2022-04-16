#include "Anime.h"

Anime::Anime()
{
    //ctor
}

Anime::~Anime()
{
    //dtor
}

Anime::Anime(string nombre)
{
    this->nombre = nombre;
}

bool Anime::eliminarCapitulo(int numero)
{
    this->capitulos.remove(numero);
}

bool Anime::agregarCapitulo(int numero)
{
    this->capitulos.push_back(numero);
    return true;
}

string Anime::getNombre() const
{
    return this->nombre;
}

void Anime::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Anime::obtenerCapitulos(list<int>& lista) const
{
    list<int>::const_iterator it = this->capitulos.begin();
    while(it != capitulos.end()) {
        lista.push_back(*it);
        it++;
    }
}
bool Anime::operator<(const Anime & anime) const
{
    return (this->nombre < anime.getNombre());
}
int Anime::getCantidadCapitulos() const
{
    return this->capitulos.size();
}

bool Anime::getEstado() const
{
    return this->estado;
}

void Anime::setEstado(bool estado)
{
    this->estado = estado;
}



