#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void printLinkedNode (LinkedNode *inicio) {
  LinkedNode *atual = inicio;
  while (atual != NULL) {
    printf("%d\n", atual->data);
    atual = atual->next;
  }
}

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes) {
  LinkedNode *atual = inicio;
  *trocas = 0;
  *comparacoes = 0;
  int count = 0;
  
  while (atual != NULL) {
    LinkedNode *minimo = atual;
    LinkedNode *proximo = atual->next;

    while(proximo != NULL) {
      if (minimo->data > proximo->data) {
        minimo = proximo;
      }
      proximo = proximo->next;
    }

    if (atual != minimo) {
      int tmp = atual->data;
      atual->data = minimo->data;
      minimo->data = tmp;
      *trocas = *trocas + 1;
    }

    atual = atual->next;
    count++;
  }

  *comparacoes = ((count - 1) * count) / 2; 
  return inicio;
}

int main() {
  LinkedNode *inicio = NULL;
  int trocas = 0, comparacoes = 0;

  inicio = insereNoFinalRecursivo(inicio, 11);
  inicio = insereNoFinalRecursivo(inicio, 22);
  inicio = insereNoFinalRecursivo(inicio, 33);
  inicio = insereNoFinalRecursivo(inicio, 44);
  inicio = insereNoFinalRecursivo(inicio, 55);

  inicio = selection_sort(inicio, &trocas, &comparacoes);
  printLinkedNode(inicio);

  printf("%d\n%d\n", trocas, comparacoes);

  return 0; 
}