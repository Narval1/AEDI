#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
  int chave;
  NoArvore *esq, *dir;
};

NoArvore *inserir(NoArvore *raiz, int chaveNova) {
  if (raiz == NULL) {
    NoArvore *novoNo = malloc(sizeof(NoArvore));
    novoNo->chave = chaveNova;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    return novoNo;
  }

  if (chaveNova < raiz->chave) raiz->esq = inserir(raiz->esq, chaveNova);
  if (chaveNova > raiz->chave) raiz->dir = inserir(raiz->dir, chaveNova);

  return raiz;  
}

void imprimir(NoArvore *raiz, int profundidade) {
  if (raiz == NULL) return;

  imprimir(raiz->dir, profundidade + 1);
  printf("\n");
  for (int i = 0; i < profundidade; i++) printf("   ");
  printf("%d", raiz->chave);
  imprimir(raiz->esq, profundidade + 1);
}

void percursoEmOrdem(NoArvore *raiz) {
  if (raiz == NULL) return;

  percursoEmOrdem(raiz->esq);
  printf("%d ", raiz->chave);
  percursoEmOrdem(raiz->dir);
}

void percursoEmPreOrdem(NoArvore *raiz) {
  if (raiz == NULL) return;

  printf("%d ", raiz->chave);
  percursoEmPreOrdem(raiz->esq);
  percursoEmPreOrdem(raiz->dir);
}

void percursoEmPosOrdem(NoArvore *raiz) {
  if (raiz == NULL) return;

  percursoEmPosOrdem(raiz->esq);
  percursoEmPosOrdem(raiz->dir);
  printf("%d ", raiz->chave);
}

void liberarArvore(NoArvore *raiz){
  if (raiz == NULL) return;

  liberarArvore(raiz->esq);
  liberarArvore(raiz->dir);
  free(raiz);
}

int main() {
  NoArvore *tree = NULL;
  tree = inserir(tree, 50);
  tree = inserir(tree, 10);
  tree = inserir(tree, 80);
  tree = inserir(tree, 70);
  tree = inserir(tree, 90);
  tree = inserir(tree, 85);

  liberarArvore(tree);

  return 0;
}