#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int n) {
  int *v = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) v[i] = rand() % 100;
  return v;
}

void imprimir( int *v, int n) {
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
}

void bubble_sort(int *v, int n) {
  int trocou = 1;
  for (int i = 0; i < n - 1 && trocou; i++) {
    trocou = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (v[j] > v[j + 1]) {
        int tmp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = tmp;
        trocou = 1;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  int tamanho = 10;
  int *vetor = vetor_aleatorio(tamanho);
  imprimir(vetor, tamanho);

  bubble_sort(vetor, tamanho);
  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}