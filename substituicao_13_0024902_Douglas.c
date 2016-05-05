/* 1)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 3
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Gerar Strings: <comando> substituição a b fn p c
*
*    - a, b e f(n) são da relação de recorrência.
*    - P é o polinômio da complexidade a ser demonstrada (pode ser 0,1,2,3... para 1,n,n^2,n^3,...)
*    - C é complexidade que pode ser O, Ω ou θ (grandeo , grandeomega ou teta ).
*
* Deve ser implementado um programa em C que:
*   - Simule uma demonstração por indução utilizando o método da substituição.
*
* <EXEMPLO> substituição 4 2 1 3 grandeo
* 		a = 4, b = 2, f(n) = n^1
* 		P = n^3
* 		C = grandeo
*
* Método da Substituição
* 	Método Geral:
* 1.Imaginar a forma da solução
* 2.Verificar por indução
* 3.Resolver para as constantes
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool GrandeO(float a, float b, float P, float fn);
bool GrandeOmega(float a, float b, float P, float fn);
bool Teta(float a, float b, float P, float fn);

int main(int argc, char* argv[]){

    float a;
    float b;
    float fn;
    float P;
    char *C;

    if(argc == 6){

        a   = atof(argv[1]);
        b   = atof(argv[2]);
        fn  = atof(argv[3]);
        P   = atof(argv[4]);
        C   = argv[5];

	/*Limite superior*/
        if(strcmp(C, "grandeo") == 0){

            printf("\nGrande O:\n");
            GrandeO(a, b, P, fn);

        }
        /*Limite inferior*/
        else if(strcmp(C, "grandeomega") == 0){

            printf("\nGrande Omega:\n");
	          GrandeOmega(a, b, P, fn);

        }
        /*Limite restrito*/
        else if(strcmp(C, "teta") == 0){

           printf("\nTeta:\n");
	         Teta(a, b, P, fn);

      	}else{
      	  printf("ERRO: complexidade invalida.");
        }
    }else{
      printf("ERRO: numero de argumentos invalidos.");
    }
   return 0;
}

bool GrandeO(float a, float b, float P, float fn){

    float baux = 1, result, complemento;

    printf("\nFato: T(n) = (%.f)*T(n/%.f) + n^%.f\n", a, b, fn);
	  printf("Suposicao: T(n/%.f) ≤ c(n/%.f)^%.f\n", b, b, P);
	  printf("Precisa provar: T(n) ≤ cn^%.f", P);

    printf("\n\n\tT(n) = (%.f)*T(n/%.f) + n^%.f", a, b, fn);
    printf("\n\t≤ (%.f)*c(n/%.f)^%.f + n^%.f", a, b, P, fn);

    baux = pow(b, P);
    result = a/baux;
    complemento = 1 - result;

    printf("\n\t= (%.2f)*cn^%.f) + n^%.f", result, P, fn);
    if(complemento == 0){
        printf("\n\t= cn^%.f - ( -n^%.f) ← desejado – residual", P, fn);
    }else{
        printf("\n\t= cn^%.f - ((%.2f)*cn^%.f - n^%.f)) ← desejado – residual", P, complemento, P, fn);
    }
    printf("\n\t≤ cn^%.f ← desejado", P);

    printf("\n\n\tQuando (%.2f)*cn^%.f – n^%.f ≥ 0, por exemplo,", complemento, P, fn);

    int ultrapassa = 0;
    int caux = 1;
    int naux = 1;

    int verifica = -1;

    while(verifica < 0){
        verifica = complemento*caux*pow(naux, P) - pow(naux, fn);
        caux++;

        if(complemento*caux*pow(naux, P) - pow(naux, fn) >= 0){
            break;
        }else{
            naux++;
        }

        if(caux > 1000 || naux > 1000){
            ultrapassa = 1;
            break;
        }
    }

    if(ultrapassa == 1){
        printf("\n\nNao foi possivel fazer prova para grande O\n\n");
        return false;
    }else{
        printf("\n\tse c ≥ %d e n ≥ %d\n\n", caux, naux);
        return true;
    }
return false;
}

bool GrandeOmega(float a, float b, float P, float fn){

  float baux = 1, result, complemento;

  printf("\nFato: T(n) = (%.f)*T(n/%.f) + n^%.f\n", a, b, fn);
  printf("Suposicao: T(n/%.f) ≤ c(n/%.f)^%.f\n", b, b, P);
  printf("Precisa provar: T(n) ≥ cn^%.f", P);

  printf("\n\n\tT(n) = (%.f)*T(n/%.f) + n^%.f", a, b, fn);
  printf("\n\t≥ (%.f)*c(n/%.f)^%.f + n^%.f", a, b, P, fn);

  baux = pow(b, P);
  result = a/baux;
  complemento = 1 - result;

  printf("\n\t= (%.2f)*cn^%.f) + n^%.f", result, P, fn);
  if(complemento == 0){
      printf("\n\t= cn^%.f - ( -n^%.f) ← desejado – residual", P, fn);
  }else{
      printf("\n\t= cn^%.f - ((%.2f)*cn^%.f - n^%.f)) ← desejado – residual", P, complemento, P, fn);
  }
  printf("\n\t≥ cn^%.f ← desejado", P);

  printf("\n\n\tQuando (%.2f)*cn^%.f – n^%.f ≤ 0, por exemplo,", complemento, P, fn);

  int ultrapassa = 0;
  int caux = 1;
  int naux = 1;

  int verifica = -1;

  while(verifica < 0){
      verifica = complemento*caux*pow(naux, P) - pow(naux, fn);
      caux++;

      if(complemento*caux*pow(naux, P) - pow(naux, fn) <= 0){
          break;
      }else{
          naux++;
      }

      if(caux > 1000 || naux > 1000){
          ultrapassa = 1;
          break;
      }
  }

  if(ultrapassa == 1){
      printf("\n\nNao foi possivel fazer prova para grande Omega\n\n");
      return false;
  }else{
      printf("\n\tse c ≤ %d e n ≤ %d\n\n", caux, naux);
      return true;
  }
return false;
}

bool Teta(float a, float b, float P, float fn){

    if(GrandeO(a, b, P, fn) && GrandeOmega(a, b, P, fn)){
        printf("\nprovas para grande O e grande Omega corretas\n");
        return true;
    }else{
        printf("falha ao provar para teta, um ou os dois casos falharam");
        return false;
    }
return false;
}
