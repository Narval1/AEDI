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

// insere um elemento no final da lista.
linkedNode *insereNoFinal (linkedNode *inicio, int elemento) {
  linkedNode *novo = malloc(sizeof(linkedNode));
  novo->data = elemento;
  novo->next = NULL;

  // caso seja null de inicio.
  if (inicio == NULL) return novo;

  // percorre a lista ate chegar no ultimo elemento.
  linkedNode *atual, *ultimoElemento;
  for (atual = inicio; atual != NULL; atual = atual->next) ultimoElemento = atual;
  ultimoElemento->next = novo;

  return inicio;
}

// ta com vazamento de memoria
int main () {
  linkedNode *inicio = NULL;

  inicio = insereNoFinal(inicio, 10);
  inicio = insereNoFinal(inicio, 20);
  inicio = insereNoFinal(inicio, 30);
  inicio = insereNoFinal(inicio, 40);

  anotherPrint(inicio);

  free(inicio);
  return 0;
}