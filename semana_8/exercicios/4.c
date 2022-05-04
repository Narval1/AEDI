#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
  int data;
  DLinkedNode *next, *prev;
};

DLinkedNode *insereNoFinal(DLinkedNode *inicio, int elemento) {
  DLinkedNode *novo = malloc(sizeof(DLinkedNode));
  novo->data = elemento;
  novo->next = NULL;
  novo->prev = NULL;

  if (inicio == NULL) return novo;

  DLinkedNode *atual = inicio, *anterior = NULL;
  while (atual != NULL) {
    anterior = atual;
    atual = atual->next;
  }

  anterior->next = novo;
  novo->prev = anterior;

  return inicio;
}

void printDLinkedNode (DLinkedNode *inicio) {
  DLinkedNode *atual = inicio;
  while (atual != NULL) {
    printf("%d\n", atual->data);
    atual = atual->next;
  }
}

int func(int a, int b, int *comparacoes) {
  (*comparacoes)++;

  return a < b;
}

DLinkedNode *insertion_sort(DLinkedNode *inicio, int *comparacoes) {
  *comparacoes = 0;
  if (inicio == NULL) return NULL;

  for (DLinkedNode *atual = inicio->next; atual != NULL; atual = atual->next) {
    int data = atual->data;

    DLinkedNode *aux;
    //encontramos o primeiro elemento menor que atual
    for (aux = atual->prev; aux != NULL && func(data, aux->data, comparacoes); aux = aux->prev) {
      DLinkedNode *noDepois = aux->next;
      noDepois->data = aux->data;
    }

    // se e null quer dizer que e na primeira posicao
    if (aux == NULL) {
      inicio->data = data;
    } else {
      aux->next->data = data;
    }
  }

  return inicio;
}


int main() {
  DLinkedNode *inicio = NULL;
  int comparacoes = 0;

  inicio = insereNoFinal(inicio, 66);
  inicio = insereNoFinal(inicio, 33);
  inicio = insereNoFinal(inicio, 22);
  inicio = insereNoFinal(inicio, 55);
  inicio = insereNoFinal(inicio, 88);
  inicio = insereNoFinal(inicio, 11);
  inicio = insereNoFinal(inicio, 44);
  inicio = insereNoFinal(inicio, 77);

  inicio = insertion_sort(inicio, &comparacoes);
  printDLinkedNode(inicio);

  printf("%d\n", comparacoes);

  return 0; 
}