#include <stdio.h>
#include <stdlib.h>

void countingsort(char *v, int k) {
  int c[k + 1];
  int n = 0;

  int vetorFrequncia[k + 1];

  for (int i = 0; v[i] != '\0'; i++) n++;

  for (int i = 0; i < k + 1; i++) {
    c[i] = 0;
    vetorFrequncia[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    int aux = v[i];
    c[aux - 65]++;
    vetorFrequncia[aux - 65]++;
  }

  for (int i = 1; i < k + 1; i++) c[i] = c[i] + c[i - 1];

  int saida[n];
  int atual;
  for (int i = n - 1; i >= 0; i--) {
    atual = v[i];
    saida[c[atual - 65] - 1] = atual;
    c[atual - 65]--;
  }

  printf("[");
  for (int i = 0; i < 25; i++) printf("%d ", vetorFrequncia[i]);
  printf("%d]\n", vetorFrequncia[25]);

  printf("[");
  for (int i = 1; i < 26; i++) printf("%d ", c[i]);
  printf("%d]\n", c[26]);

  char ordenado[1000];
  for (int i = 0; i < n; i++) ordenado[i] = saida[i];
  
  printf("%s\n", ordenado);
}

int main() {

  char *str = malloc(sizeof(char) * 1000);

  fgets(str, sizeof(char) * 1000, stdin);

  countingsort(str, 26);

  free(str);

  return 0; 
}