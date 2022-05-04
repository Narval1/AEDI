#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int n) {
  for (int i = 0; i < n - 1; i++) printf("%d ", v[i]);
  printf("%d", v[n - 1]);
}

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim, int *comparacoes) {
  int dir_inicio = esq_fim + 1;
  int esq = esq_inicio, dir = dir_inicio;
   
  int comp = dir_fim - esq_inicio + 1;
  int *v_aux = malloc(sizeof(int) * comp);

  for (int i = 0; i < comp; i++) {
    if (esq > esq_fim) v_aux[i] = v[dir++];
    else if (dir > dir_fim) v_aux[i] = v[esq++];
    else if (v[esq] <= v[dir]) {
      v_aux[i] = v[esq++];
      (*comparacoes)++;
    }
    else {
      v_aux[i] = v[dir++];
      (*comparacoes)++;
    }
  }

  for (int i = 0; i < comp; i++) v[esq_inicio + i] = v_aux[i];
  
  free(v_aux);
}

void mergesort(int *v, int esq, int dir, int *comparacoes) {
  // tem pelo menos dois elementos
  if (esq < dir) {
    int meio = (esq + dir) / 2;
    mergesort(v, esq, meio, comparacoes);
    mergesort(v, meio + 1, dir, comparacoes);
    intercala(v, esq, meio, dir, comparacoes);
  }
}

void merge_sort(int *v, int n,  int *comparacoes) {
  *comparacoes = 0;
  mergesort(v, 0, n - 1, comparacoes);
}

int main() {
  int tamanho, elemento, comparacoes = 0;

  scanf("%d", &tamanho);

  int *vetor = malloc(sizeof(int) * tamanho);

  if (tamanho != 0) {
    for (int i = 0; i < tamanho; i++) {
      scanf("%d", &elemento);
      vetor[i] = elemento;
    }

    merge_sort(vetor, tamanho, &comparacoes);

    imprimir(vetor, tamanho);
  }
  
  printf("\nComparacoes: %d\n", comparacoes);
  
  free(vetor);

  return 0; 
}