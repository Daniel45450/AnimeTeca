#ifndef CONTENEDORANIMES_H
#define CONTENEDORANIMES
#include <Anime.h>
#include <set>


class ContenedorAnimes
{
    public:
        ContenedorAnimes();
        virtual ~ContenedorAnimes();
        void agregarAnime(Anime & anime);
        void actualizarAnime(Anime & anime);
        bool recuperarAnime(Anime & anime);
        void obtenerAnimes(list<Anime> & animes) const;
        void eliminarAnime(Anime & anime);

    protected:

    private:
        set<Anime> animes;
};

#endif // CONTENEDORANIMES_H
