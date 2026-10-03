#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChegadadePedido.h"

// 1. Cadastra pacote na Prancheta (Lista) e na Esteira (Fila)
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido) {
    NoPedido* EntregaNova = (NoPedido*) malloc(sizeof(NoPedido));
    NoPedido* noPrancheta = (NoPedido*) malloc(sizeof(NoPedido));

    if (EntregaNova == NULL || noPrancheta == NULL) {
        printf("\nErro ao alocar memoria para o pedido.\n");
        return;
    }

    printf("\n===================================");
    printf("\nInsira o endereco de entrega do pacote: ");
    scanf(" %[^\n]", EntregaNova->Entrega);

    strcpy(noPrancheta->Entrega, EntregaNova->Entrega);

    printf("ID do pacote gerado: %d\n", *IdDoPedido);
    noPrancheta->NumPedido = *IdDoPedido;
    EntregaNova->NumPedido = *IdDoPedido;

    EntregaNova->ProxNo = NULL;

    // Inserção na Prancheta (Lista Simples - Início)
    noPrancheta->ProxNo = prancheta->inicio;
    prancheta->inicio = noPrancheta;

    // Inserção na Esteira (Fila FIFO - Fim)
    if (esteira->inicio == NULL) {
        esteira->inicio = EntregaNova;
        esteira->fim = EntregaNova;
    } else {
        esteira->fim->ProxNo = EntregaNova;
        esteira->fim = EntregaNova;
    }

    printf("======== Pedido Cadastrado ========\n");

    (*IdDoPedido)++;
}

// 2. Exibe os elementos da Prancheta
void verPranchetaEntrada(Prancheta* lista) {
    NoPedido* atual = lista->inicio;
    int posicao = 1;

    printf("\n======================\nPrancheta de entrada\n======================\n");

    if (atual == NULL) {
        printf("Nenhum pedido chegou ainda.\n");
        return;
    }

    while (atual != NULL) {
        printf("-Pedido #%d - Endereco: %s\n", atual->NumPedido, atual->Entrega);
        atual = atual->ProxNo;
        posicao++;
        printf("---------------------\n");
    }
}



// Módulo Estoquista
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta) {
    int user = 0;

    do {
        printf("\nChegada e Envio\n\n"
               "1- Registrar chegada de pacote\n"
               "2- Ver prancheta de entrada\n"
               "3- Operar esteira rolante (Fila)\n"
               "4- Despachar para o caminhão (Pilha)\n"
               "0- Sair\n"
               ">> ");
        scanf("%d", &user);

        switch (user) {
            case 1:
                novopacote(prancheta, esteira, IdDoPedido);
                break;
            case 2:
                verPranchetaEntrada(prancheta);
                break;
            case 3:
                
                break;
            case 4:
                /* A implementar: Despachar para o caminhão */
                break;
            case 0:
                printf("\nSaindo do menu do Estoquista...\n");
                break;
            default:
                printf("\nOpcao Invalida\n=============================\n");
                break;
        }

    } while (user != 0);
}
