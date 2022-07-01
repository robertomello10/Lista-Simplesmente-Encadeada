#include<stdio.h>
#include<stdlib.h>


typedef struct no{

    int chave;
    struct no *prox;

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

return novoNo;

}


No *insereInicio(No *L, int valor){

    No *novoNo = criaNo(valor);

    if(L == NULL){

        L = novoNo;

    }
    else{

        novoNo -> prox = L;
        L = novoNo;

    }

    return L;
}


No *insereFinal(No *L, int valor){

    No *novoNo = criaNo(valor);

    if(L == NULL){

        L = novoNo;
    }

    else{

        No *aux = L;

        while(aux -> prox != NULL){

            aux = aux -> prox;

        }
        
        aux -> prox = novoNo;
    }
    
    return L;
}


No *buscaChave(No *L, int valor){

    No *aux = L;

    if(L == NULL){
        printf("A lista está vazia");
        return NULL;
    }

    else{
        while( aux != NULL){
            if(aux -> chave == valor){
                break;
                aux = aux -> prox;
                printf("Elemento está na lista");
            }
        }
    return aux;
    
    }
}


No *excluiFinal(No *L){

    No *aux = L;
    No *pred = NULL;


    if(L == NULL){
        printf("Não tem elementos para excluir");
        return L;
    }

    else{

        while(aux -> prox != NULL){
            pred = aux;
            aux = aux -> prox;
            
        }

        if(pred == NULL){
            
            L = NULL;
        }

        else{

            pred -> prox = NULL;
            
        }

        free(aux);

    }

    return L;
}


No *excluiInicio(No *L){

    No *aux = L;
    
    if(L == NULL){

        printf("Lista está vazia");
        return NULL;
    }

    else{       

        L = L -> prox;
        free(aux);

        return L;
    }

}


No *excluiChave(No *L, int valor){
    No *aux = L;
    No *pred = NULL;

    if(L == NULL){
        
        return NULL;
    }

    else{

        while(aux != NULL && valor != aux -> chave){

            pred = aux;
            aux = aux -> prox;
        }
    
        if(pred == NULL){

            L = aux -> prox;
            
        }
        else{
            
            pred -> prox = aux -> prox;
            free(aux);


        }

    }

    return L;
}


No *imprimeLista(No *L){

    No *aux = L;

    if(L == NULL){

        printf("A lista esta vazia\n");
        return NULL;
    }
    
    else{
        while(aux != NULL){

            printf("%d ", aux -> chave);
            aux = aux -> prox;
        }
    }
    return L;
}

No *esvaziaLista(No * L){
    No *aux = L;

    while(aux != NULL){
        aux = aux -> prox;

    }
    free(aux);
    // L = NULL;
    return NULL;
}


int main(){

    No *L = NULL;

    L = insereInicio(L, 5);
    L = insereInicio(L, 4);
    L = insereInicio(L, 3);
    L = insereInicio(L, 2);
    L = insereInicio(L, 1);
   
    imprimeLista(L);

    // L = excluiChave(L, 4);
    // printf("\n");
    L = esvaziaLista(L);
    imprimeLista(L);
    
   
  


    return 0;
}