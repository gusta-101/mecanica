#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaGlobal.h"
#include "ChegadadePedido.h"
#include "caminhao.h"

<<<<<<< HEAD
void iniciarlista(Prancheta* p, FilaEsteira* e,PilhaCaminhao* c) {
    p->inicio = NULL;
    e->inicio = NULL;
    e->fim = NULL;
    c->topo = NULL;
}
=======
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

int main(){
    int user=9;
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)

int main() {
    Prancheta prancheta;
    FilaEsteira esteira;
    PilhaCaminhao caminhao;
    iniciarlista(&prancheta, &esteira,&caminhao);

    int user = 9;
    int IdDoPedido = 1;

    do {
        printf("\nLogar como...\n");
        printf("1-> Estoquista\n");
        printf("2-> Entregador\n");
<<<<<<< HEAD
        printf("0-> Sair\n>> ");
        scanf("%d",&user);
=======
        printf("0-> Sair\n");
        if(!lerInteiro(&user)){
            printf("\nOpcao invalida. Digite apenas numeros.\n");
            user = -1;
            continue;
        }
>>>>>>> 9b7dc33 (feat: mostrar primeira caixa)
        switch (user){
        case 1:
        
            Estoquista(&IdDoPedido, &esteira, &prancheta,&caminhao);
            break;
        case 2:
            Entregador(&caminhao);
            break;
        case 0:
            printf("\nPrograma Encerrando...");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (user != 0);

    return 0;
}
