#include "ListaLigada.h"

#include <cstdio>
#include <fstream>

ListaLigada::ListaLigada(){
    this->cabeca = nullptr;
};

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

void ListaLigada::salvarEmArquivo(const char* nomeArquivo){
    FILE* arquivo;
    

    arquivo = fopen("colecao_manga.txt", "w");
    
    if(arquivo == NULL){
        
        printf("O arquivo não está funcionando.");

        return;
    }
    No* temp = cabeca;
    while(temp != nullptr){
        fprintf(arquivo, "%s\n", temp->manga.getTitulo());
        fprintf(arquivo, "%s\n", temp->manga.getAutor());
        fprintf(arquivo, "%s\n", temp->manga.getGenero());
        fprintf(arquivo, "%d\n", temp->manga.getVolumes());
        fprintf(arquivo, "%.1f\n", temp->manga.getNota());

        temp = temp->proximo;
    }

    fclose(arquivo);
}

void ListaLigada::carregarDeArquivo(const char* nomeArquivo){
    FILE* arquivo;
    
    arquivo = fopen("colecao_manga.txt", "r");

    if(arquivo == NULL){

        return;
    }

    char titulo_l[100];
    char autor_l[50];
    char genero_l[50];
    int volumes_l;
    float nota_l;

    while (fscanf(arquivo, "%s", titulo_l) == 1) {
        
        fscanf(arquivo, "%s", autor_l);
        fscanf(arquivo, "%s", genero_l);
        fscanf(arquivo, "%d", &volumes_l);
        fscanf(arquivo, "%f", &nota_l);

        Manga novoManga(titulo_l, autor_l, genero_l, volumes_l, nota_l);

        this->inserirManga(novoManga);
    }

    fclose(arquivo);
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

