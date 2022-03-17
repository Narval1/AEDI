#include <stdio.h>
#include <stdlib.h>

typedef struct disco DiscoVoador;
struct disco{
  char *modelo;
  char *planeta;
  int autonomia;
};

int verificar_ordenacao(DiscoVoador *discos, int n_discos) {
  //ordenaçao por modelo, quebra se  tiver  algo na frente da letra.
  long int count_crescente = 1, count_decrescente = 1;
  for (int i = 0; i < n_discos - 1; i++) {

    int j = 0, aux = 0;
    while (discos[i].modelo[j] == discos[i + 1].modelo[j] && discos[i].modelo[j] != '\0' && discos[i + 1].modelo[j] != '\0') {
      j++;
      aux++;
    }
    
    if (discos[i].modelo[aux] > discos[i + 1].modelo[aux]) count_decrescente++;
    if (discos[i].modelo[aux] < discos[i + 1].modelo[aux]) count_crescente++;
  }

  if (count_crescente == n_discos) return 1;
  if (count_decrescente == n_discos) return 2;

  //ordenacao por planeta, esta ok.
  count_crescente = 1;
  for (int i = 0; i < n_discos - 1; i++) {
    if (discos[i].planeta[0] <= discos[i + 1].planeta[0]) count_crescente++;
  }

  if (count_crescente == n_discos) return 3;

  //ordenacao pela autonomia.
  count_crescente = 1;
  for (int i = 0; i < n_discos - 1; i++) {
    if (discos[i].autonomia <= discos[i + 1].autonomia) count_crescente++;
  }

  if (count_crescente == n_discos) return 4;

  return 0;
}



int main () {
  char modeloA[7] = "discoB1";
  char modeloB[7] = "discoB";
  char saturno[10] = "saturno";
  char terra[10] = "terra";

  DiscoVoador discos[2] = {{modeloA, terra, 100}, {modeloB, saturno, 180}};

  int resultado = verificar_ordenacao(discos, 2);  
  printf("%d\n", resultado);
}