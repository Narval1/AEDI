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

int comparar(int a, int b) {
  if (a > b) return 1;
  if (a < b) return -1;
  return 0;
}

int max_heapfy(int *v, int n, int i) {
  int maior = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  int aux = 0;

  // verifico se o esq/dir e menor que n (esta dentro do vetor)
  // verifco se e maior que o suposto no maior
  if (esq < n) {
    aux++;
    if (comparar(v[esq], v[maior]) > 0) maior = esq;
  }

  if (dir < n) {
    aux++;
    if (comparar(v[dir], v[maior]) > 0) maior = dir;
  }

  // caso um dos filhos seja maior, maior sera diferente de i, suposicao inicial
  // realizamos a troca
  if (maior != i) {
    int tmp = v[i];
    v[i] = v[maior];
    v[maior] = tmp;
    // chamada recursiva da funcao
    aux = aux + max_heapfy(v, n, maior);
  }

  return aux;
}

int build_maxheap(int * v, int n) {
  int aux = 0;
  for (int i = n/2 - 1; i >= 0; i--) aux = aux + max_heapfy(v, n, i);
  return aux;
}

int heapsort(int *v, int n) {
  int comparacoes = 0;

  comparacoes = comparacoes + build_maxheap(v, n);
  for (int i = n - 1; i >= 0; i--) {
    int tmp = v[i];
    v[i] = v[0];
    v[0] = tmp;
    comparacoes = comparacoes + max_heapfy(v, i, 0);
  }

  return comparacoes;
}

int main() {
  srand(time(NULL));

  int tamanho = 8;
  int *vetor = malloc(sizeof(int) * tamanho);

  vetor[0] = 66;
  vetor[1] = 33;
  vetor[2] = 22;
  vetor[3] = 55;
  vetor[4] = 88;
  vetor[5] = 11;
  vetor[6] = 44;
  vetor[7] = 77;


  imprimir(vetor, tamanho);

  int comparacoes = heapsort(vetor, tamanho);

  imprimir(vetor, tamanho);
  printf("%d\n", comparacoes);

  free(vetor);

  return 0; 
}