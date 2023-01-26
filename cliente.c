
#include "cliente.h"

/**
 * Função que cria a lista dos clientes
 * @return lista de clientes
 */
LISTACLIENTE* criar_lista_cliente() {

    LISTACLIENTE* lclientes = (LISTACLIENTE *) calloc(1, sizeof(LISTACLIENTE));
    lclientes->num_clientes = 0;
    lclientes->pclientes = NULL;
    return lclientes;
}

/**
 * Função que cria o cliente
 * @param id_cliente
 * @param nome
 * @param morada
 * @param contacto
 * @param nif
 * @param size_viagens
 * @return o cliente criado
 */
CLIENTE*
criar_cliente(int id_cliente, char nome[MAX100], char morada[MAX200], int contacto, int nif, int size_viagens) {

    CLIENTE* c = (CLIENTE *) malloc(sizeof(CLIENTE));
    c->id_cliente = id_cliente;
    strcpy(c->nome_cliente, nome);
    strcpy(c->morada, morada);
    c->contacto = contacto;
    c->nif = nif;
    VIAGEM_ARRAY* viagemArray = initArrayViagem(size_viagens); //array dynamico de viagens
    c->array_viagens = *viagemArray;
    c->pnext_cliente = NULL;

    return c;
}

/**
 * Função que insere um cliente à cabeça na lista
 * @param p
 * @param c
 */
void inserir_cliente_cabeca(LISTACLIENTE* p, CLIENTE* c) {

    // tem de ser esta ordem para nao perdemos a referencia do proximo
    c->pnext_cliente = p->pclientes;
    p->pclientes = c;

    p->num_clientes++;
}

/**
 * Funçao que insere um cliente à cauda na lista
 * @param p
 * @param c
 */
void inserir_cliente_cauda(LISTACLIENTE* p, CLIENTE* c) {

    if (p->num_clientes == 0)
        inserir_cliente_cabeca(p, c);
    else {

        //posição atual na lista
        CLIENTE* pcurrente = p->pclientes;
        for (int i = 1; i < p->num_clientes; i++) {
            // em teoria nunca devia de ser null
            if (pcurrente != NULL && pcurrente->pnext_cliente != NULL)
                pcurrente = pcurrente->pnext_cliente;
            else {
                //mostrar erros
                break;
            }
        }
        //quando chegar ao fim da lista meter o pcurrente->pnext_cliente apontar para aquele que nós inserimos
        pcurrente->pnext_cliente = c;
        p->num_clientes++;
    }
}

/**
 * Funçao que insere um cliente ordenado pelo nif
 * @param p
 * @param c
 */
void inserir_cliente_ordenado_nif(LISTACLIENTE* p, CLIENTE* c) {

    if (p->num_clientes == 0)
        inserir_cliente_cabeca(p, c);

    else if (p->num_clientes == 1) {

        if (c->nif < p->pclientes->nif)
            inserir_cliente_cabeca(p, c);
        else
            inserir_cliente_cauda(p, c);
    }
    else {

        //posição atual na lista
        CLIENTE* pcurrente = p->pclientes;
        //este ciclo não avalia o último elemento da list
        int inserted = 0;
        for (int i = 1; i < p->num_clientes; i++) {
            // em teoria nunca devia de ser null
            if (pcurrente != NULL && pcurrente->pnext_cliente != NULL) {
                if (c->nif > pcurrente->nif && c->nif < pcurrente->pnext_cliente->nif) {

                    // o que estamos a inserir ten que apontar para o proxino
                    c->pnext_cliente = pcurrente->pnext_cliente;

                    //o anterior ten que apontar para o que estamos a inserir
                    pcurrente->pnext_cliente = c;

                    //as duas instruçoes anterioires tem que ser por esta ordem
                    //caso contrario perdemos a referencia do proximo

                    p->num_clientes++;
                    inserted = 1;
                    break;
                } else
                    pcurrente = pcurrente->pnext_cliente;
            } else {
                //mostrar erros
                break;
            }
        }
        // inserir no fim se nao tiver inserido a meio
        if (inserted == 0) {
            c->pnext_cliente = NULL; // meter o ultimo a apontar para NULL
            pcurrente->pnext_cliente = c;
            p->num_clientes++;
        }

    }
}

/**
 * Função que procura na lista um cliente com um dado nif
 * @param p
 * @param nif
 * @return o cliente encontrado
 */
CLIENTE *procurar_cliente_nif(LISTACLIENTE *p, int nif) {

    if (p->num_clientes > 0) {
        //posição atual na lista
        CLIENTE *pcurrente = p->pclientes;

        // este ciclo nao avalia o ultimo da lista
        for (int i = 1; i < p->num_clientes; i++) {
            // em teoria nunca devia de ser null
            if (pcurrente != NULL) {
                 // se o nif que metemos for igual ao nif do cliente (pcurrente)
                 // retorna esse cliente
                if (nif == pcurrente->nif)
                    return pcurrente;
                else
                    pcurrente = pcurrente->pnext_cliente;
            } else {
                //mostrar erros
                return NULL;
            }
        }
        // avaliaçao do ultino da lista
        if (nif == pcurrente->nif)
            return pcurrente;
    }
    return NULL;
}

/**
 * Função que procura na lista um cliente com um dado nome
 * @param p
 * @param nome_cliente
 * @return o cliente encontrado
 */
CLIENTE *procurar_cliente_nome(LISTACLIENTE *p, char nome_cliente[MAX100]) {

    if (p->num_clientes > 0) {
        //posição atual na lista
        CLIENTE *pcurrente = p->pclientes;

        // este ciclo nao avalia o ultimo da lista
        for (int i = 1; i < p->num_clientes; i++) {
            // em teoria nunca devia de ser null
            if (pcurrente != NULL) {
                if (strcmp(nome_cliente, pcurrente->nome_cliente) == 0)
                    return pcurrente;
                else
                    pcurrente = pcurrente->pnext_cliente;
            } else {
                //mostrar erros
                return NULL;
            }
        }
        // avaliaçao do ultimo da lista
        if (nome_cliente == pcurrente->nome_cliente)
            return pcurrente;
    }
    return NULL;
}

/**
 * Função que remove um cliente pelo nome numa lista
 * @param p
 * @param nome
 */
void remover_cliente(LISTACLIENTE *p, char nome[MAX100]) {

    if (p->num_clientes > 0) {
        //posição atual na lista
        CLIENTE *pcurrente = p->pclientes;
        //avaliação do primeiro
        if (strcmp(nome, pcurrente->nome_cliente) == 0) {
            // apontar a lista direta para o segundo cliente para coloca-lo como primeiro
            p->pclientes = pcurrente->pnext_cliente;
            p->num_clientes--;
        } else {
            // este ciclo nao avalia o primeiro da lista
            for (int i = 1; i < p->num_clientes; i++) {
                // em teoria nunca devia de ser null
                if (pcurrente != NULL && pcurrente->pnext_cliente != NULL) {
                    if (strcmp(nome, pcurrente->pnext_cliente->nome_cliente) == 0) {
                        // o anterior aponta para o seguinte daquele que removemos
                        pcurrente->pnext_cliente = pcurrente->pnext_cliente->pnext_cliente;
                        p->num_clientes--;
                        break;
                    } else
                        pcurrente = pcurrente->pnext_cliente;
                } else {
                    //mostrar erros
                    break;
                }
            }
        }
    }
}

/**
 * Função de ordenação da lista
 * @param original
 */
void ordenar_lista_nif(LISTACLIENTE* original) {

    LISTACLIENTE* list = criar_lista_cliente();
    CLIENTE* currente = original->pclientes;
    CLIENTE* proximo;

    while (currente != NULL) {
        // manter a referencia do proximo
        proximo = currente->pnext_cliente;
        inserir_cliente_ordenado_nif(list, currente); // passando a nova lista e o cliente currente
        currente = proximo;
    }
    original->pclientes = list->pclientes;
}

