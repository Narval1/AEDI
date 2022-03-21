#include <stdio.h>
#include <stdlib.h>

// guarda a data e a referencia pro elemento seguinte da lista.
typedef struct linkedNode linkedNode;
struct linkedNode {
  int data;
  linkedNode *next;
};

linkedNode *insere(linkedNode *inicio, int elemento) {
  if (inicio == NULL) {
    linkedNode *novo = malloc(sizeof(linkedNode));
    novo->data = elemento;
    novo->next = NULL;
    return novo;
  }

  inicio->next = insere(inicio->next, elemento);
  return inicio;
}

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

// funçao que remove um elemento da lista ligada.
linkedNode *remover(linkedNode *inicio, int valor) {
  linkedNode *atual = inicio, *anterior = NULL;

  while (atual != NULL && atual->data != valor) {
    anterior = atual;
    atual = atual->next;
  }
  
  if (atual != NULL){
    // caso anterior seja null significa que estamos removendo o primeiro elemento.
    // caso negativo, anterior tem que receber o elemento seguinte ao atual.
    if (anterior != NULL) {
      anterior->next = atual->next;
    } else {
      inicio = atual->next;
    }
  }

  return inicio;
}
  

// ta com vazamento de memoria
int main () {
  linkedNode *inicio = NULL;
  inicio = insere(inicio, 10);
  inicio = insere(inicio, 20);
  inicio = insere(inicio, 30);

  printLinkedNode(inicio);

  inicio = remover(inicio, 30);
  printLinkedNode(inicio);

  return 0;
}