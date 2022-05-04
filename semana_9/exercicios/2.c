#include <stdio.h>
#include <stdlib.h>

typedef struct Disco Disco;
struct Disco {
   int codigo;
   double preco;
};

int particiona1(Disco *v, int esq, int dir, int *comparacoes) {
  Disco pivo = v[dir];

  int ultimo_menores = esq - 1;
  for (int i = esq; i < dir; i++) {
    (*comparacoes)++;

    if (v[i].codigo < pivo.codigo) {
      ultimo_menores++;
      Disco aux = v[ultimo_menores];
      v[ultimo_menores] = v[i];
      v[i] = aux;
    }
  }

  ultimo_menores++;
  v[dir] = v[ultimo_menores];
  v[ultimo_menores] = pivo;

  return ultimo_menores;
}

int particiona2(Disco *v, int esq, int dir, int *comparacoes) {
  // ultimo elemento como pivo
  Disco pivo = v[dir];

  int ultimo_menores = esq - 1;
  for (int i = esq; i < dir; i++) {
    (*comparacoes)++;

    if (v[i].codigo > pivo.codigo) {
      ultimo_menores++;
      Disco aux = v[ultimo_menores];
      v[ultimo_menores] = v[i];
      v[i] = aux;
    }
  }

  ultimo_menores++;
  v[dir] = v[ultimo_menores];
  v[ultimo_menores] = pivo;

  return ultimo_menores;
}

int particiona3(Disco *v, int esq, int dir, int *comparacoes) {
  // ultimo elemento como pivo
  Disco pivo = v[dir];

  int ultimo_menores = esq - 1;
  for (int i = esq; i < dir; i++) {
    (*comparacoes)++;

    if (v[i].preco < pivo.preco) {
      ultimo_menores++;
      Disco aux = v[ultimo_menores];
      v[ultimo_menores] = v[i];
      v[i] = aux;
    }

    if (v[i].preco == pivo.preco) {

      if (v[i].codigo < pivo.codigo) {
        ultimo_menores++;
        Disco aux = v[ultimo_menores];
        v[ultimo_menores] = v[i];
        v[i] = aux;
      }
    }
  }

  ultimo_menores++;
  v[dir] = v[ultimo_menores];
  v[ultimo_menores] = pivo;

  return ultimo_menores;
}

void quick_sort(Disco *v, int esq, int dir, int tipo, int *comparacoes) {
  if (esq < dir) {
    int i_pivo;
    if (tipo == 1) {
      i_pivo = particiona1(v, esq, dir, comparacoes);
    }
    if (tipo == 2) {
      i_pivo = particiona2(v, esq, dir, comparacoes);
    }
    if (tipo == 3) {
      i_pivo = particiona3(v, esq, dir, comparacoes);
    }
    quick_sort(v, esq, i_pivo - 1, tipo, comparacoes);
    quick_sort(v, i_pivo + 1, dir, tipo, comparacoes);
  }
}

int quicksort(Disco *v, int n, int tipo) {
  int comparacoes = 0;
  quick_sort(v, 0, n - 1, tipo, &comparacoes);

  return comparacoes;
}

