
#ifndef PROJETO_LP1_AED1_POI_H
#define PROJETO_LP1_AED1_POI_H

#define MAX100 100
#define MAX200 200

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct poi{
    char nome_poi[MAX100];
    char descricao_poi[MAX200];
}POI;

typedef struct poi_array {
    int n_poi; // usado
    int size_poi;
    POI *ppoi; //ARRAY DE CIDADES
}POI_ARRAY;

POI* criar_poi(char nome_poi[MAX100], char descricao_poi[MAX200]);
POI_ARRAY* initArrayPoi(int initsize);
void inserirArrayPoi(POI_ARRAY* list, POI* p);
void removerArrayPoi(POI_ARRAY* poi_array, POI* p);
POI* procurarPoiNome(POI_ARRAY* p, char nome_poi[MAX100]);

#endif //PROJETO_LP1_AED1_POI_H
