#include <stdio.h>

void funcao(int a, int b, int *resultado) {
  *resultado = 0;
    for (int i = 1; i <= a; i++) {
      int auxiliar = 0;
      for (int j = 1; j <= b; j++) {
        auxiliar = auxiliar + i * j + 10 ;
      }
      *resultado =  (5 * i * auxiliar) + *resultado;
    }
}

