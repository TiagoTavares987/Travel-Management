cmake_minimum_required(VERSION 3.20)
project(projeto_lp1_aed1 C)

set(CMAKE_C_STANDARD 99)

add_executable(projeto_lp1_aed1 main.c cliente.c cliente.h viagem.c viagem.h cidade.c cidade.h test/cliente_test.c test/cliente_test.h test/viagem_test.c test/viagem_test.h test/cidade_test.c test/cidade_test.h poi.c poi.h test/poi_test.c test/poi_test.h Ficheiros/ficheiro_cliente.c Ficheiros/ficheiro_cliente.h test/ficheiro_cliente_test.c test/ficheiro_cliente_test.h historico_e_pesquisa.c historico_e_pesquisa.h tsp.c tsp.h)
