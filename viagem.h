
#ifndef PROJETO_LP1_AED1_VIAGEM_H
#define PROJETO_LP1_AED1_VIAGEM_H

#include "stdio.h"
#include "time.h"
#include "string.h"
#include "stdlib.h"
#include "cidade.h"



#define MAX200 200

typedef struct viagem {
    int realizada; // realizada = 1 // a realizar = 0
    char titulo[MAX200];
    time_t data_inicio;
    time_t data_fim;
    CIDADE_ARRAY array_cidades;
}VIAGEM;


typedef struct viagem_array {
    int n_viagem; // usado no array
    int size_viagem; // tamanho do array dinamico
    VIAGEM *pviagem; //ARRAY DE VIAGENS
} VIAGEM_ARRAY;


VIAGEM* criar_viagem_a_realizar(char titulo[MAX100], int size_cidades);
VIAGEM* criar_viagem(char titulo[MAX100], time_t data_inicio, time_t data_fim, int size_cidades);
VIAGEM_ARRAY* initArrayViagem(int initsize);
void redimensionarArrayViagem(VIAGEM_ARRAY* a, int size);
void inserirArrayViagem(VIAGEM_ARRAY* a, VIAGEM* v);
void editarViagem(VIAGEM_ARRAY* a, VIAGEM* v, char titulo[MAX100], time_t data_inicio, time_t data_fim);
void removerArrayViagem(VIAGEM_ARRAY* viagem_array, VIAGEM* v);
VIAGEM* procurarArrayViagem(VIAGEM_ARRAY* a, char titulo[MAX100]);
void freeArrayViagem(VIAGEM_ARRAY * a);


#endif //PROJETO_LP1_AED1_VIAGEM_H
