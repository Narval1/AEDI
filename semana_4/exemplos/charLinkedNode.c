#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* TIPO;

// guarda a data e a referencia pro elemento seguinte da lista.
typedef struct linkedNode linkedNode;
struct linkedNode {
  TIPO data;
  linkedNode *next;
};

/*
* A funçao recebe o ponteiro inicio que guarda o endereço de memoria do primeiro elemento da lista
* Durante o loop o valor de atual sera alterado para percorrer os elementos da lista
*/
void printLinkedNode (linkedNode *inicio) {
  linkedNode *atual = inicio;
  while (atual != NULL) {
    printf("[%s] ", atual->data);
    atual = atual->next;
  }
  printf("\n");
}

// insere um elemento no final da lista.
linkedNode *insereNoFinalRecursivo(linkedNode *inicio, TIPO elemento) {
  if (inicio == NULL) {
    linkedNode *novo = malloc(sizeof(linkedNode));
    novo->data = elemento;
    novo->next = NULL;
    return novo;
  }

  inicio->next = insereNoFinalRecursivo(inicio->next, elemento);
  return inicio;
}

void liberarListaRecursivo(linkedNode *inicio) {
  if (inicio == NULL) return;
  liberarListaRecursivo(inicio->next);
  free(inicio->data);
  free(inicio);
}

// le numeros digitados pelo usuario ate receber -1.
int main () {
  linkedNode *inicio = NULL;
  
  int number;
  scanf("%d ", &number);

  for (int i = 0; i < number; i++) {
    char *texto = malloc(sizeof(char) * 100);
    fgets(texto, 100, stdin);
    // tira o espaço do ultimo caracter.
    texto[strlen(texto) - 1] = 0;
    inicio = insereNoFinalRecursivo(inicio, texto);
  }

  printLinkedNode(inicio);
  liberarListaRecursivo(inicio);

  return 0;
}