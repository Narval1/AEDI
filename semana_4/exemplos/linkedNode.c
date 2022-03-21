#include <stdio.h>
#include <stdlib.h>

// guarda a data e a referencia pro elemento seguinte da lista.
typedef struct linkedNode linkedNode;
struct linkedNode {
  int data;
  linkedNode *next;
};

/*
* A funçao recebe o ponteiro inicio que guarda o endereço de memoria do primeiro elemento da lista
* Durante o loop o valor de atual sera alterado para percorrer os elementos da lista
*/
void printLinkedNode (linkedNode *inicio) {
  linkedNode *atual = inicio;
  while (atual != NULL) {
    printf("%d\n", atual->data);
    atual = atual->next;
  }
}

// outra maneira de fazer o print anterior
void anotherPrint (linkedNode *inicio) {
  linkedNode *atual;
  for (atual = inicio; atual != NULL; atual = atual->next) printf("%d\n", atual->data);
}

int main () {
  linkedNode item1 = {10, NULL};
  linkedNode item2 = {20, NULL};
  linkedNode item3 = {30, NULL};

  item1.next = &item2;
  item2.next = &item3;

  printLinkedNode(&item1);
  anotherPrint(&item1);

  return 0;
}