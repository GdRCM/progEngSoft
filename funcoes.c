#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void inicializar(ind * data) {
    data->idc = 0.0;
    data->idp = 0.0;
    data->va = 0.0;
    data->vp = 0.0;
    data->vdp = 0.0;
    data->perRea = 0.0;
    data->perCom = 0.0;
}

//Imprime informa��es sobre os dados passados
void printData(ind *i) {
    printf("Or�amento do projeto (ONT): %.2f\n", i->ont);
    printf("Tempo total para termino: %.2f meses\n", i->pzPr);
    printf("Tempo decorrido: %.2f meses\n", i->pcPr);
    printf("Per. Real completa: %.2f\n", i->perRea);
    printf("Per. Planejada completa: %.2f\n", i->perCom);
    printf("Valor gasto (CR): %.2f\n", i->cr);
}

void printIndeces (ind *i) {
    printf("Valor agregado (VA): %.2f\n", i->va);
    printf("Valor planejado (VP): %.2f\n", i->vp);
    printf("Varia��o de prazo (VDP): %.2f\n", i->vdp);
    printf("Varia��o de custo (VDC): %.2f\n", i->vdc);
    printf("Indice de desempenho de prazo (IDP): %.2f\n", i->idp);
    printf("Indice de desempenho de custo (IDC): %.2f\n", i->idc);
}

char * statusProjeto(ind *i){
    //verifica se algum valor foi fornecido
    if (i->idp == 0.0) {
        return "Ainda nao foram inseridos dados";
    }

	if(i->idp == 1){ //testa se o o projeto est� dentro do prazo
		if(i->idc == 1){ //testa se o projeto est� dentro do or�amento
			strcpy(i->status, "Dentro prazo e dentro do orcamento");
		}else if(i->idc < 1){ //testa se o projeto est� acima do or�amento
			strcpy(i->status, "Dentro do prazo e acima do orcamento");
		}else{ //o projeto est� abaixo do or�amento!
			strcpy(i->status, "Dentro do prazo e abaixo do orcamento");
		}
	}else if(i->idp < 1){ //testa se o o projeto est� atrasado
		if(i->idc == 1){ //testa se o projeto est� dentro do or�amento
			strcpy(i->status, "Atrasado e dentro do or�amento");
		}else if(i->idc < 1){ //testa se o projeto est� acima do or�amento
			strcpy(i->status, "Atrasado e acima do or�amento");
		}else{ //o projeto est� abaixo do or�amento!
			strcpy(i->status, "Atrasado e abaixo do or�amento");
		}
	}else{ //o projeto est� adiantado
		if(i->idc == 1){ //testa se o projeto est� dentro do or�amento
			strcpy(i->status, "Adiantado e dentro do or�amento");
		}else if(i->idc < 1){ //testa se o projeto est� acima do or�amento
			strcpy(i->status, "Adiantado e acima do or�amento");
		}else{ //o projeto est� abaixo do or�amento!
			strcpy(i->status, "Adiantado e abaixo do or�amento");
		}
	}

	return i->status;

}

ind * calcInd(ind * i){

	i->perCom = i->pcPr/i->pzPr; //Calcula a % do projeto que deveria estar completa
	i->vp = i->ont * i->perCom; //Calcula o valor que deveria ter sido agregado at� o presente momento no projeto
	i->va = i->ont * i->perRea; //Calcula o valor realmente agregao at� o presente momento no projeto
	i->idp = i->va/i->vp; //calcula o indice de desempenho de prazo
	i->vdp = i->va - i->vp; //calcula a varia��o de prazo
	i->idc = i->va/i->cr; //calcula o indice de desempenho de custo
	i->vdc = i->va - i->cr; //calcula a varia��o de custo

	return i;
}
