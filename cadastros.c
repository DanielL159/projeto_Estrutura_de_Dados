#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 50
#define MAX_DETALHAMENTOSERV 100


//declaração das structs com características específicas de cada "tópico"

/*typedef struct compra {
};*/

typedef struct  {
    char nome[MAX_NOME];
    char endEletronico[MAX_ENDERECO];
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    int UF;
    struct prestador* prox;
}prestador;

typedef struct  {
    char nome[MAX_NOME];
    int idade;
    char email[MAX_EMAIL];
    int telefone;
    char endereco[MAX_ENDERECO];
    int UF;
    struct consumidor* prox;
}consumidor;

typedef struct  {
    char detalhamento[MAX_DETALHAMENTOSERV];
    char dataServico[20];
    float preco;
    struct servico* prox;
}servico;

int main() {

    Prestador* listaP = inicializarPrestador();
    Consumidor* listaC = inicializarConsumidor();
    Servico* listaS = inicializarServico();


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

            case 1:
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
