#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaGlobal.h"
#include "ChegadadePedido.h"
#include "caminhao.h"

void iniciarlista(Prancheta* p, FilaEsteira* e,PilhaCaminhao* c) {
    p->inicio = NULL;
    e->inicio = NULL;
    e->fim = NULL;
    c->topo = NULL;
}

int main() {
    Prancheta prancheta;
    FilaEsteira esteira;
    PilhaCaminhao caminhao;
    iniciarlista(&prancheta, &esteira,&caminhao);

    int user = 9;
    int IdDoPedido = 1;

    do {
        printf("\nLogar como...\n");
        printf("1-> Estoquista\n");
        printf("2-> Entregador\n");
        printf("0-> Sair\n>> ");
        scanf("%d",&user);
        switch (user){
        case 1:
        
            Estoquista(&IdDoPedido, &esteira, &prancheta,&caminhao);
            break;
        case 2:
            Entregador(&caminhao);
            break;
        case 0:
            printf("\nPrograma Encerrando...");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (user != 0);

    return 0;
}
