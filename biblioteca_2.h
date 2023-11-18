#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100

typedef struct
{
    char detalhamento[MAX_DETALHAMENTOSERV];
    char dataCadastro[20];
    float preco;
} servico;

typedef struct
{
    servico produto;
    char nome[MAX_NOME];
    char endEletronico[MAX_ENDERECO];
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4];
} prestador;

typedef struct
{
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4];
    float compra;
} consumidor;

char *cadastrarUF(int opcao)
{
    static char UF[4];

    switch (opcao)
    {
    case 1:
        strcpy(UF, "AC");
        break;
    case 2:
        strcpy(UF, "AL");
        break;
    case 3:
        strcpy(UF, "AP");
        break;
    case 4:
        strcpy(UF, "AM");
        break;
    case 5:
        strcpy(UF, "BA");
        break;
    case 6:
        strcpy(UF, "CE");
        break;
    case 7:
    	strcpy(UF, "DF");
    	break;
    case 8:
        strcpy(UF, "ES");
        break;
    case 9:
        strcpy(UF, "GO");
        break;
    case 10:
        strcpy(UF, "MA");
        break;
    case 11:
        strcpy(UF, "MT");
        break;
    case 12:
        strcpy(UF, "MS");
        break;
    case 13:
        strcpy(UF, "MG");
        break;
    case 14:
        strcpy(UF, "PA");
        break;
    case 15:
        strcpy(UF, "PB");
        break;
    case 16:
        strcpy(UF, "PR");
        break;
    case 17:
        strcpy(UF, "PE");
        break;
    case 18:
        strcpy(UF, "PI");
        break;
    case 19:
        strcpy(UF, "RJ");
        break;
    case 20:
        strcpy(UF, "RN");
        break;
    case 21:
        strcpy(UF, "RS");
        break;
    case 22:
        strcpy(UF, "RO");
        break;
    case 23:
        strcpy(UF, "RR");
        break;
    case 24:
        strcpy(UF, "SC");
        break;
    case 25:
        strcpy(UF, "SP");
        break;
    case 26:
        strcpy(UF, "SE");
        break;
    case 27:
        strcpy(UF, "TO");
        break;
    default:
        printf("OpÃ§Ã£o invÃ¡lida. Digite um nÃºmero de 1 a 26.\n");
    }
    return UF;
}

/* CASE 1: CADASTRAR PRESTADOR */
void cadastrarPrestador(prestador *industria, int *nPrestador, int *nProdutos, int *i)
{
    int opcao = 0;

    printf("Prestador\n____________\n");
    printf("\nNOME: ");
    scanf("%s", &(*industria).nome);
    fflush(stdin);

    printf("ENDERECO ELETRONICO: ");
    scanf("%s", &(*industria).endEletronico);
    fflush(stdin);

    printf("E-MAIL: ");
    scanf("%s", &(*industria).email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &(*industria).telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%s", &(*industria).endereco);
    fflush(stdin);

    printf("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n"
           "[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (DF)Distrito Federal\t[8]--> (ES)Espirito Santo\n"
           "[9]--> (GO)Goias\t[10]--> (MA)Maranhao\t\t[11]--> (MT)Mato Grosso\t\t[12]--> (MS)Mato Grosso do Sul\n"
           "[13]--> (MG)Minas Gerais[14]--> (PA)Para\t\t[15]--> (PB)Paraiba\t\t[16]--> (PR)Parana\n"
           "[17]--> (PE)Pernambuco\t[18]--> (PI)Piaui\t\t[19]--> (RJ)Rio de Janeiro\t[20]--> (RN)Rio Grande do Norte\n"
           "[21]--> (RS)Rio Grande\t[22]--> (RO)Rondonia\t\t[23]--> (RR)Roraima\t\t[24]--> (SC)Santa Catarina\n"
           "[25]--> (SP)Sao Paulo\t[26]--> (SE)Sergipe\t\t[27]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &opcao);
    strcpy((*industria).UF, cadastrarUF(opcao));
    (*nPrestador)++;

    printf("Deseja cadastrar um produto a empresa %s: (1)SIM (0)NAO: ", industria->produto.detalhamento);
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        printf("Qual o nome do produto:");
        scanf("%s", &industria->produto.detalhamento);

        printf("Qual o preco do produto: ");
        scanf("%f", &industria->produto.preco);

        time_t t;
        struct tm *infoTempo;

        time(&t);
        infoTempo = localtime(&t);

        strftime(industria->produto.dataCadastro, sizeof(industria->produto.dataCadastro), "%Y-%m-%d %H:%M:%S", infoTempo);
        printf("Data do cadastro %s\n", industria->produto.dataCadastro);
        (*nProdutos)++;
    }
    (*i)++;
}

/* CASE 2: CADASTRAR CONSUMIDOR */
void cadastrarConsumidor(consumidor *comprador, int *nCliente, prestador industria[100], int nProdutos, int *i)
{
    int opcao, x;
    int sair = 0;
    char compras[MAX_DETALHAMENTOSERV];
    comprador->compra = 0;

    printf("Comprador\n__________\n");
    printf("\nNOME: ");
    scanf("%s", &comprador->nome);
    fflush(stdin);

    printf("IDADE: ");
    scanf("%d", &comprador->idade);
    fflush(stdin);

    printf("E-MAIL: ");
    scanf("%s", &comprador->email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &comprador->telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%s", &comprador->endereco);
    fflush(stdin);

    printf("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n"
           "[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (DF)Distrito Federal\t[8]--> (ES)Espirito Santo\n"
           "[9]--> (GO)Goias\t[10]--> (MA)Maranhao\t\t[11]--> (MT)Mato Grosso\t\t[12]--> (MS)Mato Grosso do Sul\n"
           "[13]--> (MG)Minas Gerais[14]--> (PA)Para\t\t[15]--> (PB)Paraiba\t\t[16]--> (PR)Parana\n"
           "[17]--> (PE)Pernambuco\t[18]--> (PI)Piaui\t\t[19]--> (RJ)Rio de Janeiro\t[20]--> (RN)Rio Grande do Norte\n"
           "[21]--> (RS)Rio Grande\t[22]--> (RO)Rondonia\t\t[23]--> (RR)Roraima\t\t[24]--> (SC)Santa Catarina\n"
           "[25]--> (SP)Sao Paulo\t[26]--> (SE)Sergipe\t\t[27]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &opcao);
    strcpy(comprador->UF, cadastrarUF(opcao));
    (*nCliente)++;

    printf("Deseja cadastrar uma compra ao cliente a empresa %s: (1)SIM (0)NAO: ", comprador->nome);
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        do
        {
            printf("O que o cliente deseja comprar:");
            for ( x = 0; x < nProdutos; x++)
            {
                printf("%s\n", industria->produto.detalhamento);
            }
            scanf("%s", compras);
            for (x = 0; x < nProdutos; x++)
            {
                if (strcmp(compras, industria->produto.detalhamento) == 0)
                {
                    comprador->compra += industria->produto.preco;
                }
            }

            printf("O cliente deseja compra mais algo ?(1)SIM (0)NAO");
            scanf("%d", &sair);
            if (sair == 0)
            {
                printf("Total da compra: %.2f\n", comprador->compra);
            }

        } while (sair != 0);
    }
    (*i)++;
}

/* CASE 3: LISTAR SERVIÇO */
void listarServico(prestador *industria)
{
    printf("Produto: %s\n", industria->produto.detalhamento);
    printf("Data de cadastro: %s\n", industria->produto.dataCadastro);
    printf("Preco: %.2f\n", industria->produto.preco);
    printf("\n\n");
}

/* CASE 4: LISTAR CLIENTES */
void listarCliente(consumidor *comprador)
{
    printf("Nome do Cliente: %s\n", comprador->nome);
    printf("Idade do Cliente:  %d\n", comprador->idade);
    printf("Email do Cliente: %s\n", comprador->email);
    printf("Telefone do cliente: %d\n", comprador->telefone);
    printf("Endereco do cliente: %s\n", comprador->endereco);
    printf("UF do cliente%s\n", comprador->UF);
    if (comprador->compra != 0)
    {
        printf("Valor total da Compra do cliente: %.2f\n", comprador->compra);
    }
    printf(" \n");
}

/* CASE 5: LISTAR PRESTADORES DE SERVIÇO */
void listarPrestador(prestador *industria)
{
    printf("Industria: %s\n", industria->nome);
    printf("Endereco endereco eletronico: %s\n", industria->endEletronico);
    printf("Email da industria: %s\n", industria->email);
    printf("Telefone da Industria: %d\n", industria->telefone);
    printf("Endereco da industria: %s\n", industria->endereco);
    printf("UF da industria: %s\n", industria->UF);
    printf("\n\n");
}

/* CASE 6: LISTAR CLIENTES POR ESTADO ESPECÍFICO */
void listarClientesEstadoEspecifico(consumidor cliente[], int qtdClientes){
	int idUf, i, qtdEncontrada = 0;
	char uf[4];
	printf("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n"
           "[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (DF)Distrito Federal\t[8]--> (ES)Espirito Santo\n"
           "[9]--> (GO)Goias\t[10]--> (MA)Maranhao\t\t[11]--> (MT)Mato Grosso\t\t[12]--> (MS)Mato Grosso do Sul\n"
           "[13]--> (MG)Minas Gerais[14]--> (PA)Para\t\t[15]--> (PB)Paraiba\t\t[16]--> (PR)Parana\n"
           "[17]--> (PE)Pernambuco\t[18]--> (PI)Piaui\t\t[19]--> (RJ)Rio de Janeiro\t[20]--> (RN)Rio Grande do Norte\n"
           "[21]--> (RS)Rio Grande\t[22]--> (RO)Rondonia\t\t[23]--> (RR)Roraima\t\t[24]--> (SC)Santa Catarina\n"
           "[25]--> (SP)Sao Paulo\t[26]--> (SE)Sergipe\t\t[27]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &idUf);
    strcpy(uf, cadastrarUF(idUf));
    printf("\nClientes do estado (%s)", uf);
    for (i = 0; i < qtdClientes; i++)
    {
        if (strcmp(uf, cliente[i].UF) == 0)
        {
            printf("\n\nNome: %s\n", cliente[i].nome);
            printf("Idade: %d\n", cliente[i].idade);
            printf("Email: %s\n", cliente[i].email);
            printf("Telefone: %d\n", cliente[i].telefone);
            printf("Endereco: %s\n", cliente[i].endereco);
            printf("UF: %s", cliente[i].UF);
            qtdEncontrada++;
        }
    }
    printf("\n%d cliente(s) encontrado! ", qtdEncontrada);
    if (!qtdEncontrada)
    {
        printf("Nao existem clientes cadastrados desse UF(%s)", uf);
    }
}

/* CASE 7: LISTAR PRESTADORES POR TIPO */
void listarPrestadoresPorTipo(prestador industria[], int nPrestador, const char tipoBuscado[]) {
	int x;
    printf("Prestadores de serviÃ§o do tipo %s:\n", tipoBuscado);
    for ( x = 0; x < nPrestador; x++) {
        if (strcmp(tipoBuscado, industria[x].produto.detalhamento) == 0) {
            printf("Nome da Empresa: %s\n", industria[x].nome);
            printf("Endereco Eletronico: %s\n", industria[x].endEletronico);
            printf("Email: %s\n", industria[x].email);
            printf("Telefone: %d\n", industria[x].telefone);
            printf("Endereco: %s\n", industria[x].endereco);
            printf("UF: %s\n", industria[x].UF);
            printf("\n");
        }
    }
}

/* CASE 8: ENCONTRAR O ESTADO COM O SERVIÇO MAIS CARO */
void estadoServicoMaisCaro(prestador industria[], int qtdIndustrias){
	int i, encontrado = 0, posicao = 0;
	if(qtdIndustrias > 0){
		for(i = 0; i < qtdIndustrias; i++){
			if(industria[i].produto.preco >= industria[posicao].produto.preco && industria[i].produto.preco != 0){
				posicao = i;
				encontrado = 1;
			}
		}
		if(encontrado){
			printf("\nEstado e industria do servico mais caro do pais!");
			printf("\nNome da industria: %s (%s)\n", industria[posicao].nome ,industria[posicao].UF);
			printf("Servico mais caro: \nNome: %s\nPreco: R$%.2f", industria[posicao].produto.detalhamento, industria[posicao].produto.preco);
		}else{
			printf("Existem prestadores de servicos, mas nenhum produto vinculado a ele");
		}
	}else{
		printf("\nNenhum prestador de servico cadastrado");
	}
}

/* CASE 9: LISTAR SERVIÇOS EM ORDEM CRESCENTE */
void listrServicoCrescente(prestador *industria) {
    char tmps[MAX_NOME];
    int tmpi;

    // Troca de detalhamento
    strcpy(tmps, industria->produto.detalhamento);
    strcpy(industria->produto.detalhamento, (industria + 1)->produto.detalhamento);
    strcpy((industria + 1)->produto.detalhamento, tmps);

    // Troca de preÃ§o
    tmpi = industria->produto.preco;
    industria->produto.preco = (industria + 1)->produto.preco;
    (industria + 1)->produto.preco = tmpi;

    // Troca de data de cadastro
    strcpy(tmps, industria->produto.dataCadastro);
    strcpy(industria->produto.dataCadastro, (industria + 1)->produto.dataCadastro);
    strcpy((industria + 1)->produto.dataCadastro, tmps);
}

/* CASE 10: LISTAR NOMES DE CLIENTES EM ORDEM CRESCENTE */
void listaClienteCrescente(consumidor *comprador)
{
    char tmps[MAX_NOME];
    int tmpi;

    // Troca de informaÃ§Ãµes entre o comprador atual e o prÃ³ximo
    strcpy(tmps, comprador->nome);
    strcpy(comprador->nome, (comprador + 1)->nome);
    strcpy((comprador + 1)->nome, tmps);

    tmpi = comprador->idade;
    comprador->idade = (comprador + 1)->idade;
    (comprador + 1)->idade = tmpi;

    strcpy(tmps, comprador->email);
    strcpy(comprador->email, (comprador + 1)->email);
    strcpy((comprador + 1)->email, tmps);

    tmpi = comprador->telefone;
    comprador->telefone = (comprador + 1)->telefone;
    (comprador + 1)->telefone = tmpi;

    strcpy(tmps, comprador->endereco);
    strcpy(comprador->endereco, (comprador + 1)->endereco);
    strcpy((comprador + 1)->endereco, tmps);

    strcpy(tmps, comprador->UF);
    strcpy(comprador->UF, (comprador + 1)->UF);
    strcpy((comprador + 1)->UF, tmps);
}

#endif