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
            // Implemente a lógica para listar clientes de estado específico
            printf("UNIDADE FEDERATIVA:\n\n");
            int idUf, qtdEncontrada = 0;
            printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n"
                   "[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n"
                   "[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n"
                   "[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n"
                   "[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n"
                   "[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n"
                   "[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
            scanf("%d", &idUf);
            char uf[4];
            strcpy(uf, cadastrarUF(idUf));
            printf("\nClientes do estado (%s)", uf);
            for (x = 0; x < nCliente; x++)
            {
                if (strcmp(uf, cliente[x].UF) == 0)
                {
                    printf("\n\nNome: %s\n", cliente[x].nome);
                    printf("Idade:  %d\n", cliente[x].idade);
                    printf("Email: %s\n", cliente[x].email);
                    printf("Telefone: %d\n", cliente[x].telefone);
                    printf("Endereco: %s\n", cliente[x].endereco);
                    printf("UF: %s", cliente[x].UF);
                    qtdEncontrada++;
                }
            }
            printf("\n%d cliente(s) encontrado! ", qtdEncontrada);
            if (!qtdEncontrada)
            {
                printf("Nao existem clientes cadastrados desse UF(%s)", uf);
            }

            break;

            
    	case 7:
    		//Listar prestadores de serviço por tipo 
        		printf("Digite o tipo de serviço que deseja buscar: ");
        		scanf("%s", tmps);
        		
        		listarPrestadoresPorTipo(industria, nPrestador, tmps);
        	
        	break;
        	 		
        case 8:
            // Implemente a lógica para encontrar o estado com o serviço mais caro no país
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