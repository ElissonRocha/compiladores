%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	#include "FuncoesE.h"
	
	char *tokens[1000];
	int numtokens=0;
	struct Regra *regras[1000];
	int numRegras = 0;
	struct Sunion sunion;
	struct Types tps;
	
	struct Regra *primeira = NULL;
	
	int contRegras = 0;
%}

%token SEMICOLON
%token BARRA
%token DOISPONTOS
%token TYPE
%token TOKEN
%token MAIORQ
%token MENORQ
%token UNION
%token PERCENT
%token NOME
%token PERCPERC
%token STAR
%token RBRACES
%token LBRACES
%token STRUCT
%token CODE

%union{
	char *ident;
	struct Types *typ;
	struct Regra *reg;
	struct Producoes *prod;
	struct Nomes *nom;
	};

%type <reg> Regra
%type <prod> Producoes
%type <nom> Nomes
%type <nom> Nomes2
%type <typ> Type
%type <ident> NOME
%type <ident> STAR
%type <ident> STARS

%%

Programa:
	Secao1 {printf("secao1\n");} PERCPERC Regras PERCPERC {
		int i;
		for(i=0;i<numRegras;i++) {
			if(regras[i] == primeira) {
				regras[i] = regras[0];
				regras[0] = primeira;
				break;
			}
		}
	};
	
Secao1:
	Config
	| Secao1 Config;

Config:
	CODE
	|Token
	|Union
	|Type
	;


Regras: 
	Regras Regra {
		regras[numRegras++] = $2;
	}
	| Regra {
		regras[numRegras++] = $1;
		
	};

Regra: 
	NOME DOISPONTOS Producoes SEMICOLON{
		$$ = (struct Regra *)malloc(sizeof( struct Regra));
		$$->nome = $1;
		$$->producoes = $3;
		printf("Regra (%s)\n",$1 );
		
		if(contRegras == 0) {
			primeira = $$;
		}
		contRegras++;
		
	};

Producoes:
	Producoes BARRA Nomes {
		int i;
		$$ = (struct Producoes*)malloc(sizeof(struct Producoes));
		$$->numProducoes = $1->numProducoes + 1;
		$$->producoes = (struct Nomes **)malloc($$->numProducoes*sizeof(struct Nomes *));
		for(i=0;i<$1->numProducoes;i++) {
			$$->producoes[i] = $1->producoes[i];
		}
		//$$->producoes[$1->numProducoes] = $3->producoes[0];
		$$->producoes[$1->numProducoes] = $3;
	}
	|Nomes {
		int i;
		struct Producoes* producao;
		struct Regra *r;
		
		printf("Começou Nomes!\n");
		producao = (struct Producoes*)malloc(sizeof(struct Producoes));
		producao->numProducoes = 1;
		producao->producoes = (struct Nomes**)malloc(sizeof(struct Nomes*));
		producao->producoes[0] = $1;
		
		if($1->numNomes > 1) {
			struct Nomes *n = (struct Nomes*)malloc(sizeof(struct Nomes));
			$$ = (struct Producoes*)malloc(sizeof(struct Producoes));
			r = (struct Regra*)malloc(sizeof(struct Regra));
			r->producoes = producao;
			r->nome = (char*)malloc(1000*sizeof(char));
			
			strcpy(r->nome, $1->nomes[0]);
			for(i=1;i<$1->numNomes;i++) {
				strcat(r->nome, $1->nomes[i]);
			}
				strcat(r->nome, "\0");
			n->numNomes = 1;
			n->nomes = (char **)malloc(sizeof(char*));
			n->nomes[0] = strdup(r->nome);
			
			regras[numRegras++] = r;
			$$->numProducoes = 1;
			$$->producoes = (struct Nomes**)malloc(sizeof(struct Nomes*));
			$$->producoes[0] = n;
		} else {
			$$ = producao;
		}
		printf("Produção!\n");
	};


Nomes: 
	{
		$$ = (struct Nomes*)malloc(sizeof(struct Nomes));
		$$->numNomes = 0;
		$$->nomes = NULL;
	}
	|Nomes2 {
		printf("Nomes2!\n");
		$$ = $1;
	};

Nomes2:
	NOME {
		$$ = (struct Nomes*)malloc(sizeof(struct Nomes));
		$$->numNomes = 1;
		$$->nomes = (char **)malloc(sizeof(char *));
		$$->nomes[0] = $1;
		printf("%s\n", $1);
	}
	|Nomes2 NOME {
		int i;
		$$ = (struct Nomes*)malloc(sizeof(struct Nomes));
		$$->numNomes = $1->numNomes + 1;
		$$->nomes = (char **)malloc($$->numNomes*sizeof(char *));
		for(i=0;i<$1->numNomes;i++) {
			$$->nomes[i] = $1->nomes[i];
		}
		//$$->nomes[$1->numNomes] = $2->nomes[0];
		$$->nomes[$1->numNomes] = $2;
		printf("%s\n", $2);
	};
	
Token:
	PERCENT TOKEN NOME{
		int achou;
		achou=verificarToken($3);
		if(achou==1){
			char msg[64];
			sprintf(msg,"Token ja existente; \n");
			yyerror(msg);
			exit(1);
		}
		else{
			tokens[numtokens]=$3;
			numtokens++;
		}
	}
	;
	
Union: 
	PERCENT UNION LBRACES DecTipos RBRACES
	;
	
DecTipos:
	DecTipos DecTipo
	| DecTipo;

DecTipo:
	NOME NOME SEMICOLON{
		sunion.tipos[sunion.numunion]=$1;
		sunion.vartipos[sunion.numunion]=$2;
		sunion.numunion++;
		
	}
	| NOME STARS NOME SEMICOLON{
		char *conc=(char *)malloc(100*(sizeof(char)));
		strcpy(conc, $1);
		strcat(conc,$2);
		sunion.tipos[sunion.numunion]=conc;
		sunion.vartipos[sunion.numunion]=$3;
		sunion.numunion++;
	}
	| STRUCT NOME STARS NOME SEMICOLON{
		char *conc=(char *)malloc(100*(sizeof(char)));
		//strcpy(conc, "struct ");
		//strcat(conc,$2);
		//strcat(conc, $3);
		sprintf(conc, "struct %s %s", $2, $3);
		sunion.tipos[sunion.numunion]=conc;
		sunion.vartipos[sunion.numunion]=$4;
		sunion.numunion++;
		
	};

STARS:
		STARS STAR{ $$=$2; }
		|STAR{ $$=$1; };
		
Type:
	PERCENT TYPE MENORQ NOME MAIORQ NOME{
		char *cobaia;
		tps.var[tps.numtipos]=$6;
		cobaia=verificarTipos($4);
		if(cobaia==NULL){
			char msg[64];
			sprintf(msg,"Nao existe esse tipo que esta entre o < >; \n");
			yyerror(msg);
			exit(1);	
		}
		tps.tips[tps.numtipos]=cobaia;
		tps.numtipos++;
		printf("type!\n");
	}
	;
