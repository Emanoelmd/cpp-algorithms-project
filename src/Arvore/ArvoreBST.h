#pragma once

#include "../Manga/Manga.h"
#include "../ListaLigada/ListaLigada.h"

struct NoArvore {
    char genero[50];
    ListaLigada mangasDoGenero;
    NoArvore* esquerda;
    NoArvore* direita;
};

class ArvoreBST {
private:
    NoArvore* raiz;

    NoArvore* inserirRecursivo(NoArvore* no, Manga m);
    void exibirRecursivo(NoArvore* no);
    void liberarRecursivo(NoArvore* no);

public:
    ArvoreBST();
    ~ArvoreBST();

    void adicionarManga(Manga m);
    void exibirPorGenero();
};

