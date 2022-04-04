#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
  int chave;
  NoArvore *esquerda, *direita;
};

NoArvore *buscaNo(NoArvore *raiz, int chaveBusca) {
  if (raiz == NULL) return NULL;
  if (chaveBusca == raiz->chave) return raiz;
  if (chaveBusca < raiz->chave) return buscaNo(raiz->esquerda, chaveBusca);
  return buscaNo(raiz->direita, chaveBusca);
}