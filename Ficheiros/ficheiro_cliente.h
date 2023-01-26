
#ifndef PROJETO_LP1_AED1_FICHEIRO_CLIENTE_H
#define PROJETO_LP1_AED1_FICHEIRO_CLIENTE_H

#include "../cliente.h"
#include "../viagem.h"
#include "../cidade.h"
#include "../poi.h"
#define clientes_e_viagens_txt "../Ficheiros/txt/clientes_e_viagens.txt"
#define clientes_bin "../Ficheiros/bin/clientes.bin"
#define cidades_e_poi_txt "../Ficheiros/txt/cidades_e_poi.txt"
#define cidades_bin "../Ficheiros/bin/cidades.bin"

LISTACLIENTE* ler_clientes_e_viagens_txt();
void escrever_clientes_e_viagens_txt(LISTACLIENTE* list);

LISTACLIENTE* ler_clientes_bin();
void escrever_clientes_bin(LISTACLIENTE* list);

CIDADE_ARRAY* ler_cidades_e_poi_txt();
void escrever_cidades_e_poi_txt(CIDADE_ARRAY* list);

CIDADE_ARRAY* ler_cidades_bin();
void escrever_cidades_bin(CIDADE_ARRAY* list);
#endif //PROJETO_LP1_AED1_FICHEIRO_CLIENTE_H
