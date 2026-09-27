#ifndef MECANICA_PEDIDOS_H
#define MECANICA_PEDIDOS_H

typedef struct Pedido {
	int codigo;
	char cliente[100];
	char veiculo[100];
	char servico[100];
} Pedido;

typedef struct NoFila {
	Pedido pedido;
	struct NoFila *proximo;
} NoFila;

typedef struct Fila {
	NoFila *inicio;
	NoFila *fim;
	int quantidade;
} Fila;

typedef struct NoPilha {
	Pedido pedido;
	struct NoPilha *proximo;
} NoPilha;

typedef struct Pilha {
	NoPilha *topo;
	int quantidade;
} Pilha;

/* 1 - Cadastrar pedido */
void cadastrarPedido(Fila *fila);

/* 2 - Ver lista de pedidos pendentes */
void listarPedidosPendentes(const Fila *fila);

/* 3 - Ver pedido atual (fila) */
void verPedidoAtual(Fila *fila, Pilha *historico);
void marcarPedidoComoConcluido(Fila *fila, Pilha *historico);
void voltarParaFila(Fila *fila);

/* 4 - Desmarcar pedido anterior (pilha) */
void desmarcarPedidoAnterior(Fila *fila, Pilha *historico);

#endif
