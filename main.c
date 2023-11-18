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
    int i = 0, x = 0,j = 0;
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
            i = 0;
            do
            {
                cadastrarPrestador(&industria[nPrestador], &nPrestador, &nProdutos, &i);

                do
                {
                    printf("Deseja cadastrar mais alguma empresa: (1)Sim (0)Nao: ");
                    fflush(stdin);
                    scanf("%d", &sair);
                } while (sair < 0 || sair > 1);

            } while (sair != 0);
            break;

        case 2:
            /*Cadastrar Cliente ou/e compra*/
            sair = 0;
            do
            {
                cadastrarConsumidor(&cliente[nCliente], &nCliente, industria, nProdutos, &i);
                do
                {
                    printf("Deseja cadastrar mais algum cliente: (1)Sim (0)Nao: ");
                    scanf("%d", &sair);
                } while (sair < 0 || sair > 1);

            } while (sair != 0);
            break;

        case 3:
            /*Listar tipos de servicos*/
            for ( x = 0; x < nProdutos; x++)
            {
                listarServico(&industria[x]);
            }
            break;

        case 4:
            /*Listar clientes*/
            for ( x = 0; x < nCliente; x++)
            {
                listarCliente(&cliente[x]);
            }
            break;

        case 5:
            /*Listar prestadores de servico*/
            for ( x = 0; x < nPrestador; x++)
            {
                listarPrestador(&industria[x]);
            }
            break;

        case 6:
            // Implemente a lógica para listar clientes de estado especÃ­fico
            listarClientesEstadoEspecifico(cliente, nCliente);
            break;

            
    	case 7:
    		//Listar prestadores de serviço por tipo 
        		printf("Digite o tipo de serviÃ§o que deseja buscar: ");
        		scanf("%s", tmps);
        		
        		listarPrestadoresPorTipo(industria, nPrestador, tmps);
        	
        	break;
        	 		
        case 8:
            // Implemente a lógica para encontrar o estado com o serviço mais caro no paÃ­s
            estadoServicoMaisCaro(industria, nPrestador);
            break;

        case 9:
            /*Listar servicos em ordem crescente*/
            for ( i = 0; i < nProdutos - 1; i++)
            {
                for ( j = 0; j < nProdutos - i - 1; j++)
                {
                    if (strcmp(industria[j].produto.detalhamento, industria[j + 1].produto.detalhamento) > 0)
                    {
                         listrServicoCrescente(&industria[j]);
                    }
                }
            }
            for ( x = 0; x < nProdutos; x++)
            {
                listarServico(&industria[x]);
            }
            break;

        case 10:
            /*Listar nomes de clientes em ordem crescente*/
            for ( i = 0; i < nCliente - 1; i++)
            {
                for ( j = 0; j < nCliente - i - 1; j++)
                {
                    if (strcmp(cliente[j].nome, cliente[j + 1].nome) > 0)
                    {
                         listaClienteCrescente(&cliente[j]);
                    }
                }
            }
            for ( x = 0; x < nCliente; x++)
            {
               listarCliente(&cliente[x]);
            }
            break;

        default:
            if (opcao != 11) 
            {
                printf("Digite um numero valido!\n");
            }
        }
    } while (opcao != 11);
    printf("Programa encerrado");
    return 0;
}