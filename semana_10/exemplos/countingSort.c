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

void countingsort(int *v, int n, int k) {
  int c[k + 1];
  for (int i = 0; i < k + 1; i++) c[i] = 0;

  for (int i = 0; i < n; i++) c[v[i]]++;

  for (int i = 1; i < k + 1; i++) c[i] = c[i] + c[i - 1];

  int saida[n];
  int atual;
  for (int i = n - 1; i >= 0; i--) {
    atual = v[i];
    saida[c[atual] - 1] = atual;
    c[atual]--;
  }

  for (int i = 0; i < n; i++) v[i] = saida[i];
}

int main() {
  srand(time(NULL));

  int tamanho = 7;
  int *vetor = vetor_aleatorio(tamanho);

  imprimir(vetor, tamanho);

  countingsort(vetor, 7, 99);

  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}