#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
  char *chave;
  NoArvore *esq, *dir;
};

char *getMin(NoArvore *raiz) {
  if (raiz->esq == NULL) return raiz->chave;
  return getMin(raiz->esq);
}

NoArvore *buscar(NoArvore *raiz, char *chaveBusca) {
  if (raiz == NULL) return NULL;

  if (strcmp(chaveBusca, raiz->chave) == 0) return raiz;
  if (strcmp(chaveBusca , raiz->chave) < 0) return buscar(raiz->esq, chaveBusca);

  return buscar(raiz->dir, chaveBusca);
}

NoArvore *inserir(NoArvore *raiz, char *chaveNova) {
  if (raiz == NULL) {
    NoArvore *novoNo = malloc(sizeof(NoArvore));
    novoNo->chave = malloc(sizeof(char) * 100);
    strcpy(novoNo->chave, chaveNova);
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    return novoNo;
  }

  if (strcmp(chaveNova, raiz->chave) < 0) raiz->esq = inserir(raiz->esq, chaveNova);
  if (strcmp(chaveNova, raiz->chave) > 0) raiz->dir = inserir(raiz->dir, chaveNova);

  return raiz;  
}

NoArvore *remover(NoArvore *raiz, char *chave) {
  if (raiz == NULL) return NULL;
  if (strcmp(chave, raiz->chave) < 0) raiz->esq = remover(raiz->esq, chave);
  else if (strcmp(chave, raiz->chave) > 0) raiz->dir = remover(raiz->dir, chave);
  else {
    //no folha
    if (raiz->dir == NULL && raiz->esq == NULL) {
      free(raiz->chave);
      free(raiz);
      return NULL;
    }

    if (raiz->esq == NULL) {
      NoArvore *arvoredir = raiz->dir;
      free(raiz->chave);
      free(raiz);
      return arvoredir;
    }

    if (raiz->dir == NULL) {
      NoArvore *arvoreesq = raiz->esq;
      free(raiz->chave);
      free(raiz);
      return arvoreesq;
    }

    char *sucessor = getMin(raiz->dir);
    strcpy(raiz->chave, sucessor);
    raiz->dir = remover(raiz->dir, sucessor);
  }
  return raiz;
}

void liberar_arvore(NoArvore *raiz){
  if (raiz == NULL) return;

  liberar_arvore(raiz->esq);
  liberar_arvore(raiz->dir);
  free(raiz->chave);
  free(raiz);
}

void imprimir(NoArvore *raiz, int profundidade) {
  if (raiz == NULL) return;

  imprimir(raiz->dir, profundidade + 1);
  printf("\n");
  for (int i = 0; i < profundidade; i++) printf("     ");
  printf("%s", raiz->chave);
  imprimir(raiz->esq, profundidade + 1);
}

int main() {
  NoArvore *tree = NULL;
  tree = inserir(tree, "dados");
  tree = inserir(tree, "algoritmos");
  tree = inserir(tree, "estruturas");
  tree = inserir(tree, "professor");

  imprimir(tree, 0);
  printf("\n----------------");

  NoArvore *aux = buscar(tree, "dados");
  printf("\n%s\n", aux->chave);

  imprimir(tree, 0);
  printf("\n");
  liberar_arvore(tree);

  return 0;
}

