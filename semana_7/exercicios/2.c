#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
  int chave;
  int altura;
  int nota;
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

NoArvore *getMin(NoArvore *raiz) {
  if (raiz->esq == NULL) return raiz;
  return getMin(raiz->esq);
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

NoArvore *buscar(NoArvore *raiz, int chave, int *comparacoes) {
  if (raiz == NULL) return NULL;

  *comparacoes = *comparacoes + 1;

  if (raiz->chave > chave) return buscar(raiz->esq, chave,comparacoes);
  if (raiz->chave < chave) return buscar(raiz->dir, chave, comparacoes);
  return raiz;
}

NoArvore *balancear(NoArvore *raiz) {
  int fb = calcula_fb(raiz);
  if (fb > 1) {
    if (calcula_fb(raiz->esq) < 0) {
      printf("[Rotacao: DD]\n");
      raiz->esq = rotaciona_esquerda(raiz->esq);
      raiz = rotaciona_direita(raiz);
    }
    else {
      printf("[Rotacao: SD]\n");
      raiz = rotaciona_direita(raiz);
    }
  }
  if (fb < -1) {
    if (calcula_fb(raiz->dir) > 0) {
      printf("[Rotacao: DE]\n");
      raiz->dir = rotaciona_direita(raiz->dir);
      raiz = rotaciona_esquerda(raiz);
    }
    else {
      printf("[Rotacao: SE]\n");
      raiz = rotaciona_esquerda(raiz);
    }
  }

  printf("[x=%d y=%d z=%d]\n", raiz->esq->chave, raiz->chave, raiz->dir->chave);
  return raiz;
}

void liberar_arvore(NoArvore *raiz){
  if (raiz == NULL) return;

  liberar_arvore(raiz->esq);
  liberar_arvore(raiz->dir);
  printf("%d ", raiz->chave);
  free(raiz);
}

NoArvore *auxiliar_inserir(NoArvore *raiz, int RA, int nota, int *flag) {
  if (raiz == NULL) {
    NoArvore *novoNo = malloc(sizeof(NoArvore));
    novoNo->chave = RA;
    novoNo->nota = nota;
    novoNo->altura = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    return novoNo;
  }

  if (RA < raiz->chave) raiz->esq = auxiliar_inserir(raiz->esq, RA, nota, flag);
  if (RA > raiz->chave) raiz->dir = auxiliar_inserir(raiz->dir, RA, nota, flag);
  if (RA == raiz->chave) {
    raiz->nota = nota;
    return raiz;
  }

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

  int fb = calcula_fb(raiz);
  if (fb > 1 || fb < -1) {
    printf("[No desbalanceado: %d]\n", raiz->chave);
    *flag = 0;
    raiz = balancear(raiz);
  }

  return raiz; 
}

NoArvore *inserir(NoArvore *raiz, int RA, int nota) {
  int flag = 1;
  raiz = auxiliar_inserir(raiz, RA, nota, &flag);
  if (flag == 1) printf("[Ja esta balanceado]\n");
  return raiz;  
}

NoArvore *auxiliar_remover(NoArvore *raiz, int chave, int *flag) {
  if (raiz == NULL) return NULL;
  if (chave < raiz->chave) raiz->esq = auxiliar_remover(raiz->esq, chave, flag);
  else if (chave > raiz->chave) raiz->dir = auxiliar_remover(raiz->dir, chave, flag);
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

    NoArvore *sucessor = getMin(raiz->dir);
    raiz->chave = sucessor->chave;
    raiz->nota = sucessor->nota;
    raiz->dir = auxiliar_remover(raiz->dir, sucessor->chave, flag);
  }

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

  int fb = calcula_fb(raiz);
  if (fb > 1 || fb < -1) {
    printf("[No desbalanceado: %d]\n", raiz->chave);
    *flag = 0;
    raiz = balancear(raiz);
  }

  return raiz;
}

NoArvore *remover(NoArvore *raiz, int chave) {
  int flag = 1;
  raiz = auxiliar_remover(raiz, chave, &flag);
  if (flag == 1) printf("[Ja esta balanceado]\n");
  
  return raiz;
}

int main() {
	NoArvore *raiz = NULL;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
			case 'I' : {
				int RA, nota;
				scanf("%d %d", &RA, &nota);
				raiz = inserir(raiz, RA, nota);
				break;
			}
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}
      case 'B' : {
        int comparacoes = 0, RA;
        scanf("%d", &RA);
        NoArvore *aux = buscar(raiz, RA, &comparacoes);
        if (aux != NULL) {
          printf("C=%d Nota=%d\n", comparacoes, aux->nota);
        } else {
          printf("C=%d Nota=%d\n", comparacoes, -1);
        }
        break;
      }
      case 'R': {
        int RA;
        scanf("%d", &RA);
        raiz = remover(raiz, RA);
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