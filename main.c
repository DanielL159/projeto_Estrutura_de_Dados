#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "biblioteca_2.h"
#include <time.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100
 
//declaração das structs com características específicas de cada "tópico"

/*typedef struct compra {
};*/
typedef struct  {
    char detalhamento[MAX_DETALHAMENTOSERV];
    char dataCadastro[20];
    float preco;
}servico;

typedef struct  {
    servico produto;
    char nome[MAX_NOME];
    char endEletronico[MAX_ENDERECO];
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4]; 
}prestador;

typedef struct  {
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    int UF;
}consumidor;

int main() {
    int nPrestador = 0;
    prestador industria[100];
    consumidor cliente[100];
    int opcao;
    int sair=0;

    do {
        printf("\n\n********FARMACIA*********\n\n");
        printf("[1] Cadastrar prestador ou/e produto\n");
        printf("[2] Cadastrar Cliente\n");
        printf("[3] Listar tipos de servicos\n");
        printf("[4] Listar clientes\n");
        printf("[5] Listar prestadores de servico\n");
        printf("[6] Listar clientes de estado especifico\n");
        printf("[7] Listar prestadores de servico de tipo especifico\n");
        printf("[8] Estado com o servico mais caro no pais\n");
        printf("[9] Listar servicos em ordem crescente\n");
        printf("[10] Listar nomes de clientes em ordem crescente\n");
        printf("[11] Sair\n\n");

        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            int i =0;
            do
            { 
                cadastrarPrestador(&industria[i]);

                printf("Deseja cadastrar um produto a empresa %s: (1)SIM (0)NAO",industria[i].produto.detalhamento);
                scanf("%d",&opcao);

                if (opcao ==1)
                {
                    printf("Qual o nome do produto:");
                    fflush(stdin);
                    scanf("%s",&industria[i].produto.detalhamento);

                    printf("Qual o preco do produto: ");
                    fflush(stdin);
                    scanf("%f",industria[i].produto.preco);

                    time_t t;
                    struct tm *infoTempo;

                    time(&t);
                    infoTempo = localtime(&t);

                    // Formatar a data atual como string e atribuir a dataCadastro
                    strftime(industria[i].produto.dataCadastro, sizeof(industria[i].produto.dataCadastro), "%Y-%m-%d %H:%M:%S", infoTempo);
                    printf("Data do cadastro %s",industria[i].produto.dataCadastro);
                    
                }do
                {
                    printf("Deseja cadastrar mais alguma empresa: (1)Sim (0)Nao");
                    scanf("%d",&sair);
                } while (sair <0 || sair >1);
                
            
                

            } while (sair !=1); 
            
            
            break;

            case 2:
            break;

            case 3:

            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8: 
            break;

            case 9: 
            break;

            default:

            printf ("Digite um numero valido!");

        }

    } while (opcao != 0);

        printf("\n\nPrograma encerrado!");
}
