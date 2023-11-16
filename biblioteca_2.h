#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100

typedef struct {
    char detalhamento[MAX_DETALHAMENTOSERV];
    char dataCadastro[20];
    float preco;
} servico;

typedef struct {
    servico produto;
    char nome[MAX_NOME];
    char endEletronico[MAX_ENDERECO];
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4];
} prestador;

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4];
    float compra ;
} consumidor;

char *cadastrarUF(int opcao) {
    static char UF[4];

    switch (opcao) {
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
            strcpy(UF, "ES");
            break;
        case 8:
            strcpy(UF, "GO");
            break;
        case 9:
            strcpy(UF, "MA");
            break;
        case 10:
            strcpy(UF, "MT");
            break;
        case 11:
            strcpy(UF, "MS");
            break;
        case 12:
            strcpy(UF, "MG");
            break;
        case 13:
            strcpy(UF, "PA");
            break;
        case 14:
            strcpy(UF, "PB");
            break;
        case 15:
            strcpy(UF, "PR");
            break;
        case 16:
            strcpy(UF, "PE");
            break;
        case 17:
            strcpy(UF, "PI");
            break;
        case 18:
            strcpy(UF, "RJ");
            break;
        case 19:
            strcpy(UF, "RN");
            break;
        case 20:
            strcpy(UF, "RS");
            break;
        case 21:
            strcpy(UF, "RO");
            break;
        case 22:
            strcpy(UF, "RR");
            break;
        case 23:
            strcpy(UF, "SC");
            break;
        case 24:
            strcpy(UF, "SP");
            break;
        case 25:
            strcpy(UF, "SE");
            break;
        case 26:
            strcpy(UF, "TO");
            break;
        default:
            printf("Opção inválida. Digite um número de 1 a 26.\n");
    }
    return UF;
}

void cadastrarPrestador(prestador *industria, int *nPrestador) {
    int opcao = 0;

    printf("Prestador\n____________\n");
    printf("\nNOME: ");
    scanf("%s", (*industria).nome);
    fflush(stdin);

    printf("ENDERECO ELETRONICO: ");
    scanf("%s", (*industria).endEletronico);
    fflush(stdin);

    printf("E-MAIL: ");
    scanf("%s", (*industria).email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &(*industria).telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%s", &(*industria).endereco);
    fflush(stdin);

    printf("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n"
           "[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n"
           "[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n"
           "[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n"
           "[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n"
           "[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n"
           "[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &opcao);
    strcpy((*industria).UF, cadastrarUF(opcao));
    (*nPrestador)++;
}

void cadastrarConsumidor(consumidor *comprador,int *nCliente ) {
    int opcao;
    comprador->compra =0;

    printf("Comprador\n__________\n");
    printf("\nNOME: ");
    scanf("%s", comprador->nome);
    fflush(stdin);

    printf("IDADE: ");
    scanf("%d", &comprador->idade);
    fflush(stdin);

    printf("E-MAIL: ");
    scanf("%s", comprador->email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &comprador->telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%s", &comprador->endereco);
    fflush(stdin);

    printf("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n"
           "[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n"
           "[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n"
           "[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n"
           "[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n"
           "[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n"
           "[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &opcao);
    strcpy(comprador->UF, cadastrarUF(opcao));
    (*nCliente)++;
}


#endif