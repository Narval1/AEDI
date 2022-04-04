#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  char data;
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

int enqueue(FilaDinamica *fila, char item) {
  LinkedNode *novo = malloc(sizeof(LinkedNode));
  if (novo == NULL) return 0;

  novo->data = item;
  novo->next = NULL;

  if (fila->fim != NULL) fila->fim->next = novo;

  fila->fim = novo;

  if (fila->inicio == NULL) fila->inicio = novo;

  return 1;
}

int dequeue(FilaDinamica *fila, char *item) {
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

int main() {
  FilaDinamica *fila = criarFila();
  int result;
  int a, b;
  char item = 'z';

  result = enqueue(fila, 'A');
  result = enqueue(fila, 'B');
  result = enqueue(fila, 'C');
  result = enqueue(fila, 'D');
  result = enqueue(fila, 'E');
  result = enqueue(fila, 'F');
  result = enqueue(fila, 'G');
  result = enqueue(fila, 'H');
  result = enqueue(fila, 'I');
  result = enqueue(fila, 'J');
  result = enqueue(fila, 'K');
  result = enqueue(fila, 'L');
  result = enqueue(fila, 'M');
  result = enqueue(fila, 'N');
  result = enqueue(fila, 'O');
  result = enqueue(fila, 'P');

  // sao 14 jogos.
  for (int i = 0; i < 15; i++) {
    scanf("%d %d", &a, &b);
    // caso a > b adicionamos no final da fila o primeiro elemento da fila e apaga dois.
    // caso a < b apaga um ,adiciona o primeiro e apaga o proximo.
    if (a > b) {
      result = enqueue(fila, fila->inicio->data);
      result = dequeue(fila, &item);
      result = dequeue(fila, &item);
    } else {
    result = dequeue(fila, &item);
    result = enqueue(fila, fila->inicio->data);
    result = dequeue(fila, &item);
    }
  }

  printf("%c\n", fila->inicio->data);
  liberarLista(fila);
  return 0;
}