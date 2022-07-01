#include<stdio.h>
#include<stdlib.h>


typedef struct no{

    int chave;
    struct no *prox;
    struct no *pred;

}No;


No *criaNo(int valor){


    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Erro de alocacao");
        exit(1);

    }

novoNo -> chave = valor;
novoNo -> prox = NULL;
novoNo -> pred = NULL;

return novoNo;

}


No * insereinicioOrd(No *L, int valor){

    No *novoNo = criaNo(valor);
    No * aux = L;
    No * pred = NULL;

    if(L == NULL){
        
        L = novoNo;
    }

    else{
        while(aux != NULL && valor >aux -> chave){
            pred = aux;
            aux = aux -> prox;
        }

        if(pred == NULL){

            novoNo -> prox = aux;
            L = novoNo;

        }
        else{

            novoNo -> prox = aux;
            pred -> prox = novoNo;
        }

    }

    return L;
}