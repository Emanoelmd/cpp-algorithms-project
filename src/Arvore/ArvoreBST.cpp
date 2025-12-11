#include "ArvoreBST.h"
#include <cstring>
#include <cstdio>
#include <iostream>

ArvoreBST::ArvoreBST() {
    this->raiz = nullptr;
}

ArvoreBST::~ArvoreBST() {
    liberarRecursivo(raiz);
}

void ArvoreBST::liberarRecursivo(NoArvore* no) {
    if (no != nullptr) {
        liberarRecursivo(no->esquerda);
        liberarRecursivo(no->direita);
        delete no; 
    }
}

void ArvoreBST::adicionarManga(Manga m) {
    raiz = inserirRecursivo(raiz, m);
}

void ArvoreBST::exibirPorGenero() {
    if (raiz == nullptr) {
        printf("A arvore de generos esta vazia.\n");
    } else {
        printf("\n===================================\n");
        printf("   Indice por Generos (A-Z)   \n");
        printf("===================================\n");
        exibirRecursivo(raiz);
    }
}

NoArvore* ArvoreBST::inserirRecursivo(NoArvore* no, Manga m) {
    if (no == nullptr) {
        NoArvore* novo = new NoArvore;
        strcpy(novo->genero, m.getGenero()); 
        
        novo->mangasDoGenero.inserirManga(m);
        
        novo->esquerda = nullptr;
        novo->direita = nullptr;
        return novo;
    }

    int comparacao = strcmp(m.getGenero(), no->genero);

    if (comparacao < 0) {
        no->esquerda = inserirRecursivo(no->esquerda, m);
    } 
    else if (comparacao > 0) {
        no->direita = inserirRecursivo(no->direita, m);
    } 
    else {
        no->mangasDoGenero.inserirManga(m);
    }

    return no;
}

void ArvoreBST::exibirRecursivo(NoArvore* no) {
    if (no != nullptr) {
        exibirRecursivo(no->esquerda);
        
        printf("\n>> Genero: %s\n", no->genero);
        printf("===================================\n");

        no->mangasDoGenero.imprimirLista(); 
        
        exibirRecursivo(no->direita);
    }
}

bool ArvoreBST::removerMangaDoGenero(const char* titulo, const char* genero) {
    NoArvore* temp = raiz;
    
    while (temp != nullptr) {
        int comparacao = strcmp(genero, temp->genero);
        
        if (comparacao == 0) {
            return temp->mangasDoGenero.removerManga(titulo);
        }
        else if (comparacao < 0) {
            temp = temp->esquerda;
        } else {
            temp = temp->direita;
        }
    }
    return false;
}