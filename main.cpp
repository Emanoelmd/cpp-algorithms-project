#include "src/Manga/Manga.h"
#include "src/ListaLigada/ListaLigada.h"

int main(){

    Manga meuMangaDeTeste("Berserk", "Kentarou Miura", "Fantasia Sombria", 41, 10.0);

    meuMangaDeTeste.imprimirDetalhes();

    return 0;
}