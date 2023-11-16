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
    char compras[MAX_DETALHAMENTOSERV];
    int i = 0, x = 0;
    int nPrestador = 0;
    int nCliente = 0;
    int nProdutos = 0;
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
                    nProdutos++;
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
            sair = 0;
            do
            {
                cadastrarConsumidor(&cliente[i]);
                nCliente++;

                printf("Deseja cadastrar uma compra ao cliente a empresa %s: (1)SIM (0)NAO", cliente[i].nome);
                scanf("%d", &opcao);

                if (opcao == 1)
                {
                    do
                    {
                        printf("O que o cliente deseja compro :");
                        for (int x = 0; x <= nProdutos; x++)
                        {
                            printf("%s", industria[x].produto.detalhamento);
                        }
                        scanf("%s", compras);
                        for (x = 0; x < nProdutos; x++)
                        {
                            if (strcmp(compras, industria[x].produto.detalhamento) == 0)
                            {
                                cliente[i].compra += industria[x].produto.preco;
                            }
                        }

                        printf("O cliente deseja compra mais algo ?(1)SIM (0)NAO");
                        scanf("%d", sair);
                        if (sair == 0)
                        {
                            printf("Total da compra: %.2f",cliente[i].compra);
                        }
                        
                    } while (sair != 1);

                    do
                    {
                        printf("Deseja cadastrar mais algum cliente: (1)Sim (0)Nao");
                        scanf("%d", &sair);
                    } while (sair < 0 || sair > 1);

                    if (sair == 1)
                    {
                        i++;
                    }
                }
            } while (sair != 0);
            break;

        case 3:
            for (int x = 0; x <= nProdutos; x++)
            {
                printf("%s", industria[x].produto.detalhamento);
                printf("%s", industria[x].produto.dataCadastro);
                printf("%.2f",industria[x].produto.preco);
                printf("\n");
            }
            break;

        case 4:
            for (int x = 0; x <= nCliente; x++)
            {
                printf("%s",cliente[x].nome);
                printf("%d",cliente[x].idade);
                printf("%s",cliente[x].email);
                printf("%d",cliente[x].telefone);
                printf("%d",cliente[x].endereco);
                printf("%d",cliente[x].UF);
                printf("%.2f",cliente[x].compra);
                printf("\n");
            }
            break;

        case 5:
             for (int x = 0; x <= nCliente; x++)
            {
                printf("%s",industria[x].nome);
                printf("%s",industria[x].endEletronico);
                printf("%s",industria[x].email);
                printf("%d",industria[x].telefone);
                printf("%d",industria[x].endereco);
                printf("%d",industria[x].UF);
                printf("\n");
            }
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

            printf("\n\nPrograma encerrado!\n");            
        }
    }while (opcao != 11);

    return 0;
}
