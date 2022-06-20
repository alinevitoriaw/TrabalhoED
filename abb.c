#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pedido
{

    int id;
    char *nome_aluno;
    int matricula;
    char *descricao;

    int prioridade;

    struct Pedido *esq;
    struct Pedido *dir;
} PEDIDO;

typedef struct No
{

    PEDIDO *p;
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
        }
        else
        {
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
    int menor = 0, maior = 5;
    srand(time(NULL));
    id = (rand() % (maior - menor + 1)) + maior;
}
