#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ListaSondas.h"

void FLVaziaSonda(SLista* slista) {
    slista->pPrimeiro = (ApontadorSonda)malloc(sizeof(SCelula));
    slista->pUltimo = slista->pPrimeiro;
    slista->pPrimeiro->pProx = NULL;
}

int LInsereSonda(SLista* sLista, Sonda *pSonda) {
    sLista->pUltimo->pProx = (ApontadorSonda)malloc(sizeof(SCelula));
    sLista->pUltimo = sLista->pUltimo->pProx;
    sLista->pUltimo->sonda = *pSonda;
    sLista->pUltimo->pProx = NULL;
    return 1;
}

int LRetiraSonda(SLista* sLista, Sonda *pSonda) {
    if (sLista == NULL || sLista->pPrimeiro == NULL)
    {
        return 0; // Trata lista vazia ou nula
    }

    ApontadorSonda pAnterior = NULL;
    ApontadorSonda pAtual = sLista->pPrimeiro;

    while (pAtual != NULL) {
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

void ImprimeLSonda(SLista* sLista) {
    int cont = 0;
    ApontadorSonda pAux = pAux = sLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("ID: %d\n", pAux->sonda.id);
        printf("Rocha(s): %s\n", pAux->sonda.cRocha.pPrimeiro->rocha.categoria);
        printf("Latitude e longitude: %f %f\n", pAux->sonda.latitude, pAux->sonda.longitude);
        printf("Status da sonda: %s\n\n", pAux->sonda.EstaLigada);

        pAux = pAux->pProx;
    }
}

Sonda* DistElclidiana(SLista* ListaS, double lat_r, double long_r) {
    SCelula* pAux = ListaS->pPrimeiro->pProx;
    Sonda* pSonda;
    double lat_i, long_i;
    float menorDist = 1000000, distSonda = 0;

    while (pAux != NULL) {
        lat_i = pAux->sonda.latitude;
        long_i = pAux->sonda.longitude;
        distSonda = sqrt(pow(lat_r - lat_i, 2) + pow(long_r - long_i, 2));
        if (menorDist >= distSonda) {
            menorDist = distSonda;
            pSonda = &pAux->sonda;
        }
        pAux = pAux->pProx;
    }
    return pSonda;
}

void InsereRochaS(SLista* ListaS, RochaMineral* rocha){
    Sonda *sondaTemp = NULL;
    double lat_r = rocha->latitude;
    double long_r = rocha->longitude;
    
    ApontadorSonda pAux = ListaS->pPrimeiro->pProx;
    Sonda *sonda = NULL;

    while (pAux != NULL) {
        sonda = &pAux->sonda;
        float vCapacidade = LPeso(sonda) - rocha->peso;

        if (vCapacidade >= rocha->peso) {
            sondaTemp = DistElclidiana(ListaS, lat_r, long_r);
        }
        pAux = pAux->pProx;
    }
    if (sondaTemp == NULL) {
        printf("Nao ha sonda perto!\n");
    }
    sondaTemp->latitude = rocha->longitude;
    sondaTemp->longitude = rocha->longitude;

    if (sondaTemp->cRocha.pPrimeiro == NULL) {
        sondaTemp->cRocha.pPrimeiro = (RCelula*)malloc(sizeof(RCelula));
        sondaTemp->cRocha.pUltimo = sondaTemp->cRocha.pPrimeiro;
    }

    RCelula *nRocha = (RCelula*)malloc(sizeof(RCelula));
    nRocha->rocha = *rocha;
    nRocha->pProx = NULL;

    if (sondaTemp->cRocha.pPrimeiro == NULL) {
        sondaTemp->cRocha.pPrimeiro == nRocha;
        sondaTemp->cRocha.pUltimo == nRocha;
    } else {
        sondaTemp->cRocha.pUltimo->pProx = nRocha;
        sondaTemp->cRocha.pUltimo = nRocha;
    }
    sonda->capacidade -= rocha->peso;

    printf("-------Sonda Coletada-------");
    printf("Rocha coletada pela sonda: %d\n", sondaTemp->id);
}

void MoveOrigem(SLista* ListaS) {
    int cont = 0;
    ApontadorSonda pAux;
    pAux = ListaS->pPrimeiro;
    while (pAux != NULL)
    {
        pAux->sonda.latitude = 0.0;
        pAux->sonda.longitude = 0.0;
        pAux = pAux->pProx;
    }
}

