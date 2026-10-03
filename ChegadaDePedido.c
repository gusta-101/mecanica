#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChegadadePedido.h"

// 1. Cadastrar Pacote (Insere na Prancheta [Lista] e na Esteira [Fila])
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido) {
    NoPedido* EntregaNova = (NoPedido*) malloc(sizeof(NoPedido));
    NoPedido* noPrancheta = (NoPedido*) malloc(sizeof(NoPedido)); 

    printf("\n===================================");
    printf("\nInsira o endereco de entrega do pacote: ");
    scanf(" %[^\n]", EntregaNova->Entrega); 
    
    strcpy(noPrancheta->Entrega, EntregaNova->Entrega);

    printf("\nID do pacote gerado: %d\n", *IdDoPedido);
    noPrancheta->NumPedido = *IdDoPedido;
    EntregaNova->NumPedido = *IdDoPedido;

    EntregaNova->ProxNo = NULL; 

    // Inserção na Prancheta (Lista Simples - no início)
    noPrancheta->ProxNo = prancheta->inicio;
    prancheta->inicio = noPrancheta;

    // Inserção na Esteira (Fila FIFO - no fim)
    if (esteira->inicio == NULL) {
        esteira->inicio = EntregaNova;
        esteira->fim = EntregaNova;
    } else {
        esteira->fim->ProxNo = EntregaNova;
        esteira->fim = EntregaNova;
    }

    printf("========== Pedido Cadastrado ==========\n");

    (*IdDoPedido)++;
}

// 2. Visualizar histórico da Prancheta
void verPranchetaEntrada(Prancheta* lista) {
    NoPedido* atual = lista->inicio;
    int posicao = 1;

    printf("\n======================\nPrancheta de entrada\n======================\n");

    if (atual == NULL) {
        printf("Nenhum pedido chegou ainda.\n");
        return;
    }

    while (atual != NULL) {
        printf("-Pedido #%d - Endereço: %s\n", atual->NumPedido, atual->Entrega);
        atual = atual->ProxNo;
        posicao++;
        printf("---------------------------------------------------\n");
    }
}

// 3. Visualizar e desenfileirar pacote da Esteira



// Menu principal do módulo Estoquista
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta) {
    int Estoquser = 3;
    do {
        printf("\n=========================\nChegada e Envio\n=========================\n"
               "1- Registrar chegada de pacote\n"
               "2- Ver prancheta de entrada\n"
               "3- Operar esteira rolante (Fila)\n"
               "4- Despachar para o caminhão (Pilha)\n"
               "0- Sair\n"
               ">> ");
        scanf("%d", &Estoquser);

        switch (Estoquser) {
            case 1:
                novopacote(prancheta, esteira, IdDoPedido);
                break;
            case 2:
                verPranchetaEntrada(prancheta);
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 0:
                printf("\nSaindo do menu do Estoquista...\n");
                break;
            default:
                printf("\nOpção Inválida\n=============================\n");
                break;
        }

    } while (Estoquser != 0);
}