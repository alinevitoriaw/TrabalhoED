#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pedido
{

    int id;
    char *nome_aluno;
    int matricula;
    char *descricao;
    struct Pedido *p;

    int prioridade;

    struct Pedido *esq;
    struct Pedido *dir;
} PEDIDO;

typedef struct No
{
    struct No *prox;
} NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

PEDIDO *raiz = NULL;

PEDIDO *buscar(int id, PEDIDO *aux)
{

    if (aux != NULL)
    {
        if (aux->id == id)
        {
            return aux;
        }
        else if (id < aux->id)
        {
            if (aux->esq != NULL)
            {
                return buscar(id, aux->esq);
            }
            else
            {
                return aux;
            }
        }
        else if (id > aux->id)
        {
            if (aux->dir != NULL)
            {
                return buscar(id, aux->dir);
            }
            else
            {
                return aux;
            }
        }
    }
    else
    {
        return NULL;
    }
}

void add_abb(int id, char *nome_aluno, int matricula, char *descricao)
{

    PEDIDO *aux = buscar(id, raiz);

    if (aux != NULL && aux->id == id)
    {
        printf("Insercao invalida!\n");
    }
    else
    {

        PEDIDO *novo = malloc(sizeof(PEDIDO));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL;
        novo->dir = NULL;

        if (aux == NULL)
        {
            raiz = novo;
            novo->p = NULL;
        }
        else
        {
            novo->p = aux;
            if (id < aux->id)
            {
                aux->esq = novo;
            }
            else
            {
                aux->dir = novo;
            }
        }
    }
}

void in_ordem(PEDIDO *aux)
{

    if (aux->esq != NULL)
    {
        in_ordem(aux->esq);
    }
    printf("ID: %d\n", aux->id);
    printf("NOME DO ALUNO: %s\n", aux->nome_aluno);
    printf("MATRICULA: %d\n", aux->matricula);
    printf("DESCRICAO: %s\n", aux->descricao);
    if (aux->dir != NULL)
    {
        in_ordem(aux->dir);
    }
}

int id_unico()
{
    int id;
    int menor = 0, maior = 10;
    srand(time(NULL));
    id = (rand() % 100);
}

PEDIDO*remove_no(PEDIDO*pont, int id){
    if(pont==NULL){//conferindo se a arvore esta vazia ou n
        printf("ID inválido!\n");
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
            PEDIDO*aux = pont;
            pont = pont->dir;
            free(aux);
        }else if(pont->dir == NULL){
            PEDIDO*aux = pont;
            pont = pont->esq;
            free(aux);
        }
        else{// quando ele tem filhos para os dois lados, fazemos com que ele pegue o sucessor
            PEDIDO*aux = pont->dir;
            pont->id=aux->id;
            pont->dir = remove_no(pont->dir,aux->id);
            }
        }
    return pont;
}
/*
int main() {
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while (resp != 0) {
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if (resp == 1) {
            int id;
            id = id_unico();

            //encomendar um livro
            
            printf("Digite o nome do aluno: \n");
            char * nome_aluno = malloc(sizeof(char));
            scanf(" %[^\n]s", nome_aluno);

            printf("Descreva o livro: \n");
            char * descricao = malloc(sizeof(char));
            scanf(" %[^\n]s", descricao);

            printf(" Digite o número da matricula: \n");
            int matricula;
            scanf(" %d", &matricula);
            
            add_abb(id, nome_aluno, matricula, descricao);
        }else if (resp == 2){
            int id;
            in_ordem(raiz);
            printf(" Digite o id a ser removido: \n");
            scanf(" %d", &id);
            remove_no(raiz, id);
            
        }
    }
    
    return 0;
}
*/
