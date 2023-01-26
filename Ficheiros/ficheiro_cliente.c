

#include "ficheiro_cliente.h"

/**
 * Função que lê um cliente em txt
 * @param ptr
 * @return a criaçao desse cliente que foi lido
 */
CLIENTE* ler_cliente_txt(FILE* ptr) {
	int id_cliente = 0, contacto = 0, nif = 0, size_viagens = 0;
	char nome_cliente[MAX100], morada[MAX200];

	fscanf(ptr, "%i,%[^,],%[^,],%i,%i,%i\n", &id_cliente, nome_cliente, morada, &contacto, &nif, &size_viagens);

	if (id_cliente != 0)
		return criar_cliente(id_cliente, nome_cliente, morada, contacto, nif, size_viagens);
	else
		return NULL;
}

/**
 * Função que lê uma viagem em txt
 * @param ptr
 * @return a criaçao dessa viagem que foi lida
 */
VIAGEM* ler_viagem_txt(FILE* ptr) {

	int data_inicio = 0, data_fim = 0;
	char titulo[MAX200];

	fscanf(ptr, "%[^,],%i,%i\n", titulo, &data_inicio, &data_fim);

	if (strcmp(titulo, "") != 0)
		return criar_viagem(titulo, data_inicio, data_fim, 0);
	else
		return NULL;
}

/**
 * Função que lê uma cidade em txt
 * @param ptr
 * @return a criaçao dessa cidade que foi lida
 */
CIDADE* ler_cidade_txt(FILE* ptr) {

	char nome_cidade[MAX100];
	char cidade_pais[MAX100];
	float latitude, longitude;
	int size_poi = 0;

    // se debitar -1 há erro de leitura ou o nr de parametros que cpnseguir ler
	if(fscanf(ptr, "%[^,],%[^,],%f,%f,%i\n", nome_cidade, cidade_pais, &latitude, &longitude, &size_poi) > 0)
		return criar_cidade(nome_cidade, cidade_pais, latitude, longitude, size_poi);
	else
		return NULL;
}

/**
 * Função que lê um poi em txt
 * @param ptr
 * @return a criaçao desse poi que foi lido
 */
POI* ler_poi_txt(FILE* ptr) {

	char nome_poi[MAX100], descricao_poi[MAX200];

	fscanf(ptr, "%[^,],%[^,^\n]\n", nome_poi, descricao_poi);

	if (strcmp(nome_poi, "") != 0 && strcmp(descricao_poi, "") != 0)
		return criar_poi(nome_poi, descricao_poi);
	else
		return NULL;
}

/**
 * Função que le os clientes e as viagens desses clientes em txt
 * @return a lista de clientes
 */
LISTACLIENTE* ler_clientes_e_viagens_txt() {

	FILE* ptr = fopen(clientes_e_viagens_txt, "r");
	if (ptr == NULL) {
		fprintf(stdout, "Erros... %s", clientes_e_viagens_txt);
		return NULL;
	}


	LISTACLIENTE* list = criar_lista_cliente();

	CLIENTE* c;

	do {
		c = ler_cliente_txt(ptr);
		if (c != NULL) {
			if (c->array_viagens.size_viagem > 0) {
				VIAGEM* v;
				for (int i = 0; i < c->array_viagens.size_viagem; i++) {
					v = ler_viagem_txt(ptr);
					if (v != NULL)
						inserirArrayViagem(&c->array_viagens, v);
				}
			}
			inserir_cliente_cauda(list, c);
		}
	} while (c != NULL);

	fclose(ptr);

	return list;
}

/**
 * Função que escreve clientes e viagens num ficheiro txt
 * @param list
 */
void escrever_clientes_e_viagens_txt(LISTACLIENTE* list) {

	FILE* ptr = fopen(clientes_e_viagens_txt, "w");
	if (ptr == NULL) {
		fprintf(stdout, "Erros... %s", clientes_e_viagens_txt);
		return;
	}

	CLIENTE* current = list->pclientes;
	while (current != NULL) {
		fprintf(ptr, "%i,", current->id_cliente);
		fprintf(ptr, "%s,", current->nome_cliente);
		fprintf(ptr, "%s,", current->morada);
		fprintf(ptr, "%i,", current->contacto);
		fprintf(ptr, "%i,", current->nif);
		fprintf(ptr, "%i", current->array_viagens.n_viagem);
		if (current->array_viagens.n_viagem > 0)
			fprintf(ptr, "\n");
		for (int i = 0; i < current->array_viagens.n_viagem; i++) {
			fprintf(ptr, "%s,", current->array_viagens.pviagem[i].titulo);
			fprintf(ptr, "%lld,", current->array_viagens.pviagem[i].data_inicio);
			fprintf(ptr, "%lld", current->array_viagens.pviagem[i].data_fim);
			if (i < current->array_viagens.n_viagem - 1)
				fprintf(ptr, "\n");
		}
		current = current->pnext_cliente;
		if (current != NULL)
			fprintf(ptr, "\n");
	}

	fclose(ptr);
}

/**
 * Função que lê os clientes de um ficheiro bin
 * @return o endereço da lista
 */
LISTACLIENTE* ler_clientes_bin() {

	FILE* ptr = fopen(clientes_bin, "rb");
	if (ptr == NULL)
		return NULL;

	LISTACLIENTE list;

	fread(&list, sizeof(LISTACLIENTE), 1, ptr);

	fclose(ptr);

	return &list;
}

/**
 * Função que escreve os clientes para um ficheiro binario
 * @param list
 */
void escrever_clientes_bin(LISTACLIENTE* list) {

	FILE* ptr = fopen(clientes_bin, "wb");
	if (ptr == NULL)
		return;

	fwrite(&*list, sizeof(LISTACLIENTE), 1, ptr);

	fclose(ptr);
}

/**
 * Função que le as cidades e os poi em txt
 * @return a lista das cidades
 */
CIDADE_ARRAY* ler_cidades_e_poi_txt() {

    FILE* ptr = fopen(cidades_e_poi_txt, "r");
    if (ptr == NULL) {
        fprintf(stdout, "Erros... %s", cidades_e_poi_txt);
        return NULL;
    }


    CIDADE_ARRAY* list = initArrayCidade(1);

    CIDADE* c;

    do {
        c = ler_cidade_txt(ptr);
        if (c != NULL) {
            POI* p;
            for (int i = 0; i < c->array_poi.size_poi; i++) {
                p = ler_poi_txt(ptr);
                if (p != NULL)
                    inserirArrayPoi(&c->array_poi, p);
                else
                    break;
            }
            inserirArrayCidade(list, c);
        }
    } while (c != NULL);

    fclose(ptr);

    return list;
}

/**
 * Função que escreve as cidades e poi's num ficheiro txt
 * @param list
 */
void escrever_cidades_e_poi_txt(CIDADE_ARRAY* list) {

    FILE* ptr = fopen(cidades_e_poi_txt, "w");
    if (ptr == NULL) {
        fprintf(stdout, "Erros... %s", cidades_e_poi_txt);
        return;
    }

    for (int i = 0; i < list->n_cidade; i++) {
        fprintf(ptr, "%s,", list->pcidade[i].nome_cidade);
        fprintf(ptr, "%s,", list->pcidade[i].cidade_pais);
        fprintf(ptr, "%f,", list->pcidade[i].latitude);
        fprintf(ptr, "%f,", list->pcidade[i].longitude);
        fprintf(ptr, "%i", list->pcidade[i].array_poi.n_poi);
        if (list->pcidade[i].array_poi.n_poi > 0)
            fprintf(ptr, "\n");
        for (int j = 0; j < list->pcidade[i].array_poi.n_poi; j++) {
            fprintf(ptr, "%s,", list->pcidade[i].array_poi.ppoi[j].nome_poi);
            fprintf(ptr, "%s", list->pcidade[i].array_poi.ppoi[j].descricao_poi);
            if (j < list->pcidade[i].array_poi.n_poi - 1)
                fprintf(ptr, "\n");
        }
        if (i < list->n_cidade - 1)
            fprintf(ptr, "\n");
    }

    fclose(ptr);
}

/**
 * Função que lê as cidades de um ficheiro bin
 * @return o endereço da lista
 */
CIDADE_ARRAY* ler_cidades_bin() {

    FILE* ptr = fopen(cidades_bin, "rb");
    if (ptr == NULL)
        return NULL;

    CIDADE_ARRAY list;

    fread(&list, sizeof(CIDADE_ARRAY), 1, ptr);

    fclose(ptr);

    return &list;
}

/**
 * Função que escreve as cidades para um ficheiro binario
 * @param list
 */
void escrever_cidades_bin(CIDADE_ARRAY* list) {

    FILE* ptr = fopen(cidades_bin, "wb");
    if (ptr == NULL)
        return;

    fwrite(&*list, sizeof(CIDADE_ARRAY), 1, ptr);

    fclose(ptr);
}