#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode *next;
};

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

void contar(LinkedNode *inicio, int *qtd, int *soma) {
    LinkedNode *atual = inicio;
    *qtd = 0;
    *soma = 0;

    while (atual != NULL) {
      (*qtd)++;
      *soma = *soma + atual->data;
      atual = atual->next;
    }
}

void imprimir1(LinkedNode *inicio) {
    LinkedNode *atual;
    for (atual = inicio; atual != NULL; atual = atual->next) printf("%d", atual->data);
    printf("\n");
}

void imprimir2(LinkedNode *inicio) {
  int size = 0;
  LinkedNode *atual;

  for (atual = inicio; atual != NULL; atual = atual->next) size++;

  int data[size];
  int i = 0;
  atual = inicio;

  while(atual != NULL) {
    data[i] = atual->data;
    i++;
    atual = atual->next;
  }

  for (int i = size - 1; i >= 0; i--) printf("%d ", data[i]);
  printf("\n");

}

int main() {
  LinkedNode *inicio = NULL;
  int soma, qtd;

  inicio = insereNoFinalRecursivo(inicio, 10);
  inicio = insereNoFinalRecursivo(inicio, 20);
  inicio = insereNoFinalRecursivo(inicio, 30);

  imprimir2(inicio);
  return 0;
}