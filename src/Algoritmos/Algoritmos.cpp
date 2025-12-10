#include "Algoritmos.h"
#include <cstring>

void trocar(Manga** a, Manga** b) {
    Manga* temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(Manga* vetor[], int baixo, int alto) {
    const char* pivo = vetor[alto]->getTitulo();
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (strcmp(vetor[j]->getTitulo(), pivo) < 0) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}

void quicksort(Manga* vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(vetor, baixo, alto);

        quicksort(vetor, baixo, pi - 1);
        quicksort(vetor, pi + 1, alto);
    }
}

int buscaBinaria(Manga* vetor[], int tamanho, const char* tituloBusca) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        int res = strcmp(vetor[meio]->getTitulo(), tituloBusca);

        if (res == 0) return meio;

        if (res < 0) inicio = meio + 1;

        else fim = meio - 1;
    }

    return -1;
}