#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "ChegadadePedido.h" 

typedef struct PilhaCaminhao {
    NoPedido* topo;
} PilhaCaminhao;

typedef struct ListaEntregasFeitas {
    NoPedido* inicio;
} ListaEntregasFeitas;

void Entregador(PilhaCaminhao* caminhao);

int empilharCaminhao(PilhaCaminhao* caminhao, const NoPedido* pedido);
void liberarCaminhao(PilhaCaminhao* caminhao);

#endif