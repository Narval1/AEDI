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

void printLinkedNode (LinkedNode *inicio) {
  LinkedNode *atual = inicio;
  while (atual != NULL) {
    printf("%d\n", atual->data);
    atual = atual->next;
  }
}

LinkedNode* inverter_lista(LinkedNode *inicio) {
    LinkedNode *atual = inicio;
    LinkedNode *temp = NULL, *temp2 = NULL;

    while (atual != NULL) {
      temp2 = atual->next;
      atual->next = temp;
      temp = atual;
      atual = temp2;
    }
    atual = temp;
    return atual;
}

int main() {
  LinkedNode *inicio = NULL;

  inicio = insereNoFinalRecursivo(inicio, 10);
  inicio = insereNoFinalRecursivo(inicio, 20);
  inicio = insereNoFinalRecursivo(inicio, 30);
  inicio = insereNoFinalRecursivo(inicio, 40);

  printLinkedNode(inicio);
  inicio = inverter_lista(inicio);
  printLinkedNode(inicio);

  return 0;
}