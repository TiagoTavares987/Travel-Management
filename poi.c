
#include "poi.h"

/**
 * Função cria um poi
 * @param nome_poi
 * @param descricao_poi
 * @return o poi criado
 */
POI* criar_poi(char nome_poi[MAX100], char descricao_poi[MAX200]) {

    POI* p = (POI*) malloc(sizeof(POI));
    strcpy(p->nome_poi, nome_poi);
    strcpy(p->descricao_poi, descricao_poi);

    return p;
}

/**
 * Função que inicializa o array dinamico de poi
 * @param initsize
 * @return o array dinamico de poi
 */
POI_ARRAY* initArrayPoi(int initsize) {

    POI_ARRAY* p  = (POI_ARRAY*) calloc(1, sizeof(POI_ARRAY));
    p->size_poi = initsize;
    p->n_poi = 0;
    p->ppoi = (POI*) malloc(sizeof(POI) * p->size_poi);

    return p;
}

/**
 * Função que obtem o indice no array dinamico de poi, do poi que queremos
 * @param list
 * @param p
 * @return o indice do poi que queremos
 */
int obterIndexDaPoi(POI_ARRAY* list, POI* p){
    for (int i = 0; i < list->n_poi; i++) {
        if (&list->ppoi[i] == p)
            return i;
    }
    return -1;
}

/**
 * Função que insere uma poi dentro do array dinamico de poi
 * @param list
 * @param p
 */
void inserirArrayPoi(POI_ARRAY* list, POI* p) {

    if (list->size_poi == list->n_poi) {
        if (list->size_poi == 0)
            list->size_poi = 1;
        else {
            list->size_poi *= 2;
            list->ppoi = (POI*) realloc(list->ppoi, sizeof(POI) * list->size_poi);
        }
    }
    list->ppoi[list->n_poi] = *p;
    list->n_poi++;
}

/**
 * Função que remove um poi dentro do array dinamico de poi
 * @param list
 * @param p
 */
void removerArrayPoi(POI_ARRAY* list, POI* p) {

    int index = obterIndexDaPoi(list, p);
    if(index >= 0) {
        memmove(list->ppoi + index, list->ppoi + (index + 1), (list->n_poi - (index + 1)) * sizeof(POI_ARRAY));
        list->n_poi--;
    }
}

/**
 * Função que procura um poi dentro do array dinamico de poi
 * @param p
 * @param nome_poi
 * @return
 */
POI* procurarPoiNome(POI_ARRAY* p, char nome_poi[MAX100]) {

    for (int i = 0; i < p->n_poi; i++) {
        if(strcmp((&p->ppoi[i])->nome_poi, nome_poi) == 0) {
            return &p->ppoi[i];
        }
    }
    return NULL;
}