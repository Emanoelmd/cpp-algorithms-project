#include "ListaLigada.h"

#include <cstdio>

ListaLigada::ListaLigada(){
    this->inicio = nullptr;
};

void ListaLigada::inserirManga(Manga novo_manga){
    No* inicio_n = new No;
    inicio_n->manga = novo_manga;
    inicio_n->proximo = nullptr;
    if (inicio == nullptr){
        inicio = inicio_n;
    }else{
        No* temp = inicio;
        while (temp->proximo != nullptr){
            temp = temp->proximo;
        }
        temp->proximo = inicio_n;
    }
}

void ListaLigada::imprimirLista(){
    
}
