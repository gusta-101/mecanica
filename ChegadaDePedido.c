
#include "ChegadadePedido.h"
#include "caminhao.h"

// 1. Cadastra pacote na Prancheta (Lista) e na Esteira (Fila)
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido) {
    NoPedido* EntregaNova = (NoPedido*) malloc(sizeof(NoPedido));
    NoPedido* noPrancheta = (NoPedido*) malloc(sizeof(NoPedido));

<<<<<<< HEAD
    if (EntregaNova == NULL || noPrancheta == NULL) {
=======
void inicializarFilaEsteira(FilaEsteira* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

static void limparEntrada(){
    int caractere;

    while((caractere = getchar()) != '\n' && caractere != EOF){
    }
}

static int lerInteiro(int* valor){
    if(scanf("%d", valor) != 1){
        limparEntrada();
        return 0;
    }

    return 1;
}

static int pedidoJaExiste(ListaNovaEntrada* lista, int numPedido){
    No* atual = lista->inicio;

    while(atual != NULL){
        if(atual->NumPedido == numPedido){
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

static int enfileirarEsteira(FilaEsteira* fila, int numPedido){
    No* novaCaixa = (No*) malloc(sizeof(No));

    if(novaCaixa == NULL){
        printf("\nErro ao alocar memoria para a esteira.\n");
        return 1;
    }

    novaCaixa->NumPedido = numPedido;
    novaCaixa->proximo = NULL;

    if(fila->inicio == NULL){
        fila->inicio = novaCaixa;
        fila->fim = novaCaixa;
    } else {
        fila->fim->proximo = novaCaixa;
        fila->fim = novaCaixa;
    }

    return 0;
}

int novopacote(ListaNovaEntrada* lista, FilaEsteira* fila){
    int numPedido;
    No* novoPedido = NULL;

    printf("\nInsira o ID do pacote:\n");

    if(!lerInteiro(&numPedido)){
        printf("\nID invalido. Digite apenas numeros.\n");
        return 1;
    }

    if(pedidoJaExiste(lista, numPedido)){
        printf("\nPedido %d ja existe. Cadastro nao realizado.\n", numPedido);
        return 1;
    }

    novoPedido = (No*) malloc(sizeof(No));

    if(novoPedido == NULL){
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)
        printf("\nErro ao alocar memoria para o pedido.\n");
        return;
    }

<<<<<<< HEAD
    printf("\n===================================");
    printf("\nInsira o endereco de entrega do pacote: ");
    scanf(" %[^\n]", EntregaNova->Entrega);

    strcpy(noPrancheta->Entrega, EntregaNova->Entrega);

    printf("ID do pacote gerado: %d\n", *IdDoPedido);
    noPrancheta->NumPedido = *IdDoPedido;
    EntregaNova->NumPedido = *IdDoPedido;

    EntregaNova->ProxNo = NULL;

    // Inserção na Prancheta (Lista Simples - Início)
    noPrancheta->ProxNo = prancheta->inicio;
    prancheta->inicio = noPrancheta;

    // Inserção na Esteira (Fila FIFO - Fim)
    if (esteira->inicio == NULL) {
        esteira->inicio = EntregaNova;
        esteira->fim = EntregaNova;
=======
    novoPedido->NumPedido = numPedido;
    novoPedido->proximo = NULL;

    if(enfileirarEsteira(fila, novoPedido->NumPedido) != 0){
        free(novoPedido);
        return 1;
    }

    if(lista->inicio == NULL){
        lista->inicio = novoPedido;
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)
    } else {
        esteira->fim->ProxNo = EntregaNova;
        esteira->fim = EntregaNova;
    }

    printf("======== Pedido Cadastrado ========\n");

    (*IdDoPedido)++;
}

// 2. Exibe os elementos da Prancheta
void verPranchetaEntrada(Prancheta* lista) {
    NoPedido* atual = lista->inicio;
    int posicao = 1;

    printf("\n======================\nPrancheta de entrada\n======================\n");

    if (atual == NULL) {
        printf("Nenhum pedido chegou ainda.\n");
        return;
    }

    while (atual != NULL) {
        printf("-Pedido #%d - Endereco: %s\n", atual->NumPedido, atual->Entrega);
        atual = atual->ProxNo;
        posicao++;
        printf("---------------------\n");
    }
}

<<<<<<< HEAD
//Despachar para caminhao
=======
void verPrimeiraCaixaEsteira(FilaEsteira* fila){
    printf("\nEsteira rolante\n");

    if(fila->inicio == NULL){
        printf("Nenhuma caixa esta na esteira.\n");
        return;
    }

    printf("Primeira caixa na ponta da esteira: Pedido %d\n", fila->inicio->NumPedido);
}

void liberarListaNovaEntrada(ListaNovaEntrada* lista){
    No* atual = lista->inicio;
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)

void DespacharParaCaminhao(FilaEsteira* esteira, Prancheta* prancheta, PilhaCaminhao* caminhao) {
    if (esteira == NULL || esteira->inicio == NULL) {
        printf("\n========================\nEsteira está vazia!\n========================\n");
        return;
    }

    while (esteira->inicio != NULL) {
        NoPedido* novoNo = (NoPedido*) malloc(sizeof(NoPedido));
        
        if (novoNo == NULL) {
            printf("\n---------------------\nErro de alocacao de memoria\n---------------------\n");
            return;
        }

        NoPedido* pacoteRemovido = esteira->inicio;

        novoNo->NumPedido = pacoteRemovido->NumPedido;
        strcpy(novoNo->Entrega, pacoteRemovido->Entrega);

        novoNo->ProxNo = caminhao->topo;
        caminhao->topo = novoNo;

        printf("\nPedido #%d despachado", novoNo->NumPedido);

        esteira->inicio = esteira->inicio->ProxNo;

        free(pacoteRemovido);
    }

    esteira->fim = NULL;
    printf("\n\nTodos os pacotes da esteira foram despachados com sucesso!\n");
}

<<<<<<< HEAD
//  Estoquista
void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta, PilhaCaminhao* caminhao){
    int user = 0;

    do {
        printf("\nChegada e Envio\n\n"
               "1- Registrar chegada de pacote\n"
               "2- Ver prancheta de entrada\n"
               "3- Operar esteira rolante (Fila)\n"
               "4- Despachar para o caminhão (Pilha)\n"
               "0- Sair\n"
               ">> ");
        scanf("%d", &user);

        switch (user) {
            case 1:
                novopacote(prancheta, esteira, IdDoPedido);
=======
void liberarFilaEsteira(FilaEsteira* fila){
    No* atual = fila->inicio;

    while(atual != NULL){
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
}

void Estoquista(){
    int user;
    ListaNovaEntrada listaEntrada;
    FilaEsteira esteira;

    inicializarListaNovaEntrada(&listaEntrada);
    inicializarFilaEsteira(&esteira);

    do{
        printf("\nChegada e Envio\n\n"
           "1- Registrar chegada de pacote\n"
           "2- Ver prancheta de entrada\n"
           "3- Operar esteira rolante (Fila)\n"
           "|-> Empilhar: Move o primeiro valor da Esteira (Fila) para Transportadora (fila) e apaga o nome dela da Prancheta (Lista Simples).\n\n"
           "4- Despachar para o caminhão (Pilha)\n"
           "5- Sair\n");
           if(!lerInteiro(&user)){
                printf("\nOpcao invalida. Digite apenas numeros.\n=============================\n");
                user = -1;
                continue;
           }
            switch (user)
            {
            case 1:
                novopacote(&listaEntrada, &esteira);
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)
                break;
            case 2:
                verPranchetaEntrada(prancheta);
                break;
            case 3:
<<<<<<< HEAD
            //a fazer
=======
                verPrimeiraCaixaEsteira(&esteira);
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)
                break;
            case 4:
            DespacharParaCaminhao(esteira, prancheta, caminhao);
                break;
            case 0:
                printf("\nSaindo do menu do Estoquista...\n");
                break;
            default:
                printf("\nOpcao Invalida\n=============================\n");
                break;
        }

<<<<<<< HEAD
    } while (user != 0);
    return;
=======


    }while(user!=5);

    liberarListaNovaEntrada(&listaEntrada);
    liberarFilaEsteira(&esteira);
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)
}
