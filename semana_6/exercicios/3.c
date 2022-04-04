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

int buscaNo(NoArvore *raiz, int chaveBusca) {
  if (raiz == NULL) return 0;
  if (chaveBusca == raiz->chave) return 1;
  if (chaveBusca < raiz->chave) return buscaNo(raiz->esq, chaveBusca);
  return buscaNo(raiz->dir, chaveBusca);
}

int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2) {
    if (raiz1 == NULL || raiz2 == NULL) return 0;
    return buscaNo(raiz2, raiz1->chave) + qtd_chaves_comuns(raiz1->dir, raiz2) + qtd_chaves_comuns(raiz1->esq, raiz2);
}


int main() {
  NoArvore *tree = NULL, *tree2 = NULL;
  tree = inserir(tree, 11);
  tree = inserir(tree, 22);
  tree = inserir(tree, 5);
  tree = inserir(tree, 10);

  tree2 = inserir(tree2, 55);
  tree2 = inserir(tree2, 22);
  tree2 = inserir(tree2, 10);
  tree2 = inserir(tree2, 33);

  imprimir(tree, 0);
  printf("\n-----------");
  imprimir(tree2, 0);
  printf("\n");

  int result = qtd_chaves_comuns(tree, tree2);
  printf("%d\n", result);

  liberarArvore(tree);
  liberarArvore(tree2);

  return 0;
}

