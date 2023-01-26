
#include "../viagem.h"

VIAGEM_ARRAY* viagem_test_initArrayViagem() {
    printf("\nCriacao de array dinamico de viagens: ");

    // resultado
    VIAGEM_ARRAY* viagem_array = initArrayViagem(4);

    // teste
    if (viagem_array == NULL) {
        printf("Falhou - array dinamico nao criado");
    }
    else if (viagem_array->n_viagem != 0) {
        printf("Falhou - array dinamico com nr de viagens invalido");
    }
    else {
        printf("Sucesso");
    }
    return viagem_array;
}


VIAGEM* viagem_test_criar_viagem_realizada() {
    printf("\nNova viagem: ");

    char titulo[] = "porto";
    time_t data_inicio = time(NULL);
    time_t data_fim = time(NULL);
    int size_cidades = 0;

    // resultado
   VIAGEM* v = criar_viagem(titulo, data_inicio, data_fim, size_cidades); // time(NULL) vai ser a data atual

    // teste
    if (v == NULL) {
        printf("Falhou - viagem nao criada");
    }
    else if (v->realizada != 1) {
        printf("Falhou - viagem realizada errada");
    }
    else if (strcmp(titulo, v->titulo) != 0) {
        printf("Falhou - viagem com titulo errado");
    }
    else if (difftime(data_inicio, v->data_inicio) != 0) {
        printf("Falhou - viagem com data de inicio errada");
    }
    else if (difftime(data_fim, v->data_fim) != 0) {
        printf("Falhou - viagem com data de fim errada");
    }
    else if (v->array_cidades.size_cidade != size_cidades) {
        printf("Falhou - viagem com tamanho de cidades errado");
    }
    else {
        printf("Sucesso");
    }
    return v;
}

VIAGEM* viagem_test_criar_viagem_a_realizar() {
    printf("\nNova viagem: ");

    char titulo[] = "lisboa";
    int size_cidades = 0;

    // resultado
    VIAGEM* v = criar_viagem_a_realizar(titulo, size_cidades); // time(NULL) vai ser a data atual

    // teste
    if (v == NULL) {
        printf("Falhou - viagem nao criada");
    }
    else if (v->realizada != 0) {
        printf("Falhou - viagem realizada errada");
    }
    else if (strcmp(titulo, v->titulo) != 0) {
        printf("Falhou - viagem com titulo errado");
    }
    else if (v->array_cidades.size_cidade != size_cidades) {
        printf("Falhou - viagem com tamanho de cidades errado");
    }
    else {
        printf("Sucesso");
    }
    return v;
}


void viagem_test_inserirArrayViagem(VIAGEM_ARRAY* viagem_array, VIAGEM* v) {
    printf("\nInserir viagem: ");
    if (viagem_array == NULL || v == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoViagem = viagem_array->n_viagem;

    inserirArrayViagem(viagem_array, v);

    if (viagem_array->pviagem == NULL) {
        printf("Falhou - array vazio");
    }
    else if (nrAntigoViagem != viagem_array->n_viagem - 1) {
        printf("Falhou - viagem nao inserida");
    }
    else {
        printf("Sucesso");
    }
}

void viagem_test_editarArrayViagem(VIAGEM_ARRAY* viagem_array, VIAGEM* v) {
    printf("\nEditar viagem: ");
    if (viagem_array == NULL || v == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    char titulo[] = "gaia";
    time_t data_inicio = time(NULL);
    time_t data_fim = time(NULL);

    editarViagem(viagem_array, v, titulo, data_inicio, data_fim);

    if (strcmp(titulo, v->titulo) != 0) {
        printf("Falhou - viagem com titulo errado");
    }
    else if (difftime(data_inicio, v->data_inicio) != 0) {
        printf("Falhou - viagem com data de inicio errada");
    }
    else if (difftime(data_fim, v->data_fim) != 0) {
        printf("Falhou - viagem com data de fim errada");
    }
    else {
        printf("Sucesso");
    }
}

void viagem_test_removerArrayViagem(VIAGEM_ARRAY* viagem_array, VIAGEM* v) {
    printf("\nRemover viagem: ");
    if (viagem_array == NULL || v == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoViagens = viagem_array->n_viagem;

    removerArrayViagem(viagem_array, v);

    if (nrAntigoViagens != viagem_array->n_viagem + 1) {
        printf("Falhou - viagem nao removida");
    }
    else {
        printf("Sucesso");
    }
}

void viagem_test_procurarArrayViagem(VIAGEM_ARRAY* viagem_array, char titulo[MAX100]) {
    printf("\nProcurar viagem: ");
    if (viagem_array == NULL || titulo == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    VIAGEM* v = procurarArrayViagem(viagem_array, titulo);

    if (v == NULL) {
        printf("Falhou - viagem nao encontrada");
    } else if (strcmp(titulo, v->titulo) != 0) {
        printf("Falhou - viagem encontrada com titulo errado");
    }
    else {
        printf("Sucesso");
    }
}

void viagem_test(int argc, const char *argv[]) {
    printf("\nTeste Array Dinamico Viagem");

    VIAGEM_ARRAY* viagemArray = viagem_test_initArrayViagem();

    VIAGEM* v1 = viagem_test_criar_viagem_realizada();

    VIAGEM* v2 = viagem_test_criar_viagem_a_realizar();

    viagem_test_inserirArrayViagem(viagemArray, v1);

    viagem_test_inserirArrayViagem(viagemArray, v2);

    viagem_test_editarArrayViagem(viagemArray, procurarArrayViagem(viagemArray, v1->titulo));

    viagem_test_removerArrayViagem(viagemArray, procurarArrayViagem(viagemArray, v2->titulo));

    viagem_test_procurarArrayViagem(viagemArray, "gaia");

    printf("\n");
}
