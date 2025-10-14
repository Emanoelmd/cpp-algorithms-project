#include "src/Manga/Manga.h"
#include "src/ListaLigada/ListaLigada.h"

#include <cstdio>
#include <cstring>

void exibirMenu(){
    printf("===== Minha Coleção de Mangás =====\n");
    printf("1. Adicionar um novo mangá\n");
    printf("2. Listar todos os mangá\n");
    printf("0. Sair\n");
    printf("===================================\n");
    printf("Escolha uma das opções a cima: \n");
    printf("===================================");

};

int main(){
    ListaLigada colecao;
    int opcao;

    while (true){
        exibirMenu();
        scanf("%d", &opcao);

        //Adicionar um novo mangá
        if(opcao == 1){
            char titulo_local[100];
            char autor_local[50];
            char genero_local[50];
            int volumes_local;
            float nota_local;
 
            printf("Digite o nome do mangá: \n");
            scanf("%s", titulo_local);
            printf("Digite o nome do autor do mangá: \n");
            scanf("%s", autor_local);
            printf("Digite o genero do mangá: \n");
            scanf("%s", genero_local);
            printf("Digite a quantidade de volumes do mangá: \n");
            scanf("%d", &volumes_local);
            printf("Digite a nota que você acredita que esse mangá merece: \n");
            scanf("%f", &nota_local);

            Manga novoManga(titulo_local, autor_local, genero_local, volumes_local, nota_local);
            colecao.inserirManga(novoManga);

        //Mostrando lista de mangá
        }else if(opcao == 2){
            colecao.imprimirLista();

        //Encerrando o menu
        }else if(opcao == 0){
            printf("Encerrando...");
            
            return 0;

        }else{
            printf("Opção Inválida.");
        }
    }

    return 0;
}