#ifndef CHEGADA_DE_PEDIDO_H
#define CHEGADA_DE_PEDIDO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward Declaration (Avisa que a struct existe)
typedef struct PilhaCaminhao PilhaCaminhao;

// Nó do Pedido
typedef struct NoPedido {
    int NumPedido;
    char Entrega[100];
    struct NoPedido* ProxNo;
} NoPedido;

// Prancheta (Lista)
typedef struct {
    NoPedido* inicio;
} Prancheta;

// Esteira (Fila)
typedef struct {
    NoPedido* inicio;
    NoPedido* fim;
} FilaEsteira;

// Protótipos das funções
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta, PilhaCaminhao* caminhao);

void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido);
void verPranchetaEntrada(Prancheta* lista);
void verPrimeiraCaixaEsteira(FilaEsteira* fila);
void DespacharParaCaminhao(FilaEsteira* esteira, Prancheta* prancheta, PilhaCaminhao* caminhao);
#endif