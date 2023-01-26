//
// Created by Tiago on 27/12/2021.
//

#include "cidade.h"

/**
 * Função que cria uma cidade
 * @param nome_cidade
 * @param cidade_pais
 * @param latitude
 * @param longitude
 * @param size_poi
 * @return a cidade criada
 */
CIDADE* criar_cidade(char nome_cidade[MAX100], char cidade_pais[MAX100], float latitude, float longitude, int size_poi) {

    CIDADE* c = (CIDADE*) malloc(sizeof(CIDADE));
    strcpy(c->nome_cidade, nome_cidade);
    strcpy(c->cidade_pais, cidade_pais);
    c->latitude = latitude;
    c->longitude = longitude;
    POI_ARRAY* poiArray = initArrayPoi(size_poi); //array dynamico de poi
    c->array_poi = *poiArray;

    return c;
}

/**
 * Função que inicializa o array dinamico de cidades
 * @param initsize
 * @return o array dinamico de cidades
 */
CIDADE_ARRAY* initArrayCidade(int initsize) {

    CIDADE_ARRAY* c  = (CIDADE_ARRAY*) calloc(1, sizeof(CIDADE_ARRAY));
    c->size_cidade = initsize;
    c->n_cidade = 0;
    c->pcidade = (CIDADE*) malloc(sizeof(CIDADE) * c->size_cidade);
    return c;
}

/**
 * Função que obtem o indice no array dinamico de cidades, da cidades que queremos
 * @param list
 * @param c
 * @return o indice da cidade que queremos
 */
int obterIndexDaCidade(CIDADE_ARRAY* list, CIDADE * c){
    for (int i = 0; i < list->n_cidade; i++) {
        if (&list->pcidade[i] == c)
            return i;
    }
    return -1;
}

/**
 * Funcão que redimensiona o array dinamico de cidades
 * @param c
 * @param size
 */
void redimensionarArrayCidade(CIDADE_ARRAY* c, int size) {

    if (size > c->n_cidade) {
        c->size_cidade = size;
        c->pcidade = (CIDADE *) realloc(c->pcidade, sizeof(CIDADE) * c->size_cidade);
    }
}

/**
 * Função que insere uma cidade dentro do array dinamico de cidades
 * @param list
 * @param c
 */
void inserirArrayCidade(CIDADE_ARRAY* list, CIDADE* c) {

    if (list->size_cidade == list->n_cidade) {
        if (list->size_cidade == 0)
            list->size_cidade = 1;
        else {
            list->size_cidade *= 2;
            list->pcidade = (CIDADE*) realloc(list->pcidade, sizeof(CIDADE) * list->size_cidade);
        }
    }
    list->pcidade[list->n_cidade] = *c;
    list->n_cidade++;

}

/**
 * Função que edita uma cidade dentro do array dinamico de cidades
 * @param list
 * @param c
 * @param nome_cidade
 * @param cidade_pais
 * @param latitude
 * @param longitude
 */
void editarCidade(CIDADE_ARRAY* list, CIDADE* c, char nome_cidade[MAX100], char cidade_pais[MAX100], float latitude, float longitude) {

    if (c != NULL) {
        int index = obterIndexDaCidade(list, c);
        if(index >= 0) {
            strcpy(c->nome_cidade, nome_cidade);
            strcpy(c->cidade_pais, cidade_pais);
            c->latitude = latitude;
            c->longitude = longitude;
            list->pcidade[index] = *c; // meter a cidade editada no array de cidades com indice "index"
        }
    }
}

/**
 * Função que remove uma cidade dentro do array dinamico de cidades
 * @param list
 * @param c
 */
void removerArrayCidade(CIDADE_ARRAY* list, CIDADE* c) {

    int index = obterIndexDaCidade(list, c);
    if(index >= 0) {
        memmove(list->pcidade + index, list->pcidade + (index + 1), (list->n_cidade - (index + 1)) * sizeof (CIDADE_ARRAY));
        list->n_cidade--;
    }
}

/**
 * Função que procura uma cidade dentro do array dinamico de cidades
 * @param c
 * @param nome_cidade
 * @return
 */
CIDADE* procurarCidadeNome(CIDADE_ARRAY* c, char nome_cidade[MAX100]) {

    for (int i = 0; i < c->n_cidade; i++) {
        // a cada iteraçao vamos comparar se o titulo é igual ao titulo da viagem dessa posição (i)
        if(strcmp((&c->pcidade[i])->nome_cidade, nome_cidade) == 0) {
            return &c->pcidade[i];
        }
    }
    return NULL;
}

void freeArrayCidade(CIDADE_ARRAY* c) {

    free(c->pcidade);
    c->pcidade = NULL;
    c->size_cidade = 0;
    c->n_cidade = 0;
    c = NULL;
}