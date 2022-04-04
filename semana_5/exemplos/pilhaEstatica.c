#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaEstatica pilhaEstatica;
struct pilhaEstatica {
  int *itens;
  int tamanho, topo;
};

pilhaEstatica *criarPilha(int tamanho) {
  pilhaEstatica *pilha = malloc(sizeof(pilhaEstatica));
  pilha->itens = malloc(sizeof(int) * tamanho);
  pilha->tamanho = tamanho;
  pilha->topo = -1;

  return pilha;
}

int push(pilhaEstatica *pilha, int item) {
  // pilha cheia?.
  if (pilha->topo == pilha->tamanho - 1) return 0;

  //o mais mais antes incremente primeiro e ai adiciona.
  pilha->itens[++pilha->topo] = item;
  return 1;
}

int pop(pilhaEstatica *pilha, int *item) {
  // pilha vazia?.
  if (pilha->topo == -1) return 0;

  *item = pilha->itens[pilha->topo--];

  return 1;
}

void liberarPilha(pilhaEstatica *pilha) {
  free(pilha->itens);
  free(pilha);
}

int main() {
  pilhaEstatica *p = criarPilha(4);
  int r, item;

  item = 10;
  r = push(p, item);
  printf("E %d : %d\n", item, r);

  item = 20;
  r = push(p, item);
  printf("E %d : %d\n", item, r);

  item = 30;
  r = push(p, item);
  printf("E %d : %d\n", item, r);

  item = 40;
  r = push(p, item);
  printf("E %d : %d\n", item, r);

  item = 50;
  r = push(p, item);
  printf("E %d : %d\n", item, r);

  r = pop(p, &item);
  printf("D %d : %d\n", item, r);

  r = pop(p, &item);
  printf("D %d : %d\n", item, r);

  r = pop(p, &item);
  printf("D %d : %d\n", item, r);

  r = pop(p, &item);
  printf("D %d : %d\n", item, r);

  r = pop(p, &item);
  printf("D %d : %d\n", item, r);

  liberarPilha(p);

  return 0;
}