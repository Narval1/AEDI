#include <stdlib.h>
#include <stdio.h>

typedef struct disciplina Disciplina;
struct disciplina {
  int cod;
  char *nome;
  int creditos;
  Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
  *qtd = 0;

  if (disciplina->requisito == NULL) {
    return NULL;
  }

  Disciplina *aux = disciplina;
  printf("%s\n", aux->nome);

  while(aux->requisito != NULL) {
    (*qtd)++;
    aux = aux->requisito;
  }

  return aux;
}

int main() {
  Disciplina calculo_3;
  calculo_3.cod = 555;
  calculo_3.nome = "calculo 3";
  calculo_3.creditos = 4;

  Disciplina calculo_2;
  calculo_2.cod = 444;
  calculo_2.nome = "calculo 2";
  calculo_2.creditos = 4;

  Disciplina calculo_1;
  calculo_1.cod = 333;
  calculo_1.nome = "calculo 1";
  calculo_1.creditos = 4;
  calculo_1.requisito = NULL;

  calculo_3.requisito = &calculo_2;
  calculo_2.requisito = &calculo_1;

  int qtd = 0;

  Disciplina *aux = requisito_inicial(&calculo_3, &qtd);
  printf("%s\n",aux->nome);
  return 0;
}