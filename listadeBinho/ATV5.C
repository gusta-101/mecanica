#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,numpar=0,numimpar=0;
    printf("Insira quantos valores voce deseja colocar: ");
    scanf("%d",&num);
    int *vetor=(int*) malloc(sizeof(int)*num);
    if (vetor==NULL){
        printf("ERRO DE ALOCAMENTO");
        return 1;
    }
    
    for(int i=0;i<num;i++){
        printf("\nInsira o valor n.%d\n",i+1);
        scanf("%d",&vetor[i]);
        if(vetor[i]%2==0){
            numpar++;
        }else if(vetor[i]%2!=0){
            numimpar++;
        }
    }

    int *impar=(int*) malloc(sizeof(int) *numimpar);
    int *par=(int*) malloc(sizeof(int) *numpar);
    if(impar==NULL||par==NULL){
        printf("ERRO DE ALOCAMENTO");
        return 1;
    }

    int imprcont=0,parcont=0;
    for(int i=0;i<num;i++){
        if(vetor[i]%2==0){
            par[parcont]=vetor[i];
            parcont++;
        }else{
            impar[imprcont]=vetor[i];
            imprcont++;
        }
    }

    printf("Numeros impares:\n");
    for(int i=0;i<imprcont;i++){
        printf("%d\n",impar[i]);
    }
    printf("\nNumeros impares:\n");
    for(int i=0;i<parcont;i++){
        printf("%d \n",par[i]);
    }
}