#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int ordena_lexico(char *a, char *b) {
  int counter = 0;
  
  for (int i = 0; a[i] == b[i] && a[i] != '\0' && b[i] != '\0'; i++) counter++;

  if (a[counter] == '\0' && b[counter] == '\0') return 0;
  if (a[counter] < b[counter]) return -1;

  return 1;
}

int comparar(ItemVetor item1, ItemVetor item2) {
    if (item1.autonomia < item2.autonomia) return -1;
    if (item1.autonomia > item2.autonomia) return 1;

    if (ordena_lexico(item1.planeta, item2.planeta) == -1) return -1;
    if (ordena_lexico(item1.planeta, item2.planeta) == 1) return 1;

    if (ordena_lexico(item1.modelo, item2.modelo) == -1) return -1;
    if (ordena_lexico(item1.modelo, item2.modelo) == 1) return 1;

    return 0;
}

void bubble_sort(ItemVetor *v, int n) {
  int trocou = 1;
  for (int i = 0; i < n - 1 && trocou; i++) {
    trocou = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (comparar(v[j], v[j + 1]) == 1) {
        ItemVetor tmp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = tmp;
        trocou = 1;
      }
    }
  }
}

int main() {
  ItemVetor vetor[8] = {
    {"DiscoA", "Terra", 500},
    {"DiscoB", "Terra", 20},
    {"DiscoC", "Marte", 25},
    {"DiscoD", "Marte", 40},
    {"DiscoE", "Marte", 40},
    {"DiscoF", "Jupiter", 90},
    {"DiscoG", "Saturno", 90},
    {"DiscoH", "Saturno", 150}
  };

  bubble_sort(vetor, 8);

  for (int i = 0; i < 8; i++) {
    printf("%s %s %d\n", vetor[i].modelo, vetor[i].planeta, vetor[i].autonomia);
  }

  return 0; 
}