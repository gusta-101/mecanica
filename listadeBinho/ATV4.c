#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("insira o tamanho da lista: \n");
    scanf("%d",&n);
    printf("\n");
    int *point=(int*)malloc(n*sizeof(int));
    if(point==NULL){
        printf("ERRO DE ALOCAMENTO");
        return 1;
    }
    for(int i=0;i<n;i++){
        printf("valor n. %d: ",i+1);
        scanf("%d",&point[i]);
        printf("\n");
    }
    printf("Lista inversa:\n");
    for(int i=n-1;i>=0;i--){
        printf("%d",point[i]);
        printf("\n");
    }

    free(point);
    return 1;

}
