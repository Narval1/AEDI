#include "qtd_palavras_frase.h"

void imprimir_qtd_palavras(char texto[]) {
  int counter = 1, i = 0;
  while (texto[i] != '\0') {
     if ((int) texto[i] == 32 && (int) texto[i + 1] != 32 && (int) texto[i + 1] != 46 ) counter++;
     if ((int) texto[i] == 46) {
       printf("%d\n", counter);
       counter = 0;
     }
     i++;
  }
}