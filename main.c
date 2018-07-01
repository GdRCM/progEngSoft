#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"

int contProg = 0;
ind dados;
char nmProj[] = "Informe o nome do projeto", orc[] = "Informe o valor total do orcamento",
pzProj[] = "Informe o total de meses para execucao do projeto",
pcProj[] = "Quantos meses se passaram desde o inicio do projeto?",
crProj[]="Quanto foi gasto até o presente momento";

void menuPrinc();
void menuIns();
ind calcInd();

int main(int argc, char *argv[]) {
	system("mode con:cols=50 lines=25");
	while(contProg!=2){
		menuPrinc();
	}
	return 0;
}

void menuPrinc(){
	system("cls");
	printf("                 Nome do Programa\n");
	printf("===================Tela inicial===================\n\n");
	printf("    Ainda nao foram inseridos dados de projeto    \n                a serem analisados\n\n");
	printf("==================================================\n");
	printf("\t\tSelecione uma opcao\n\n");
	
	printf("1 - Adicionar informacoes do projeto\n\n2 - Encerrar o programa\n\n");
	scanf(" %i", &contProg);
	
	switch(contProg){
		case 1: 
			menuIns();
			break;
		case 2:
			exit(EXIT_SUCCESS);
			break;
		
		default:
			printf("Valor Invalido!\n\nFavor digitar um valor valido\n\n");
			system("pause");
			break;
	}
}

void menuIns(){
	system("cls");
	printf("                 Nome do Programa\n");
	printf("================insercao de dados=================\n\n");
	
	printf("Projeto: %s\n",nmProj);
	scanf("%s", &nmProj);
	
	printf("Orcamento: %s\n",orc); //Define o valor do orçamento planejado para executar o projeto
	scanf("%s", &orc);
	dados.ont = atof(orc);
	
	printf("Prazo para execucao: %s\n",pzProj); //Define o tempo maximo planejado para executar o projeto
	scanf("%s", &pzProj);
	dados.pzPr = atof(pzProj);
	
	printf("Periodo concretizado: %s\n",pcProj); //Define quanto tempo correu desde o inicio do projeto
	scanf("%s", &pcProj);
	dados.pcPr = atof(pcProj);
	
	printf("Valor Gasto: %s\n",crProj); //Define o valor total gasto até o momento atual do projeto
	scanf("%s", &crProj);
	dados.cr = atof(crProj);
	
	system("pause");
}
