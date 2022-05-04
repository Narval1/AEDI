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

void insertion_sort(int *v, int n) {
  for (int i = 1; i < n; i++) {
    int indice_para_insercao = i;
    int item_atual = v[i];
    for (int j = i - 1; j >= 0 && item_atual < v[j]; j--) {
      v[j + 1] = v[j];
      indice_para_insercao--;
    }
    v[indice_para_insercao] = item_atual;
  }
}

int main() {
  srand(time(NULL));

  int tamanho = 10;
  int *vetor = vetor_aleatorio(tamanho);
  imprimir(vetor, tamanho);

  insertion_sort(vetor, tamanho);
  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}