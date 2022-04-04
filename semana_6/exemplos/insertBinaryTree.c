#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
  int chave;
  NoArvore *esquerda, *direita;
};

NoArvore *inserir(NoArvore *raiz, int chaveNova) {
  if (raiz == NULL) {
    NoArvore *novoNo = malloc(sizeof(NoArvore));
    novoNo->chave = chaveNova;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    
    return novoNo;
  }

  if (chaveNova < raiz->chave) raiz->esquerda = inserir(raiz->esquerda, chaveNova);
  if (chaveNova > raiz->chave) raiz->direita = inserir(raiz->direita,chaveNova);

  return raiz;  
}

void imprimir(NoArvore *raiz, int profundidade) {
  if (raiz == NULL) return;

  imprimir(raiz->direita, profundidade + 1);
  printf("\n");
  for (int i = 0; i < profundidade; i++) printf("   ");
  printf("%d", raiz->chave);
  imprimir(raiz->esquerda, profundidade + 1);
}

int main() {
  NoArvore *tree = NULL;
  tree = inserir(tree, 50);
  tree = inserir(tree, 10);
  tree = inserir(tree, 80);
  tree = inserir(tree, 90);
  tree = inserir(tree, 70);
  tree = inserir(tree, 20);

  imprimir(tree, 0);
  printf("\n");
  return 0;
}