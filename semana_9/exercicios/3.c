#include <stdio.h>
#include <stdlib.h>

int dicionarioMarciano(int numero) {
  int result = 0, multiplicador = 1;

  while (numero > 0) {
    int aux;
    switch (numero % 10) {
      case 0: aux = 0; break;
      case 5: aux = 1; break;
      case 6: aux = 2; break;
      case 4: aux = 3; break;
      case 8: aux = 4; break;
      case 9: aux = 5; break;
      case 7: aux = 6; break;
      case 3: aux = 7; break;
      case 1: aux = 8; break;
      case 2: aux = 9; break;
    }

    result = result + aux * multiplicador;
    multiplicador = multiplicador * 10;
    
    numero = numero / 10;
  }
  return result;
}

int comparaMarciano(int a, int b) {
  a = dicionarioMarciano(a);
  b = dicionarioMarciano(b);

  return a < b;
}

int particiona(int *v, int esq, int dir, int *comparacoes) {
  // ultimo elemento como pivo
  int pivo = v[dir];

  int ultimo_menores = esq - 1;
  for (int i = esq; i < dir; i++) {
    (*comparacoes)++;
    if (comparaMarciano(v[i], pivo)) {
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

void quick_sort(int *v, int esq, int dir, int *comparacoes) {
  // pelo menos dois elementos
  if (esq < dir) {
    int i_pivo = particiona(v, esq, dir, comparacoes);
    quick_sort(v, esq, i_pivo - 1, comparacoes);
    quick_sort(v, i_pivo + 1, dir, comparacoes);
  }
}

int quicksortm(int *v, int n) {
  int comparacoes = 0;
  quick_sort(v, 0, n - 1, &comparacoes);
  return comparacoes;
}

void imprimir(int *v, int n) {
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
}

int main() {
  int vetorMarciano[6] = {0, 2, 5, 8, 23, 28};
  int comparacoes;

  comparacoes = quicksort(vetorMarciano, 6);
  imprimir(vetorMarciano, 6);
  printf("%d\n", comparacoes);

  return 0; 
}