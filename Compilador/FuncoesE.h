#include<string.h>
#include<stdio.h>
#include<math.h>
#ifndef _FuncoesE_h
#define _FuncoesE_h
	
	extern struct Regra *regras[1000];
	extern int numRegras;
	extern struct Types tps;
	extern struct Sunion sunion;
	extern char *tokens[1000];
	extern int numtokens;
	extern char vetorstr[1000000];

	void criarTipos();
	char* verificarTipos(char *name);
	int verificarToken(char *name);
	void TypeeUnion();
	void gerarCodigo();
	char* verificarTps(char *name);
	
	
	struct Types {
		int numtipos;
		char *var[100000];
		char *tips[100000];
	};

	struct Sunion {
		int numunion; 
		char *tipos[100000];
		char *vartipos[100000];
	};
	
	struct Nomes {
		int numNomes;
		char **nomes;
	};

	struct Producoes {
		int numProducoes;
		struct Nomes **producoes;
	};
	
	struct Regra {
		char *nome;
		struct Producoes *producoes;
	};
	
#endif

