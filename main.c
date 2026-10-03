#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaGlobal.h"
#include "ChegadadePedido.h"

void iniciarlista(Prancheta* p, FilaEsteira* e) {
    p->inicio = NULL;
    e->inicio = NULL;
    e->fim = NULL;
}

int main() {
    Prancheta prancheta;
    FilaEsteira esteira;

    iniciarlista(&prancheta, &esteira);

    int user = 9;
    int IdDoPedido = 1;

    do {
        printf("\nLogar como...\n");
        printf("1-> Estoquista\n");
        printf("2-> Entregador\n");
        printf("0-> Sair\n");
        printf(">> ");
        scanf("%d", &user);

        switch (user) {
            case 1: 
                // Passa o endereço &IdDoPedido para que o incremento persista
                Estoquista(&IdDoPedido, &esteira, &prancheta);
                break;
            case 2:
                /* Módulo Entregador */
                break;
            case 0:
                printf("\nPrograma Encerrando...\n");
                break;
            default:
                printf("\nOpção inválida\n");
                break;
        }
    } while (user != 0);

    return 0;
}