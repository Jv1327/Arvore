#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int valor; 
  struct No* esquerda;
  struct No* direita;
} No;

No* inserir(No* raiz, int valor);
No* CriarNo(int valor);

int main(){
  No* raiz = NULL;
  raiz = inserir(raiz, 15);
  raiz = inserir(raiz, 11);
  raiz = inserir(raiz, 18);
  return 0;
}

No* inserir(No* raiz, int valor){
  if(raiz == NULL){
    return CriarNo(valor);
  }
  
  if(valor < raiz->valor){
    raiz->esquerda = inserir(raiz->esquerda, valor);
  }else if(valor > raiz->valor){
    raiz->direita = inserir(raiz->direita, valor);
  }
  return raiz;
}

No* CriarNo(int valor){
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->valor = valor;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
}