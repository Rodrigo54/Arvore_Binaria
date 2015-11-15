/**
 * @name ÁRVORE BINÁRIA
 *
 * @todo Escreva um programa que contenha as seguintes FUNCÕES:
 * a) Mostre apenas os elementos folha de uma árvore binária.
 * b) Mostre os elementos de uma árvore que se encontram em um determinado nível (o usário informa o nível desejado).
 * c) Calcule e mostre a soma de todos os valores de uma árvore.
 * d) Escreva uma função recursiva que conta o número de folhas em uma árvore binária.
 * e) Escreva uma função que realiza um percurso em largura na árvore. Você pode usar uma fila auxiliar.
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @version 2.5
 * @date 25 Jun 2015
 * @copyright 2015 by Rodrigo Alves Mesquita - Todos os Direitos Reservados!
 * @file arvore.c
**/

#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

/** @name Cria Árvore Vazia
 *  @note Leia mais em arvore.h
**/
No* arv_criavazia (void){
  return NULL;
}

/** @name Verifica Árvore
 *  @note Leia mais em arvore.h
**/
int arv_vazia (No* a){
  return a == NULL;
}

/** @name Cria Árvore
 *  @note Leia mais em arvore.h
**/
No* arv_cria (int c, No* sae, No* sad){
  No* p=(No*)malloc(sizeof(No));
    p->v = c;
    p->esq = sae;
    p->dir = sad;
  return p;
}

/** @name Limpa a Árvore
 *  @note Leia mais em arvore.h
**/
No* arv_libera (No* a){
  if (!arv_vazia(a)){
    arv_libera(a->esq); // libera sae  
    arv_libera(a->dir); // libera sad  
    free(a);            // libera raiz 
  }
  return NULL;
}

/** @name Imprime a Árvore em Pré-Ordem
 *  @note Leia mais em arvore.h
**/
void arv_imprime_pre (No* a){
  if (!arv_vazia(a)){
    wprintf(L"%d ", a->v);    // mostra raiz 
    arv_imprime_pre(a->esq);  // mostra sae  
    arv_imprime_pre(a->dir);  // mostra sad  
  }
}

/** @name Imprime a Árvore em Pos-Ordem
 *  @note Leia mais em arvore.h
**/
void arv_imprime_pos (No* a){
  if (!arv_vazia(a)){
    arv_imprime_pos(a->esq);  // mostra sae  
    arv_imprime_pos(a->dir);  // mostra sad  
    wprintf(L"%d ", a->v);    // mostra raiz
  }
}

/** @name Pesquisar valores na Árvore
 *  @note Leia mais em arvore.h
**/
int busca (No* t, int v){
  if (arv_vazia(t))
    return 0; //árvore vazia: não encontrou
  else if (v == t->v)
    return 1; //Valor encontrado
  else if (busca(t->esq, v))
    return 1; //Valor encontrado na esquerda
  else
    return busca(t->dir, v); //Valor encontrado na direita
}

/** @name Exibir nós folhas da Árvore
 *  @note Leia mais em arvore.h
**/
void mostra_folhas(No* a){
  if (arv_vazia(a))
    return;
  else{
    if(a->esq == NULL && a->dir == NULL){
    wprintf(L"%d\t", a->v);
    return;
    }
  }
  mostra_folhas(a->esq);
  mostra_folhas(a->dir);
}

/** @name Conta Folhas
 *  @note Leia mais em arvore.h
**/
int conta_folhas(No* a){
  if (arv_vazia(a))
    return 0;
  else if(a->esq == NULL && a->dir == NULL)
    return 1;
  return 0 + conta_folhas(a->esq) + conta_folhas(a->dir);
}

/** @name Imprime a Árvore em Largura
 *  @note Leia mais em arvore.h
**/
void largura(No* t){
  No *aux, *vet[50];
  int fim, inicio;

  vet[0] = t;
  inicio = 0;
  fim = 1;

  while(inicio < fim){
    aux = vet[inicio];
    inicio++;
    wprintf(L"%d  ", aux->v);
    if(aux->esq != NULL){
      vet[fim] = aux->esq;
      fim++;
    }
    if(aux->dir != NULL){
      vet[fim] = aux->dir;
      fim++;
    }
  }

}

/** @name Somar nós da Árvore
 *  @note Leia mais em arvore.h
**/
int soma_nos (No* p){
  int cont=0;
  if(!arv_vazia(p)){
    return cont = p->v + soma_nos(p->esq) + soma_nos(p->dir);
  }
  return cont;
}

/** @name Altura da Árvore
 *  @note Leia mais em arvore.h
**/
int altura (No* a){
  int e,d;
  if (arv_vazia(a))
    return 0;

  e = altura(a->esq);
  d = altura(a->dir);

  if(e > d)
    return e+1;

  return d+1;
}

/** @name Imprime Nós de um nivel
 *  @note Leia mais em arvore.h
**/
void imprime_nivel (No* a, int nivel,int valor){
  if (arv_vazia(a))
    return;
  imprime_nivel(a->esq, nivel+1,valor);
  if(nivel == valor){
    wprintf(L"%2d\t",a->v);
  }
  imprime_nivel(a->dir,nivel+1,valor);
}

/** @name Imprime Árvore
 *  @note Leia mais em arvore.h
**/
void imprime (No *p, int nivel){
  int i=0;
  if(arv_vazia(p))
    return;
  imprime(p->dir, nivel+1);
  for(i=0;i<nivel;i++)
    wprintf(L" ══ ");
  wprintf(L"%3d\n",p->v);
  imprime(p->esq,nivel+1);
}

/** @name Insere Nó na Árvore
 *  @note Leia mais em arvore.h
**/
No* abb_insere (No* a, int valor){
  if (arv_vazia(a))
    a = arv_cria(valor,arv_criavazia(),arv_criavazia());
  else if (valor < a->v)
    a->esq = abb_insere(a->esq,valor);
  else if (valor >= a->v)
    a->dir = abb_insere(a->dir,valor);
  return a;
}

/** @name Remove Nó da Árvore
 *  @note Leia mais em arvore.h
**/
No* remove_ArvBin (No* r, int valor){
  if (arv_vazia(r))
    return NULL;
  else if (r->v > valor)
    r->esq = remove_ArvBin(r->esq, valor);
  else if (r->v < valor)
    r->dir = remove_ArvBin(r->dir, valor);
  else { /* achou o nó a remover */
    /* nó sem filhos (Folhas) */
    if (r->esq == NULL && r->dir == NULL) {
      free (r);
      r = NULL;
    }
    /* nó só tem filho à direita */
    else if (r->esq == NULL) {
      No* t = r;
      r = r->dir;
      free (t);
    }
    /* só tem filho à esquerda */
    else if (r->dir == NULL) {
      No* t = r;
      r = r->esq;
      free (t);
    }
    /* nó tem os dois filhos */
    else {
      No* f = r->esq;
      while (f->dir != NULL) {
        f = f->dir;
      }
      r->v = f->v; /* troca as informações */
      f->v = valor;
      r->esq = remove_ArvBin(r->esq,valor);
    }
  }
  return r;
}
