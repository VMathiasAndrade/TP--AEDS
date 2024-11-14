#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"

void FLVaziaSonda(SLista *slista)
{
    slista->pPrimeiro = (ApontadorSonda)malloc(sizeof(SCelula));
    slista->pUltimo = slista->pPrimeiro;
    slista->pPrimeiro->pProx = NULL;
}

int LInsereSonda(SLista *sLista, Sonda *pSonda)
{
    sLista->pUltimo->pProx = (ApontadorSonda)malloc(sizeof(SCelula));
    sLista->pUltimo = sLista->pUltimo->pProx;
    sLista->pUltimo->sonda = *pSonda;
    sLista->pUltimo->pProx = NULL;
    return 1;
}
int LRetiraSonda(SLista *sLista, Sonda *pSonda){
    if (sLista == NULL || sLista->pPrimeiro == NULL) {
        return 0; // Trata lista vazia ou nula
    }

    ApontadorSonda pAnterior = NULL;
    ApontadorSonda pAtual = sLista->pPrimeiro;

    while(pAtual != NULL){
        if(pAtual->sonda.id == pSonda->id){
            if (pAnterior == NULL) {
                sLista->pPrimeiro = pAtual->pProx; // Remove o primeiro elemento
            } else {
                pAnterior->pProx = pAtual->pProx; // Remove elementos intermediários ou o último
            }

            if (pAtual == sLista->pUltimo) {
                sLista->pUltimo = pAnterior;  // Atualiza o último ponteiro
            }

            free(pAtual);
            return 1;
        }
        pAnterior = pAtual;
        pAtual = pAtual->pProx;
    }
    return 0;
}
void ImprimeLSonda(SLista *sLista){
    int cont=0;
    ApontadorSonda pAux;
    pAux=sLista->pPrimeiro->pProx;
    while(pAux!=NULL){
        printf("Sonda %d\n", cont++);
        printf("ID: %d\n", pAux->sonda.id);
        printf("Latitude e longitude: %f %f\n", pAux->sonda.latitude, pAux->sonda.longitude);
        printf("Status da sonda: %s\n\n", pAux->sonda.EstaLigada);
        pAux = pAux->pProx;
    }
}