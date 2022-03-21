#include <stdlib.h>
#include <stdio.h>

typedef struct disciplina Disciplina;
struct disciplina {
  int cod;
  char *nome;
  Disciplina *requisito;
};

typedef struct curso Curso;
struct curso {
  int cod_curso;
  char *nome_curso;
  Disciplina *ultima_disciplina;
};

//funcao pra verificar qual palavra e maior lexicograficamente.
int func (char *a, char *b) {
  int counter = 0;
  
  for (int i = 0; a[i] == b[i] && a[i] != '\0' && b[i] != '\0'; i++) counter++;

  //case a is lower than b.
  if (a[counter] < b[counter]) return 1;

  //case a is bigger or equal than b.
  return 0;
}

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina) {
  char *ultimaDisciplina = curso->ultima_disciplina->nome;
  char *novaDisciplina = nova_disciplina->nome;
  
  //caso a disciplina nova seja maior lexicograficamente que a ultima disciplina.
  if (func(novaDisciplina, ultimaDisciplina) == 0) {
    nova_disciplina->requisito = curso->ultima_disciplina;
    curso->ultima_disciplina = nova_disciplina;
    return;
  }

  /**
  para termos a referencia da ultima disciplina que ainda e maior lexicograficamente que 
  a nova disciplina usamos o aux. este ira receber o valor da disciplina atual, e disciplinaAtual vai 
  receber o valor do requisito desta.
  verifica-se que nao e null pra n ter segmentation fault.
  */
  Disciplina *disciplinaAtual = curso->ultima_disciplina, *aux;
  while (func(novaDisciplina, disciplinaAtual->nome) == 1) {
    aux = disciplinaAtual;
    disciplinaAtual = disciplinaAtual->requisito;
    if (disciplinaAtual == NULL) break;
  }
  
  aux->requisito = nova_disciplina;
  nova_disciplina->requisito = disciplinaAtual;
}


int main() {
  Disciplina *B = malloc(sizeof(Disciplina));
  B->nome = "B";
  B->requisito = NULL;

  Disciplina *D = malloc(sizeof(Disciplina));
  D->nome = "D";
  D->requisito = B;

  Disciplina *F = malloc(sizeof(Disciplina));
  F->nome = "F";
  F->requisito = D;

  Curso *curso = malloc(sizeof(curso));
  curso->ultima_disciplina = F;

  Disciplina *A = malloc(sizeof(Disciplina));
  A->nome = "A";
  A->requisito = NULL;

  Disciplina *C = malloc(sizeof(Disciplina));
  C->nome = "C";
  C->requisito = NULL;

  Disciplina *E = malloc(sizeof(Disciplina));
  E->nome = "E";
  E->requisito = NULL;

  Disciplina *G = malloc(sizeof(Disciplina));
  G->nome = "G";
  G->requisito = NULL;


  printf("\n");
  printf("dA { requisito: %s }\n", A->requisito != NULL ? A->requisito->nome : "null");
  printf("dB { requisito: %s }\n", B->requisito != NULL ? B->requisito->nome : "null");
  // printf("dC { requisito: %s }\n", C->requisito != NULL ? C->requisito->nome : "null");
  // printf("dD { requisito: %s }\n", D->requisito != NULL ? D->requisito->nome : "null");
  printf("\n");

  insere_disciplina(curso, A);

  printf("\n");
  printf("dA { requisito: %s }\n", A->requisito != NULL ? A->requisito->nome : "null");
  printf("dB { requisito: %s }\n", B->requisito != NULL ? B->requisito->nome : "null");
  // printf("dC { requisito: %s }\n", C->requisito != NULL ? C->requisito->nome : "null");
  // printf("dD { requisito: %s }\n", D->requisito != NULL ? D->requisito->nome : "null");
  printf("\n");

  free(A);
  free(B);
  free(C);
  free(D);
  free(E);
  free(F);
  free(G);

  return 0;
}