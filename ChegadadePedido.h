#ifndef CHEGADA_DE_PEDIDO_H
#define CHEGADA_DE_PEDIDO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. NÓ DO PEDIDO
typedef struct NoPedido {
    int NumPedido;
    char Entrega[50];
    struct NoPedido* ProxNo;
} NoPedido;

// 2. PRANCHETA (Lista Simples)
typedef struct {
    NoPedido* inicio;
} Prancheta;

// 3. ESTEIRA (Fila)
typedef struct {
    NoPedido* inicio;
    NoPedido* fim;
} FilaEsteira;

// Protótipos das funções
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido);
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta);
void verPranchetaEntrada(Prancheta* lista);

#endif
