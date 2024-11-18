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
int LRetiraSonda(SLista *sLista, Sonda *pSonda)
{
    if (sLista == NULL || sLista->pPrimeiro == NULL)
    {
        return 0; // Trata lista vazia ou nula
    }

    ApontadorSonda pAnterior = NULL;
    ApontadorSonda pAtual = sLista->pPrimeiro;

    while (pAtual != NULL)
    {
        if (pAtual->sonda.id == pSonda->id)
        {
            if (pAnterior == NULL)
            {
                sLista->pPrimeiro = pAtual->pProx; // Remove o primeiro elemento
            }
            else
            {
                pAnterior->pProx = pAtual->pProx; // Remove elementos intermediários ou o último
            }

            if (pAtual == sLista->pUltimo)
            {
                sLista->pUltimo = pAnterior; // Atualiza o último ponteiro
            }

            free(pAtual);
            return 1;
        }
        pAnterior = pAtual;
        pAtual = pAtual->pProx;
    }
    return 0;
}
void ImprimeLSonda(SLista *sLista)
{
    int cont = 0;
    ApontadorSonda pAux;
    pAux = sLista->pPrimeiro;
    while (pAux != NULL)
    {
        printf("ID: %d\n", pAux->sonda.id);
        printf("AAAAAAAAAAA");
        printf("Rocha(s): %s\n", pAux->sonda.compartimento_sonda.pPrimeiro->rocha.categoria);
        printf("AAAAAAAAAAA");
        printf("Latitude e longitude: %f %f\n", pAux->sonda.latitude, pAux->sonda.longitude);
        printf("Status da sonda: %s\n\n", pAux->sonda.EstaLigada);

        pAux = pAux->pProx;
    }
}
/*void OperacaoI(SLista *sLista){
    SCelula* pAux;
    pAux= sLista->pPrimeiro->pProx;
    while(pAux != NULL){
        Sonda* p_sonda = &pAux->sonda;
        printf("ID: %d\n", p_sonda->id);
        printf("%.s, %.2f\n", p_sonda->compartimento_sonda.pPrimeiro->rocha.categoria, p_sonda->compartimento_sonda.pPrimeiro->rocha.peso);

        if (LEhVazia(&p_sonda->compartimento_sonda)) {
            printf("Compartimento Vazio. \n");
        }

        else {
            LImprime(&p_sonda->compartimento_sonda);
        } 

        pAux = pAux -> pProx;
    }

}   
*/
void MoveOrigem(SLista *sLista)
{
    int cont = 0;
    ApontadorSonda pAux;
    pAux = sLista->pPrimeiro;
    while (pAux != NULL)
    {
        pAux->sonda.latitude = 0.0;
        pAux->sonda.longitude = 0.0;
        pAux = pAux->pProx;
    }
}

