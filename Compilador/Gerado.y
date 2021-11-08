%{
	#include "tipos.h"
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
  
	struct Programa *raiz;
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
	 char* ident;
	 struct Programa * Programa1;
	 struct Secao1PERCPERCRegrasPERCPERC * Secao1PERCPERCRegrasPERCPERC1;
	 struct Secao1Config * Secao1Config1;
	 struct Secao1 * Secao11;
	 struct Config * Config1;
	 struct RegrasRegra * RegrasRegra1;
	 struct Regras * Regras1;
	 struct NOMEDOISPONTOSProducoesSEMICOLON * NOMEDOISPONTOSProducoesSEMICOLON1;
	 struct Regra * Regra1;
	 struct ProducoesBARRANomes * ProducoesBARRANomes1;
	 struct Producoes * Producoes1;
	 struct Nomes * Nomes1;
	 struct Nomes2NOME * Nomes2NOME1;
	 struct Nomes2 * Nomes21;
	 struct PERCENTTOKENNOME * PERCENTTOKENNOME1;
	 struct Token * Token1;
	 struct PERCENTUNIONLBRACESDecTiposRBRACES * PERCENTUNIONLBRACESDecTiposRBRACES1;
	 struct Union * Union1;
	 struct DecTiposDecTipo * DecTiposDecTipo1;
	 struct DecTipos * DecTipos1;
	 struct NOMENOMESEMICOLON * NOMENOMESEMICOLON1;
	 struct DecTipo * DecTipo1;
	 struct STARSSTAR * STARSSTAR1;
	 struct STARS * STARS1;
	 struct PERCENTTYPEMENORQNOMEMAIORQNOME * PERCENTTYPEMENORQNOMEMAIORQNOME1;
	 struct Type * Type1;
};

%type <ident> NOME
%type <ident> STAR
%type <Programa1> Programa
%type <Secao1PERCPERCRegrasPERCPERC1> Secao1PERCPERCRegrasPERCPERC
%type <Secao1Config1> Secao1Config
%type <Secao11> Secao1
%type <Config1> Config
%type <RegrasRegra1> RegrasRegra
%type <Regras1> Regras
%type <NOMEDOISPONTOSProducoesSEMICOLON1> NOMEDOISPONTOSProducoesSEMICOLON
%type <Regra1> Regra
%type <ProducoesBARRANomes1> ProducoesBARRANomes
%type <Producoes1> Producoes
%type <Nomes1> Nomes
%type <Nomes2NOME1> Nomes2NOME
%type <Nomes21> Nomes2
%type <PERCENTTOKENNOME1> PERCENTTOKENNOME
%type <Token1> Token
%type <PERCENTUNIONLBRACESDecTiposRBRACES1> PERCENTUNIONLBRACESDecTiposRBRACES
%type <Union1> Union
%type <DecTiposDecTipo1> DecTiposDecTipo
%type <DecTipos1> DecTipos
%type <NOMENOMESEMICOLON1> NOMENOMESEMICOLON
%type <DecTipo1> DecTipo
%type <STARSSTAR1> STARSSTAR
%type <STARS1> STARS
%type <PERCENTTYPEMENORQNOMEMAIORQNOME1> PERCENTTYPEMENORQNOMEMAIORQNOME
%type <Type1> Type

%%
Programa:
	Secao1PERCPERCRegrasPERCPERC { 
			$$=(struct Programa *)malloc(sizeof(struct Programa));
			$$->secao1percpercregraspercperc=$1;
			raiz=$$;
}
;

Secao1PERCPERCRegrasPERCPERC:
	Secao1 PERCPERC Regras PERCPERC {
			$$=(struct Secao1PERCPERCRegrasPERCPERC *)malloc(sizeof(struct Secao1PERCPERCRegrasPERCPERC));
			$$->secao1=$1;
			$$->regras=$3;
			
}
;

Secao1Config:
	Secao1 Config {
			$$=(struct Secao1Config *)malloc(sizeof(struct Secao1Config));
			$$->secao1=$1;
			$$->config=$2;
			
}
;

Secao1:
	Secao1Config {
			$$=(struct Secao1 *)malloc(sizeof(struct Secao1));
			$$->secao1config=$1;
		}
	|Config {
			$$=(struct Secao1 *)malloc(sizeof(struct Secao1));
			$$->config=$1;
		}
;

Config:
	Token {
			$$=(struct Config *)malloc(sizeof(struct Config));
			$$->token=$1;
		}
	|Union {
			$$=(struct Config *)malloc(sizeof(struct Config));
			$$->union=$1;
		}
	|Type {
			$$=(struct Config *)malloc(sizeof(struct Config));
			$$->type=$1;
		}
;

RegrasRegra:
	Regras Regra {
			$$=(struct RegrasRegra *)malloc(sizeof(struct RegrasRegra));
			$$->regras=$1;
			$$->regra=$2;
			
}
;

Regras:
	RegrasRegra {
			$$=(struct Regras *)malloc(sizeof(struct Regras));
			$$->regrasregra=$1;
		}
	|Regra {
			$$=(struct Regras *)malloc(sizeof(struct Regras));
			$$->regra=$1;
		}
;

NOMEDOISPONTOSProducoesSEMICOLON:
	NOME DOISPONTOS Producoes SEMICOLON {
			$$=(struct NOMEDOISPONTOSProducoesSEMICOLON *)malloc(sizeof(struct NOMEDOISPONTOSProducoesSEMICOLON));
			$$->nome=$1;
			$$->producoes=$3;
			
}
;

Regra:
	NOMEDOISPONTOSProducoesSEMICOLON { 
			$$=(struct Regra *)malloc(sizeof(struct Regra));
			$$->nomedoispontosproducoessemicolon=$1;
}
;

ProducoesBARRANomes:
	Producoes BARRA Nomes {
			$$=(struct ProducoesBARRANomes *)malloc(sizeof(struct ProducoesBARRANomes));
			$$->producoes=$1;
			$$->nomes=$3;
			
}
;

Producoes:
	ProducoesBARRANomes {
			$$=(struct Producoes *)malloc(sizeof(struct Producoes));
			$$->producoesbarranomes=$1;
		}
	|Nomes {
			$$=(struct Producoes *)malloc(sizeof(struct Producoes));
			$$->nomes=$1;
		}
;

Nomes:
	Nomes2 { 
			$$=(struct Nomes *)malloc(sizeof(struct Nomes));
			$$->nomes2=$1;
}
;

Nomes2NOME:
	Nomes2 NOME {
			$$=(struct Nomes2NOME *)malloc(sizeof(struct Nomes2NOME));
			$$->nomes2=$1;
			$$->nome=$2;
			
}
;

Nomes2:
	Nomes2NOME {
			$$=(struct Nomes2 *)malloc(sizeof(struct Nomes2));
			$$->nomes2nome=$1;
		}
	|NOME {
			$$=(struct Nomes2 *)malloc(sizeof(struct Nomes2));
			$$->nome=$1;
		}
;

PERCENTTOKENNOME:
	PERCENT TOKEN NOME {
			$$=(struct PERCENTTOKENNOME *)malloc(sizeof(struct PERCENTTOKENNOME));
			$$->nome=$3;
			
}
;

Token:
	PERCENTTOKENNOME { 
			$$=(struct Token *)malloc(sizeof(struct Token));
			$$->percenttokennome=$1;
}
;

PERCENTUNIONLBRACESDecTiposRBRACES:
	PERCENT UNION LBRACES DecTipos RBRACES {
			$$=(struct PERCENTUNIONLBRACESDecTiposRBRACES *)malloc(sizeof(struct PERCENTUNIONLBRACESDecTiposRBRACES));
			$$->dectipos=$4;
			
}
;

Union:
	PERCENTUNIONLBRACESDecTiposRBRACES { 
			$$=(struct Union *)malloc(sizeof(struct Union));
			$$->percentunionlbracesdectiposrbraces=$1;
}
;

DecTiposDecTipo:
	DecTipos DecTipo {
			$$=(struct DecTiposDecTipo *)malloc(sizeof(struct DecTiposDecTipo));
			$$->dectipos=$1;
			$$->dectipo=$2;
			
}
;

DecTipos:
	DecTiposDecTipo {
			$$=(struct DecTipos *)malloc(sizeof(struct DecTipos));
			$$->dectiposdectipo=$1;
		}
	|DecTipo {
			$$=(struct DecTipos *)malloc(sizeof(struct DecTipos));
			$$->dectipo=$1;
		}
;

NOMENOMESEMICOLON:
	NOME NOME SEMICOLON {
			$$=(struct NOMENOMESEMICOLON *)malloc(sizeof(struct NOMENOMESEMICOLON));
			$$->nome=$1;
			$$->nome=$2;
			
}
;

DecTipo:
	NOMENOMESEMICOLON {
			$$=(struct DecTipo *)malloc(sizeof(struct DecTipo));
			$$->nomenomesemicolon=$1;
		}
	|NOME STARS NOME SEMICOLON {
			$$=(struct DecTipo *)malloc(sizeof(struct DecTipo));
		$$->nome=$1;
			$$->stars=$2;
			$$->nome=$3;
			}
	|STRUCT NOME STARS NOME SEMICOLON {
			$$=(struct DecTipo *)malloc(sizeof(struct DecTipo));
		$$->nome=$2;
			$$->stars=$3;
			$$->nome=$4;
			}
;

STARSSTAR:
	STARS STAR {
			$$=(struct STARSSTAR *)malloc(sizeof(struct STARSSTAR));
			$$->stars=$1;
			$$->star=$2;
			
}
;

STARS:
	STARSSTAR {
			$$=(struct STARS *)malloc(sizeof(struct STARS));
			$$->starsstar=$1;
		}
	|STAR {
			$$=(struct STARS *)malloc(sizeof(struct STARS));
			$$->star=$1;
		}
;

PERCENTTYPEMENORQNOMEMAIORQNOME:
	PERCENT TYPE MENORQ NOME MAIORQ NOME {
			$$=(struct PERCENTTYPEMENORQNOMEMAIORQNOME *)malloc(sizeof(struct PERCENTTYPEMENORQNOMEMAIORQNOME));
			$$->nome=$4;
			$$->nome=$6;
			
}
;

Type:
	PERCENTTYPEMENORQNOMEMAIORQNOME { 
			$$=(struct Type *)malloc(sizeof(struct Type));
			$$->percenttypemenorqnomemaiorqnome=$1;
}
;

