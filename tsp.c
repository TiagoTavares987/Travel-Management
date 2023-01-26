
#include "tsp.h"
#include <math.h>

#define rand_min -10
#define rand_max 10

/**
 * Função que cria um ponto
 * @param id
 * @param x
 * @param y
 * @return o ponto criado
 */
PONTO* criar_ponto(int id, float x, float y) {

	PONTO* p = (PONTO*)malloc(sizeof(PONTO));
	p->id = id;
	p->x = x;
	p->y = y;

	return p;
}

/**
 * Função que inicializa o array dinamico de pontos
 * @param initsize
 * @return o array dinamico de pontos
 */
PONTO_ARRAY* initArrayPonto(int initsize) {

	PONTO_ARRAY* p = (PONTO_ARRAY*)calloc(1, sizeof(PONTO_ARRAY));
	p->size_pontos = initsize;
	p->n_pontos = 0;
	p->pontos = (PONTO*)malloc(sizeof(PONTO) * p->size_pontos);

	return p;
}

/**
 * Função que inicializa o algoritmo
 * @param nome
 * @param distancia
 * @param list
 * @return o algoritmo
 */
ALGORITMO* initAlgoritmo(char nome[MAX100], float distancia, PONTO_ARRAY* list) {

	ALGORITMO* a = (ALGORITMO*)calloc(1, sizeof(ALGORITMO));
	strcpy(a->nome, nome);
	a->distancia = distancia;
	a->list = list;

	return a;
}

/**
 * Função que insere um ponto dentro do array dinamico de pontos
 * @param list
 * @param p
 */
void inserirArrayPonto(PONTO_ARRAY* list, PONTO* p) {

	if (list->size_pontos == list->n_pontos) {
		if (list->size_pontos == 0)
			list->size_pontos = 1;
		else {
			list->size_pontos *= 2;
			list->pontos = (PONTO*)realloc(list->pontos, sizeof(PONTO) * list->size_pontos);
		}
	}
	list->pontos[list->n_pontos] = *p;
	list->n_pontos++;

}

/**
 * Função que remove um ponto dentro do array dinamico de pontos
 * @param list
 * @param p
 */
void removerArrayPonto(PONTO_ARRAY* list, PONTO* p) {

	for (int i = 0; i < list->n_pontos; i++) {
		if (&list->pontos[i] == p) {
			memmove(list->pontos + i, list->pontos + (i + 1), (list->n_pontos - (i + 1)) * sizeof(PONTO_ARRAY));
			list->n_pontos--;
			break;
		}
	}
}

//---------------------------aux
/**
 * Função para randomizar um inteiro
 * @param min
 * @param max
 * @return
 */
int int_rand(int min, int max)
{
	return min + rand() % (max - min);
}

/**
 * Função para randomizar um float
 * @param min
 * @param max
 * @return
 */
float float_rand(float min, float max)
{
	float scale = rand() / (float)RAND_MAX;
	return min + scale * (max - min);
}

/**
 * Função para gerar uma lista de pontos
 * @param n_pontos
 * @return a lista/array de pontos
 */
PONTO_ARRAY* gerar_lista_de_pontos(int n_pontos)
{
	PONTO_ARRAY* pontos = initArrayPonto(n_pontos);
	for (int i = 1; i <= n_pontos; i++) {
		float x = float_rand(rand_min, rand_max);
		float y = float_rand(rand_min, rand_max);
		PONTO* p = criar_ponto(i, x, y);
		inserirArrayPonto(pontos, p);
	}
	return pontos;
}

/**
 * Função que obtem a distancia entre dois pontos
 * @param p1
 * @param p2
 * @return a distancia
 */
float obter_distancia(PONTO* p1, PONTO* p2) {

	return sqrtf(powf(p2->x - p1->x, 2) + powf(p2->y - p1->y, 2));
}

/**
 * Função que obtem a distancia total
 * @param pontos
 * @return a distancia total
 */
float obter_distancia_total(PONTO_ARRAY* pontos)
{
	float distancia_total = 0.0f;

	if (pontos->n_pontos > 1)
	{
		for (int i = 0; i < pontos->n_pontos - 1; i++)
			distancia_total += obter_distancia(&pontos->pontos[i], &pontos->pontos[i + 1]);

		distancia_total += obter_distancia(&pontos->pontos[pontos->n_pontos - 1], &pontos->pontos[0]);
	}

	return distancia_total;
}

//---------------------------algoritmo
/**
 * Algoritmo do vizinho mais proximo
 * @param pontos
 * @return a inicialização do algoritmo
 */
ALGORITMO* vizinho_mais_proximo(PONTO_ARRAY* pontos) {

	PONTO_ARRAY* list = initArrayPonto(pontos->n_pontos);

	if (pontos->n_pontos > 0) {
		float d_min = 0.0f;
		PONTO* p = NULL;
		int p_i = int_rand(0, pontos->n_pontos - 1);

		do {
			p = &pontos->pontos[p_i];
			inserirArrayPonto(list, p);
			removerArrayPonto(pontos, p);
			p = &list->pontos[list->n_pontos - 1];

			p_i = -1;
			d_min = 3.402823466f;

			for (int i = 0; i < pontos->n_pontos; i++) {

				int d = obter_distancia(p, &pontos->pontos[i]);
				if (d < d_min) {
					d_min = d;
					p_i = i;
				}
			}

		} while (p_i > -1);
	}

	return initAlgoritmo("Vizinho mais próximo", obter_distancia_total(list), list);
}

//---------------------------teste
void imprimir_pontos(PONTO_ARRAY* list)
{
	printf("\nlista de pontos\n");
	for (int i = 0; i < list->n_pontos; i++)
		printf("id:%i x:%f y:%f\n", list->pontos[i].id, list->pontos[i].x, list->pontos[i].y);
}

void imprimir_algoritmo(ALGORITMO* alg)
{
	printf("\n%s\ndistancia:%f\n", alg->nome, alg->distancia);
	imprimir_pontos(alg->list);
}

void teste_algoritmos() {

	PONTO_ARRAY* pontos = gerar_lista_de_pontos(10);
	imprimir_pontos(pontos);


	ALGORITMO* alg = vizinho_mais_proximo(pontos);
	imprimir_algoritmo(alg);

}
