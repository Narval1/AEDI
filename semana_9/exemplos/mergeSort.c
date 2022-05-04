#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int n) {
  int *v = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) v[i] = rand() % 100;
  return v;
}

void imprimir(int *v, int n) {
  for (int i = 0; i < n - 1; i++) printf("%d ", v[i]);
  printf("%d\n", v[n - 1]);
}

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim) {
  int dir_inicio = esq_fim + 1;
  int esq = esq_inicio, dir = dir_inicio;
   
  int comp = dir_fim - esq_inicio + 1;
  int *v_aux = malloc(sizeof(int) * comp);

  for (int i = 0; i < comp; i++) {
    if (esq > esq_fim) v_aux[i] = v[dir++];
    else if (dir > dir_fim) v_aux[i] = v[esq++];
    else if (v[esq] <= v[dir]) {
      v_aux[i] = v[esq++];
    }
    else {
      v_aux[i] = v[dir++];
    }
  }

  for (int i = 0; i < comp; i++) v[esq_inicio + i] = v_aux[i];
  
  free(v_aux);
}

void mergesort(int *v, int esq, int dir) {
  // tem pelo menos dois elementos
  if (esq < dir) {
    int meio = (esq + dir) / 2;
    mergesort(v, esq, meio);
    mergesort(v, meio + 1, dir);
    intercala(v, esq, meio, dir);
  }
}

void merge_sort(int *v, int n) {
  mergesort(v, 0, n - 1);
}

int main() {
  srand(time(NULL));
  int tamanho = 10;
  int *vetor = vetor_aleatorio(tamanho);

  imprimir(vetor, tamanho);

  merge_sort(vetor, tamanho);
  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}