
#include "viagem.h"


/**
 * Função que cria uma viagem a realizar
 * @param titulo
 * @param size_cidades
 * @return a viagem criada
 */
VIAGEM* criar_viagem_a_realizar(char titulo[MAX100], int size_cidades) {
    return criar_viagem(titulo, 0, 0, size_cidades); // para a viagem ser a realizar tem a data de inicio e fim = 0
}

/**
 * Função que cria uma viagem
 * @param titulo
 * @param data_inicio
 * @param data_fim
 * @param size_cidades
 * @return a viagem criada
 */
VIAGEM* criar_viagem(char titulo[MAX100], time_t data_inicio, time_t data_fim, int size_cidades) {
    // realizada = 0 -> viagem a realizar          realizada = 1 -> viagem realizada
    VIAGEM* a = (VIAGEM*) malloc(sizeof(VIAGEM));
    a->realizada = data_inicio == 0 || data_fim == 0 ? 0 : 1;
    strcpy(a->titulo, titulo);
    a->data_inicio = data_inicio;
    a->data_fim = data_fim;
    CIDADE_ARRAY* cidadeArray = initArrayCidade(size_cidades); //array dynamico de cidades
    a->array_cidades = *cidadeArray;

    return a;
}

/**
 * Função que inicializa o array dinamico de viagens
 * @param initsize
 * @return o array dinamico de viagens
 */
VIAGEM_ARRAY* initArrayViagem(int initsize) {

    VIAGEM_ARRAY* a  = (VIAGEM_ARRAY*) calloc(1, sizeof(VIAGEM_ARRAY));
    a->size_viagem = initsize;
    a->n_viagem = 0;
    a->pviagem = (VIAGEM*) malloc(sizeof(VIAGEM) * a->size_viagem);
    return a;
}

/**
 * Função que obtem o indice no array dinamico de viagens, da viagem que queremos
 * @param a
 * @param v
 * @return o indice da viagem que queremos
 */
int obterIndexDaViagem(VIAGEM_ARRAY* a, VIAGEM* v){
    for (int i = 0; i < a->n_viagem; i++) {
        // vamos a cada iteração comparar se a viagem é igual a que esta naquela posiçao
        if (&a->pviagem[i] == v)
            return i;
    }
    return -1;
}

/**
 * Funcão que redimensiona o array dinamico de viagens
 * @param a
 * @param size
 */
void redimensionarArrayViagem(VIAGEM_ARRAY* a, int size) {

    if (size > a->n_viagem) {
        a->size_viagem = size;
        a->pviagem = (VIAGEM*) realloc(a->pviagem, sizeof(VIAGEM) * a->size_viagem);
    }
}

/**
 * Função que insere uma viagem dentro do array dinamico de viagens
 * @param a
 * @param v
 */
void inserirArrayViagem(VIAGEM_ARRAY* a, VIAGEM* v) {

    if (a->size_viagem == a->n_viagem) {
        if (a->size_viagem == 0)
            a->size_viagem = 1;
        else {
            a->size_viagem *= 2;
            a->pviagem = (VIAGEM*) realloc(a->pviagem, sizeof(VIAGEM) * a->size_viagem);
        }
    }
    a->pviagem[a->n_viagem] = *v; // meter a viagem inserida no array de viagens com "indice" a->n_viagem
    a->n_viagem++;
}

/**
 * Função que edita uma viagem dentro do array dinamico de viagens
 * @param a
 * @param v
 * @param titulo
 * @param data_inicio
 * @param data_fim
 */
void editarViagem(VIAGEM_ARRAY* a, VIAGEM* v, char titulo[MAX100], time_t data_inicio, time_t data_fim) {

    if (v != NULL) {
        int index = obterIndexDaViagem(a, v);
        if(index >= 0) {
            v->realizada = data_inicio == 0 || data_fim == 0 ? 0 : 1;
            v->data_inicio = data_inicio;
            v->data_fim = data_fim;
            strcpy(v->titulo, titulo);
            a->pviagem[index] = *v; // meter a viagem editada no array de viagens com indice "index" que obtivemos em cima
        }
    }
}

/**
 * Função que remove uma viagem dentro do array dinamico de viagens
 * @param a
 * @param v
 */
void removerArrayViagem(VIAGEM_ARRAY* a, VIAGEM* v) {
    int index = obterIndexDaViagem(a, v);
    if(index >= 0) {
        // move um bloco de codigo de um sitio para outro, destino do bloco, origem do bloco, tamanho do bloco
        memmove(a->pviagem + index, a->pviagem + (index + 1), (a->n_viagem - (index + 1)) * sizeof (VIAGEM_ARRAY));
        a->n_viagem--;
    }
}

/**
 * Função que procura uma viagem dentro do array dinamico de viagens
 * @param a
 * @param titulo
 * @return a viagem que procuramos
 */
VIAGEM* procurarArrayViagem(VIAGEM_ARRAY* a, char titulo[MAX100]) {

    for (int i = 0; i < a->n_viagem; i++) {
        // a cada iteraçao vamos comparar se o titulo é igual ao titulo da viagem dessa posição (i)
        if (strcmp((&a->pviagem[i])->titulo, titulo) == 0)
            return &a->pviagem[i];
    }
    return NULL;
}

void freeArrayViagem(VIAGEM_ARRAY* a) {

    free(a->pviagem);
    a->pviagem = NULL;
    a->size_viagem = 0;
    a->n_viagem = 0;
    a = NULL;
}
