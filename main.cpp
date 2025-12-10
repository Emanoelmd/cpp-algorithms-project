#include "src/Manga/Manga.h"
#include "src/ListaLigada/ListaLigada.h"
#include "src/Arvore/ArvoreBST.h"

#include <cstdio>
#include <cstring>

void exibirMenu(){
    printf("===== Minha Colecao de mangas =====\n");
    printf("1. Adicionar um novo manga\n");
    printf("2. Listar todos os manga\n");
    printf("3. Listar ordenado por Titulo (A-Z)\n");
    printf("4. Buscar manga por Titulo\n");
    printf("5. Listar por Genero\n");
    printf("0. Sair\n");
    printf("===================================\n");
    printf("Escolha uma das opcoes a cima: ");
};

int main(){
    ListaLigada colecao;
    ArvoreBST indiceGeneros;

    colecao.carregarDeArquivo("colecao_manga.txt");
    int opcao;
    
    while (true){
        exibirMenu();
        scanf("%d", &opcao);

        //Adicionar um novo manga
        if(opcao == 1){
            char titulo_local[100];
            char autor_local[50];
            char genero_local[50];
            int volumes_local;
            float nota_local;
 
            printf("Digite o nome do manga: ");
            scanf("%s", titulo_local);
            printf("Digite o nome do autor do manga: ");
            scanf("%s", autor_local);
            printf("Digite o genero do manga: ");
            scanf("%s", genero_local);
            printf("Digite a quantidade de volumes do manga: ");
            scanf("%d", &volumes_local);
            printf("Digite a nota que voce acredita que esse manga merece: ");
            scanf("%f", &nota_local);

            Manga novoManga(titulo_local, autor_local, genero_local, volumes_local, nota_local);
            colecao.inserirManga(novoManga);
            indiceGeneros.adicionarManga(novoManga);

        }else if(opcao == 2){
            colecao.imprimirLista();

        }else if (opcao == 3) {
            colecao.listarPorTitulo();

        }else if (opcao == 4) {
            char busca[100];
            printf("Digite o titulo para buscar: ");
            scanf(" %[^\n]", busca);
            colecao.buscarPorTitulo(busca);

        }   
         else if (opcao == 5) {
            indiceGeneros.exibirPorGenero();

        }else if(opcao == 0){
            printf("Encerrando...");

            colecao.salvarEmArquivo("colecao_manga.txt");

            return 0;

        }else{
            printf("Opcao Invalida.");
        }
    }

    return 0;
}