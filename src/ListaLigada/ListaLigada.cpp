#include "ListaLigada.h"
#include "../Algoritmos/Algoritmos.h"

#include <cstdio>
#include <fstream>

ListaLigada::ListaLigada(){
    this->cabeca = nullptr;
};

int ListaLigada::contarElementos() {
    int cont = 0;
    No* temp = cabeca;
    while(temp != nullptr) {
        cont++;
        temp = temp->proximo;
    }
    return cont;
}

void ListaLigada::inserirManga(Manga novo_manga){
    No* nova_c = new No(novo_manga);
    nova_c->manga = novo_manga;
    nova_c->proximo = nullptr;
    if (cabeca == nullptr){
        cabeca = nova_c;
    }else{
        No* temp = cabeca;
        while (temp->proximo != nullptr){
            temp = temp->proximo;
        }
        temp->proximo = nova_c;
    }
}

void ListaLigada::imprimirLista(){
    No* temp = cabeca;
    if(cabeca == nullptr){
        printf("Não tem nenhuma mangá registrado.\n");

        return;
    }else{
        while (temp != nullptr){
            temp-> manga.imprimirDetalhes();
            temp = temp->proximo;
        }
    }
    
}

ListaLigada::~ListaLigada() {
    
    No* no_atual = this->cabeca;
    No* proximo_no = nullptr;

    while (no_atual != nullptr) {
        proximo_no = no_atual->proximo;
        delete no_atual;
        no_atual = proximo_no;
    }

    this->cabeca = nullptr;
}

void ListaLigada::listarPorTitulo() {
    int n = contarElementos();
    if (n == 0) {
        printf("Lista vazia.\n");
        return;
    }

    Manga** vetor = new Manga*[n];
    
    No* temp = cabeca;
    for(int i=0; i<n; i++) {
        vetor[i] = &(temp->manga);
        temp = temp->proximo;
    }

    quicksort(vetor, 0, n-1);

    printf("\n--- MANGÁS ORDENADOS POR TÍTULO (A-Z) ---\n");
    for(int i=0; i<n; i++) {
        vetor[i]->imprimirDetalhes();
    }

    delete[] vetor;
}

void ListaLigada::buscarPorTitulo(const char* titulo) {
    int n = contarElementos();
    if (n == 0) {
        printf("Lista vazia.\n");
        return;
    }

    Manga** vetor = new Manga*[n];
    No* temp = cabeca;
    for(int i=0; i<n; i++) {
        vetor[i] = &(temp->manga);
        temp = temp->proximo;
    }

    quicksort(vetor, 0, n-1);

    int indice = buscaBinaria(vetor, n, titulo);

    if (indice != -1) {
        printf("\nMangá Encontrado:\n");
        vetor[indice]->imprimirDetalhes();
    } else {
        printf("\nMangá '%s' não encontrado.\n", titulo);
    }

    delete[] vetor;
}