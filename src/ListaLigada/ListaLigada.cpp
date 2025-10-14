#include "ListaLigada.h"

#include <cstdio>

ListaLigada::ListaLigada(){
    this->cabeca = nullptr;
};

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