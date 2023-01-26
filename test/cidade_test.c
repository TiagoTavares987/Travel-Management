
#include "../cidade.h"

CIDADE_ARRAY* cidade_test_initArrayCidade() {
    printf("\nCriacao de array dinamico de cidades: ");

    // resultado
    CIDADE_ARRAY* cidade_array = initArrayCidade(4);

    // teste
    if (cidade_array == NULL) {
        printf("Falhou - array dinamico nao criado");
    }
    else if (cidade_array->n_cidade != 0) {
        printf("Falhou - array dinamico com nr de cidades invalido");
    }
    else {
        printf("Sucesso");
    }
    return cidade_array;
}


CIDADE* cidade_test_criar_cidade(char nome_cidade[MAX100], char cidade_pais[MAX100], float latitude, float longitude, int size_poi) {
    printf("\nNova cidade: ");


    // resultado
    CIDADE* c = criar_cidade(nome_cidade, cidade_pais, latitude, longitude, size_poi);

    // teste
    if (c == NULL) {
        printf("Falhou - cidade nao criada");
    }
    else if (strcmp(nome_cidade, c->nome_cidade) != 0) {
        printf("Falhou - cidade com nome errado");
    }
    else if (strcmp(cidade_pais, c->cidade_pais) != 0) {
        printf("Falhou - cidade com pais errado");
    }
    else if (c->latitude != latitude) {
        printf("Falhou - cidade com latitude errada");
    }
    else if (c->longitude != longitude) {
        printf("Falhou - cidade com longitude errada");
    }
    else if (c->array_poi.size_poi != size_poi) {
        printf("Falhou - cidade com tamanho de poi errado");
    }
    else {
        printf("Sucesso");
    }
    return c;
}

void cidade_test_inserirArrayCidade(CIDADE_ARRAY* cidade_array, CIDADE* c) {
    printf("\nInserir cidade: ");
    if (cidade_array == NULL || c == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoCidade = cidade_array->n_cidade;

    inserirArrayCidade(cidade_array, c);

    if (cidade_array->pcidade == NULL) {
        printf("Falhou - array vazio");
    }
    else if (nrAntigoCidade != cidade_array->n_cidade - 1) {
        printf("Falhou - cidade nao inserida");
    }
    else {
        printf("Sucesso");
    }
}

void cidade_test_editarCidade(CIDADE_ARRAY* cidade_array, CIDADE* c) {
    printf("\nEditar cidade: ");
    if (cidade_array == NULL || c == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    char nome_cidade[] = "Dubai";
    char cidade_pais[] = "Arabia Saudita";
    float latitude = 1.03456f;
    float longitude = 2.98977f;

    editarCidade(cidade_array, c, nome_cidade, cidade_pais, latitude, longitude);

    if (cidade_array->pcidade == NULL) {
        printf("Falhou - cidade nao inserida");
    }
    else if (strcmp(c->nome_cidade, nome_cidade) != 0) {
        printf("Falhou - cidade editada com nome errada");
    }
    else if (strcmp(c->cidade_pais, cidade_pais) != 0) {
        printf("Falhou - cidade editada com pais errado");
    }
    else if (c->latitude != latitude) {
        printf("Falhou - cidade editada com latitude errada");
    }
    else if (c->longitude != longitude) {
        printf("Falhou - cidade editada com longitude errada");
    }
    else {
        printf("Sucesso");
    }
}

void cidade_test_removerArrayCidade(CIDADE_ARRAY* cidade_array, CIDADE* c) {
    printf("\nRemover cidade: ");
    if (cidade_array == NULL || c == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoCidades = cidade_array->n_cidade;

    removerArrayCidade(cidade_array, c);

    if (nrAntigoCidades != cidade_array->n_cidade + 1) {
        printf("Falhou - cidade nao removida");
    }
    else {
        printf("Sucesso");
    }
}

CIDADE* cidade_test_procurarCidadeNome(CIDADE_ARRAY* cidade_array, char nome[MAX100]) {
    printf("\nProcurar cidade: ");
    if (cidade_array == NULL || nome == NULL) {
        printf("Falhou - entradas invalidas");
        return NULL;
    }

    CIDADE* x = procurarCidadeNome(cidade_array, nome);

    if (x == NULL) {
        printf("Falhou - cidade nao encontrada");
    } else if (strcmp(x->nome_cidade, nome) != 0) {
        printf("Falhou - cidade procurada pelo nome errado");
    }
    else {
        printf("Sucesso");
    }
    return x;
}

void cidade_test(int argc, const char *argv[]) {
    printf("\nTeste Array Dinamico Cidade");

    CIDADE_ARRAY* cidadeArray = cidade_test_initArrayCidade();

    CIDADE* cidade1 = cidade_test_criar_cidade("Porto", "Portugal", 1.0034f, 20.003f, 2);

    CIDADE* cidade2 = cidade_test_criar_cidade("Paris", "Franca", 1.0034f, 20.003f, 1);

    cidade_test_inserirArrayCidade(cidadeArray, cidade1);

    cidade_test_inserirArrayCidade(cidadeArray, cidade2);

    cidade1 = cidade_test_procurarCidadeNome(cidadeArray, cidade1->nome_cidade);

    cidade2 = cidade_test_procurarCidadeNome(cidadeArray, cidade2->nome_cidade);

    cidade_test_editarCidade(cidadeArray, cidade1);

    cidade_test_editarCidade(cidadeArray, cidade2);

    cidade_test_removerArrayCidade(cidadeArray, cidade1);

    printf("\n");
}
