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
        printf("Latitude e longitude: %.6f %.6f\n", pAux->sonda.latitude, pAux->sonda.longitude);
        printf("Capacidade: %.2f\n", pAux->sonda.capacidade);
        printf("Status da sonda: %s\n\n", pAux->sonda.EstaLigada);

        pAux = pAux->pProx;
    }
}

Sonda* DistElclidiana(SLista* ListaS, double lat_r, double long_r, RochaMineral* rocha) {
    SCelula* pAux = ListaS->pPrimeiro->pProx;
    Sonda* primeiraSonda = NULL;
    Sonda* segundaSonda = NULL;
    double menorDist = 1000000, segundaMenorDist = 1000000;
    double lat_i, long_i, distSonda;

    while (pAux != NULL) {
        lat_i = pAux->sonda.latitude;
        long_i = pAux->sonda.longitude;
        distSonda = sqrt(pow(lat_r - lat_i, 2) + pow(long_r - long_i, 2));

        if (distSonda < menorDist) {
            segundaMenorDist = menorDist;
            segundaSonda = primeiraSonda;
            menorDist = distSonda;
            primeiraSonda = &pAux->sonda;
        } else if (distSonda < segundaMenorDist) {
            segundaMenorDist = distSonda;
            segundaSonda = &pAux->sonda;
        }
        pAux = pAux->pProx;
    }

    if (primeiraSonda != NULL && LPeso(primeiraSonda) + rocha->peso <= primeiraSonda->capacidade) {
        return primeiraSonda;
    } else if (segundaSonda != NULL && LPeso(segundaSonda) + rocha->peso <= segundaSonda->capacidade) {
        return segundaSonda;
    } else {
        return primeiraSonda; // Retorna a primeira sonda para o caso 2 (troca de rochas)
    }
}

void InsereRochaS(SLista* ListaS, RochaMineral* rocha){
    Sonda *sondaTemp = DistElclidiana(ListaS, rocha->latitude, rocha->longitude, rocha);

    if (sondaTemp == NULL) {
        printf("Nao ha sonda perto!\n");
        return; // Sai da função se não houver sonda próxima
    }

    if (LPeso(sondaTemp) + rocha->peso > sondaTemp->capacidade) {
        // Caso 1: Capacidade insuficiente, tenta trocar por rocha mais pesada
        ApontadorRocha pAux = sondaTemp->cRocha.pPrimeiro->pProx;
        ApontadorRocha rochaMaisPesada = NULL;
        float maiorPeso = 0;

        while (pAux != NULL) {
            if (strcmp(pAux->rocha.categoria, rocha->categoria) == 0 && pAux->rocha.peso > maiorPeso) {
                maiorPeso = pAux->rocha.peso;
                rochaMaisPesada = pAux;
            }
            pAux = pAux->pProx;
        }

        if (rochaMaisPesada != NULL && rochaMaisPesada->rocha.peso > rocha->peso) {
            rochaMaisPesada->rocha = *rocha; // Substitui a rocha mais pesada
            printf("Rocha coletada pela sonda %d (troca por rocha mais pesada).\n", sondaTemp->id);
             return; // Sai da função após a troca bem-sucedida
        } else {
             printf("Impossivel coletar ou trocar rochas. Rocha descartada.\n");
             return; // Sai da função se a troca não for possível
        }
    } else {
        // Caso 2: Capacidade suficiente, insere a rocha normalmente
        sondaTemp->latitude = rocha->latitude;
        sondaTemp->longitude = rocha->longitude;
         if (LInsere(&sondaTemp->cRocha, rocha)) {
            printf("\nRocha coletada pela sonda: %d\n", sondaTemp->id);
         } else {
            printf("\nErro ao inserir rocha na sonda %d.\n", sondaTemp->id);
        }
    }
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

