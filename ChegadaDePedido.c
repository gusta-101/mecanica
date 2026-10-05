
#include "ChegadadePedido.h"
#include "caminhao.h"

// 1. Cadastra pacote na Prancheta (Lista) e na Esteira (Fila)
void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido) {
    NoPedido* EntregaNova = (NoPedido*) malloc(sizeof(NoPedido));
    NoPedido* noPrancheta = (NoPedido*) malloc(sizeof(NoPedido));

    if (EntregaNova == NULL || noPrancheta == NULL) {
        printf("\nErro ao alocar memoria para o pedido.\n");
        return;
    }

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
    } else {
        esteira->fim->ProxNo = EntregaNova;
        esteira->fim = EntregaNova;
    }
    (*IdDoPedido)++;
    printf("======== Pedido Cadastrado ========\n");
    return;
}

// 2. Exibe os elementos da Prancheta
void verPranchetaEntrada(Prancheta* lista) {
    printf("\n======================\nPrancheta de entrada\n======================\n");
    
    if (lista->inicio== NULL) {
        printf("Nenhum pedido chegou ainda.\n");
        return;
    }
    NoPedido* temp=lista->inicio;
    while (temp!= NULL) {
        printf("-Pedido #%d - Endereco: %s\n", temp->NumPedido,temp->Entrega);
        temp = temp->ProxNo;
        printf("---------------------\n");
    }
}

//Despachar para caminhao


void verPrimeiraCaixaEsteira(FilaEsteira* fila){
    printf("\n================================\nEsteira rolante\n================================\n");

    if(fila->inicio == NULL){
        printf("Nenhuma caixa esta na esteira.\n");
        return;
    }

    printf("Primeira caixa na ponta da esteira: Pedido #%d\n", fila->inicio->NumPedido);
}

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

        NoPedido* atual = prancheta->inicio;
        NoPedido* anterior = NULL;

        while (atual != NULL && atual->NumPedido != pacoteRemovido->NumPedido) {
            anterior = atual;
            atual = atual->ProxNo;
        }

        if (atual != NULL) {
            if (anterior == NULL) {
                prancheta->inicio = atual->ProxNo;
            } else {
                anterior->ProxNo = atual->ProxNo;
            }
            free(atual);
        }

        printf("\nPedido #%d despachado", novoNo->NumPedido);

        esteira->inicio = esteira->inicio->ProxNo;

        free(pacoteRemovido);
    }

    esteira->fim = NULL;
    printf("\n\nTodos os pacotes da esteira foram despachados com sucesso!\n");
    return;
}


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
                break;
            case 2:
                verPranchetaEntrada(prancheta);
                break;
            case 3:
                verPrimeiraCaixaEsteira(esteira);
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

    } while (user != 0);
    return;
}
