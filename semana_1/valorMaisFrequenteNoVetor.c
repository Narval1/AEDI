#include "valor_freq.h"

int valor_frequente(int v[], int n) {
    //bubble sort
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
        //caso o elemento da esquerda seja maior que o da direita, troca eles de lugar
        if (v[j] > v[j + 1]) {
          int temporary = v[j + 1];
          v[j + 1] = v[j];
          v[j] = temporary;
        }
      }
    }

    //com o array em ordem fica facil achar o valor mais frequente.
    int currentCounter = 1, maximumCounter = 1;
    int mostFrequenteElement = v[0];

    for (int i = 0; i < n - 1; i++) {
      if (v[i] == v[i + 1]) {
        currentCounter++;
      } else {
        if (currentCounter > maximumCounter) {
          maximumCounter = currentCounter;
          mostFrequenteElement = v[i];
        }
        currentCounter = 1;
      }
    }

    //caso o ultimo elemento seja o mais frequente
    if (currentCounter > maximumCounter) mostFrequenteElement = v[n - 1];

    return mostFrequenteElement;
}