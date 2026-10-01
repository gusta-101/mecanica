#include "bibliotecaGlobal.h"

int main(){
    int user=9;

    do{
        printf("\nLogar como...\n");
        printf("1->Estoquista\n");
        printf("2-> Entregador\n");
        printf("0-> Sair\n");
        scanf("%d",&user);
        switch (user){
        case '1':
            Estoquista();
            break;
        case '2':
            /* code */
            break;
        case '0':
            printf("\nPrograma Encerrando...");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    }while(user!=0);
}