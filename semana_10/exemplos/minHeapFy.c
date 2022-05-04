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

void min_heapfy(int *v, int n, int i) {
  int menor = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  if (esq < n && v[esq] < v[menor]) menor = esq;
  if (dir < n && v[dir] < v[menor]) menor = dir;

  if (menor != i) {
    int tmp = v[i];
    v[i] = v[menor];
    v[menor] = tmp;
    
    min_heapfy(v, n, menor);
  }
}

void build_minheap(int * v, int n) {
  for (int i = n/2 - 1; i >= 0; i--) min_heapfy(v, n, i);
}

int main() {
  srand(time(NULL));

  // 10 22 11 40 85 82 79 96 97 86
  int tamanho = 10;
  int *vetor = malloc(sizeof(int) * tamanho);

  vetor[0] = 10;
  vetor[1] = 22;
  vetor[2] = 11;
  vetor[3] = 40;
  vetor[4] = 85;
  vetor[5] = 82;
  vetor[6] = 79;
  vetor[7] = 96;
  vetor[8] = 97;
  vetor[9] = 86;
  
  imprimir(vetor, tamanho);

  build_minheap(vetor, 7);

  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}