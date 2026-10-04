#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caminhao.h"

// A lista de entregas feitas pode continuar estática no dia do entregador
static ListaEntregasFeitas entregasFeitasHoje = { NULL };

int empilharCaminhao(PilhaCaminhao* caminhao, const NoPedido* pedido) {
    NoPedido* novo = (NoPedido*) malloc(sizeof(NoPedido));

    if (novo == NULL) {
        printf("\nErro ao alocar memoria para o caminhao.\n");
        return 1;
    }

    novo->NumPedido = pedido->NumPedido;
    strcpy(novo->Entrega, pedido->Entrega);

    novo->ProxNo = caminhao->topo;   
    caminhao->topo = novo;           

    printf("\nPedido #%d carregado no caminhao.\n", novo->NumPedido);
    return 0;
}

static NoPedido* desempilharCaminhao(PilhaCaminhao* caminhao) {
    if (caminhao == NULL || caminhao->topo == NULL) {
        return NULL;
    }

    NoPedido* removido = caminhao->topo;
    caminhao->topo = removido->ProxNo;   // o de baixo vira o topo
    removido->ProxNo = NULL;            // desliga o no da pilha
    return removido;
}

/* ---------- LISTA ENTREGAS_FEITAS_HOJE ---------- */

static void registrarEntregaFeita(NoPedido* pedido) {
    pedido->ProxNo = NULL;

    if (entregasFeitasHoje.inicio == NULL) {
        entregasFeitasHoje.inicio = pedido;
    } else {
        NoPedido* atual = entregasFeitasHoje.inicio;

        while (atual->ProxNo != NULL) {
            atual = atual->ProxNo;
        }

        atual->ProxNo = pedido;
    }
}

static void limparEntregasFeitas(void) {
    NoPedido* atual = entregasFeitasHoje.inicio;

    while (atual != NULL) {
        NoPedido* proximo = atual->ProxNo;
        free(atual);
        atual = proximo;
    }

    entregasFeitasHoje.inicio = NULL;
}

// Opção 1: mostra o topo do caminhão e pergunta se a entrega foi concluída
static void verProximaEntrega(PilhaCaminhao* caminhao) {
    int resposta;

    if (caminhao == NULL || caminhao->topo == NULL) {
        printf("\nO caminhao esta vazio. Nenhuma entrega pendente.\n");
        return;
    }

    printf("\n======== Proxima entrega ========\n");
    printf("Pedido #%d - Endereco: %s\n", caminhao->topo->NumPedido, caminhao->topo->Entrega);
    printf("Marcar como concluida?\n1- Sim\n2- Nao\n>> ");
    scanf("%d", &resposta);

    if (resposta == 1) {
        NoPedido* entregue = desempilharCaminhao(caminhao); // sai da pilha...
        if (entregue != NULL) {
            registrarEntregaFeita(entregue);                 // ...e vai para a lista
            printf("\nEntrega do pedido #%d concluida!\n", entregue->NumPedido);
        }

        if (caminhao->topo != NULL) {
            printf("Proxima entrega: Pedido #%d - Endereco: %s\n",
                   caminhao->topo->NumPedido, caminhao->topo->Entrega);
        } else {
            printf("Nao ha mais entregas no caminhao.\n");
        }
    } else {
        printf("\nEntrega mantida como pendente.\n");
    }
}

static void verEntregasFeitas(void) {
    NoPedido* atual = entregasFeitasHoje.inicio;
    int posicao = 1;

    printf("\n======================\nEntregas feitas hoje\n======================\n");

    if (atual == NULL) {
        printf("Nenhuma entrega concluida ainda.\n");
        return;
    }

    while (atual != NULL) {
        printf("%d- Pedido %d - endereco: %s\n", posicao, atual->NumPedido, atual->Entrega);
        printf("---------------------\n");
        atual = atual->ProxNo;
        posicao++;
    }
}

static void fecharDiaEntregas(void) {
    limparEntregasFeitas();
    printf("\nDia de entregas encerrado. Lista de entregas feitas esvaziada.\n");
}

void liberarCaminhao(PilhaCaminhao* caminhao) {
    NoPedido* pedido;

    while ((pedido = desempilharCaminhao(caminhao)) != NULL) {
        free(pedido);
    }

    limparEntregasFeitas();
}

/* ---------- MENU DO ENTREGADOR ---------- */

void Entregador(PilhaCaminhao* caminhao) {
    int user = 0;

    do {
        printf("\nEntregas\n\n"
               "1- Ver proxima entrega (Caminhao)\n"
               "2- Ver entregas feitas hoje\n"
               "3- Fechar dia de entregas\n"
               "0- Sair\n"
               ">> ");
        scanf("%d", &user);

        switch (user) {
            case 1:
                verProximaEntrega(caminhao);
                break;
            case 2:
                verEntregasFeitas();
                break;
            case 3:
                fecharDiaEntregas();
                break;
            case 0:
                printf("\nSaindo do menu do Entregador...\n");
                break;
            default:
                printf("\nOpcao Invalida\n=============================\n");
                break;
        }
    } while (user != 0);
}