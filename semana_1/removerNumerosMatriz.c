#include "numeros_matriz.h"

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas]) {

  if (l == -1) return;
  if (l == n_linhas) return;
  if (c == -1) return;
  if (c == n_colunas) return;

  int temporary = m[l][c];
  m[l][c] = 0;

  if (m[l - 1][c] == temporary) remover_numeros_matriz(l - 1, c, n_linhas, n_colunas, m);
  if (m[l + 1][c] == temporary) remover_numeros_matriz(l + 1, c, n_linhas, n_colunas, m);
  if (m[l][c - 1] == temporary) remover_numeros_matriz(l, c - 1, n_linhas, n_colunas, m);
  if (m[l][c + 1] == temporary) remover_numeros_matriz(l, c + 1, n_linhas, n_colunas, m);
}

