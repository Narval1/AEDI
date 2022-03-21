#include <stdio.h>
#include <stdlib.h>

void frequencia_string(const char *str, const char *texto, int *qtd) {
  int countStr = 0, countTexto = 0;
  *qtd = 0;

  // determinar o tamanho da string.
  for (int i = 0; str[i] != '\0'; i++) countStr++;
  // determinar o tamanho do texto
  for (int i = 0; texto[i] != '\0'; i++) countTexto++;

  // cria uma string em lowercase
  char strAux[countStr];

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 65 && str[i] <= 90) {
      strAux[i] = str[i] + 32;
      continue;
    }
    strAux[i] = str[i];
  }

  // criar um texto em lowercase
  char textoAux[countTexto];

  for (int i = 0; texto[i] != '\0'; i++) {
    if (texto[i] >= 65 && texto[i] <= 90) {
      textoAux[i] = texto[i] + 32;
      continue;
    }
    textoAux[i] = texto[i];
  }

  //conta a quantidade de repeticoes.
  for (int i = 0; i < countTexto; i++) {
    if (textoAux[i] == strAux[0]) {
      int counter = 0;
      for (int j = 0; j < countStr; j++) {
        if (textoAux[i + j] == strAux[j]) counter++;
        if (counter == countStr) *qtd = *qtd + 1;
      }
    }
  }
}


int main() {
 const char texto[] = "abcdeABCaBcAbcAbCABcabCaBCde";
 const char c[] = "ABC";
 int qtd = 0;

 frequencia_string(c, texto, &qtd);
 printf("%d\n", qtd);
}