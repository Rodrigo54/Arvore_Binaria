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
 * @file arvore.h
**/

#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

/** Estrutura do NÓ da árvore **/
typedef struct no {
  int v;                //Valor numerico
  struct no *esq, *dir; //Ponteiro pra Esquerda e pra direita
} No;

/** @name Cria Árvore Vazia
 *  @function arv_criavazia (void)
 *  @brief Esta função cria um nó na arvore vazio (NULL) 
 *  @param sem parametros (vazio)
 *  @return NULL --> árvore vazia
**/
No* arv_criavazia (void);

/** @name Cria Árvore 
 *  @function arv_cria (int c, No* sae, No* sad)
 *  @brief Esta função cria um nó na arvore 
 *  @param int c --> Valor numerico da estrutura (nó)
 *  @param No* sae --> Poteiro para nó esquerdo
 *  @param No* sad --> Poteiro para nó direito
 *  @return No* p --> retorna a Árvore
**/
No* arv_cria (int c, No* sae, No* sad);

/** @name Verifica Árvore
 *  @function arv_vazia (No* a)
 *  @brief Esta função verifica se a arvore esta vazia 
 *  @param No* a --> Árvore para verificação
 *  @return 1 --> se a árvore estiver vazia
 *  @return 0 --> se a árvore não estiver vazia
**/
int arv_vazia (No* a);

/** @name Limpa a Árvore
 *  @function arv_libera (No* a)
 *  @brief Esta função limpa toda a arvore deixando ela vazia
 *  @param No* a --> Árvore para limpar
 *  @return NULL --> árvore vazia
**/
No* arv_libera (No* a);

/** @name Imprime a Árvore em Pré-Ordem
 *  @function arv_imprime_pre (No* a)
 *  @brief Esta função imprime toda a arvore 
 *  no formato raiz, esquerda, direita (RED)
 *  @param No* a --> Árvore para imprimir
**/
void arv_imprime_pre (No* a);

/** @name Imprime a Árvore em Pos-Ordem
 *  @function arv_imprime_pos (No* a)
 *  @brief Esta função imprime toda a arvore 
 *  no formato esquerda, direita, raiz (EDR)
 *  @param No* a --> Árvore para imprimir
**/
void arv_imprime_pos (No* a);

/** @name Pesquisar valores na Árvore
 *  @function busca (No* t, int v)
 *  @brief Esta função faz a busca de um valor numerico na árvore
 *  @param No* a --> Árvore onde se fará a busca
 *  @return 0 --> caso não encontre o valor
 *  @return 1 --> caso encontre o valor
 *  @remarks A árvore precisa ser de busca binaria
**/
int busca (No* t, int v);

/** @name Exibir nós folhas da Árvore
 *  @function mostra_folhas(No* a)
 *  @brief Esta função mostra os valores das folhas da árvore
 *  @param No* a --> Árvore para imprimir as folhas
 *  @remarks As folhas são exibidas da esquerda para a direita
**/
void mostra_folhas (No* a);

/** @name Altura da Árvore
 *  @function altura (No* a)
 *  @brief Esta função calcula a altura da árvore
 *  @param No* a --> Árvore para calcular a altura
 *  @return altura --> Altura da árvore
 *  @remarks Considere que a raiz é nivel 1
**/
int altura (No* a);

/** @name Conta Folhas
 *  @function conta_folhas (No* a)
 *  @brief Esta função conta o numero de folhas em uma árvore
 *  @param No* a --> Árvore para contar folhas
 *  @return folhas --> Numero de folhas
**/
int conta_folhas (No* a);

/** @name Imprime a Árvore em Largura
 *  @function largura (No* t)
 *  @brief Esta função imprime toda a árvore em largura (nivel a nivel)
 *  @param No* t --> Árvore para imprimir
 *  @remarks Os nós são impressos da esquerda para a direita
**/
void largura (No* t);

/** @name Somar nós da Árvore
 *  @function soma_nos (No* p)
 *  @brief Esta função Soma todos os nós da árvore
 *  @param No* p --> Árvore para somar os nós
 *  @return cont --> Resultado da soma de todos os nós
**/
int soma_nos (No* p);

/** @name Imprime Nós de um nivel
 *  @function imprime_nivel (No* a, int nivel,int valor)
 *  @brief Esta função imprime os nós em um nivel especifico de uma árvore
 *  @param No* a --> Árvore para imprimir
 *  @param int nivel --> Nivel da raiz
 *  @param int valor --> Nivel para mostrar seus nós
 *  @remarks O usuário informa o nivel para imprimir seus nós
**/
void imprime_nivel (No* a, int nivel, int valor);

/** @name Imprime Árvore
 *  @function imprime (No *p, int nivel)
 *  @brief Esta função imprime a árvore completa
 *  @param No* p --> Árvore para imprimir
 *  @param int nivel --> Nivel da raiz
**/
void imprime (No *p, int nivel);

/** @name Remove Nó da Árvore
 *  @function remove_ArvBin (No *r, int valor)
 *  @brief Esta função remove um nó da árvore
 *  @param No* r --> Árvore para eliminar nó
 *  @param int valor --> valor numerico a ser removido
 *  @return r --> Árvore com o nó removido
 *  @remarks Considere que a árvore é de busca binaria
**/
No* remove_ArvBin (No *r, int valor);

/** @name Insere Nó na Árvore
 *  @function abb_insere (No *r, int valor)
 *  @brief Esta função insere um nó na árvore
 *  @param No* r --> Árvore para inserir nó
 *  @param int valor --> valor numerico a ser inserido
 *  @return r --> Árvore com o nó inserido
 *  @remarks Considere que a árvore é de busca binaria.
 *  Esta função Insere nós repetidos a esquerda do nó repetido.
**/
No* abb_insere (No* a, int valor);

#endif // ARVORE_H_INCLUDED
