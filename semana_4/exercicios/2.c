#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
  int data;
  DLinkedNode *next, *prev;
};

DLinkedNode *insereNoFinalRecursivo(DLinkedNode *inicio, int elemento) {
  if (inicio == NULL) {
    DLinkedNode *novo = malloc(sizeof(DLinkedNode));
    novo->data = elemento;
    novo->next = NULL;
    return novo;
  }

  inicio->next = insereNoFinalRecursivo(inicio->next, elemento);
  return inicio;
}

void printLinkedNode (DLinkedNode *inicio) {
  DLinkedNode *atual, *anterior;

  for (atual = inicio; atual != NULL; atual = atual->next) {
    anterior = atual;
    printf("%d ", atual->data);
  }
  printf("\n");

  for (atual = anterior; atual != NULL; atual = atual->prev) printf("%d ", atual->data);
  printf("\n");
}

void duplicar_pares1(LinkedNode *inicio) {
    LinkedNode *atual;
    int size = 0;

    for (atual = inicio; atual != NULL; atual = atual->next) {
      if (atual->data % 2 == 0) {
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        novo->data = atual->data;
        novo->next = atual->next;
        atual->next = novo;
        //pula pro no que criamos para que possa ser trocado na proxima iteraçao.
        atual = atual->next;
      }
    }
}

void duplicar_pares2(DLinkedNode *inicio) {
    DLinkedNode *atual;
    int size = 0;

    for (atual = inicio; atual != NULL; atual = atual->next) {
      if (atual->data % 2 == 0) {
        DLinkedNode *novo = malloc(sizeof(DLinkedNode));
        DLinkedNode *proximo = atual->next;

        novo->data = atual->data;
        novo->next = proximo;
        novo->prev = atual;
        atual->next = novo;

        if (proximo != NULL) proximo->prev = novo;

        //pula pro no que criamos para que possa ser trocado na proxima iteraçao.(pulo duplo)
        atual = atual->next;
      }
    }
}

int main() {
  DLinkedNode *inicio = NULL;

  inicio = insereNoFinalRecursivo(inicio, 10);
  inicio = insereNoFinalRecursivo(inicio, 25);
  inicio = insereNoFinalRecursivo(inicio, 30);
  inicio = insereNoFinalRecursivo(inicio, 35);
  inicio = insereNoFinalRecursivo(inicio, 40);

  duplicar_pares2(inicio);
  printLinkedNode(inicio);

  return 0;
}