

#ifndef PROJETO_LP1_AED1_CLIENTE_H
#define PROJETO_LP1_AED1_CLIENTE_H


#define MAX100 100
#define MAX200 200

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "viagem.h"

// LISTA LIGADA DE CLIENTES
typedef struct cliente {
    int id_cliente;
    char nome_cliente[MAX100];
    char morada[MAX200];
    int contacto;
    int nif;
    VIAGEM_ARRAY array_viagens;
    struct cliente* pnext_cliente;
}CLIENTE;


typedef struct listacliente {
    int num_clientes;
    CLIENTE* pclientes;
}LISTACLIENTE;

LISTACLIENTE *criar_lista_cliente();
CLIENTE *criar_cliente(int id_cliente, char nome[MAX100], char morada[MAX200], int contacto, int nif, int size_viagens);
void inserir_cliente_cabeca(LISTACLIENTE* p, CLIENTE* c);
void inserir_cliente_cauda(LISTACLIENTE* p, CLIENTE* c);
void inserir_cliente_ordenado_nif(LISTACLIENTE* p, CLIENTE* c);
CLIENTE *procurar_cliente_nif(LISTACLIENTE *p, int nif);
CLIENTE *procurar_cliente_nome(LISTACLIENTE *p, char nome_cliente[MAX100]);
void remover_cliente(LISTACLIENTE *p, char nome[MAX100]);
void ordenar_lista_nif(LISTACLIENTE* original);


#endif //PROJETO_LP1_AED1_CLIENTE_H
