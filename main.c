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
 * @file main.c
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wchar.h>  //Biblioteca para conjunto UTF8 de caracteres
#include <io.h>     //Biblioteca para conjunto UTF8 de caracteres
#include <fcntl.h>  //Biblioteca para conjunto UTF8 de caracteres
#define UTF_8  0x40000
#include "arvore.h"

int main(){
  system("title ARVORE BINARIA");
  system("color 0e");
  /*CORES 1=FUNDO 2=TEXTO
    0 = Preto        8 = Cinza
    1 = Azul         9 = Azul claro
    2 = Verde        A = Verde claro
    3 = Verde-água   B = Verde-água claro
    4 = Vermelho     C = Vermelho claro
    5 = Roxo         D = Lilás
    6 = Amarelo      E = Amarelo claro
    7 = Branco       F = Branco brilhante
  */
  _setmode(_fileno(stdout), UTF_8); //Define no console o conjunto UTF8 de caracteres
  int opcao,v;

  No* a = arv_cria(8,
                arv_cria(4,
                    arv_cria(2,
                             arv_cria(1,arv_criavazia(),arv_criavazia()),
                             arv_cria(3,arv_criavazia(),arv_criavazia())),
                    arv_cria(6,
                             arv_cria(5,arv_criavazia(),arv_criavazia()),
                             arv_cria(7,arv_criavazia(),arv_criavazia()))
                ),
                arv_cria(10,
                    arv_cria(9, arv_criavazia(), arv_criavazia()),
                    arv_cria(11, arv_criavazia(), arv_criavazia())
                )
          );

  do{
    system("cls");
    wprintf(L"\n\t┌───────────── ÁRVORE BINÁRIA ──────────────────┐");
    wprintf(L"\n\t│                                               │");
    wprintf(L"\n\t│  1) Mostrar folhas da árvore                  │");
    wprintf(L"\n\t│  2) Mostrar elementos de um nivel             │");
    wprintf(L"\n\t│  3) Mostrar a soma de todos os elementos      │");
    wprintf(L"\n\t│  4) Mostrar o numero de folhas da árvore      │");
    wprintf(L"\n\t│  5) Mostrar percurso em largura na árvore     │");
    wprintf(L"\n\t│  6) Mostrar a árvore                          │");
    wprintf(L"\n\t│  7) Eliminar um elemento da árvore            │");
    wprintf(L"\n\t│  8) Adicionar um elemento na árvore           │");
    wprintf(L"\n\t│  9) Limpar a árvore                           │");
    wprintf(L"\n\t│ 10) Buscar um elemento da árvore              │");
    wprintf(L"\n\t│  0) Sair                                      │");
    wprintf(L"\n\t│                                               │");
    wprintf(L"\n\t└───────────────────────────────────────────────┘");
    wprintf(L"\n\t   Digite uma opção:  ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - MOSTRAR FOLHAS\n\n");
        wprintf(L"\t");
        mostra_folhas(a);
        getch();
        break;
      }
      case 2:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - MOSTAR POR NIVEL\n\n");
        wprintf(L"\tA árvore possui %d nivels", altura(a)-1); //pois raiz e nivel zero
        wprintf(L"\n\tDigite um nivel para exibir seus elementos:");
        scanf("%i",&v);
        wprintf(L"\t");
        imprime_nivel(a,0,v);
        getch();
        break;
      }
      case 3:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - SOMA DOS ELEMENTOS\n\n");
        wprintf(L"\tA soma de todos os elementos é: %d\n\t", soma_nos(a));
        getch();
        break;
      }
      case 4:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - TOTAL DE FOLHAS\n\n");
        wprintf(L"\tO número total de folhas é: %d\n\t", conta_folhas(a));
        getch();
        break;
      }
      case 5:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - PERCUSO EM LARGURA\n\n");
        wprintf(L"\t");
        largura(a);
        getch();
        break;
      }
      case 6:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - SHOW\n\n");
        if(!arv_vazia(a))
          imprime(a,0);
        else wprintf(L"\n\tA árvore esta Vazia!");
        getch();
        break;
      }
      case 7:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - REMOVE NÓ\n\n");
        imprime(a,0);
        wprintf(L"\n\tDigite um elemento para remover: ");
        scanf("%i",&v);
        remove_ArvBin(a,v);
        wprintf(L"\n");
        imprime(a,0);
        getch();
        break;
      }
      case 8:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - ADICIONAR NÓ\n\n");
        imprime(a,0);
        wprintf(L"\n\tDigite um elemento para Adicionar: ");
        scanf("%i",&v);
        abb_insere(a,v);
        wprintf(L"\n");
        imprime(a,0);
        getch();
        break;
      }
      case 9:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - LIMPAR\n\n");
        arv_libera(a);
        wprintf(L"\n\tÁrvore Limpa com sucesso!");
        getch();
        break;
      }
      case 10:{
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - PESQUISAR\n\n");
        wprintf(L"\n\tDigite um valor para buscar na árvore: ");
        scanf("%d", &v);
        if(busca(a,v)){
          wprintf(L"\n\tValor %d foi encontrado!\n",v);
          getch();
        }
        else{
          wprintf(L"\n\tValor %d não encontrado!\n",v);
          getch();
        }
        break;
      }
      case 0:{
        system("cls");
        wprintf(L"\n\n\t\t");
          wprintf(L"\n\t┌─────────── ÁRVORE BINÁRIA ──────────────┐");
          wprintf(L"\n\t│                                         │");
          wprintf(L"\n\t│  Programa feito para obtenção de nota   │");
          wprintf(L"\n\t│  parcial de estrutura de dados          │");
          wprintf(L"\n\t│  Obrigado por usar nosso app!           │");
          wprintf(L"\n\t│                                         │");
          wprintf(L"\n\t│  Criado por Rodrigo Alves Mesquita      │");
          wprintf(L"\n\t│                                         │");
          wprintf(L"\n\t└─────────────────────────────────────────┘\n\t");
        getch();
      exit(0);
        break;
      }
      default:{
        wprintf(L"\a\tDigite uma opção valida!");
        getch();
        break;
      }
    }
  }while(opcao);
  return 0;
}
