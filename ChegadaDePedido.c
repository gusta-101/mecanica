#include "ChegadadePedido.h"

void Estoquista(){
    int user;
    int novopacote(No* NovoPedido, ListaNovaEntrada* Lista){
        printf("\nInsira o ID do pacote:\n");
        scanf("%d",&NovoPedido->NumPedido);
        return 0;
    }
    do{
        printf("\nChegada e Envio\n\n"
           "1- Registrar chegada de pacote\n"
           "2- Ver prancheta de entrada\n"
           "3- Operar esteira rolante (Fila)\n"
           "|-> Empilhar: Move o primeiro valor da Esteira (Fila) para Transportadora (fila) e apaga o nome dela da Prancheta (Lista Simples).\n\n"
           "4- Despachar para o caminhão (Pilha)\n"
           "5- Sair\n");
           scanf("%d",&user);
            switch (user)
            {
            case '1':
                /* code */
                break;
            case '2':
                /* code */
                break;
            case '3':
                /* code */
                break;
            case '4':
                /* code */
                break;
            case '5':
                /* code */
                break;
            
            default:
                printf("\nOpcao Invalida\n=============================\n");
                break;
            }



    }while(user!=5);
}