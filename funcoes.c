#include <stdio.h>
#include <stdlib.h>

typedef struct indices{
	float ont, pzPr, pcPr, cr, vp, va, idp, idc, vdp, vdc, perCom, perRea;
	char status[];
}ind;

char statusProjeto(ind i){
	if(i.idp i.idc)
	
	return s
}

ind calcInd(ind i){

	i.perCom = i.pcPr/i.pzPr; //Calcula a % do projeto que deveria estar completa
	i.vp = i.ont * i.perCom; //Calcula o valor que deveria ter sido agregado at� o presente momento no projeto
	i.va = i.ont * i.perRea; //Calcula o valor realmente agregao at� o presente momento no projeto
	i.idp = i.va/i.vp; //calcula o indice de desempenho de prazo
	i.vdp = i.va - i.vp; //calcula a varia��o de prazo
	i.idc = i.va/i.cr; //calcula o indice de desempenho de custo
	i.vdc = i.va - i.cr; //calcula a varia��o de custo
	i.status = statusProjeto(); //define a situa��o do projeto
	return i;
}
