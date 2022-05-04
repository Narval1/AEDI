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

NoArvore *func(NoArvore *raiz, int chaveNova, int *flag) {
  if (raiz == NULL) {
    NoArvore *novoNo = malloc(sizeof(NoArvore));
    novoNo->chave = chaveNova;
    novoNo->altura = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    printf("Inserir:%d\n", novoNo->chave);
    return novoNo;
  }

  if (chaveNova < raiz->chave) raiz->esq = func(raiz->esq, chaveNova, flag);
  if (chaveNova > raiz->chave) raiz->dir = func(raiz->dir, chaveNova, flag);
  if (chaveNova == raiz->chave) printf("Inserir:%d\n", raiz->chave);

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

  int fb = calcula_fb(raiz);
  if (fb > 1 || fb < -1) {
    printf("[No desbalanceado: %d]\n", raiz->chave);
    *flag = 0;
  }

  return raiz;
}

NoArvore *inserir(NoArvore *raiz, int chaveNova) {
  int flag = 1;
  raiz = func(raiz, chaveNova, &flag);
  if (flag == 1) printf("[Ja esta balanceada]\n");
  return raiz;  
}

void liberar_arvore(NoArvore *raiz){
  if (raiz == NULL) return;

  liberar_arvore(raiz->esq);
  liberar_arvore(raiz->dir);
  printf("%d ", raiz->chave);
  free(raiz);
}

int main() {
	NoArvore *raiz = NULL;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
			case 'I' : {
				int valor;
				scanf("%d", &valor);
				raiz = inserir(raiz, valor);
				break;
			}
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}
			case 'P' : {
				printf("[");
				liberar_arvore(raiz);
				printf("]\n");
				break;
			}
		}
	} while (operacao != 'P');
    
	return 0;
}