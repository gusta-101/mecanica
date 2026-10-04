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

<<<<<<< HEAD
// Esteira (Fila)
typedef struct {
    NoPedido* inicio;
    NoPedido* fim;
} FilaEsteira;
=======
typedef struct {
    No* inicio;
    No* fim;
} FilaEsteira;

void Estoquista();
void inicializarListaNovaEntrada(ListaNovaEntrada* lista);
void inicializarFilaEsteira(FilaEsteira* fila);
int novopacote(ListaNovaEntrada* lista, FilaEsteira* fila);
void verPranchetaEntrada(ListaNovaEntrada* lista);
void verPrimeiraCaixaEsteira(FilaEsteira* fila);
void liberarListaNovaEntrada(ListaNovaEntrada* lista);
void liberarFilaEsteira(FilaEsteira* fila);
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)

// Protótipos das funções
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido);
void verPranchetaEntrada(Prancheta* lista);
void operarEsteira(FilaEsteira* esteira);
void DespacharParaCaminhao(FilaEsteira* esteira, Prancheta* prancheta, PilhaCaminhao* caminhao);
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta, PilhaCaminhao* caminhao);

#endif