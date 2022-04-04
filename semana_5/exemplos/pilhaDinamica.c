#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
  LinkedNode *topo;
};

PilhaDinamica *criarPilha() {
  PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
  pilha->topo = NULL;

  return pilha;
}

int push(PilhaDinamica *pilha, int item) {
  LinkedNode *novo = malloc(sizeof(LinkedNode));
  if (novo == NULL) return 0;

  novo->data = item;
  novo->next = pilha->topo;

  pilha->topo = novo;

  return 1;
}

int pop(PilhaDinamica *pilha, int *item) {
  // pilha vazia?.
  if (pilha->topo == NULL) return 0;

  LinkedNode *node = pilha->topo;
  pilha->topo = pilha->topo->next;

  *item = node->data;
  free(node);

  return 1;
}

void liberarLista(LinkedNode *node) {
  if (node == NULL) return;
  liberarLista(node->next);
  free(node);
}

void liberarPilha(PilhaDinamica *pilha) {
  liberarLista(pilha->topo);
  free(pilha);
}

int main() {
  PilhaDinamica *p = criarPilha();
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

  r = pop(p, &item);
  printf("D %d : %d\n", item, r);

  liberarPilha(p);

  return 0;
}