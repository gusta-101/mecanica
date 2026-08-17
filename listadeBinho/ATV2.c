#include <stdio.h>
#include <stdlib.h>
int main(){
    int maior,menor,num;
    int *maiorPTR=&maior;
    int *menorPTR=&menor;
    printf("Insira quantos valores terão na sua lista: ");

    scanf("%d",&num);
    printf("\n");
    int *valores=(int*) malloc(sizeof(int)*num);
    if(valores==NULL){
        printf("ERRO DE ALOCACAO"); 
        return 1;
    }

    for(int i=0;i<num;i++){
        printf("Insira seu %d valor: ",i+1);
        scanf("%d",&valores[i]);
        printf("\n");
        if(i==0){
            menor=valores[i];
            *menorPTR=&valores[i];
            maior=valores[i];
            *maiorPTR=&valores[i];
        }
        if(menor>valores[i]){menor=valores[i];*menorPTR=&valores[i];};
        if(maior<valores[i]){maior=valores[i];*maiorPTR=&valores[i];}
    }

    printf("Maior valor: %d\n Guardado na posicao: %p\n\n",maior,maior);
    printf("Menor valor: %d\n Guardado na posicao: %p\n",menor,menor);
    free(valores);
}