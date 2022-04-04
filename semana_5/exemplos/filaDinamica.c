#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode *next;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica {
  LinkedNode *inicio, *fim;
};

FilaDinamica *criarFila() {
  FilaDinamica *fila = malloc(sizeof(FilaDinamica));
  fila->inicio = NULL;
  fila->fim = NULL;

  return fila;
}

int enqueue(FilaDinamica *fila, int item) {
  LinkedNode *novo = malloc(sizeof(LinkedNode));
  if (novo == NULL) return 0;

  novo->data = item;
  novo->next = NULL;

  if (fila->fim != NULL) fila->fim->next = novo;

  fila->fim = novo;

  if (fila->inicio == NULL) fila->inicio = novo;

  return 1;
}

int dequeue(FilaDinamica *fila, int *item) {
  if (fila->inicio == NULL) return 0;

  LinkedNode *node = fila->inicio;
  *item = node->data;

  fila->inicio = fila->inicio->next;
  if (fila->inicio == NULL) fila->fim == NULL;

  free(node);
  return 1;
}

void liberarLista(LinkedNode *node) {
  if (node == NULL) return;
  liberarLista(node->next);
  free(node);
}

void liberarFila(FilaDinamica *fila) {
  liberarLista(fila->inicio);
  free(fila);
}

int main() {
  FilaDinamica *fila = criarFila();
  int r, item;

  item = 10;
  r = enqueue(fila, item);
  printf("E: %d : %d\n", item, r);

  item = 20;
  r = enqueue(fila, item);
  printf("E: %d : %d\n", item, r);

  item = 30;
  r = enqueue(fila, item);
  printf("E: %d : %d\n", item, r);

  item = 40;
  r = enqueue(fila, item);
  printf("E: %d : %d\n", item, r);

  for (int i = 0; i < 5; i++) {
    item = -1;
    r = dequeue(fila, &item);
    printf("D: %d : %d\n", item, r);
  }

  liberarFila(fila);

  return 0;
}