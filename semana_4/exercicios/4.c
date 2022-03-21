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

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2) {
  LinkedNode *atual1 = inicio1, *atual2 = inicio2, *head = NULL;

  if (inicio1 == NULL) return inicio2;  
  if (inicio2 == NULL) return inicio1;

  if (atual1->data < atual2->data) {
    head = atual1;
    atual1 = atual1->next;
  } else {
      head = atual2;
      atual2 = atual2->next;
  }

  LinkedNode *currentNode = head;

  while (atual1 != NULL && atual2 != NULL) {
    if (atual1->data < atual2->data) {
      currentNode->next = atual1;
      atual1 = atual1->next;
    } else {
        currentNode->next = atual2;
        atual2 = atual2->next;
    }
    currentNode = currentNode->next;
  }

  if (atual1 == NULL) currentNode->next = atual2;
  else currentNode->next = atual1;

  return head;

}


int main() {
  LinkedNode *inicio = NULL, *inicio2 = NULL, *result = NULL;

  inicio = insereNoFinalRecursivo(inicio, 1);
  inicio = insereNoFinalRecursivo(inicio, 2);
  inicio = insereNoFinalRecursivo(inicio, 4);

  inicio2 = insereNoFinalRecursivo(inicio2, 1);
  inicio2 = insereNoFinalRecursivo(inicio2, 3);
  inicio2 = insereNoFinalRecursivo(inicio2, 4);

  result = intercalar_listas(inicio, inicio2);

  printLinkedNode(result);

  return 0;
}