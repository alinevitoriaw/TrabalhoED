#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pedido{
    int id;
    char *nome_aluno;
    int matricula;
    char *descricao;
    struct Pedido *p;

    int prioridade;

    struct Pedido *esq;
    struct Pedido *dir;
} ENCOMENDA;

typedef struct No{
    struct No *prox;
} NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

ENCOMENDA *raiz = NULL;

ENCOMENDA *buscar(int id, ENCOMENDA *aux){

    if (aux != NULL{
        if (aux->id == id){
            return aux;
        }else if (id < aux->id) {
            if (aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if (id > aux->id){
            if (aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }
}

void add_abb(int id, char *nome_aluno, int matricula, char *descricao){

    ENCOMENDA *aux = buscar(id, raiz);

    if (aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");
    }else{
        ENCOMENDA *novo = malloc(sizeof(ENCOMENDA));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL;
        novo->dir = NULL;

        if (aux == NULL){
            raiz = novo;
            novo->p = NULL;
        }else{
            novo->p = aux;
            if (id < aux->id){
                aux->esq = novo;
            }else{
                aux->dir = novo;
            }
        }
    }
}

void in_ordem(ENCOMENDA *aux){

    if (aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("ENCOMENDA\n");
    printf("ID: %d\n", aux->id);
    printf("NOME DO ALUNO: %s\n", aux->nome_aluno);
    printf("MATRICULA: %d\n", aux->matricula);
    printf("DESCRICAO: %s\n", aux->descricao);
    if (aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

int id_unico(){
    int id;
    int menor = 0, maior = 10;
    srand(time(NULL));
    id = (rand() % 100);
}

ENCOMENDA*remove_no(ENCOMENDA*pont, int id){
    if(pont==NULL){//conferindo se a arvore esta vazia ou n
        printf("ID invalido!\n");
        return pont;
    }else if(id < pont->id){
        pont->esq = remove_no(pont->esq, id);
    }else if(id > pont->id){
        pont->dir = remove_no(pont->dir,id);
    }else{
        if(pont->dir == NULL && pont->esq == NULL){//remo de no a ser removido eh uma folha
            free(pont);
            pont=NULL;
        }else if(pont->esq == NULL){//os dois proximos casos servem para remover o no quando ele tem apenas um filho
            ENCOMENDA*aux = pont;
            pont = pont->dir;
            free(aux);
        }else if(pont->dir == NULL){
            ENCOMENDA*aux = pont;
            pont = pont->esq;
            free(aux);
        }
        else{// quando ele tem filhos para os dois lados, fazemos com que ele pegue o sucessor
            ENCOMENDA*aux = pont->dir;
            pont->id=aux->id;
            pont->dir = remove_no(pont->dir,aux->id);
            }
        }
    return pont;
}
