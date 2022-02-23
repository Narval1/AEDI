#include "qtd_digitos.h"

int quantidade_digitos(int numero) {
  int counter = 1;
  int ok = 1;
  if (numero < 0) numero = (-1) * numero;
  while (ok) {
    if (numero % 10 != numero) {
      counter++;
      numero = numero / 10;
    } else {
      ok = 0;
    }
  }
  return counter;
}