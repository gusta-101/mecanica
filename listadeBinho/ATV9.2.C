#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100000000

int main() {
    int *vetor = (int *) calloc(TAMANHO, sizeof(int));
    if (vetor == NULL) return 1;

    long long soma = 0;
    for (size_t i = 0; i < TAMANHO; i++) {
        soma += vetor[i];
    }

    printf("Soma (calloc): %lld\n", soma);
    free(vetor);
    return 0;
}