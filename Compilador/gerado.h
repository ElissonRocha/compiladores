/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GERADO_H_INCLUDED
# define YY_YY_GERADO_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEMICOLON = 258,
     BARRA = 259,
     DOISPONTOS = 260,
     TYPE = 261,
     TOKEN = 262,
     MAIORQ = 263,
     MENORQ = 264,
     UNION = 265,
     PERCENT = 266,
     NOME = 267,
     PERCPERC = 268,
     STAR = 269,
     RBRACES = 270,
     LBRACES = 271,
     STRUCT = 272,
     CODE = 273
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 35 "gerado.y"
 
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


/* Line 2058 of yacc.c  */
#line 106 "gerado.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GERADO_H_INCLUDED  */
