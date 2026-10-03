O prototipo das funçoes foi adicionado ao arquivo deem uma olhada para analisarmos mais tarde

Sistema pra gerenciamento de armazém e entregas

Logar como...
1->Estoquista
2-> Entregador

---------> 1 -> Estoquista

chegada e envio

1- Registrar chegada de pacote
Anota o pedido na prancheta (lista normal) e esteira (Fila).

2- Ver prancheta de entrada
Mostra todos os pedidos que chegaram (Lista normal).

3- Operar esteira rolante (Fila)
Mostra a primeira caixa que está na ponta da esteira (na fila).

|-> Empilhar: Move o primeiro valor da Esteira (Fila) para Transportadora (fila) e apaga o nome dela da Prancheta (Lista Simples).

4- Despachar para o caminhão (Pilha)
Move da Transportadora(Fila) para Caminhão (Pilha).

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
