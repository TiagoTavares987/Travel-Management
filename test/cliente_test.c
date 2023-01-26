
#include "../cliente.h"

LISTACLIENTE* client_test_listagem() {
    printf("\nCriacao de listagem: ");

    // resultado
    LISTACLIENTE* list = criar_lista_cliente();

    // teste
    if (list == NULL) {
        printf("Falhou - listagem nao criada");
    }
    else if (list->num_clientes != 0) {
        printf("Falhou - listagem nr de clientes invalido");
    }
    else {
        printf("Sucesso");
    }
    return list;
}

CLIENTE* client_test_criar_cliente(CLIENTE* c, int id, char nome[], char morada[], int contacto, int nif, int size_viagens) {
    printf("\nNovo cliente: ");

    // resultado
    c = criar_cliente(id, nome, morada, contacto, nif, size_viagens);

    // teste
    if (c == NULL) {
        printf("Falhou - cliente nao criado");
    }
    else if (c->id_cliente != id) {
        printf("Falhou - cliente com id errado");
    }
    else if (strcmp(nome, c->nome_cliente) != 0) {
        printf("Falhou - cliente com nome errado");
    }
    else if (strcmp(morada, c->morada) != 0) {
        printf("Falhou - cliente com morada errado");
    }
    else if (c->contacto != contacto) {
        printf("Falhou - cliente com contacto errado");
    }
    else if (c->nif != nif) {
        printf("Falhou - cliente com nif errado");
    }
    else {
        printf("Sucesso");
    }
    return c;
}

void client_test_inserir_cliente_cabeca(LISTACLIENTE* list, CLIENTE* c) {
    printf("\nInserir cliente a cabeca: ");
    if (list == NULL || c == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    // resultado
    inserir_cliente_cabeca(list, c);

    // teste
    if (list->pclientes == NULL) {
        printf("Falhou - cliente nao inserido");
    }
    else if (strcmp(c->nome_cliente, list->pclientes->nome_cliente) != 0) {
        printf("Falhou - cliente inserido a cabeca com nome errado");
    }
    else if (strcmp(c->morada, list->pclientes->morada) != 0) {
        printf("Falhou - cliente inserido a cabeca com morada errado");
    }
    else if (list->pclientes->contacto != c->contacto) {
        printf("Falhou - cliente inserido a cabeca com contacto errado");
    }
    else if (list->pclientes->nif != c->nif) {
        printf("Falhou - cliente inserido a cabeca com nif errado");
    }
    else if (list->pclientes->array_viagens.size_viagem != c->array_viagens.size_viagem) {
        printf("Falhou - cliente inserido a cabeca com tamanho de viagens errado");
    }
    else {
        printf("Sucesso");
    }
}

void client_test_inserir_cliente_cauda(LISTACLIENTE* list, CLIENTE* c) {
    printf("\nInserir cliente a cauda: ");
    if (list == NULL || c == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    // resultado
    inserir_cliente_cauda(list, c);

    CLIENTE *pcurrente = list->pclientes;
    for (int i = 1; i < list->num_clientes; i++) {
        // em teoria nunca devia de ser null
        if (pcurrente != NULL && pcurrente->pnext_cliente != NULL)
            pcurrente = pcurrente->pnext_cliente;
        else {
            //mostrar erros
            break;
        }
    }

    // teste
    if (list->pclientes == NULL || pcurrente == NULL) {
        printf("Falhou - cliente nao inserido");
    }
    else if (strcmp(c->nome_cliente, pcurrente->nome_cliente) != 0) {
        printf("Falhou - cliente inserido a cauda com nome errado");
    }
    else if (strcmp(c->morada, pcurrente->morada) != 0) {
        printf("Falhou - cliente inserido a cauda com morada errado");
    }
    else if (pcurrente->contacto != c->contacto) {
        printf("Falhou - cliente inserido a cauda com contacto errado");
    }
    else if (pcurrente->nif != c->nif) {
        printf("Falhou - cliente inserido a cauda com nif errado");
    }
    else if (pcurrente->array_viagens.size_viagem != c->array_viagens.size_viagem) {
        printf("Falhou - cliente inserido a cauda com tamanho de viagens errado");
    }
    else {
        printf("Sucesso");
    }
}

void client_test_inserir_cliente_ordenado_nif(LISTACLIENTE* list, CLIENTE* c) {
    printf("\nInserir cliente ordenado nif: ");
    if (list == NULL || c == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoClientes = list->num_clientes;

    // resultado
    inserir_cliente_ordenado_nif(list, c);

    // teste
    if (list->pclientes == NULL) {
        printf("Falhou - lista vazia");
    }
    else if (nrAntigoClientes != list->num_clientes - 1) {
        printf("Falhou - cliente nao inserido");
    }
    else {
        printf("Sucesso");
    }
}

void client_test_procurar_cliente_nif(LISTACLIENTE* list, int nif) {
    printf("\nProcurar cliente pelo nif: ");
    if (list == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    // resultado
    CLIENTE* c = procurar_cliente_nif(list, nif);

    // teste
    if (list->pclientes == NULL) {
        printf("Falhou - lista vazia");
    } else if (c->nif != nif) {
        printf("Falhou - cliente procurado pelo nif com nif errado");
    } else {
        printf ("Sucesso");
    }
}

void client_test_procurar_cliente_nome(LISTACLIENTE* list, char nome_cliente[MAX100]) {
    printf("\nProcurar cliente pelo nome: ");
    if (list == NULL || nome_cliente == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    // resultado
    CLIENTE* c = procurar_cliente_nome(list, nome_cliente);

    // teste
    if (list->pclientes == NULL) {
        printf("Falhou - lista vazia");
    } else if (strcmp(nome_cliente, c->nome_cliente) != 0) {
        printf("Falhou - cliente procurado pelo nome com nome errado");
    } else {
        printf ("Sucesso");
    }
}

void client_test_remover_cliente_nome(LISTACLIENTE* list, char nome_cliente[MAX100]) {
    printf("\nRemover cliente pelo nome: ");
    if (list == NULL || nome_cliente == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoClientes = list->num_clientes;
    // resultado
    remover_cliente(list, nome_cliente);

    // teste
    if (nrAntigoClientes != list->num_clientes + 1) {
        printf("Falhou - cliente nao removido");
    } else {
        printf ("Sucesso");
    }
}

void client_test_ordenar_lista_nif(LISTACLIENTE* list) {
    printf("\nOrdenar lista pelo nif: ");
    if (list == NULL) {
        printf("Falhou - entradas invalidas");
        return;
    }

    int nrAntigoClientes = list->num_clientes;

    // resultado
    ordenar_lista_nif(list);

    // teste
    if (list->num_clientes != nrAntigoClientes) {
        printf("Falhou - nr de clientes diferente");
    } else {
        printf ("Sucesso");
    }
}

void cliente_test(int argc, const char *argv[]) {

    printf("\nTeste Class Cliente");

    LISTACLIENTE* list = client_test_listagem();

    CLIENTE* c1 = client_test_criar_cliente(c1,1, "Tiago", "rua dr", 912137300, 100100200, 4);

    CLIENTE* c2 = client_test_criar_cliente(c2,2, "Diana", "rua", 98888888, 100200100, 1);

    CLIENTE* c3 = client_test_criar_cliente(c3,3, "antonio", "rua", 98888888, 100300000, 1);

    client_test_inserir_cliente_cabeca(list, c3);

    client_test_inserir_cliente_cauda(list, c1);

    client_test_ordenar_lista_nif(list);

    client_test_inserir_cliente_ordenado_nif(list, c2);

    client_test_procurar_cliente_nif(list, c1->nif);

    client_test_procurar_cliente_nome(list, c2->nome_cliente);

    client_test_remover_cliente_nome(list, c1->nome_cliente);

    printf("\n");


}