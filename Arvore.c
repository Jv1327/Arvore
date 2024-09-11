#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int valor;
  struct No* esquerda;
  struct No* direita;
} No;

No* inserir(No* raiz, int valor);
No* CriarNo(int valor);
void inOrder(No* raiz);
void preOrder(No* raiz);
void posOrder(No* raiz);

int main() {
  No* raiz = NULL;
  raiz = inserir(raiz, 15);
  raiz = inserir(raiz, 12);
  raiz = inserir(raiz, 19);
  raiz = inserir(raiz, 20);
  raiz = inserir(raiz, 10);
  raiz = inserir(raiz, 14);
  raiz = inserir(raiz, 18);
  raiz = inserir(raiz, 40);
  raiz = inserir(raiz, 42);

  printf("InOrder: ");
  inOrder(raiz);
  printf("\n");

  printf("PreOrder: ");
  preOrder(raiz);
  printf("\n");

  printf("PosOrder: ");
  posOrder(raiz);
  printf("\n");

  return 0;
}

No* inserir(No* raiz, int valor) {
  if (raiz == NULL) {
    return CriarNo(valor);
  }

  if (valor < raiz->valor) {
    raiz->esquerda = inserir(raiz->esquerda, valor);
  } else if (valor > raiz->valor) {
    raiz->direita = inserir(raiz->direita, valor);
  }
  return raiz;
}

No* CriarNo(int valor) {
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->valor = valor;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
  return novoNo;
}

void inOrder(No* raiz) {
  if (raiz != NULL) {
    inOrder(raiz->esquerda);
    printf("%d ", raiz->valor);
    inOrder(raiz->direita);
  }
}

void preOrder(No* raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->valor);
    preOrder(raiz->esquerda);
    preOrder(raiz->direita);
  }
}

void posOrder(No* raiz) {
  if (raiz != NULL) {
    posOrder(raiz->esquerda);
    posOrder(raiz->direita);
    printf("%d ", raiz->valor);
  }
}
