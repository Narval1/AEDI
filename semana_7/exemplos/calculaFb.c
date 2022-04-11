#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
  int chave;
  int altura;
  NoArvore *esq, *dir;
};

int altura(NoArvore *raiz) {
  if (raiz == NULL) return -1;
  else return raiz->altura;
}

int calcula_fb(NoArvore *raiz) {
  return altura(raiz->esq) - altura(raiz->dir);
}

int maior(int v1, int v2) {
  return v1 > v2 ? v1 : v2;
}


int getMin(NoArvore *raiz) {
  if (raiz->esq == NULL) return raiz->chave;
  return getMin(raiz->esq);
}

NoArvore *inserir(NoArvore *raiz, int chaveNova) {
  if (raiz == NULL) {
    NoArvore *novoNo = malloc(sizeof(NoArvore));
    novoNo->chave = chaveNova;
    novoNo->altura = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    return novoNo;
  }

  if (chaveNova < raiz->chave) raiz->esq = inserir(raiz->esq, chaveNova);
  if (chaveNova > raiz->chave) raiz->dir = inserir(raiz->dir, chaveNova);

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

  return raiz;  
}

NoArvore *remover(NoArvore *raiz, int chave) {
  if (raiz == NULL) return NULL;
  if (chave < raiz->chave) raiz->esq = remover(raiz->esq, chave);
  else if (chave > raiz->chave) raiz->dir = remover(raiz->dir, chave);
  else {
    //no folha
    if (raiz->dir == NULL && raiz->esq == NULL) {
      free(raiz);
      return NULL;
    }

    if (raiz->esq == NULL) {
      NoArvore *arvoredir = raiz->dir;
      free(raiz);
      return arvoredir;
    }

    if (raiz->dir == NULL) {
      NoArvore *arvoreesq = raiz->esq;
      free(raiz);
      return arvoreesq;
    }

    int sucessor = getMin(raiz->dir);
    raiz->chave = sucessor;
    raiz->dir = remover(raiz->dir, sucessor);
  }

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

  return raiz;
}

NoArvore *buscar(NoArvore *raiz, int chave) {
  if (raiz == NULL) return NULL;
  if (raiz->chave == chave) return raiz;
  if (raiz->chave > chave) return buscar(raiz->esq, chave);
  return buscar(raiz->dir, chave);
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

  NoArvore *no = buscar(tree, 50);
  int fb = calcula_fb(no);
  printf("fb(%d) = %d\n", no->chave, fb);

  liberarArvore(tree);

  return 0;
}