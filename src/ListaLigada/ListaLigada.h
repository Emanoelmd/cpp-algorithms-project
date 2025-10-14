#pragma once

#include "../Manga/Manga.h"

struct No{
    No* proximo;
    Manga manga;

    No(const Manga& m) : manga(m), proximo(nullptr) {}
};

class ListaLigada{
    private:
        No* cabeca;
    public:
        ListaLigada();
        ~ListaLigada();

        void inserirManga(Manga novo_manga);
        void imprimirLista();
};