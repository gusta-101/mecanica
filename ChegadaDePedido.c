#include "ChegadadePedido.h"

void inicializarListaNovaEntrada(ListaNovaEntrada* lista){
    lista->inicio = NULL;
}

int novopacote(ListaNovaEntrada* lista){
    No* novoPedido = (No*) malloc(sizeof(No));

    if(novoPedido == NULL){
        printf("\nErro ao alocar memoria para o pedido.\n");
        return 1;
    }

    printf("\nInsira o ID do pacote:\n");
    scanf("%d", &novoPedido->NumPedido);
    novoPedido->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novoPedido;
    } else {
        No* atual = lista->inicio;

        while(atual->proximo != NULL){
            atual = atual->proximo;
        }

        atual->proximo = novoPedido;
    }

    printf("\nPedido %d registrado na prancheta de entrada.\n", novoPedido->NumPedido);
    return 0;
}

void verPranchetaEntrada(ListaNovaEntrada* lista){
    No* atual = lista->inicio;
    int posicao = 1;

    printf("\nPrancheta de entrada\n");

    if(atual == NULL){
        printf("Nenhum pedido chegou ainda.\n");
        return;
    }

    while(atual != NULL){
        printf("%d- Pedido %d\n", posicao, atual->NumPedido);
        atual = atual->proximo;
        posicao++;
    }
}

void liberarListaNovaEntrada(ListaNovaEntrada* lista){
    No* atual = lista->inicio;

    while(atual != NULL){
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
}

void Estoquista(){
    int user;
    ListaNovaEntrada listaEntrada;

    inicializarListaNovaEntrada(&listaEntrada);

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
            case 1:
                novopacote(&listaEntrada);
                break;
            case 2:
                verPranchetaEntrada(&listaEntrada);
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                printf("\nVoltando ao menu principal...\n");
                break;
            
            default:
                printf("\nOpcao Invalida\n=============================\n");
                break;
            }



    }while(user!=5);

    liberarListaNovaEntrada(&listaEntrada);
}
