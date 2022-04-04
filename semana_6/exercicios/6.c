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

int sucessor(NoArvore *raiz, int chave) {
    NoArvore *no = raiz;
    int aux = -1;

    if (no == NULL) return -1;

    while (no != NULL) {
      if (no->chave > chave) {
        aux = no->chave;
        no = no->esq;
      }
      else if (no->chave < chave) no = no->dir;
      else if (no->chave == chave) {
        if (no->dir != NULL) {
          no = no->dir;
          while (no->esq != NULL) no = no->esq;
          return no->chave;
        }

        if (aux == -1) return -1;
        return aux;
      }
    }
}

int getMin(NoArvore *raiz) {
  if (raiz->esq == NULL) return raiz->chave;
  return getMin(raiz->esq);
}

int getMax(NoArvore *raiz) {
  if (raiz->dir == NULL) return raiz->chave;
  return getMax(raiz->dir);
}

int buscaNo(NoArvore *raiz, int chaveBusca) {
  if (raiz == NULL) return -1;
  if (chaveBusca == raiz->chave) return raiz->chave;
  if (chaveBusca < raiz->chave) return buscaNo(raiz->esq, chaveBusca);
  return buscaNo(raiz->dir, chaveBusca);
}

int menor_chave_comum(NoArvore *raiz1, NoArvore *raiz2) {
  if (raiz1 == NULL || raiz2 == NULL) return -1;
  int min = getMin(raiz1), max = getMax(raiz1), result;

  while (min != max) {
    result = buscaNo(raiz2, min);
    if (result != -1) return result;
    min = sucessor(raiz1, min);
  }
  result = buscaNo(raiz2, min);
  if (result != -1) return result;
  return -1;
}


int main() {
  NoArvore *tree = NULL;
  tree = inserir(tree, 120);
  tree = inserir(tree, 110);
  tree = inserir(tree, 150);
  tree = inserir(tree, 250);
  tree = inserir(tree, 200);
  tree = inserir(tree, 1);
  tree = inserir(tree, 2);
  tree = inserir(tree, 90);
  tree = inserir(tree, 10);
  tree = inserir(tree, 100);
  tree = inserir(tree, 20);
  tree = inserir(tree, 160);

  int result = getMax(tree);
  printf("%d\n", result);

  liberarArvore(tree);

  return 0;
}

