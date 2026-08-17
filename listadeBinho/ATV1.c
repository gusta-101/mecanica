#include <stdio.h>
#include <stdlib.h>

int main(){
    int quant;
    int *valores;
    printf("Insira a quantidade de valores\n");
    scanf("%d",&quant);
    valores=(int*) malloc(quant * sizeof(int));
    for(int i=0;i<quant;i++){
        if(valores==NULL){
            printf("ERRO DE ALOCAÇAO ESPACO\n");
            return 1;
        }
        printf("Insira o %d valor: ",i+1);
        scanf("%d",&valores[i]);
    }
    printf("\n\nSeus Valores:\n");

    for(int i=0;i<quant;i++){
        printf("%d\n",valores[i]);
    }
    free(valores);
    return 0;
}