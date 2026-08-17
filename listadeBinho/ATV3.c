#include <stdio.h>
#include <stdlib.h>

float media(int n,float vetor[n]){
    int total=0;
    for(int i=0;i<n;i++){
        printf("Insira o %d valor de sua lista:",i+1);
        scanf("%f",&vetor[i]);
        total=total+vetor[i];
        printf("\n");
    }
    float medi=total/n;
   printf("A media e %.1f\nOs valores que estao acima da media sao:\n",medi);
    for(int i=0;i<n;i++){
        if(vetor[i]>medi){
            printf("%.1f\n",vetor[i]);
        }
        
    }
    return 0;
}
int main(){
    int num;
    printf("Quantos valores terao na sua lista?\n");
    scanf("%d",&num);
    int *vetor= malloc(num * sizeof(float));
    if(vetor==NULL){
        printf("ERRO DE ALOCACAO");
        return 1;
    }
    media(num,vetor);
    free(vetor);
    return 0;
}
