#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "heap.h"
#include "lista.h"

void telainicial(){
    printf("                 SISTEMA DE ENCOMENDA              \n");
    printf("                     DE LIVROS                   \n");
    printf("             UNIVERSIDADE FEDERAL DO CEARA        \n");
}

int main(){
    PFILA f = criarFila();
    telainicial();
    int resp = -1;
    cadastrar_secretario(58555, 1231, "Luisizt");
    cadastrar_secretario(8955, 5622, "Alanis");
    cadastrar_secretario(124, 633, "Aanis");
    cadastrar_transportador(7777, 545, "asda");
    while (resp != 0) {
        printf("\n 1 - Encomendar um livro.\n");
        printf("\n 2 - Remover uma encomenda de livro.\n");
        printf("\n 3 - Remover um pedido de livro.\n");
        printf("\n 0 - Sair do sistema!\n");
        printf("\n Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        system("cls");
        if (resp == 1) {
            int id; 
            id = id_unico();
            printf("Digite o nome do aluno: \n");
            char * nome_aluno = malloc(sizeof(char));
            scanf(" %[^\n]s", nome_aluno);

            printf("Descreva o livro: \n");
            char * descricao = malloc(sizeof(char));
            scanf(" %[^\n]s", descricao);

            printf("Digite o numero da matricula: \n");
            int matricula;
            scanf(" %d", &matricula);
            
            
            add_abb(id, nome_aluno, matricula, descricao);
            system("cls");
        }else if (resp == 2){
            int id;
            in_ordem(raiz);
            int cpf;
            int senha;
            int opcao;
            secretario *aux = inicio_s;
            int retorno;
            printf("1 - Secretario\n");
            printf("2 - Transportador \n");
            printf("\n--Qual seu cargo?--\n");
            scanf("%d", &opcao);
            if (opcao == 1)
            {
            printf("Digite seu CPF: \n");
            scanf("%d", &cpf);
            printf("Digite sua senha: \n");
            scanf("%d", &senha);
        
            for(int i=0; i < tam_s; i++){
                if(aux->cpf == cpf && aux->senha == senha){
                    printf("\nBem vindo %s\n", aux->nomedosec);
                    retorno = 0;
                    printf("\t\nDigite o id a ser removido: \n");
                    scanf(" %d", &id);
                    remove_no(raiz, id);
                    printf("ID da encomenda: ");
                    scanf("%d", &id);
                    printf("Campus onde esta o livro: \n");
                    char * nome_campus = malloc(sizeof(char));
                    scanf(" %[^\n]s", nome_campus);
                    printf("Campus do aluno: \n");
                    char * nome_campusa = malloc(sizeof(char));
                    scanf(" %[^\n]s", nome_campusa);
                    printf(" Prioridade do pedido: \n");
                    int prioridade;
                    scanf(" %d", &prioridade);
                    inserirElemento(f, id, prioridade, nome_campusa, nome_campus);
                    
                }else if(aux->cpf != cpf && aux->senha != senha){
                            printf("CPF ou senha invalidos!\n");
                            aux = aux->prox;
                }else if(aux->prox == NULL){
                    retorno = 1;
            }
        }
        }else if (opcao == 2){
            printf("Area destinada somente a secretário");
            system("cls");
        }
        }else if(resp == 3){
            imprimir(f);
            int cpf_t;
            int senha_t;
            int opcao_t;
            transportador *aux = inicio_t;
		int retorno;
            printf("1 - Secretario\n");
            printf("2 - Transportador \n");
            printf("\n--Qual seu cargo?--\n");
            scanf("%d", &opcao_t);
            system("cls");
            if(opcao_t == 1){
                printf("Area destinada a transportadores!");
            }else if(opcao_t == 2){
                printf("Digite seu CPF: \n");
                scanf("%d", &cpf_t);
                printf("Digite sua senha: \n");
                scanf("%d", &senha_t);
                for(int j = 0; j < tam_t; j++){
                    if(aux->cpf_t == cpf_t && senha_t == senha_t){
                        printf("Bem vindo(a), %s\n", aux->nome_t);
                        removerElemento(f);
                        printf("Elemento de maior prioridade removido pelo sistema!\n");
                    }
                    else{
                        printf("CPF ou senha incorretos!\n");
                    }

                }
            }
     }
    }  
    return 0; 
}   
