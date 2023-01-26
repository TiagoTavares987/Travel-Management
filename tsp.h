
#ifndef PROJETO_LP1_AED1_TSP_H
#define PROJETO_LP1_AED1_TSP_H

#define MAX100 100

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct ponto {
    int id;
    float x;
    float y;
}PONTO;

typedef struct ponto_array {
    int n_pontos;
    int size_pontos;
    PONTO* pontos;
} PONTO_ARRAY;

typedef struct algoritmo {
    char nome[MAX100];
    float distancia;
    PONTO_ARRAY* list;
} ALGORITMO;

PONTO* criar_ponto(int id, float x, float y);
PONTO_ARRAY* initArrayPonto(int initsize);
ALGORITMO* initAlgoritmo(char nome[MAX100], float distancia, PONTO_ARRAY* list);

void inserirArrayPonto(PONTO_ARRAY* list, PONTO* p);
void removerArrayPonto(PONTO_ARRAY* list, PONTO* p);

PONTO_ARRAY* gerar_lista_de_pontos(int n_pontos);

ALGORITMO* vizinho_mais_proximo(PONTO_ARRAY* pontos);

void teste_algoritmos();

#endif //PROJETO_LP1_AED1_TSP_H
