#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  float data;
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

int push(PilhaDinamica *pilha, float item) {
  LinkedNode *novo = malloc(sizeof(LinkedNode));
  if (novo == NULL) return 0;

  novo->data = item;
  novo->next = pilha->topo;

  pilha->topo = novo;

  return 1;
}

int pop(PilhaDinamica *pilha, float *item) {
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

int calcular_posfixa(char *expressao, double *resultado) {
    
}

int main() {
  PilhaDinamica *p = criarPilha();
  float r, item;

  char *aux = "515";
  printf("%.3f\n", (double)aux[0]);

  return 0;
}