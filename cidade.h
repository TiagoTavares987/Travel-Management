
#ifndef PROJETO_LP1_AED1_CIDADE_H
#define PROJETO_LP1_AED1_CIDADE_H

#define MAX100 100

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "poi.h"

typedef struct cidade {
    char nome_cidade[MAX100];
    char cidade_pais[MAX100];
    float latitude;
    float longitude;
    POI_ARRAY array_poi;
}CIDADE;

typedef struct cidade_array {
    int n_cidade; // usado
    int size_cidade;
    CIDADE *pcidade; //ARRAY DE CIDADES
} CIDADE_ARRAY;

CIDADE* criar_cidade(char nome_cidade[MAX100], char cidade_pais[MAX100], float latitude, float longitude, int size_poi);
CIDADE_ARRAY* initArrayCidade(int initsize);
void redimensionarArrayCidade(CIDADE_ARRAY* c, int size);
void inserirArrayCidade(CIDADE_ARRAY* list, CIDADE* c);
void editarCidade(CIDADE_ARRAY* list, CIDADE* c, char nome_cidade[MAX100], char cidade_pais[MAX100], float latitude, float longitude);
void removerArrayCidade(CIDADE_ARRAY* cidade_array, CIDADE* c);
CIDADE* procurarCidadeNome(CIDADE_ARRAY* c, char nome_cidade[MAX100]);
void freeArrayCidade(CIDADE_ARRAY* c);

#endif //PROJETO_LP1_AED1_CIDADE_H
