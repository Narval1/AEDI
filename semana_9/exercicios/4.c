#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char *data; 
   LinkedNode *next;
};

LinkedNode *insere(LinkedNode *inicio, char *elemento) {
  if (inicio == NULL) {
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->data = malloc(sizeof(char) * 100);
    strcpy(novo->data, elemento);
    novo->next = NULL;
    return novo;
  }

  inicio->next = insere(inicio->next, elemento);
  return inicio;
}

void print(LinkedNode *inicio) {
  LinkedNode *atual = inicio;
  while (atual != NULL) {
    printf("%s\n", atual->data);
    atual = atual->next;
  }
}

int ordena_lexico(char *a, char *b) {
  int counter = 0;
  
  for (int i = 0; *(a + i) == *(b + i) && *(a + i) != '\0' && *(b + i) != '\0'; i++) counter++;

  if (*(a + counter) == '\0' && *(b + counter) == '\0') return 0;
  if (*(a + counter) < *(b + counter)) return -1;

  return 1;
}

LinkedNode *merge(LinkedNode *a, LinkedNode *b, int *comparacoes) {
  if (a == NULL) return b;
  if (b == NULL) return a;

  LinkedNode *c;

  if (ordena_lexico(a->data, b->data) < 0) {
    (*comparacoes)++;

    c = a;
    c->next = merge(a->next, b, comparacoes);
  } else {
    (*comparacoes)++;

    c = b;
    c->next = merge(a, b->next, comparacoes);
  }

  return c;
}

LinkedNode *getMid(LinkedNode *inicio) {
  LinkedNode *a = inicio;
  LinkedNode *b = inicio->next;

  while (b != NULL && b->next != NULL) {
    a = a->next;
    b = b->next->next;
  }

  return a;
}

LinkedNode *merge_sort(LinkedNode *inicio, int *comparacoes) {
  // caso base
  if (inicio == NULL || inicio->next == NULL) return inicio;

  // pega o meio da lista
  LinkedNode *meio = getMid(inicio);

  // separa a lista a partir do meio
  LinkedNode *primeiraParte = inicio;
  LinkedNode *segundaParte = meio->next;
  meio->next = NULL;

  // sort nas listas
  primeiraParte = merge_sort(primeiraParte, comparacoes);
  segundaParte = merge_sort(segundaParte, comparacoes);

  return merge(primeiraParte, segundaParte, comparacoes);
}

LinkedNode *mergesort(LinkedNode *inicio, int *comparacoes) {
  *comparacoes = 0;
  inicio = merge_sort(inicio, comparacoes);
  return inicio;
}

int main() {
  LinkedNode *lista1 = NULL;
  int comparacoes;
  
  lista1 = insere(lista1, "a");
  lista1 = insere(lista1, "b");
  lista1 = insere(lista1, "c");
  lista1 = insere(lista1, "d");
  lista1 = insere(lista1, "e");

  lista1 = mergesort(lista1, &comparacoes);
  print(lista1);
  printf("%d\n", comparacoes);

  return 0; 
}