/* 1)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 3
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Gerar Strings: <comando> gera_strings N ordem > entrada.txt
*
* Deve ser implementado um programa em C que:
*   - Simule uma demonstração por indução utilizando o método da substituição.
* 
* <COMANDO> substituição a b fn p c
*    - a, b e f(n) são da relação de recorrência.
*    - P é o polinômio da complexidade a ser demonstrada (pode ser 0,1,2,3... para 1,n,n2,n3,...)
*    - C é complexidade que pode ser O, Ω ou θ (grandeo , grandeomega ou teta ).
*
* <EXEMPLO> substituição 4 2 1 3 grandeo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(&argc, &argv[]){
    
    int a;
    int b;
    int fn;
    int P;
    char *C;
    
    if(argc == 5){
                
        a   = atoi(argv[1]);
        b   = atoi(argv[2]);
        c   = atoi(argv[3]);
        fn  = atoi(argv[4]);
        C   = argv[5]; 

        if(strcmp(C, "grandeo") == 0){
            
            
        }else if(strcmp(C, "grandeomega") == 0){
            
            
        }else if(strcmp(C, "teta") == 0){
            
            
        }else{
            printf("ERRO: complexidade invalida.");
            exit 1;
        }
    }else{
        printf("ERRO: numero de argumentos invalidos.");
    }      
   return 0; 
}