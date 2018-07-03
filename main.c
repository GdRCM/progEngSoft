#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "funcoes.c"
#include <locale.h>

int contProg = 0;
ind * dados;
char nmProj[] = "Informe o nome do projeto", orc[] = "Informe o valor total do orcamento",
pzProj[] = "Informe o total de meses para execucao do projeto",
pcProj[] = "Quantos meses se passaram desde o inicio do projeto?",
pRealProj[] = "Informe a % do projeto que está concluida",
crProj[]="Quanto foi gasto até o presente momento";

void menuPrinc();
void menuIns();
void menuInfo();

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    dados = malloc(sizeof(ind));
    inicializar(dados);
	system("mode con:cols=50 lines=25");
	while(contProg!=3){
		menuPrinc();
	}
	free(dados);
	return 0;
}

void menuPrinc(){
	system("cls");
	printf("            Calculadora de indices GVA\n\n");
	printf("================Status do Projeto=================\n\n");
	printf("\t%s\t\n\n", statusProjeto(dados));
	printf("==================================================\n");
	printf("\t\tSelecione uma opção\n\n");

	printf("1 - Adicionar informações do projeto\n\n2 - Informações do projeto\n\n3 - Encerrar o programa\n\n");
	printf("op: ");
	scanf(" %i", &contProg);

	switch(contProg){
		case 1:
			menuIns();
			break;
        case 2:
            menuInfo();
            break;
		case 3:
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
	printf("            Calculadora de indices GVA\n\n");
	printf("================insercao de dados=================\n\n");

	printf("Nome do Projeto: ");
	scanf("%s", &nmProj);

	printf("Orcamento (R$): "); //Define o valor do orçamento planejado para executar o projeto
	scanf("%s", &orc);
	dados->ont = atof(orc);

	printf("Prazo para termino(em meses): "); //Define o tempo maximo planejado para executar o projeto
	scanf("%s", &pzProj);
	dados->pzPr = atof(pzProj);

	printf("Periodo concretizado (em meses): "); //Define quanto tempo correu desde o inicio do projeto
	scanf("%s", &pcProj);
	dados->pcPr = atof(pcProj);

	printf("Porcentagem do projeto concretizada: "); //Define quanto tempo correu desde o inicio do projeto
	scanf("%s", &pRealProj);
	dados->perRea = atof(pRealProj) / 100;

	printf("Valor Gasto até o momento (R$): "); //Define o valor total gasto até o momento atual do projeto
	scanf("%s", &crProj);
	dados->cr = atof(crProj);

	dados = calcInd(dados);

	system("pause");
}


//Menu de informçãoes do projeto
void menuInfo() {
    dados = calcInd(dados);
    system("cls");
	printf("            Calculadora de indices GVA\n\n");
	printf("=================Dados do projeto=================\n\n");

    //Verifica se foi calculado os idices
	if(dados->idc == 0.0){
	    printf("\t%s\t\n\n", statusProjeto(dados));
	    printf("=================================================\n\n");
	    system("pause");
        return;
	}
	printf("Projeto: %s\n", nmProj);
	printData(dados);
	printf("\n===============Indices do projeto=================\n\n");
	printIndeces(dados);
	system("pause");
}
