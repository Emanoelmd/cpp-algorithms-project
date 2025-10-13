#include "Manga.h"

#include <cstdio>
#include <cstring>

Manga::Manga(const char* titulo_p, const char* autor_p, const char* genero_p, int volumes_p, float minhaNota_p){
    strcpy(this->titulo, titulo_p);
    strcpy(this->autor, autor_p);
    strcpy(this->genero, genero_p);
    this->volumes = volumes_p;
    this->minhaNota = minhaNota_p;
};

void Manga::imprimirDetalhes(){
    printf("Nome do Mangá: %s\n", titulo);
    printf("Nome do Autor: %s\n", autor);
    printf("Genéro: %s\n", genero);
    printf("Quantidade de Volumes: %d\n", volumes);
    printf("Nota de Avaliação: %2.f\n", minhaNota);
}