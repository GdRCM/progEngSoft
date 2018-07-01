#include <stdio.h>
#include <stdlib.h>

typedef struct indices{
	float ont, pzPr, pcPr, cr, vp, va, idp, idc, vdp, vdc, perCom, perRea;
}ind;

ind calcInd(ind i){
	i.perCom = i.pcPr/i.pzPr; //Calcula a % do projeto que deveria estar completa
	return i;
}
