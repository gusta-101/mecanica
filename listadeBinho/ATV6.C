#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int alocamento(int quant,int vet[]){
    printf("insira os valores na lista de %d numeros:\n",quant);
    for(int i=0;i<quant;i++){
        printf("n.%d- ",i+1);
        scanf("%d",&vet[i]);
        printf("\n");
    }
    printf("Sua lista atual possui atualmente %d espaços, deseja modificar o tamanho dela? (S para sim e N para nao)\n",quant);
    char user;
    scanf(" %c",&user);
    switch (user){
    case 'S':
    case 's':
        int temp;
        bool confirm=false;
        while(confirm==false){

            printf("\nInsira a quantidade de valores que deseja aumenta ou diminuir na sua lista: \n");
            scanf("%d",&temp);
            if(quant+temp<=0){
            printf("Valor invalido! Digite novamente\n");
            }else{
                quant=quant+temp;
                vet=realloc(vet, sizeof(int) * quant); 
                printf("\n Modificação salva\n");
                alocamento(quant,vet);
            }
        }   
        break;
    
    default:
        printf("\nLista salva com sucesso");
        break;
    }
    return 0;
}

int main(){
    int quant=5;
    int *vet=(int*) malloc(quant*sizeof(int));
    if(vet==NULL){
        printf("ERRO DE ALOCAMENTO");
        return 1;
    }
    alocamento(quant,vet);
free(vet);
vet=NULL;
return 0;
}