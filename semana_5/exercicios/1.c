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

PilhaDinamica *criar_pilha() {
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

void liberar_pilha(PilhaDinamica *pilha) {
  liberarLista(pilha->topo);
  free(pilha);
}

LinkedNode *insereNoFinalRecursivo(LinkedNode *inicio, int elemento) {
  if (inicio == NULL) {
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->data = elemento;
    novo->next = NULL;
    return novo;
  }

  inicio->next = insereNoFinalRecursivo(inicio->next, elemento);
  return inicio;
}

void printLinkedNode (LinkedNode *inicio) {
  LinkedNode *atual = inicio;
  while (atual != NULL) {
    printf("%d\n", atual->data);
    atual = atual->next;
  }
}

int verificar_lista(LinkedNode *lista) {
  int size = 0, result;
  LinkedNode *atual;
  PilhaDinamica *pilha = criar_pilha();

  for (atual = lista; atual != NULL; atual = atual->next) {
    size++;
  }

  atual = lista;
  for (int i = 0; i < size / 2; i++) {
    result = push(pilha, atual->data);
    atual = atual->next;
  }

  if (size % 2 != 0) {
    atual = lista;
    for (int i = 0; i <= size/2; i++) {
      atual = atual->next;
    }
  }

  while (atual != NULL) {
    int item = -1;
    if (atual->data == pilha->topo->data) result = pop(pilha, &item);
    atual = atual->next;
  }

  if (pilha->topo == NULL) {
    liberar_pilha(pilha);
    return 1;
  }

  liberar_pilha(pilha);
  return 0;
}

int main() {
  LinkedNode *inicio = NULL;

  inicio = insereNoFinalRecursivo(inicio, 111);
  inicio = insereNoFinalRecursivo(inicio, 222);
  inicio = insereNoFinalRecursivo(inicio, 333);
  inicio = insereNoFinalRecursivo(inicio, 333);
  inicio = insereNoFinalRecursivo(inicio, 222);
  inicio = insereNoFinalRecursivo(inicio, 111);
  inicio = insereNoFinalRecursivo(inicio, 111);

  int result = verificar_lista(inicio);
  printf("%d\n", result);

  liberarLista(inicio);

  return 0;
}