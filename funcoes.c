#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct indices{
	float ont, pzPr, pcPr, cr, vp, va, idp, idc, vdp, vdc, perCom, perRea;
	char status[40];
}ind;

void statusProjeto(ind i){
	
	if(i.idp = 1){ //testa se o o projeto est� dentro do prazo
		if(i.idc = 1){ //testa se o projeto est� dentro do or�amento
			strcpy(i.status, "dentro prazo e dentro do orcamento");
		}else if(i.idc < 1){ //testa se o projeto est� acima do or�amento
			strcpy(i.status, "dentro do prazo e acima do orcamento");
		}else{ //o projeto est� abaixo do or�amento!
			strcpy(i.status, "dentro do prazo e abaixo do orcamento");
		}
	}else if(i.idp < 1){ //testa se o o projeto est� atrasado
		if(i.idc = 1){ //testa se o projeto est� dentro do or�amento
			strcpy(i.status, "atrasado e dentro do or�amento");
		}else if(i.idc < 1){ //testa se o projeto est� acima do or�amento
			strcpy(i.status, "atrasado e acima do or�amento");
		}else{ //o projeto est� abaixo do or�amento!
			strcpy(i.status, "atrasado e abaixo do or�amento");
		}
	}else{ //o projeto est� adiantado
		if(i.idc = 1){ //testa se o projeto est� dentro do or�amento
			strcpy(i.status, "adiantado e dentro do or�amento");
		}else if(i.idc < 1){ //testa se o projeto est� acima do or�amento
			strcpy(i.status, "adiantado e acima do or�amento");
		}else{ //o projeto est� abaixo do or�amento!
			strcpy(i.status, "adiantado e abaixo do or�amento");
		}
	}
	
}

ind calcInd(ind i){

	i.perCom = i.pcPr/i.pzPr; //Calcula a % do projeto que deveria estar completa
	i.vp = i.ont * i.perCom; //Calcula o valor que deveria ter sido agregado at� o presente momento no projeto
	i.va = i.ont * i.perRea; //Calcula o valor realmente agregao at� o presente momento no projeto
	i.idp = i.va/i.vp; //calcula o indice de desempenho de prazo
	i.vdp = i.va - i.vp; //calcula a varia��o de prazo
	i.idc = i.va/i.cr; //calcula o indice de desempenho de custo
	i.vdc = i.va - i.cr; //calcula a varia��o de custo
	
	return i;
}
