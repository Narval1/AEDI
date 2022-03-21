#include <stdio.h>
#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante) {

  *quantidade_por_fabricante = malloc(sizeof(int) * 4);

  (*quantidade_por_fabricante)[0] = 0;
  (*quantidade_por_fabricante)[1] = 0;
  (*quantidade_por_fabricante)[2] = 0;
  (*quantidade_por_fabricante)[3] = 0;

  for (int i = 0; i < n_discos; i++) {
    switch (discos[i][7]) {
      case 'A':
        (*quantidade_por_fabricante)[0]++;
        break;
      case 'B':
        (*quantidade_por_fabricante)[1]++;
        break;
      case 'C':
        (*quantidade_por_fabricante)[2]++;
        break;
      case 'D':
        (*quantidade_por_fabricante)[3]++;
        break;
    }
  }
}

