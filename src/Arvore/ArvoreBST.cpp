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
        printf("A árvore de gêneros está vazia.\n");
    } else {
        printf("\n==============================\n");
        printf("   ÍNDICE POR GÊNEROS (A-Z)   \n");
        printf("==============================\n");
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
        
        printf("\n>> GÊNERO: %s\n", no->genero);
        printf("--------------------\n");

        no->mangasDoGenero.imprimirLista(); 
        
        exibirRecursivo(no->direita);
    }
}