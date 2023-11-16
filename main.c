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
    char tmps[50];
    char compras[MAX_DETALHAMENTOSERV];
    int i = 0, x = 0;
    int nPrestador = 0;
    int nCliente = 0;
    int nProdutos = 0;
    prestador industria[100];
    consumidor cliente[100];
    int opcao, tmpi;
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
                cadastrarPrestador(&industria[i], &nPrestador);

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
                cadastrarConsumidor(&cliente[i], &nCliente);

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
                            printf("Total da compra: %.2f", cliente[i].compra);
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
            for (int x = 0; x < nProdutos; x++)
            {
                printf("Produto: %s", industria[x].produto.detalhamento);
                printf("Data de cadastro: %s", industria[x].produto.dataCadastro);
                printf("Preco: %.2f", industria[x].produto.preco);
                printf("\n");
            }
            break;

        case 4:
            for (int x = 0; x < nCliente; x++)
            {
                printf("Nome do Cliente: %s\n", cliente[x].nome);
                printf("Idade do Cliente:  %d\n", cliente[x].idade);
                printf("Email do Cliente: %s\n", cliente[x].email);
                printf("Telefone do cliente: %d\n", cliente[x].telefone);
                printf("Endereco do cliente: %s\n", cliente[x].endereco);
                printf("UF do cliente%s\n", cliente[x].UF);
                if (cliente[x].compra != 0)
                {
                    printf("Valor total da Compra do cliente: %.2f\n", cliente[x].compra);
                }
                printf(" \n");
            }
            break;

        case 5:
            for (int x = 0; x < nPrestador; x++)
            {
                printf("Industria: %s\n", industria[x].nome);
                printf("Endereco endereco eletronico: %s\n", industria[x].endEletronico);
                printf("Email da industria: %s\n", industria[x].email);
                printf("Telefone da Industria: %d\n", industria[x].telefone);
                printf("Endereco da industria: %s\n", industria[x].endereco);
                printf("UF da industria: %s\n", industria[x].UF);
                printf("\n\n");
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
            for (int i = 0; i < nProdutos - 1; i++)
            {
                for (int j = 0; j < nProdutos - i - 1; j++)
                {
                    if (strcmp(industria[j].produto.detalhamento, industria[j + 1].produto.detalhamento) > 0)
                    {
                        strcpy(tmps, industria[j].produto.detalhamento);
                        strcpy(industria[j].produto.detalhamento, industria[j + 1].produto.detalhamento);
                        strcpy(industria[j + 1].produto.detalhamento, tmps);

                        tmpi = industria[j].produto.preco;
                        industria[j].produto.preco = industria[j + 1].produto.preco;
                        industria[j + 1].produto.preco = tmpi;

                        strcpy(tmps, industria[j].produto.dataCadastro);
                        strcpy(industria[j].produto.dataCadastro, industria[j + 1].produto.dataCadastro);
                        strcpy(industria[j + 1].produto.dataCadastro, tmps);
                    }
                }
            }
            for (int x = 0; x < nProdutos; x++)
            {
                printf("Produto: %s", industria[x].produto.detalhamento);
                printf("Data de cadastro: %s", industria[x].produto.dataCadastro);
                printf("Preco: %.2f", industria[x].produto.preco);
                printf("\n");
            }
            break;

        case 10:
            for (int i = 0; i < nCliente - 1; i++)
            {
                for (int j = 0; j < nCliente - i - 1; j++)
                {
                    if (strcmp(cliente[j].nome, cliente[j + 1].nome) > 0)
                    {
                        strcpy(tmps, cliente[j].nome);
                        strcpy(cliente[j].nome, cliente[j + 1].nome);
                        strcpy(cliente[j + 1].nome, tmps);

                        tmpi = cliente[j].idade;
                        cliente[j].idade = cliente[j + 1].idade;
                        cliente[j + 1].idade = tmpi;

                        strcpy(tmps, cliente[j].email);
                        strcpy(cliente[j].email, cliente[j + 1].email);
                        strcpy(cliente[j + 1].email, tmps);

                        tmpi = cliente[j].telefone;
                        cliente[j].telefone = cliente[j + 1].telefone;
                        cliente[j + 1].telefone = tmpi;

                        strcpy(tmps, cliente[j].endereco);
                        strcpy(cliente[j].endereco, cliente[j + 1].endereco);
                        strcpy(cliente[j + 1].endereco, tmps);

                        strcpy(tmps, cliente[j].UF);
                        strcpy(cliente[j].UF, cliente[j + 1].UF);
                        strcpy(cliente[j + 1].UF, tmps);
                    }
                }
            }
            for (int x = 0; x < nCliente; x++)
            {
                printf("Nome do Cliente: %s\n", cliente[x].nome);
                printf("Idade do Cliente:  %d\n", cliente[x].idade);
                printf("Email do Cliente: %s\n", cliente[x].email);
                printf("Telefone do cliente: %d\n", cliente[x].telefone);
                printf("Endereco do cliente: %s\n", cliente[x].endereco);
                printf("UF do cliente%s\n", cliente[x].UF);
                if (cliente[x].compra != 0)
                {
                    printf("Valor total da Compra do cliente: %.2f\n", cliente[x].compra);
                }
                printf(" \n");
            }
            break;

        default:
            if (opcao != 11)
            {
                printf("Digite um numero valido!\n")
            }
        }
    } while (opcao != 11);
        printf("Programa encerrado"); 
    return 0;
}
