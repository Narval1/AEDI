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

void selection_sort(int *v, int n) {
  for (int i = 0; i < n - 1; i++) {
    int indice_menor = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[indice_menor]) indice_menor = j;
    }
    if (indice_menor != i) {
      int aux = v[indice_menor];    
      v[indice_menor] = v[i];
      v[i] = aux;
    }
  }
}

int main() {
  srand(time(NULL));

  int tamanho = 10;
  int *vetor = vetor_aleatorio(tamanho);
  imprimir(vetor, tamanho);

  selection_sort(vetor, tamanho);
  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}