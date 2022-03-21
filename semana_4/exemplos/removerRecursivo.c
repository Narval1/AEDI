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
linkedNode *removerRecursivo(linkedNode *inicio, int valor) {
  if (inicio == NULL) return NULL;
  if (inicio->data == valor) {
    // novo inicio.
    linkedNode *temp = inicio->next;
    // libere o valor que queremos apagar da memoria.
    free(inicio);
    return temp;
  }

  inicio->next = removerRecursivo(inicio->next, valor);
  return inicio;

  return inicio;
}

void liberarListaRecursivo(linkedNode *inicio) {
  if (inicio == NULL) return;
  liberarListaRecursivo(inicio->next);
  free(inicio);
}

void liberarLista(linkedNode *inicio) {
  linkedNode *atual = inicio, *remover;

  while(atual != NULL) {
    remover = atual;
    atual = atual->next;
    free(remover);
  }
}
  

// ta com vazamento de memoria
int main () {
  linkedNode *inicio = NULL;
  inicio = insere(inicio, 10);
  inicio = insere(inicio, 20);
  inicio = insere(inicio, 30);

  printLinkedNode(inicio);

  inicio = removerRecursivo(inicio, 20);
  printLinkedNode(inicio);

  liberarListaRecursivo(inicio);

  return 0;
}