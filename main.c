/*
 * Projeto realizado por:
 * Diana Marques 39845
 * Tiago Tavares 38609
 */
#include "test/cliente_test.h"
#include "test/viagem_test.h"
#include "test/cidade_test.h"
#include "test/poi_test.h"
#include "test/ficheiro_cliente_test.h"

int main(int argc, const char *argv[]) {

    cliente_test(argc, argv);
    viagem_test(argc, argv);
    cidade_test(argc, argv);
    poi_test(argc, argv);

    ficheiro_cliente_test();

    return 0;
}
