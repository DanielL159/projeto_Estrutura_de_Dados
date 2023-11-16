#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100

//declaraÃƒÂ§ÃƒÂ£o das structs com caracterÃƒÂ­sticas especÃƒÂ­ficas de cada "tÃƒÂ³pico"

/*typedef struct compra {
};*/

typedef struct{
    char detalhamento[MAX_DETALHAMENTOSERV];
    char dataCadastro[20];
    float preco;
}Servico;

typedef struct{
    Servico produto;
    char nome[MAX_NOME];
    char endEletronico[MAX_ENDERECO];
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4]; 
}Prestador;

typedef struct{
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    char UF[4];
}Consumidor;

char *cadastrarUF(int opcao){
    static char UF[4];

	do{
		switch (opcao) {
        case 1:
            strcpy(UF, "AC"); // Acre
            break;
        case 2:
            strcpy(UF, "AL"); // Alagoas
            break;
        case 3:
            strcpy(UF, "AP"); // AmapÃƒÂ¡
            break;
        case 4:
            strcpy(UF, "AM"); // Amazonas
            break;
        case 5:
            strcpy(UF, "BA"); // Bahia
            break;
        case 6:
            strcpy(UF, "CE"); // CearÃƒÂ¡
            break;
        case 7:
            strcpy(UF, "ES"); // EspÃƒÂ­rito Santo
            break;
        case 8:
            strcpy(UF, "GO"); // GoiÃƒÂ¡s
            break;
        case 9:
            strcpy(UF, "MA"); // MaranhÃƒÂ£o
            break;
        case 10:
            strcpy(UF, "MT"); // Mato Grosso
            break;
        case 11:
            strcpy(UF, "MS"); // Mato Grosso do Sul
            break;
        case 12:
            strcpy(UF, "MG"); // Minas Gerais
            break;
        case 13:
            strcpy(UF, "PA"); // ParÃƒÂ¡
            break;
        case 14:
            strcpy(UF, "PB"); // ParaÃƒÂ­ba
            break;
        case 15:
            strcpy(UF, "PR"); // ParanÃƒÂ¡
            break;
        case 16:
            strcpy(UF, "PE"); // Pernambuco
            break;
        case 17:
            strcpy(UF, "PI"); // PiauÃƒÂ­
            break;
        case 18:
            strcpy(UF, "RJ"); // Rio de Janeiro
            break;
        case 19:
            strcpy(UF, "RN"); // Rio Grande do Norte
            break;
        case 20:
            strcpy(UF, "RS"); // Rio Grande do Sul
            break;
        case 21:
            strcpy(UF, "RO"); // RondÃƒÂ´nia
            break;
        case 22:
            strcpy(UF, "RR"); // Roraima
            break;
        case 23:
            strcpy(UF, "SC"); // Santa Catarina
            break;
        case 24:
            strcpy(UF, "SP"); // SÃƒÂ£o Paulo
            break;
        case 25:
            strcpy(UF, "SE"); // Sergipe
            break;
        case 26:
            strcpy(UF, "TO"); // Tocantins
            break;
        default:
            printf("OpÃƒÂ§ÃƒÂ£o invÃƒÂ¡lida. Digite um nÃƒÂºmero de 1 a 26.\n");
		} 
	}while (opcao < 1 || opcao > 26);
     
    return UF;
}

void cadastrarPrestador(Prestador *industria) {
    char x[4];
    int opcao=0;

    printf("Prestador\n____________");
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
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d",&opcao);
    strcpy((*industria).UF, cadastrarUF(opcao));
    fflush(stdin);
}

void cadastrarConsumidor(Consumidor *cliente) {
    char x[4];
    int opcao=0;

    printf("Consumidor\n____________");
    printf("\nNOME: ");
    scanf("%s", &(*cliente).nome);
    fflush(stdin);

    printf("IDADE: ");
    scanf("%d", &(*cliente).idade);
    fflush(stdin);

    printf("EMAIL: ");
    scanf("%s", &(*cliente).email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &(*cliente).telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%s", &(*cliente).endereco);
    fflush(stdin);
    
    printf("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d",&opcao);
    strcpy((*cliente).UF, cadastrarUF(opcao));
    fflush(stdin);
}
