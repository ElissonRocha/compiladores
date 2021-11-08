%{
	#include"FuncoesE.h"
	#include<stdlib.h>
	#include<string.h>
	#include<stdio.h>
	#include "compilador.h"
	
	int cont_linhas=0;
	extern int cont_vetor;
	char ajuda[100000];
	int gambiarra=0;
	char linebuf[500];
	int cont_aspas=0;
	void yyerror(char *s)    {         
		printf("%d: %s at %s in this line:\n%s\n",
		cont_linhas, s, yytext, linebuf);    
	} 
	
	//int yyerror(const char*msg){
	//printf("ERROR(%d): %s\n",cont_linhas, msg);
	//return 1;
	
//	}
	
%}

%option noyywrap nodefault
%x COMENTARIO

%%

"struct" {
	return STRUCT;
	}
"type" {
	return TYPE;
	}
"token" {
	return TOKEN;
	}
"union" {
	return UNION;
	}
"%%" {
	return PERCPERC;
	}
"%" {
	return PERCENT;
	}
";" {
	return SEMICOLON;
	}
":" {
	return DOISPONTOS;
	}
"|" {
	return BARRA;
	}
">" {
	return MAIORQ;
	}
"<" {
	return MENORQ;
	}
"{" {
	return LBRACES;
	}
"}" {
	return RBRACES;
	}
"*" {
	yylval.ident=strdup(yytext);
	return STAR;
	}
[a-zA-z][a-zA-Z0-9]* {
	yylval.ident=strdup(yytext);
	return NOME;
	}

\n.*  { 
	strncpy(linebuf, yytext+1, sizeof(linebuf)); /* save the next line */
    yyless(1);      /* give back all but the \n to rescan */          
	cont_linhas++;
	}    
    

[ \t\r]+ {}

"%{" { BEGIN( COMENTARIO); } 
<COMENTARIO>\n { cont_linhas++; }
<COMENTARIO>"%}" { BEGIN( INITIAL); }
<COMENTARIO>. {
		if(gambiarra==0){
			gambiarra=1;
			strcpy(ajuda, strdup(yytext));
		}
		else{
			if(strcmp(yytext, ">")==0 || strcmp(yytext, "\"")==0  || strcmp(yytext, ";")==0 ){
				if(strcmp(yytext, "\"")==0){
					if(cont_aspas==0){
						cont_aspas=1;
						strcat(ajuda, strdup(yytext));
					}
					else{
						strcat(ajuda, strdup(yytext));
						strcat(ajuda, "\n");
						cont_aspas=0;
					}
				}
				else{
				strcat(ajuda, strdup(yytext));
				strcat(ajuda, "\n");
				}
			}else{ 
				strcat(ajuda, strdup(yytext));
			}
		}
		strcpy(vetorstr, ajuda);
}
. {
	char msg[64];
	sprintf(msg,"caractere ou termo invalido: %s \n", yytext);
	yyerror(msg);
	exit(7);
}

%%