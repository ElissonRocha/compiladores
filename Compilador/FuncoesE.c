#include "FuncoesE.h"
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char vetorstr[1000000];
extern struct Regra * primeira;

void criarTipos() {
	FILE* saida = fopen("tipos.h","w");
		printf("Entrou no criarTipos\n");
	
	int i, j, k=0, achou=0, l;
	for(i=0;i<numRegras;i++) {
		printf("Entrou no for num regras\n");
		struct Regra *r = regras[i];
		fprintf(saida, "struct %s {\n", r->nome);
		if(r->producoes->numProducoes==1){
			printf("Entrou no if produçoes\n");
			
			for(j=0;j<(r->producoes->producoes[0]->numNomes);j++){
				achou=0;
				printf("Entrou no for numNomes\n");
				for(k=0;k<(tps.numtipos);k++){
					printf("Entrou no for tps.numtipos\n");
					if(strcmp(r->producoes->producoes[0]->nomes[j], tps.var[k])==0){
						printf("Entrou no if nomes e var\n");
						achou=1;
						//for(l=0;l<sunion.numunion;l++){
							//printf("Entrou no for sunion.numunion\n");
								//if(strcmp(tps.tips[k], sunion.vartipos[l])==0){
									printf("COLOCOU NO ARQUIVO s s \n");
									printf("\t %s %s ;\n", tps.tips[l] , r->producoes->producoes[0]->nomes[j]);
									fprintf(saida, "\t %s %s ;\n", tps.tips[k] , r->producoes->producoes[0]->nomes[j]);
								//}
							//}
					}
				}
				if(achou==0){
					char* nameajuda=(char *)malloc(100*sizeof(char));
					strcpy(nameajuda, r->producoes->producoes[0]->nomes[j]);
					strlwr(nameajuda);
					printf("COLOCOU NO ARQUIVO struct s * s\n");
					printf("\tstruct %s * %s;\n", r->producoes->producoes[0]->nomes[j], nameajuda);
					fprintf(saida, "\tstruct %s * %s;\n", r->producoes->producoes[0]->nomes[j], nameajuda);
					
					}
			}
		}
		else{
			printf("Entrou no else");
			fprintf(saida, "\tunion { \n");
			printf("numproducoes: %d\n", r->producoes->numProducoes);
			for(j=0;j<(r->producoes->numProducoes);j++){
					
					achou=0;
					printf("Entrou aki");
					for(k=0;k<(tps.numtipos);k++){
						printf("Entrou aki2");
						printf(" %s 1\n", r->producoes->producoes[j]->nomes[0]);
						
						if(strcmp(r->producoes->producoes[j]->nomes[0], tps.var[k])==0){
							printf("Entrou aki3");
						achou=1;
						//for(l=0;l<sunion.numunion;l++){
								//if(strcmp(tps.tips[k], sunion.vartipos[l])==0){
									//printf("mais de 1 producao COLOCOU NO ARQUIVO s s\n");
									fprintf(saida, "\t %s %s ;\n", tps.tips[k] , r->producoes->producoes[j]->nomes[0]);
								//}
							//}
						}
					}
				if(achou==0){
					char* nameajuda=(char *)malloc(100*sizeof(char));
					strcpy(nameajuda, r->producoes->producoes[j]->nomes[0]);
					strlwr(nameajuda);
					printf("mais de 1 producao COLOCOU NO ARQUIVO struct s * s\n");
					printf("\tstruct %s * %s;\n", r->producoes->producoes[j]->nomes[0], nameajuda);
					fprintf(saida, "\tstruct %s * %s;\n", r->producoes->producoes[j]->nomes[0], nameajuda);
					
					}
			}
			fprintf(saida, "};\n");
		}
	fprintf(saida, "};\n\n");
	}
	fclose(saida);
}

char* verificarTipos(char *name){
	int i;
	for(i=0;i<sunion.numunion;i++){
		if(strcmp(name, sunion.vartipos[i])==0){
			return sunion.tipos[i];
		}
	}
	return NULL;
}

char* verificarTps(char *name){
	int i;
	for(i=0;i<tps.numtipos;i++){
		if(strcmp(name, tps.var[i])==0){
			return tps.var[i];
		}
	}
	return NULL;
}

int verificarToken(char *name){
	int i;
	for(i=0;i<numtokens;i++){
		if(strcmp(name, tokens[i])==0){
			return 1;
		}
	}
	return 0;
}

void TypeeUnion(){
	int i;
	for(i=0;i<numRegras;i++) {
		char *conc=(char *)malloc(100*(sizeof(char)));
		char* nameajudaajuda;
		char* nameajuda=(char*)malloc(100*(sizeof(char)));
			printf("Entrou no for num regras\n");
			struct Regra *r = regras[i];
				sprintf(conc, "struct %s *", r->nome);
				sunion.tipos[sunion.numunion]=conc;
				tps.var[tps.numtipos]=r->nome;
				strcpy(nameajuda,r->nome);
				nameajudaajuda=strcat(nameajuda,"1");
				sunion.vartipos[sunion.numunion]=nameajudaajuda;
				tps.tips[tps.numtipos]=nameajudaajuda;
				sunion.numunion++;
				tps.numtipos++;
	}
}


void gerarCodigo(){
	FILE* saida = fopen("Gerado.y","w");
	int i, j, k,n;
	fprintf(saida,"%%{\n\t#include \"tipos.h\"\n %s \n", vetorstr);
	fprintf(saida, "\tstruct %s *raiz;\n%%}\n\n", primeira->nome);
	for(i=0;i<numtokens;i++){
		fprintf(saida,"%%token %s\n", tokens[i]);
	}
	fprintf(saida,"\n");
	fprintf(saida,"%%union{ \n");
	for(i=0;i<sunion.numunion;i++){
		fprintf(saida, "\t %s %s;\n", sunion.tipos[i], sunion.vartipos[i]);
	}
	fprintf(saida,"};\n\n");
	for(i=0;i<tps.numtipos;i++){
		int verif;
		verif=verificarToken(tps.var[i]);
		if(verif==1){
			for(j=0;j<sunion.numunion;j++){
				if(strcmp(tps.tips[i], sunion.tipos[j])==0){
					fprintf(saida,"%%type <%s> %s\n", sunion.vartipos[j], tps.var[i]);
				}
			}
		}
		else{
	fprintf(saida,"%%type <%s> %s\n", tps.tips[i], tps.var[i]);
		}
	}
	fprintf(saida,"\n");
	fprintf(saida,"%%%%\n");
	for(i=0;i<numRegras;i++){
		struct Regra *r = regras[i];
		fprintf(saida,"%s:\n", r->nome);
		for(j=0;j<r->producoes->numProducoes;j++){
			if(r->producoes->numProducoes==1){
				fprintf(saida,"\t");
				for(k=0;k<r->producoes->producoes[0]->numNomes;k++){
					if(r->producoes->producoes[0]->numNomes==1){
						char* nameajuda=(char *)malloc(100*sizeof(char));
						strcpy(nameajuda, r->producoes->producoes[0]->nomes[k]);
						strlwr(nameajuda);
						printf("%s ", r->producoes->producoes[0]->nomes[k]);
						fprintf(saida,"%s { \n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t\t$$->%s=$%d;", r->producoes->producoes[0]->nomes[k], r->nome, r->nome, nameajuda,(k+1));
						if(r==primeira){
							fprintf(saida,"\n\t\t\traiz=$$;");
						}
						fprintf(saida,"\n}");
					}
					
					else{
						if(k==(r->producoes->producoes[0]->numNomes-1)){
							printf("%s \n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t\t", r->producoes->producoes[0]->nomes[k], r->nome, r->nome);
							fprintf(saida,"%s {\n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t\t", r->producoes->producoes[0]->nomes[k], r->nome, r->nome);
							for(n=0;n<r->producoes->producoes[0]->numNomes;n++){
								char *nomeajuda;
								char nameajuda[100];
								strcpy(nameajuda, r->producoes->producoes[0]->nomes[n]);
								strlwr(nameajuda);
								nomeajuda=verificarTps(r->producoes->producoes[0]->nomes[n]);
								if(nomeajuda!=NULL){
								fprintf(saida,"$$->%s=$%d;\n\t\t\t", nameajuda,(n+1));
								}
							}
							if(r==primeira){
								fprintf(saida,"\n\t\t\traiz=$$;");
							}
							fprintf(saida,"\n}");
							}
						else{
							printf("%s ", r->producoes->producoes[0]->nomes[k]);
							fprintf(saida,"%s ", r->producoes->producoes[0]->nomes[k]);
						}
					}
				}
				fprintf(saida,"\n;\n\n");
			}
			else{
				if(j==0){
					fprintf(saida, "\t");
				}
				if(r->producoes->producoes[j]->numNomes==1){
					if(j==(r->producoes->numProducoes-1)){
						char* nameajuda=(char *)malloc(100*sizeof(char));
						strcpy(nameajuda, r->producoes->producoes[j]->nomes[0]);
						strlwr(nameajuda);
						printf("\t%s\n;\n\n", r->producoes->producoes[j]->nomes[0]);
						fprintf(saida,"%s {\n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t\t$$->%s=$%d;\n\t\t}\n;\n\n", r->producoes->producoes[j]->nomes[0], r->nome, r->nome, nameajuda, 1);
					}
					else{
						char* nameajuda=(char *)malloc(100*sizeof(char));
						strcpy(nameajuda, r->producoes->producoes[j]->nomes[0]);
						strlwr(nameajuda);
						printf("%s\n\t|", r->producoes->producoes[j]->nomes[0]);
						fprintf(saida,"%s {\n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t\t$$->%s=$%d;\n\t\t}\n\t|", r->producoes->producoes[j]->nomes[0], r->nome, r->nome, nameajuda, 1);
					}
				}
				else{
					for(k=0;k<r->producoes->producoes[j]->numNomes;k++){
						if(j==(r->producoes->numProducoes-1)){
							if(k==(r->producoes->producoes[j]->numNomes-1)){
								printf("\t%s {\n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t\t", r->producoes->producoes[j]->nomes[k], r->nome, r->nome);
								fprintf(saida,"%s {\n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t", r->producoes->producoes[j]->nomes[k], r->nome, r->nome);
								for(n=0;n<r->producoes->producoes[j]->numNomes;n++){
									char* nomeajuda;
									char nameajuda[100];
									strcpy(nameajuda, r->producoes->producoes[j]->nomes[n]);
									strlwr(nameajuda);
									nomeajuda=verificarTps(r->producoes->producoes[j]->nomes[n]);
									if(nomeajuda!=NULL){
										fprintf(saida,"$$->%s=$%d;\n\t\t\t", nameajuda,(n+1));
									}
								}
								fprintf(saida,"}\n;\n\n");
							}
							else{
								printf("%s ", r->producoes->producoes[j]->nomes[k]);
								fprintf(saida, "%s ", r->producoes->producoes[j]->nomes[k]); 
							}
						}
						else{
							if(k==(r->producoes->producoes[j]->numNomes-1)){
								fprintf(saida,"%s {\n\t\t\t$$=(struct %s *)malloc(sizeof(struct %s));\n\t\t", r->producoes->producoes[j]->nomes[k], r->nome, r->nome);
								for(n=0;n<r->producoes->producoes[j]->numNomes;n++){
									char* nomeajuda;
									char* nameajuda=(char *)malloc(100*sizeof(char));
									strcpy(nameajuda, r->producoes->producoes[j]->nomes[n]);
									strlwr(nameajuda);
									nomeajuda=verificarTps(r->producoes->producoes[j]->nomes[n]);
									if(nomeajuda!=NULL){
										fprintf(saida,"$$->%s=$%d;\n\t\t\t", nameajuda,(n+1));
									}
								}
								fprintf(saida, "}\n\t|");
							}
							else{
								printf("%s ", r->producoes->producoes[j]->nomes[k]);
								fprintf(saida, "%s ", r->producoes->producoes[j]->nomes[k]); 
							}
							
						}
					}	
				}
			
			}
		}
	}
	fclose(saida);

}


