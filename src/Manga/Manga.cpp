#include "Manga.h"

#include <cstdio>
#include <cstring>

Manga::Manga(const char* titulo_p, const char* autor_p, const char* genero_p, int volumes_p, float nota_p){
    strcpy(this->titulo, titulo_p);
    strcpy(this->autor, autor_p);
    strcpy(this->genero, genero_p);
    this->volumes = volumes_p;
    this->nota = nota_p;
};

void Manga::imprimirDetalhes(){
    printf("===================================\n");
    printf("Nome do Mangá: %s\n", titulo);
    printf("Nome do Autor: %s\n", autor);
    printf("Genéro: %s\n", genero);
    printf("Quantidade de Volumes: %d\n", volumes);
    printf("Nota de Avaliação: %2.f\n", nota);
    printf("===================================");
}

const char* Manga::getTitulo() const {
    return this->titulo;
}

const char* Manga::getAutor() const {
    return this->autor;
}

const char* Manga::getGenero() const {
    return this->genero;
}

int Manga::getVolumes() const {
    return this->volumes;
}

float Manga::getNota() const {
    return this->nota;
}

void Manga::setTitulo(const char* novoTitulo){
    strcpy(this->titulo, novoTitulo);
};

void Manga::setAutor(const char* novoAutor){
    strcpy(this->autor, novoAutor);
};

void Manga::setGenero(const char* novoGenero){
    strcpy(this->genero, novoGenero);
};
void Manga::setVolumes(int novosVolumes){
    this->volumes = novosVolumes;
};

void Manga::setNota(float novaNota){
    this->nota = novaNota;
};