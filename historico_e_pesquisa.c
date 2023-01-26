
#include "historico_e_pesquisa.h"

/**
 * Função que disponibliza o historico de viagens de um dado cliente dando o seu nome
 * @param list
 * @param nome_cliente
 * @return as viagens que esse cliente realizou
 */
VIAGEM_ARRAY* historico_de_viagens_por_cliente(LISTACLIENTE* list, char nome_cliente[MAX100]) {
    printf("\nHistorico de Viagens\n");
    if (nome_cliente != NULL && strcmp(nome_cliente, "") != 0) {
        CLIENTE* c = list->pclientes;
        while (c != NULL) {
            if (strcmp(nome_cliente, c->nome_cliente) == 0) {
                printf("O cliente com nome %s realizou estas viagens:\n", nome_cliente);
                for (int i = 0; i < c->array_viagens.n_viagem; i++) {
                    printf("->%s\n", c->array_viagens.pviagem[i].titulo);
                }
                break;
            }
            else
                c = c->pnext_cliente;
        }
    }
    return NULL;
}

/**
 * Função que pesquisa pelas cidades ou poi's nas viagens de um cliente
 * @param c
 * @param cidade_a_pesquisar
 * @param poi_a_pesquisar
 * @return a viagem onde foi visitar uma cidade ou a viagem onde visitou um poi
 */
VIAGEM* pesquisar_cidade_ou_poi_em_viagens_de_cliente(CLIENTE* c, char cidade_a_pesquisar[MAX100],
                                                      char poi_a_pesquisar[MAX100]) {
    printf("\nPesquisa de Viagens atraves das Cidades ou Poi\n");
    if (cidade_a_pesquisar == NULL && poi_a_pesquisar == NULL)
        return NULL;

    int cv = cidade_a_pesquisar != NULL && strcmp(cidade_a_pesquisar, "") != 0 ? 1 : 0;
    int pv = poi_a_pesquisar != NULL && strcmp(poi_a_pesquisar, "") != 0 ? 1 : 0;

    for (int v = 0; v < c->array_viagens.n_viagem; v++) {
        for (int i = 0; i < c->array_viagens.pviagem[v].array_cidades.n_cidade; i++) {
            if (cv == 1) {
                if (strcmp(cidade_a_pesquisar, c->array_viagens.pviagem[v].array_cidades.pcidade[i].nome_cidade) == 0) {
                    printf("Cliente %s vistou a cidade de %s na viagem %s\n", c->nome_cliente, c->array_viagens.pviagem[v].array_cidades.pcidade[i].nome_cidade, c->array_viagens.pviagem[v].titulo);
                    return &c->array_viagens.pviagem[v];
                }
            }
            if (pv == 1) {
                for (int p = 0; p < c->array_viagens.pviagem[v].array_cidades.pcidade[i].array_poi.n_poi; p++) {
                    if (strcmp(poi_a_pesquisar, c->array_viagens.pviagem[v].array_cidades.pcidade[i].array_poi.ppoi[p].nome_poi) == 0) {
                        printf("Cliente %s visitou o poi %s com a descricao (%s) na viagem %s\n", c->nome_cliente, c->array_viagens.pviagem[v].array_cidades.pcidade[i].array_poi.ppoi[p].nome_poi, c->array_viagens.pviagem[v].array_cidades.pcidade[i].array_poi.ppoi[p].descricao_poi,c->array_viagens.pviagem[v].titulo);
                        return &c->array_viagens.pviagem[v];
                    }
                }
            }
        }
    }
    return NULL;
}