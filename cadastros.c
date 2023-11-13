#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100


//declaração das structs com características específicas de cada "tópico"

/*typedef struct compra {
};*/

typedef struct prestador {
    char nome[MAX_NOME];
    char endEletronico[MAX_ENDERECO];
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    int UF;
    struct prestador* prox;
}Prestador;

typedef struct consumidor {
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    int UF;
    struct consumidor* prox;
}Consumidor;

typedef struct servico {
    char detalhamento[MAX_DETALHAMENTOSERV];
    char dataServico[20];
    float preco;
    struct servico* prox;
}Servico;

//funções para inicializar as listas vazias.

Prestador* inicializarPrestador(void) {
    return NULL;
}

Consumidor* inicializarConsumidor(void) {
    return NULL;
}

Servico* inicializarServico(void) {
    return NULL;
}

//cadastros

Prestador* cadastrarPrestador(Prestador* listaP) {
    Prestador* novoPrestador = (Prestador*)malloc(sizeof(Prestador));

    printf ("PRESTADOR\n____________");
    printf("\nNOME: ");
    scanf("%s", novoPrestador->nome);
    fflush(stdin);

    printf("ENDERECO ELETRONICO: ");
    scanf("%s", novoPrestador->endEletronico);
    fflush(stdin);

    printf("E-MAIL: ");
    scanf("%s", novoPrestador->email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &novoPrestador->telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%s", novoPrestador->endereco);
    fflush(stdin);
        
        
    printf ("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &novoPrestador->UF);
    fflush(stdin);

    novoPrestador->prox = listaP;
    return novoPrestador;
}

Consumidor* cadastrarConsumidor(Consumidor* listaC) {
    Consumidor* novoConsumidor = (Consumidor*)malloc(sizeof(Consumidor));

    printf ("CONSUMIDOR\n__________");
    printf("\nNOME: ");
    scanf("%s", novoConsumidor->nome);
    fflush(stdin);

    printf("IDADE: ");
    scanf("%d", &novoConsumidor->idade);
    fflush(stdin);

    printf("E-MAIL: ");
    scanf("%s", novoConsumidor->email);
    fflush(stdin);

    printf("TELEFONE: ");
    scanf("%d", &novoConsumidor->telefone);
    fflush(stdin);

    printf("ENDERECO: ");
    scanf("%[^/n]s", novoConsumidor->endereco);
    fflush(stdin);
        
        
    printf ("UNIDADE FEDERATIVA:\n\n");
    printf("[1]--> (AC)Acre\t\t[2]--> (AL)Alagoas\t\t[3]--> (AP)Amapa\t\t[4]--> (AM)Amazonas\n[5]--> (BA)Bahia\t[6]--> (CE)Ceara\t\t[7]--> (ES)Espirito Santo\t[8]--> (GO)Goias\n[9]--> (MA)Maranhao\t[10]--> (MT)Mato Grosso\t\t[11]--> (MS)Mato Grosso do Sul\t[12]--> (MG)Minas Gerais\n[13]--> (PA)Para\t[14]--> (PB)Paraiba\t\t[15]--> (PR)Parana\t\t[16]--> (PE)Pernambuco\n[17]--> (PI)Piaui\t[18]--> (RJ)Rio de Janeiro\t[19]--> (RN)Rio Grande do Norte\t[20]--> (RS)Rio Grande do Sul\n[21]--> (RO)Rondonia\t[22]--> (RR)Roraima\t\t[23]--> (SC)Santa Catarina\t[24]--> (SP)Sao Paulo\n[25]--> (SE)Sergipe\t[26]--> (TO)Tocantins\n\nDIGITE UMA UF:");
    scanf("%d", &novoConsumidor->UF);
    fflush(stdin);

    novoConsumidor->prox = listaC;
    return novoConsumidor;

}

Servico* cadastrarServico(Servico* listaS) {
    Servico* novoServico = (Servico*)malloc(sizeof(Servico));

    printf ("SERVICO\n__________");
    printf("\nDetalhamento do servico: ");
    scanf("%s", novoServico->detalhamento);
    fflush(stdin);

    printf("Data do servico prestado: ");
    scanf("%s", novoServico->dataServico);
    fflush(stdin);

    printf("Preco cobrado: ");
    scanf("%f", &novoServico->preco);
    fflush(stdin);

    novoServico->prox = listaS;
    return novoServico;
}

int main() {

    Prestador* listaP = inicializarPrestador;
    Consumidor* listaC = inicializarConsumidor;
    Servico* listaS = inicializarServico;


    int opcao;

    do {
        printf ("----------CADASTRO----------\n\n");
        printf("[1] Cadastrar prestador de servico\n");
        printf("[2] Cadastrar consumidor\n");
        printf("[3] Cadastrar servico\n");
        printf("[4] Sair\n\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            cadastrarPrestador(listaP);
            break;

            case 2:
            cadastrarConsumidor(listaC);
            break;

            case 3:
            cadastrarServico(listaS);
            break;

            default:
            printf("Digite um valor valido!");
        }

    }while (opcao != 4);


    do {
        printf("\n\n********FARMACIA*********\n\n");
        printf("[1] Listar tipos de servicos\n");
        printf("[2] Listar clientes\n");
        printf("[3] Listar prestadores de servico\n");
        printf("[4] Listar clientes de estado especifico\n");
        printf("[5] Listar prestadores de servico de tipo especifico\n");
        printf("[6] Estado com o servico mais caro no pais\n");
        printf("[7] Listar servicos em ordem crescente\n");
        printf("[8] Listar nomes de clientes em ordem crescente\n");
        printf("[0] Sair\n\n");

        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        /*switch (opcao) {

            /*case 1:
            imprimirTiposServicos(lista);
            break;

            case 2:
            imprimirClientes(listaC);
            break;

            case 3:
            imprimirPrestadorServico(listaP);
            break;

            case 4:
            imprimirClientesEstado(listaC);
            break;

            case 5:
            imprimirServicoEspecifico(lista);
            break;

            case 6:
            imprimirEstadosCaro(listaS);
            break;

            case 7: 
            imprimirServicos(lista);
            break;

            case 8: 
            imprimirClientes(listaC);
            break;

            default:

            printf ("Digite um numero valido!");

        }*/

    } while (opcao != 0);

        printf("\n\nPrograma encerrado!");
}