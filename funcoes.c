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

//Imprime informações sobre os dados passados
void printData(ind *i) {
    printf("Orçamento do projeto (ONT): %.2f\n", i->ont);
    printf("Tempo total para termino: %.2f meses\n", i->pzPr);
    printf("Tempo decorrido: %.2f meses\n", i->pcPr);
    printf("Per. Real completa: %.2f\n", i->perRea);
    printf("Per. Planejada completa: %.2f\n", i->perCom);
    printf("Valor gasto (CR): %.2f\n", i->cr);
}

void printIndeces (ind *i) {
    printf("Valor agregado (VA): %.2f\n", i->va);
    printf("Valor planejado (VP): %.2f\n", i->vp);
    printf("Variação de prazo (VDP): %.2f\n", i->vdp);
    printf("Variação de custo (VDC): %.2f\n", i->vdc);
    printf("Indice de desempenho de prazo (IDP): %.2f\n", i->idp);
    printf("Indice de desempenho de custo (IDC): %.2f\n", i->idc);
}

char * statusProjeto(ind *i){
    //verifica se algum valor foi fornecido
    if (i->idp == 0.0) {
        return "Ainda nao foram inseridos dados";
    }

	if(i->idp == 1){ //testa se o o projeto está dentro do prazo
		if(i->idc == 1){ //testa se o projeto está dentro do orçamento
			strcpy(i->status, "Dentro prazo e dentro do orcamento");
		}else if(i->idc < 1){ //testa se o projeto está acima do orçamento
			strcpy(i->status, "Dentro do prazo e acima do orcamento");
		}else{ //o projeto está abaixo do orçamento!
			strcpy(i->status, "Dentro do prazo e abaixo do orcamento");
		}
	}else if(i->idp < 1){ //testa se o o projeto está atrasado
		if(i->idc == 1){ //testa se o projeto está dentro do orçamento
			strcpy(i->status, "Atrasado e dentro do orçamento");
		}else if(i->idc < 1){ //testa se o projeto está acima do orçamento
			strcpy(i->status, "Atrasado e acima do orçamento");
		}else{ //o projeto está abaixo do orçamento!
			strcpy(i->status, "Atrasado e abaixo do orçamento");
		}
	}else{ //o projeto está adiantado
		if(i->idc == 1){ //testa se o projeto está dentro do orçamento
			strcpy(i->status, "Adiantado e dentro do orçamento");
		}else if(i->idc < 1){ //testa se o projeto está acima do orçamento
			strcpy(i->status, "Adiantado e acima do orçamento");
		}else{ //o projeto está abaixo do orçamento!
			strcpy(i->status, "Adiantado e abaixo do orçamento");
		}
	}

	return i->status;

}

ind * calcInd(ind * i){

	i->perCom = i->pcPr/i->pzPr; //Calcula a % do projeto que deveria estar completa
	i->vp = i->ont * i->perCom; //Calcula o valor que deveria ter sido agregado até o presente momento no projeto
	i->va = i->ont * i->perRea; //Calcula o valor realmente agregao até o presente momento no projeto
	i->idp = i->va/i->vp; //calcula o indice de desempenho de prazo
	i->vdp = i->va - i->vp; //calcula a variação de prazo
	i->idc = i->va/i->cr; //calcula o indice de desempenho de custo
	i->vdc = i->va - i->cr; //calcula a variação de custo

	return i;
}
