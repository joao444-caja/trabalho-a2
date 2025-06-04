#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

#define N 1000
#define MAX_RANDOM 9999

void gerarvetor(int *vetor) {
    for (int i = 0; i < N; i++) {
        *(vetor + i) = rand() % MAX_RANDOM;
    }
}

void imprimirVetor(int *vetor, const char* descricao) {
    printf("\n%s\n", descricao);
    for (int i = 0; i < N; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}

void copiarvetor(int *origem, int *destino) {
    for (int i = 0; i < N; i++) {
        *(destino + i) = *(origem + i);
    }
}

void fetoresprincipais(int *vetor, const char* descricao) {
    printf("\n%s\n", descricao);
    printf("Primeiros 20:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\nUltimos 20:\n");
    for (int i = N - 20; i < N; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}

void bubblesort(int vetor[], int crescente) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if ((crescente && *(vetor + j) > *(vetor + j + 1)) ||
                (!crescente && *(vetor + j) < *(vetor + j + 1))) {
                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
                }
        }
    }
}

void selectionsort(int vetor[], int crescente) {
    for (int i = 0; i < N - 1; i++) {
        int indice_extremo = i;
        for (int j = i + 1; j < N; j++) {
            if ((crescente && *(vetor + j) > *(vetor + j + 1)) ||
                (!crescente && *(vetor + j) < *(vetor + j + 1))) {

                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
         }
       }
    }
}

int main() {
    srand(time(NULL));

    int *original = (int*)malloc(N * sizeof(int));
    int *v1 = (int*)malloc(N * sizeof(int));
    int *v2 = (int*)malloc(N * sizeof(int));


    gerarvetor(original);
    imprimirVetor(original, "Vetor original:");

    copiarvetor(original, v1);
    bubblesort(v1, 1);
    imprimirVetor(v1, "Vetor ordenado com Bubble Sort (crescente):");
    fetoresprincipais(v1, "Elementos principais do Bubble Sort (crescente):");

    copiarvetor(original, v2);
    bubblesort(v2, 0);
    imprimirVetor(v2, "Vetor ordenado com Bubble Sort (decrescente):");
    fetoresprincipais(v2, "Elementos principais do Bubble Sort (decrescente):");

    copiarvetor(original, v1);
    selectionsort(v1, 1);
    imprimirVetor(v1, "Vetor ordenado com Selection Sort (crescente):");
    fetoresprincipais(v1, "Elementos principais do Selection Sort (crescente):");

    copiarvetor(original, v2);
    selectionsort(v2, 0);
    imprimirVetor(v2, "Vetor ordenado com Selection Sort (decrescente):");
    fetoresprincipais(v2, "Elementos principais do Selection Sort (decrescente):");

    free(original);
    free(v1);
    free(v2);

    return 0;
}  