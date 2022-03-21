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

// insere um elemento no final da lista.
linkedNode *insereNoFinalRecursivo(linkedNode *inicio, int elemento) {
  if (inicio == NULL) {
    linkedNode *novo = malloc(sizeof(linkedNode));
    novo->data = elemento;
    novo->next = NULL;
    return novo;
  }

  inicio->next = insereNoFinalRecursivo(inicio->next, elemento);
  return inicio;
}
  

// ta com vazamento de memoria
int main () {
  linkedNode *inicio = NULL;

  inicio = insereNoFinalRecursivo(inicio, 10);
  inicio = insereNoFinalRecursivo(inicio, 20);
  printLinkedNode(inicio);

  return 0;
}