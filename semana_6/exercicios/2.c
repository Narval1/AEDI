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

int numero_nos(NoArvore *raiz){
    if (raiz == NULL) return 0;
    return (1 + numero_nos(raiz->esq) + numero_nos(raiz->dir));
}

int numero_nos_folha(NoArvore *raiz){
    if (raiz == NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;
    return numero_nos_folha(raiz->esq) + numero_nos_folha(raiz->dir);
}

int numero_nos_internos(NoArvore *raiz){
    if (raiz == NULL) return 0;
    return numero_nos(raiz) - numero_nos_folha(raiz);
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

  int result = numero_nos_internos(tree);

  printf("%d\n", result);

  liberarArvore(tree);

  return 0;
}

