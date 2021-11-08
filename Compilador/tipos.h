struct Programa {
	struct Secao1PERCPERCRegrasPERCPERC * secao1percpercregraspercperc;
};

struct Secao1PERCPERCRegrasPERCPERC {
	struct Secao1 * secao1;
	struct PERCPERC * percperc;
	struct Regras * regras;
	struct PERCPERC * percperc;
};

struct Secao1Config {
	struct Secao1 * secao1;
	struct Config * config;
};

struct Secao1 {
	union { 
	struct Secao1Config * secao1config;
	struct Config * config;
};
};

struct Config {
	union { 
	struct Token * token;
	struct Union * union;
	struct Type * type;
};
};

struct RegrasRegra {
	struct Regras * regras;
	struct Regra * regra;
};

struct Regras {
	union { 
	struct RegrasRegra * regrasregra;
	struct Regra * regra;
};
};

struct NOMEDOISPONTOSProducoesSEMICOLON {
	 char* NOME ;
	struct DOISPONTOS * doispontos;
	struct Producoes * producoes;
	struct SEMICOLON * semicolon;
};

struct Regra {
	struct NOMEDOISPONTOSProducoesSEMICOLON * nomedoispontosproducoessemicolon;
};

struct ProducoesBARRANomes {
	struct Producoes * producoes;
	struct BARRA * barra;
	struct Nomes * nomes;
};

struct Producoes {
	union { 
	struct ProducoesBARRANomes * producoesbarranomes;
	struct Nomes * nomes;
};
};

struct Nomes {
	struct Nomes2 * nomes2;
};

struct Nomes2NOME {
	struct Nomes2 * nomes2;
	 char* NOME ;
};

struct Nomes2 {
	union { 
	struct Nomes2NOME * nomes2nome;
	 char* NOME ;
};
};

struct PERCENTTOKENNOME {
	struct PERCENT * percent;
	struct TOKEN * token;
	 char* NOME ;
};

struct Token {
	struct PERCENTTOKENNOME * percenttokennome;
};

struct PERCENTUNIONLBRACESDecTiposRBRACES {
	struct PERCENT * percent;
	struct UNION * union;
	struct LBRACES * lbraces;
	struct DecTipos * dectipos;
	struct RBRACES * rbraces;
};

struct Union {
	struct PERCENTUNIONLBRACESDecTiposRBRACES * percentunionlbracesdectiposrbraces;
};

struct DecTiposDecTipo {
	struct DecTipos * dectipos;
	struct DecTipo * dectipo;
};

struct DecTipos {
	union { 
	struct DecTiposDecTipo * dectiposdectipo;
	struct DecTipo * dectipo;
};
};

struct NOMENOMESEMICOLON {
	 char* NOME ;
	 char* NOME ;
	struct SEMICOLON * semicolon;
};

struct DecTipo {
	union { 
	struct NOMENOMESEMICOLON * nomenomesemicolon;
	 char* NOME ;
	struct STRUCT * struct;
};
};

struct STARSSTAR {
	struct STARS * stars;
	 char* STAR ;
};

struct STARS {
	union { 
	struct STARSSTAR * starsstar;
	 char* STAR ;
};
};

struct PERCENTTYPEMENORQNOMEMAIORQNOME {
	struct PERCENT * percent;
	struct TYPE * type;
	struct MENORQ * menorq;
	 char* NOME ;
	struct MAIORQ * maiorq;
	 char* NOME ;
};

struct Type {
	struct PERCENTTYPEMENORQNOMEMAIORQNOME * percenttypemenorqnomemaiorqnome;
};

