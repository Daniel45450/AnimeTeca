#ifndef ANIME_H
#define ANIME_H

#include <iterator>
#include <list>

using namespace std;


class Anime
{
    public:
        Anime();
        virtual ~Anime();
        Anime(string nombre);
        bool eliminarCapitulo(int numero);
        bool agregarCapitulo(int numero);
        string getNombre() const;
        void setNombre(string nombre);
        void obtenerCapitulos(list<int> & lista) const;
        int getCantidadCapitulos() const;
        bool getEstado() const;
        void setEstado(bool estado);
        bool operator<(const Anime & Anime) const;

    protected:

    private:
        string nombre;
        bool estado =0;
        list<int> capitulos;

};

#endif // ANIME_H

