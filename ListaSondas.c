#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"

void FLVaziaSonda(SLista *slista)
{
    slista->pPrimeiro = (Apontador)malloc(sizeof(SCelula));
    slista->pUltimo = slista->pPrimeiro;
    slista->pPrimeiro->pProx = NULL;
}

void LInsereSonda(SLista *sLista, Sonda *pSonda)
{
    sLista->pUltimo->pProx = (Apontador)malloc(sizeof(SCelula));
    sLista->pUltimo = sLista->pUltimo->pProx;
    sLista->pUltimo->sonda= *pSonda;
    sLista->pUltimo->pProx=NULL;
}
void LRetiraSonda(SLista *sLista, Sonda id){
    Apontador pAnterior = sLista->pPrimeiro;
    Apontador pAtual = sLista->pUltimo;

    while(pAtual!=NULL){
        if(strcmp(pAtual->sonda.id, id)==0){
            pAnterior->pProx=pAtual->pProx;
            if(pAtual== sLista->pUltimo){
                sLista->pUltimo=pAnterior;
            }
            free(pAtual);
            return 1;
        }
        pAnterior=pAtual;
        pAtual=pAtual->pProx;
    }
    return 0;
}
void ImprimeLSonda(SLista *sLista){
    int cont=0;
    Apontador pAux;
    pAux=sLista->pPrimeiro->pProx;
    while(pAux!=NULL){
        printf("Sonda %d\n", cont++);
        printf("ID: %d\n", pAux->sonda.id);
        printf("Latitude e longitude: %f %f", pAux->sonda.latitude, pAux->sonda.longitude);
        printf("Status da sonda: %s", pAux->sonda.EstaLigada);
    }
}