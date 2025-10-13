#pragma once

#include "../Manga/Manga.h"

struct No{
    No* proximo;
    Manga manga;
};

class ListaLigada{
    private:
        No* inicio;
    public:
        ListaLigada();
        ~ListaLigada();

        void inserirManga(Manga novo_manga);
        void imprimirLista();
};