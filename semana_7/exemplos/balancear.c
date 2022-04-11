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

NoArvore *buscar(NoArvore *raiz, int chave) {
  if (raiz == NULL) return NULL;
  if (raiz->chave == chave) return raiz;
  if (raiz->chave > chave) return buscar(raiz->esq, chave);
  return buscar(raiz->dir, chave);
}

NoArvore *rotaciona_direita(NoArvore *raiz) {
  NoArvore *filho_esq = raiz->esq;
  NoArvore *filho_esq_dir = filho_esq->dir;

  raiz->esq = filho_esq_dir;
  filho_esq->dir = raiz;

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));
  filho_esq->altura = 1 + maior(altura(filho_esq->esq), altura(filho_esq->dir));

  return filho_esq;
}

NoArvore *rotaciona_esquerda(NoArvore *raiz) {
  NoArvore *filho_dir = raiz->dir;
  NoArvore *filho_dir_esq = filho_dir->esq;

  raiz->dir = filho_dir_esq;
  filho_dir->esq = raiz;

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));
  filho_dir->altura = 1 + maior(altura(filho_dir->esq), altura(filho_dir->dir));

  return filho_dir;
}

NoArvore *balancear(NoArvore *raiz) {
  int fb = calcula_fb(raiz);
  if (fb > 1) {
    if (calcula_fb(raiz->esq) < 0) raiz->esq = rotaciona_esquerda(raiz->esq);
    raiz = rotaciona_direita(raiz);
  }
  if (fb < -1) {
    if (calcula_fb(raiz->dir) > 0) raiz->dir = rotaciona_direita(raiz->dir);
    raiz = rotaciona_esquerda(raiz);
  }
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

int main() {
  NoArvore *tree = NULL;
  tree = inserir(tree, 30);
  tree = inserir(tree, 20);
  tree = inserir(tree, 10);
  
  imprimir(tree, 0);
  printf("\n-----------\n");

  tree = balancear(tree);
  imprimir(tree, 0);
  printf("\n");

  return 0;
}