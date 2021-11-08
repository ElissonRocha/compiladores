#include<stdio.h>
#include<string.h>
#include "FuncoesE.h"
//#include "compilador.h"


unsigned int cont_vetor=0;
extern FILE *yyin;
extern int yyparse();

void inicializar(){
	tps.numtipos=0;
	sunion.numunion=0;
}

int main(int argc, char **argv){
    if(argc!=2){
                return 1;
                }
    if(!(yyin=fopen(argv[1],"r"))){
                                   return 1;
                                   }
    inicializar();
    if(yyparse()==0) printf("\n\nSucesso\n");
    criarTipos();
	TypeeUnion();
	gerarCodigo();
    return 0;
    
}