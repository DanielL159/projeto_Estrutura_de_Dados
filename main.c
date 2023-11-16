#include "biblioteca_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100

int main()
{
    int i = 0;
    int nPrestador = 0;
    int nCliente = 0;
    prestador industria[100];
    consumidor cliente[100];
    int opcao;
    int sair = 0;

    do
    {
        printf("\n\n********FARMACIA*********\n\n");
        printf("[1] Cadastrar prestador ou/e produto\n");
        printf("[2] Cadastrar Cliente ou/e compra\n");
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

        switch (opcao)
        {
        case 1:
            do
            {
                cadastrarPrestador(&industria[i]);
                nPrestador++;

                printf("Deseja cadastrar um produto a empresa %s: (1)SIM (0)NAO", industria[i].produto.detalhamento);
                scanf("%d", &opcao);

                if (opcao == 1)
                {
                    printf("Qual o nome do produto:");
                    scanf("%s", industria[i].produto.detalhamento);

                    printf("Qual o preco do produto: ");
                    scanf("%f", &industria[i].produto.preco);

                    time_t t;
                    struct tm *infoTempo;

                    time(&t);
                    infoTempo = localtime(&t);

                    strftime(industria[i].produto.dataCadastro, sizeof(industria[i].produto.dataCadastro), "%Y-%m-%d %H:%M:%S", infoTempo);
                    printf("Data do cadastro %s", industria[i].produto.dataCadastro);
                }

                do
                {
                    printf("Deseja cadastrar mais alguma empresa: (1)Sim (0)Nao");
                    scanf("%d", &sair);
                } while (sair < 0 || sair > 1);

                if (sair == 1)
                {
                    i++;
                }
            } while (sair != 0);
            break;

        case 2:
            i = 0;
            do
            {
                cadastrarConsumidor(&cliente[i]);
                nCliente++;

                printf("Deseja cadastrar uma compra ao cliente a empresa %s: (1)SIM (0)NAO", cliente[i].nome);
                scanf("%d", &opcao);

                if (opcao == 1)
                {
                    // Implemente a lógica para cadastrar compra
                }

                do
                {
                    printf("Deseja cadastrar mais algum cliente: (1)Sim (0)Nao");
                    scanf("%d", &sair);
                } while (sair < 0 || sair > 1);

                if (sair == 1)
                {
                    i++;
                }
            } while (sair != 0);
            break;

        case 3:
            // Implemente a lógica para listar tipos de serviços
            break;

        case 4:
            // Implemente a lógica para listar clientes
            break;

        case 5:
            // Implemente a lógica para listar prestadores de serviço
            break;

        case 6:
            // Implemente a lógica para listar clientes de estado específico
            break;

        case 7:
            // Implemente a lógica para listar prestadores de serviço de tipo específico
            break;

        case 8:
            // Implemente a lógica para encontrar o estado com o serviço mais caro no país
            break;

        case 9:
            // Implemente a lógica para listar serviços em ordem crescente
            break;

        case 10:
            // Implemente a lógica para listar nomes de clientes em ordem crescente
            break;

        case 11:
            break;

        default:
            printf("Digite um numero valido!\n");
        }

    } while (opcao != 11);

    printf("\n\nPrograma encerrado!\n");

    return 0;
}
