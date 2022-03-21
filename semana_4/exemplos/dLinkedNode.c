#include <stdio.h>
#include <stdlib.h>

// guarda a data e a referencia pro elemento seguinte da lista.
typedef struct DlinkedNode DlinkedNode;
struct DlinkedNode {
  int data;
  DlinkedNode *next, *prev;
};

void printLinkedNode (DlinkedNode *inicio) {
  DlinkedNode *atual, *anterior;

  for (atual = inicio; atual != NULL; atual = atual->next) {
    anterior = atual;
    printf("%d ", atual->data);
  }
  printf("\n");

  for (atual = anterior; atual != NULL; atual = atual->prev) printf("%d ", atual->data);
  printf("\n");
}

DlinkedNode *insereNoFinal(DlinkedNode *inicio, int elemento) {
  DlinkedNode *novo = malloc(sizeof(DlinkedNode));
  novo->data = elemento;
  novo->next = NULL;
  novo->prev = NULL;

  if (inicio == NULL) return novo;

  DlinkedNode *atual = inicio, *anterior = NULL;
  while (atual != NULL) {
    anterior = atual;
    atual = atual->next;
  }

  anterior->next = novo;
  novo->prev = anterior;

  return inicio;
}

DlinkedNode *remover(DlinkedNode *inicio, int valor) {
  DlinkedNode *atual = inicio;

  for (atual = inicio; atual != NULL && atual->data != valor; atual = atual->next);

  if (atual != NULL) {
    DlinkedNode *anterior = atual->prev;
    DlinkedNode *proximo = atual->next;

    if (anterior != NULL) anterior->next = atual->next;
    else inicio = atual->next;

    if (proximo != NULL) proximo->prev = anterior;

    free(atual);
  }

  return inicio;
}

void liberarListaRecursivo(DlinkedNode *inicio) {
  if (inicio == NULL) return;
  liberarListaRecursivo(inicio->next);
  free(inicio);
}

int main () {
  DlinkedNode *inicio = NULL;

  inicio = insereNoFinal(inicio, 10);
  inicio = insereNoFinal(inicio, 20);
  inicio = insereNoFinal(inicio, 30);
  inicio = insereNoFinal(inicio, 40);

  inicio = remover(inicio, 30);

  printLinkedNode(inicio);
  liberarListaRecursivo(inicio);

  return 0;
}