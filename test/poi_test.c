
#include "../poi.h"

POI_ARRAY* poi_test_initArrayPoi() {
    printf("\nCriacao de array dinamico de poi: ");

    // resultado
    POI_ARRAY* poi_array = initArrayPoi(2);

    // teste
    if (poi_array == NULL) {
        printf("Falhou - array dinamico nao criado");
    }
    else if (poi_array->n_poi != 0) {
        printf("Falhou - array dinamico com nr de poi invalido");
    }
    else {
        printf("Sucesso");
    }
    return poi_array;
}


POI* poi_test_criar_poi(char nome_poi[MAX100], char descricao_poi[MAX200]) {
    printf("\nNovo poi: ");


    // resultado
    POI* p = criar_poi(nome_poi, descricao_poi);

    // teste
    if (p == NULL) {
        printf("Falhou - poi nao criado");
    }
    else if (strcmp(nome_poi, p->nome_poi) != 0) {
        printf("Falhou - poi com nome errado");
    }
    else if (strcmp(descricao_poi, p->descricao_poi) != 0) {
        printf("Falhou - poi com descricao errada");
    }
    else {
        printf("Sucesso");
    }
    return p;
}

void poi_test_inserirArrayPoi(POI_ARRAY* poi_array, POI* p) {
    printf("\nInserir poi: ");
    if (poi_array == NULL || p == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoPoi = poi_array->n_poi;

    inserirArrayPoi(poi_array, p);

    if (poi_array->ppoi == NULL) {
        printf("Falhou - array vazio");
    }
    else if (nrAntigoPoi != poi_array->n_poi - 1) {
        printf("Falhou - poi nao inserido");
    }
    else {
        printf("Sucesso");
    }
}

void poi_test_removerArrayPoi(POI_ARRAY* poi_array, POI* p) {
    printf("\nRemover poi: ");
    if (poi_array == NULL || p == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoPoi = poi_array->n_poi;

    removerArrayPoi(poi_array, p);

    if (nrAntigoPoi != poi_array->n_poi + 1) {
        printf("Falhou - poi nao removido");
    }
    else {
        printf("Sucesso");
    }
}

POI* poi_test_procurarPoiNome(POI_ARRAY* poi_array, char nome_poi[MAX100]) {
    printf("\nProcurar poi: ");
    if (poi_array == NULL || nome_poi == NULL) {
        printf("Falhou - entradas invalidas");
        return NULL;
    }

    POI* x = procurarPoiNome(poi_array, nome_poi);

    if (x == NULL) {
        printf("Falhou - poi nao encontrado");
    } else if (strcmp(x->nome_poi, nome_poi) != 0) {
        printf("Falhou - poi procurado pelo nome errado");
    }
    else {
        printf("Sucesso");
    }
    return x;
}

void poi_test(int argc, const char *argv[]) {
    printf("\nTeste Array Dinamico Poi");

    POI_ARRAY* poiArray = poi_test_initArrayPoi();

    POI* poi1 = poi_test_criar_poi("Ponte d luis", "pois e uma ponte historica");

    POI* poi2 = poi_test_criar_poi("Praia de matosinhos", "praia muito fixe");

    poi_test_inserirArrayPoi(poiArray, poi1);

    poi_test_inserirArrayPoi(poiArray, poi2);

    poi1 = poi_test_procurarPoiNome(poiArray, poi1->nome_poi);

    poi_test_removerArrayPoi(poiArray, poi1);

    printf("\n");
}