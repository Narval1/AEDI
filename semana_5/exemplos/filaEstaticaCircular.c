#include <stdio.h>
#include <stdlib.h>

typedef struct FilaCircular FilaCircular;
struct FilaCircular {
  int *itens;
  int tamanho, inicio, fim;
};

FilaCircular *criarFila(int tamanho) {
  FilaCircular *fila = malloc(sizeof(FilaCircular));
  fila->itens = malloc(sizeof(int) * tamanho);
  fila->tamanho = tamanho;
  //indices dos elementos de inicio e fim.
  fila->inicio = 0;
  fila->fim = 0;

  return fila;
}

int enqueue(FilaCircular *fila, int item) {
  //fila cheia?.
  int novoFim = (fila->fim + 1) % fila->tamanho;
  if (novoFim == fila->inicio) return 0;

  fila->itens[fila->fim] = item;
  fila->fim = novoFim;

  return 1;
}

int dequeue(FilaCircular *fila, int *item) {
  //fila vazia?.
  if (fila->inicio == fila->fim) return 0;

  *item = fila->itens[fila->inicio];
  fila->inicio = (fila->inicio + 1) % fila->tamanho;

  return 1;
}

void liberarFila(FilaCircular *fila) {
  free(fila->itens);
  free(fila);
}

int main() {
  FilaCircular *fila = criarFila(4);
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