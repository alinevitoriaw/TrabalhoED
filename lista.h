#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sec
{
    int cpf;
    int senha;
    char *nomedosec;
    struct sec *prox;
    struct sec *ant;
} secretario;
typedef struct t
{
    int cpf_t;
    char *senha_t;
    char *nome_t;
    struct t *ant;
    struct t *prox;
} transportador;

transportador *inicio_t = NULL;
transportador *fim_t = NULL;
int tam_t = 0;
secretario *inicio = NULL;
secretario *fim = NULL;
int tam = 0;
void cadastrar_secretario(int cpf, int senha, char *nomedosec)
{
    secretario *novo_sec = malloc(sizeof(secretario));
    novo_sec->cpf = cpf;
    novo_sec->senha = senha;
    novo_sec->nomedosec = nomedosec;
    novo_sec->prox = NULL;
    novo_sec->ant = NULL;

    if (inicio == NULL)
    {
        inicio = novo_sec;
        fim = novo_sec;
    }
    else
    {
        fim->prox = novo_sec;
        novo_sec->ant = fim;
        fim = novo_sec;
    }
    tam++;
}
void cadastrar_transportador(int cpf_t, char *senha_t, char *nome_t)
{
    transportador *novo_t = malloc(sizeof(transportador));
    novo_t->cpf_t = cpf_t;
    novo_t->senha_t = senha_t;
    novo_t->nome_t = nome_t;
    novo_t->prox = NULL;
    novo_t->ant = NULL;

    if (inicio_t == NULL)
    {
        inicio_t = novo_t;
        fim_t = novo_t;
    }
    else
    {
        fim_t->prox = novo_t;
        novo_t->ant = fim_t;
        fim_t = novo_t;
    }
    tam_t++;
}

void dados_sec()
{
    secretario *aux = inicio;
    for (int i = 0; i < tam; i++)
    {
        printf("CPF: %d\nSenha:%d\nNome: %s\n", aux->cpf, aux->senha, aux->nomedosec);
        aux = aux->prox;
    }
}

void dados_transp()
{
    transportador *aux = inicio_t;
    for (int i = 0; i < tam_t; i++)
    {
        printf("CPF: %d\nSenha:%s\nNome: %s\n", aux->cpf_t, aux->senha_t, aux->nome_t);
        aux = aux->prox;
    }
}

int main()
{
    cadastrar_secretario(58555, 1231, "Luisizt");
    cadastrar_secretario(8955, 5622, "Alanis");
    cadastrar_transportador(7777, "adasd", "asda");
    dados_sec();
    dados_transp();
}
