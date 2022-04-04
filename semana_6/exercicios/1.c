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

void liberarArvore(NoArvore *raiz){
  if (raiz == NULL) return;

  liberarArvore(raiz->esq);
  liberarArvore(raiz->dir);
  free(raiz);
}

void imprimir(NoArvore *raiz, int profundidade) {
  if (raiz == NULL) return;

  imprimir(raiz->dir, profundidade + 1);
  printf("\n");
  for (int i = 0; i < profundidade; i++) printf("   ");
  printf("%d", raiz->chave);
  imprimir(raiz->esq, profundidade + 1);
}

int menor(NoArvore *raiz) {
    if (raiz == NULL) return -1;
    while (raiz->esq != NULL) raiz = raiz->esq;
    return raiz->chave;
}

int maior(NoArvore *raiz) {
    if (raiz == NULL) return -1;
    while (raiz->dir != NULL) raiz = raiz->dir;
    return raiz->chave;
}

int main() {
  NoArvore *tree = NULL;
  tree = inserir(tree, 50);
  tree = inserir(tree, 10);
  tree = inserir(tree, 80);
  tree = inserir(tree, 70);
  tree = inserir(tree, 90);
  tree = inserir(tree, 85);

  imprimir(tree, 0);
  printf("\n");

  int resultMaior = maior(tree);
  int resultMenor = menor(tree);

  printf("%d\n%d\n", resultMaior,resultMenor);

  liberarArvore(tree);

  return 0;
}

