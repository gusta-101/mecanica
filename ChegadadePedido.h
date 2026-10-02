#ifndef CHEGADADE_PEDIDO_H
#define CHEGADADE_PEDIDO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int NumPedido;             
    struct No* proximo;    
} No;

typedef struct {
    No* inicio;
} ListaNovaEntrada;

void Estoquista();
void inicializarListaNovaEntrada(ListaNovaEntrada* lista);
int novopacote(ListaNovaEntrada* lista);
void verPranchetaEntrada(ListaNovaEntrada* lista);
void liberarListaNovaEntrada(ListaNovaEntrada* lista);

#endif
