#include <stdio.h>
#include <stdlib.h>

int contProg = 0;
float ont, cr, vp, va, idp, idc, vdp, vdc, perCom, perRea;
char nmProj[] = "Informe o nome do projeto", orc[] = "Informe o valor total do orçamento do projeto";
void menuPrinc();
void menuIns();

int main(int argc, char *argv[]) {
	system("mode con:cols=50 lines=15");
	while(contProg!=2){
		menuPrinc();
	}
	return 0;
}

void menuIns(){
	system("cls");
	printf("                 Nome do Programa\n");
	printf("================insercao de dados=================\n\n");
	printf("Projeto: %s\n",nmProj);
	scanf("%s", &nmProj);
	printf("Projeto: %s\n",orc);
	scanf("%s", &orc);
	ont = atof(orc);
	system("pause");
}

void menuPrinc(){
	system("cls");
	printf("                 Nome do Programa\n");
	printf("===================Tela inicial===================\n\n");
	printf("    Ainda nao foram inseridos dados de projeto    \n                a serem analisados\n\n");
	printf("==================================================\n");
	printf("\t\tSelecione uma opcao\n\n");
	
	printf("1 - Adicionar informacoes do projeto\n\n2 - Encerrar o programa\n");
	scanf(" %i", &contProg);
	
	switch(contProg){
		case 1: 
			printf("selecionou 1");
			menuIns();
			break;
		
		default: break;
	}
}
