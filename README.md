Para rodar:
Abra a pasta pelo terminal e siga os passos, dependendo do seu sistema:
No Linux (Terminal / Bash)
    Use o comando:
    gcc *.c -o programa

    Execute o programa gerado:
    Bash./programa

No Windows 
    
    Compile gerando um executável:
    gcc *.c -o programa.exe
    
    Execute-o:
    .\programa.exe

## Sistema pra gerenciamento de armazém e entregas

Logar como...
1-> Estoquista
2-> Entregador

---------> 1 -> Estoquista

chegada e envio

1- Registrar chegada de pacote
Anota o pedido na prancheta (lista normal) e esteira (Fila).

2- Ver prancheta de Pedidos do Dia
Mostra todos os pedidos que chegaram (Lista normal).

3- Operar esteira rolante (Fila)
Mostra a primeira caixa que está na ponta da esteira (na fila).

|-> Empilhar: Move o primeiro valor da Esteira (Fila) para Transportadora (fila)

4- Despachar para o caminhão (Pilha)
Move da Transportadora(Fila) para Caminhão (Pilha) e apaga o nome dela da Prancheta (Lista Simples).

---------> 2 -> Entregador

Entregas

1- Ver Próxima entrega (acessar lista caminhão (Pilha))
|-> Marcar entrega como concluída e ir para a próxima entrega
desenfileiramento e move pra lista simples (Entregas_Feitas_hoje)

2- Ver entregas Entregas Feitas hoje
lista todos os produtos da lista simples(Entregas_Feitas_hoje)

3- Fechar dia de entregas
esvazia lista simples Entregas_Feitas_hoje


Para rodar o codigo:

```bash
gcc -Wall -Wextra -std=c11 main.c ChegadaDePedido.c Caminhao.c -o mecanica
./mecanica
```
