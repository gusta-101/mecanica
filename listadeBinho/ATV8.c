#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);

    if (linhas <= 0 || colunas <= 0) {
        printf("Dimensoes invalidas!\n");
        return 1;
    }

    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("ERRO DE ALOCAMENTO NAS LINHAS\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("ERRO DE ALOCAMENTO NA COLUNA %d\n", i);
            return 1;
        }
    }

    printf("\nPreencha os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz Completa\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    int soma_total = 0;
    int maior = matriz[0][0];

    printf("\n--- Soma de Cada Linha ---\n");
    for (int i = 0; i < linhas; i++) {
        int soma_linha = 0;
        for (int j = 0; j < colunas; j++) {
            soma_linha += matriz[i][j];
            soma_total += matriz[i][j];

            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
        printf("Soma da linha %d: %d\n", i + 1, soma_linha);
    }

    printf("\nResultados Gerais:\n");
    printf("Soma de todos os elementos: %d\n", soma_total);
    printf("Maior elemento da matriz: %d\n", maior);

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}