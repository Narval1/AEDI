#include <stdlib.h>
#include <stdio.h>

typedef struct disciplina Disciplina;
struct disciplina {
  int cod;
  char *nome;
  int creditos;
  Disciplina *requisito;
};

typedef struct curso Curso;
struct curso {
  int cod_curso;
  char *nome_curso;
  Disciplina *ultima_disciplina;
};

int func (char *a, char *b) {
  int counter = 1;
  //for roda n-1 vezes por isso o contador tem que começar em 1.
  for (int i = 0; a[i] != '\0' && b[i] != '\0' && a[i] == b[i]; i++) counter++;

  //case a is equal than b lexicograficaly.
  if (a[counter] == b[counter] && a[counter] == '\0') return 1;

  //case a is lower than b lexicograficaly.
  if (a[counter] < b[counter]) return 2;

  //case a is bigger than b lexicograficaly.
  return 0;
}

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina) {
  char *novaDisciplina = nova_disciplina->nome;
  char *ultimaDisciplina = curso->ultima_disciplina->nome;

  /*if (func(novaDisciplina, ultimaDisciplina) == 0) {
    nova_disciplina->requisito = curso->ultima_disciplina;
    return;
  }*/

  Disciplina disciplinaAtual = curso->ultima_disciplina;
  for (int i = 0; i < 3; i++) {
    //printf("%s\n", disciplinaAtual->nome);
    printf("%d\n", i);
  }
}

int main () {
  char a[10] = "palavra180", b[10] = "palavra22";

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

  Disciplina calculo_4;
  calculo_4.cod = 666;
  calculo_4.nome = "calculo 4";
  calculo_4.requisito = &calculo_3;


  Curso matematica = {1, "matematica", &calculo_3};
 // insere_disciplina(&matematica, &calculo_4);
}