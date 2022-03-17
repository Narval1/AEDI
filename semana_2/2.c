#include <stdio.h>
#include <stdlib.h>

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido) {
    *n_expandido = 0;

    int position = 0;
    for (int i = 1; i < n_compactado; i = i + 2) *n_expandido = *n_expandido + vetor[i];
    
    int *array = malloc(sizeof(int) * *n_expandido);

    for (int i = 1; i < n_compactado; i++) {
      if (i % 2 != 0) {
        for (int j = 0; j < vetor[i]; j++) {
          array[position] = vetor[i - 1];
          position++;
        }
      }
    }

    return array;
}

