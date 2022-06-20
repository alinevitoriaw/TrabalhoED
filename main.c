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
            //int matricula;

            //encomendar um livro

            printf("Digite o nome do aluno: \n");
            char * nome_aluno = malloc(sizeof(char));
            scanf(" %[^\n]s", nome_aluno);

            printf("Descreva o livro: \n");
            char * descricao = malloc(sizeof(char));
            scanf(" %[^\n]s", descricao);

            printf(" Digite o número da matricula: \n");
            int matricula = malloc(sizeof(int));
            scanf(" %d", &matricula);

            add_abb(id, nome_aluno, matricula, descricao);
            in_ordem(raiz);


            
            return 0;
        }
    }
}