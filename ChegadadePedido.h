#ifndef CHEGADA_DE_PEDIDO_H
#define CHEGADA_DE_PEDIDO_H

#include "bibliotecaGlobal.h"

//Nó do Pedido
typedef struct NoPedido {
    int NumPedido;
    char Entrega[100];
    struct NoPedido* ProxNo;
} NoPedido;

//Prancheta Lista Simples
typedef struct {
    NoPedido* inicio;
} Prancheta;

//Esteira(Fila) 
typedef struct {
    NoPedido* inicio;
    NoPedido* fim;
} FilaEsteira;

// Estoquista
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta);
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido);
void verPranchetaEntrada(Prancheta* lista);



#endif