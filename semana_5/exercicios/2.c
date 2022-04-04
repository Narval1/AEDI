#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  char data;
  LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica {
  LinkedNode *topo;
};

PilhaDinamica *criar_pilha() {
  PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
  pilha->topo = NULL;

  return pilha;
}

int push(PilhaDinamica *pilha, char item) {
  LinkedNode *novo = malloc(sizeof(LinkedNode));
  if (novo == NULL) return 0;

  novo->data = item;
  novo->next = pilha->topo;

  pilha->topo = novo;

  return 1;
}

int pop(PilhaDinamica *pilha, char *item) {
  // pilha vazia?.
  if (pilha->topo == NULL) return 0;

  LinkedNode *node = pilha->topo;
  pilha->topo = pilha->topo->next;

  *item = node->data;
  free(node);

  return 1;
}

void liberarLista(LinkedNode *node) {
  if (node == NULL) return;
  liberarLista(node->next);
  free(node);
}

void liberar_pilha(PilhaDinamica *pilha) {
  liberarLista(pilha->topo);
  free(pilha);
}

LinkedNode *insereNoFinalRecursivo(LinkedNode *inicio, int elemento) {
  if (inicio == NULL) {
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    novo->data = elemento;
    novo->next = NULL;
    return novo;
  }

  inicio->next = insereNoFinalRecursivo(inicio->next, elemento);
  return inicio;
}

int verifica(char *string) {
  PilhaDinamica *pilha = criar_pilha();
  int result;
  char item = 'f';

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '(') result = push(pilha, string[i]);
    if (string[i] == '{') result = push(pilha, string[i]);
    if (string[i] == '[') result = push(pilha, string[i]);

    if (string[i] == ')') {
      if (pilha->topo == NULL) {
        liberar_pilha(pilha);
        return 0;
      }
      if (pilha->topo->data != '(') {
        liberar_pilha(pilha);
        return 0;
      }
      result = pop(pilha, &item);
    }
    if (string[i] == '}') {
      if (pilha->topo == NULL) {
        liberar_pilha(pilha);
        return 0;
      }
      if (pilha->topo->data != '{') {
        liberar_pilha(pilha);
        return 0;
      }
      result = pop(pilha, &item);
    }
    if (string[i] == ']') {
      if (pilha->topo == NULL) {
        liberar_pilha(pilha);
        return 0;
      }
      if (pilha->topo->data != '[') {
        liberar_pilha(pilha);
        return 0;
      }
      result = pop(pilha, &item);
    }
  }

  if (pilha->topo != NULL) {
    liberar_pilha(pilha);
    return 0;
  }

  liberar_pilha(pilha);
  return 1;
}


int main() {
  char string[100];
  fgets(string, sizeof(string), stdin);

  int result = verifica(string);
  if (result == 0) printf("NAO");
  else printf("SIM");

  return 0;
}