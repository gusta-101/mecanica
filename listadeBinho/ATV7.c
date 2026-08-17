#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("escreva o tamanho de sua lista:\n");
    scanf("%d", &n);
    int *num = malloc(n * sizeof(int));
    
    if(num == NULL){
        printf("\nERRO DE ALOCAMENTO");
        return 1;
    }

    printf("preencha sua lista:\n");
    for(int i = 0; i < n; i++){
        printf("\nInsira o %d valor: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("insira a posicao do numero que voce deseja remover:\n");
    int redu;
    scanf("%d", &redu);
    while(redu < 1 || redu > n){
        printf("valor invalido, fora dos limites da lista.\nInsira novamente:\n");
        scanf("%d", &redu);
    }
    
    for(int i = redu - 1; i < n - 1; i++){
        num[i] = num[i + 1];
    }

    n--;
    num = (int*) realloc(num, n * sizeof(int));

    printf("\nLista Atual:");
    for(int i = 0; i < n; i++){
        printf("\n %d valor: %d", i + 1, num[i]);
    }

    free(num);
    return 0;
}