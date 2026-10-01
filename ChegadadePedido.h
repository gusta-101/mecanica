#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int NumPedido;             
    struct No* proximo;    
} No;

typedef struct {
    No* inicio;
} ListaNovaEntrada;

int novopacote(No* NovoPedido, ListaNovaEntrada* Lista);