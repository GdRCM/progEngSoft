#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct indices{
	float ont, pzPr, pcPr, cr, vp, va, idp, idc, vdp, vdc, perCom, perRea;
	char status[40];
}ind;

void statusProjeto(ind i){
	
	if(i.idp = 1){ //testa se o o projeto está dentro do prazo
		if(i.idc = 1){ //testa se o projeto está dentro do orçamento
			strcpy(i.status, "dentro prazo e dentro do orcamento");
		}else if(i.idc < 1){ //testa se o projeto está acima do orçamento
			strcpy(i.status, "dentro do prazo e acima do orcamento");
		}else{ //o projeto está abaixo do orçamento!
			strcpy(i.status, "dentro do prazo e abaixo do orcamento");
		}
	}else if(i.idp < 1){ //testa se o o projeto está atrasado
		if(i.idc = 1){ //testa se o projeto está dentro do orçamento
			strcpy(i.status, "atrasado e dentro do orçamento");
		}else if(i.idc < 1){ //testa se o projeto está acima do orçamento
			strcpy(i.status, "atrasado e acima do orçamento");
		}else{ //o projeto está abaixo do orçamento!
			strcpy(i.status, "atrasado e abaixo do orçamento");
		}
	}else{ //o projeto está adiantado
		if(i.idc = 1){ //testa se o projeto está dentro do orçamento
			strcpy(i.status, "adiantado e dentro do orçamento");
		}else if(i.idc < 1){ //testa se o projeto está acima do orçamento
			strcpy(i.status, "adiantado e acima do orçamento");
		}else{ //o projeto está abaixo do orçamento!
			strcpy(i.status, "adiantado e abaixo do orçamento");
		}
	}
	
}

ind calcInd(ind i){

	i.perCom = i.pcPr/i.pzPr; //Calcula a % do projeto que deveria estar completa
	i.vp = i.ont * i.perCom; //Calcula o valor que deveria ter sido agregado até o presente momento no projeto
	i.va = i.ont * i.perRea; //Calcula o valor realmente agregao até o presente momento no projeto
	i.idp = i.va/i.vp; //calcula o indice de desempenho de prazo
	i.vdp = i.va - i.vp; //calcula a variação de prazo
	i.idc = i.va/i.cr; //calcula o indice de desempenho de custo
	i.vdc = i.va - i.cr; //calcula a variação de custo
	
	return i;
}
