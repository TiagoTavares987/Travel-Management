
#ifndef PROJETO_LP1_AED1_HISTORICO_E_PESQUISA_H
#define PROJETO_LP1_AED1_HISTORICO_E_PESQUISA_H

#include "cliente.h"
#include "viagem.h"
#include "cidade.h"
#include "poi.h"

VIAGEM_ARRAY *historico_de_viagens_por_cliente(LISTACLIENTE *list, char nome_cliente[MAX100]);
VIAGEM *pesquisar_cidade_ou_poi_em_viagens_de_cliente(CLIENTE *c, char cidade_a_pesquisar[MAX100], char poi_a_pesquisar[MAX100]);
#endif //PROJETO_LP1_AED1_HISTORICO_E_PESQUISA_H
