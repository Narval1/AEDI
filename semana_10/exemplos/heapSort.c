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

void max_heapfy(int *v, int n, int i) {
  int maior = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  // verifico se o esq/dir e menor que n (esta dentro do vetor)
  // verifco se e maior que o suposto no maior
  if (esq < n && v[esq] > v[maior]) maior = esq;
  if (dir < n && v[dir] > v[maior]) maior = dir;
  // caso um dos filhos seja maior, maior sera diferente de i, suposicao inicial
  // realizamos a troca
  if (maior != i) {
    int tmp = v[i];
    v[i] = v[maior];
    v[maior] = tmp;
    // chamada recursiva da funcao
    max_heapfy(v, n, maior);
  }
}

void build_maxheap(int * v, int n) {
  for (int i = n/2 - 1; i >= 0; i--) max_heapfy(v, n, i);
}

void heapsort(int *v, int n) {
  build_maxheap(v, n);
  for (int i = n - 1; i >= 0; i--) {
    int tmp = v[i];
    v[i] = v[0];
    v[0] = tmp;
    max_heapfy(v, i, 0);
  }
}

int main() {
  srand(time(NULL));

  int tamanho = 7;
  int *vetor = vetor_aleatorio(tamanho);

  imprimir(vetor, tamanho);

  heapsort(vetor, 7);

  imprimir(vetor, tamanho);

  free(vetor);

  return 0; 
}