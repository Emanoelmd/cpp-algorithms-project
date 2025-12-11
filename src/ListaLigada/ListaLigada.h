#pragma once

#include "../Manga/Manga.h"

class ArvoreBST;

struct No{
    No* proximo;
    Manga manga;

    No(const Manga& m) : manga(m), proximo(nullptr) {}
};

class ListaLigada{
    private:
        No* cabeca;
        int contarElementos();

    public:
        ListaLigada();
        ~ListaLigada();

        void inserirManga(Manga novo_manga);
        void salvarEmArquivo(const char* nomeArquivo);
        void carregarDeArquivo(const char* nomeArquivo);
        void imprimirLista();

        void listarPorTitulo();
        void buscarPorTitulo(const char* titulo);

        bool removerManga(const char* titulo);
        void sincronizarArvore(ArvoreBST& arvore);
};