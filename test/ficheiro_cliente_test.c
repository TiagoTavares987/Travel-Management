
#include "../cliente.h"
#include "../viagem.h"
#include "../cidade.h"
#include "../poi.h"
#include "../Ficheiros/ficheiro_cliente.h"
#include "ficheiro_cliente_test.h"
#include "../historico_e_pesquisa.h"

LISTACLIENTE *criar_clientes_test() {

    LISTACLIENTE *list = criar_lista_cliente();

    CLIENTE *c = criar_cliente(1, "Maria", "Rua", 911234567, 123456789, 3);

    VIAGEM *v = criar_viagem("bermudas", time(NULL), time(NULL), 1);

    CIDADE *cidade = criar_cidade("Porto", "Portugal", 2.0945f, 1.9678f, 2);

    POI *poi = criar_poi("Ponte d luis", "e muito fixe");
    inserirArrayPoi(&cidade->array_poi, poi);
    poi = criar_poi("Ponte de arrabida", "e brutal");
    inserirArrayPoi(&cidade->array_poi, poi);
    poi = criar_poi("Torre eiffel", "asdasdasd");
    inserirArrayPoi(&cidade->array_poi, poi);

    inserirArrayCidade(&v->array_cidades, cidade);

    cidade = criar_cidade("Lisboa", "Portugal", 2.0945f, 1.9678f, 2);

    poi = criar_poi("OLA", "adeus");
    inserirArrayPoi(&cidade->array_poi, poi);

    inserirArrayCidade(&v->array_cidades, cidade);

    inserirArrayViagem(&c->array_viagens, v);

    v = criar_viagem("ilhas", time(NULL), time(NULL), 0);
    inserirArrayViagem(&c->array_viagens, v);

    v = criar_viagem("usa", time(NULL), time(NULL), 0);
    inserirArrayViagem(&c->array_viagens, v);

    inserir_cliente_cauda(list, c);

    //removerArrayViagem(&c->array_viagens, procurarArrayViagem(&c->array_viagens, "ilhas"));

    //----------

    c = criar_cliente(2, "abc", "qq", 921234567, 323456789, 2);
    inserir_cliente_cauda(list, c);

    //----------
    c = criar_cliente(3, "Antonio", "Travessa", 931234567, 223456789, 2);

    v = criar_viagem("ilhas", time(NULL), time(NULL), 0);

    cidade = criar_cidade("Algarve", "Portugal", 2.044456f, 2.044544f,2);

    poi = criar_poi("Escalar montanha", "ok");
    inserirArrayPoi(&cidade->array_poi, poi);

    inserirArrayCidade(&v->array_cidades, cidade);

    inserirArrayViagem(&c->array_viagens, v);

    inserir_cliente_cauda(list, c);

    return list;
}


void ficheiro_cliente_test() {

    LISTACLIENTE* list = criar_clientes_test();


    historico_de_viagens_por_cliente(list, "Maria");

    pesquisar_cidade_ou_poi_em_viagens_de_cliente(list->pclientes->pnext_cliente->pnext_cliente, "Algarve", NULL);
    pesquisar_cidade_ou_poi_em_viagens_de_cliente(list->pclientes->pnext_cliente->pnext_cliente, NULL, "Escalar montanha");

    escrever_clientes_e_viagens_txt(list);

    LISTACLIENTE *clientes_e_viagens = ler_clientes_e_viagens_txt();

    escrever_cidades_e_poi_txt(&list->pclientes->array_viagens.pviagem->array_cidades);

    CIDADE_ARRAY *cidades_e_poi = ler_cidades_e_poi_txt();

    escrever_clientes_bin(list);

    LISTACLIENTE *clientes_completos = ler_clientes_bin();

    escrever_cidades_bin(&list->pclientes->array_viagens.pviagem->array_cidades);

    CIDADE_ARRAY* cidades_completas = ler_cidades_bin();

}