#include "ChegadadePedido.h"

void novopacote(Prancheta* prancheta, FilaEsteira* esteira, int* IdDoPedido) {
    NoPedido* EntregaNova = (NoPedido*) malloc(sizeof(NoPedido));
    NoPedido* noPrancheta = (NoPedido*) malloc(sizeof(NoPedido)); 

    
    printf("\n\nInsira o endereco de entrega: ");
    scanf(" %[^\n]", EntregaNova->Entrega); 
    
    strcpy(noPrancheta->Entrega, EntregaNova->Entrega);

    printf("\nID do pacote: %d\n", *IdDoPedido);
    noPrancheta->NumPedido = *IdDoPedido;
    EntregaNova->NumPedido = *IdDoPedido;

    EntregaNova->ProxNo = NULL; 

    noPrancheta->ProxNo = prancheta->inicio;
    prancheta->inicio = noPrancheta;

    if (esteira->inicio == NULL) {
        esteira->inicio = EntregaNova;
        esteira->fim = EntregaNova;
    } else {
        esteira->fim->ProxNo = EntregaNova;
        esteira->fim = EntregaNova;
    }

    printf("========== Pedido Cadastrado ==========\n");

    (*IdDoPedido)++;
}

//2- ver prancheta
void verPranchetaEntrada(Prancheta* lista){
    NoPedido* atual = lista->inicio;
    int posicao = 1;

    printf("\n======================\nPrancheta de entrada\n======================\n");

    if(atual == NULL){
        printf("Nenhum pedido chegou ainda.\n");
        return;
    }

    while(atual != NULL){
        printf("%d- Pedido %d - endereco: %s \n", posicao, atual->NumPedido,atual->Entrega);
        atual = atual->ProxNo;
        posicao++;
        printf("---------------------\n");
    }
}


void Estoquista(int* IdDoPedido, FilaEsteira* esteira, Prancheta* prancheta) {
    int Estoquser = 3;
    do {
        printf("\nChegada e Envio\n\n"
               "1- Registrar chegada de pacote\n"
               "2- Ver prancheta de entrada\n"
               "3- Operar esteira rolante (Fila)\n"
               "|-> Empilhar: Move o primeiro valor da Esteira (Fila) para Transportadora (fila)\n"
               "4- Despachar para o caminhão (Pilha)\n"
               "0- Sair\n>> ");
        scanf("%d", &Estoquser);

        switch (Estoquser) {
            case 1:
                novopacote(prancheta, esteira, IdDoPedido);
                break;
            case 2:
                verPranchetaEntrada(prancheta);
                break;
            case 3: {
                int usertemp = 9;
                while (usertemp != 0) {
                    printf("\n1- Empilhar(mover para transportadora)\n 0- Sair\n");
                    scanf("%d", &usertemp);
                    switch (usertemp) {
                        case 1:
                            break;
                        case 0:
                            break;
                        default:
                            printf("opção invalida\n");
                            break;
                    }
                }
                break;
            }
            case 4:
                /* code */
                break;
            case 0:
                printf("\nSaindo do menu...\n");
                break;
            default:
                printf("\nOpcao Invalida\n=============================\n");
                break;
        }

    } while (Estoquser != 0); // Correção: encerra com 0 em vez de 5
}