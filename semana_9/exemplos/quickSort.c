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

int particiona(int *v, int esq, int dir) {
  // ultimo elemento como pivo
  int pivo = v[dir];

  int ultimo_menores = esq - 1;
  for (int i = esq; i < dir; i++) {
    if (v[i] < pivo) {
      ultimo_menores++;
      int aux = v[ultimo_menores];
      v[ultimo_menores] = v[i];
      v[i] = aux;
    }
  }

  ultimo_menores++;
  v[dir] = v[ultimo_menores];
  v[ultimo_menores] = pivo;

  return ultimo_menores;
}

void quick_sort(int *v, int esq, int dir) {
  // pelo menos dois elementos
  if (esq < dir) {
    int i_pivo = particiona(v, esq, dir);
    quick_sort(v, esq, i_pivo - 1);
    quick_sort(v, i_pivo + 1, dir);
  }
}

void quicksort(int *v, int n) {
  quick_sort(v, 0, n - 1);
}

int main() {
  srand(time(NULL));

  int tamanho = 10;
  int *vetor = vetor_aleatorio(tamanho);
  imprimir(vetor, tamanho);

  quicksort(vetor, tamanho);
  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}