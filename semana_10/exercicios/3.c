#include <stdio.h>
#include <stdlib.h>

void max_heapfy(int *v, int n, int i) {
  int maior = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  if (esq < n && v[esq] > v[maior]) maior = esq;
  if (dir < n && v[dir] > v[maior]) maior = dir;

  if (maior != i) {
    int tmp = v[i];
    v[i] = v[maior];
    v[maior] = tmp;

    max_heapfy(v, n, maior);
  }
}

void build_maxheap(int * v, int n) {
  for (int i = n/2 - 1; i >= 0; i--) max_heapfy(v, n, i);
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

int heap_min_max(int n, int *v) {
  int *minHeap = malloc(sizeof(int) * n);
  int *maxHeap = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    minHeap[i] = v[i];
    maxHeap[i] = v[i];
  }

  build_minheap(minHeap, n);
  build_maxheap(maxHeap, n);

  int result = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] != maxHeap[i]) result = 1;
  }

  // se result n for alterado e um heap de  maximo
  if (result == 0) {
    free(maxHeap);
    free(minHeap);

    return 2;
  }

  result = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] != minHeap[i]) result = 0;
  }

  free(maxHeap);
  free(minHeap);
  
  return result;
}

int main() {

  int tamanho;
  scanf("%d", &tamanho);

  int *vetor = malloc(sizeof(int) * tamanho);

  for (int i = 0; i < tamanho; i++) {
    int number;
    scanf("%d", &number);
    vetor[i] = number;
  }
  
  int result = heap_min_max(tamanho, vetor);
  printf("%d\n", result);

  free(vetor);

  return 0; 
}