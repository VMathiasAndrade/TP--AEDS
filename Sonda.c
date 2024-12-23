#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sonda.h"

void InicializaSonda(Sonda *sonda, int id, double latitude, double longitude, float capacidade, char *EstaLigada)
{
    setIds(sonda, id);
    setLats(sonda, latitude);
    setLongs(sonda, longitude);
    setCapacidade(sonda, capacidade);
    setEstaLigadas(sonda, EstaLigada);
    FLVazia(&sonda->cRocha);
}
void LigaSonda(Sonda *sonda)
{
    strcpy((*sonda).EstaLigada, "Sim");
}
void DesligaSonda(Sonda *sonda)
{
    strcpy((*sonda).EstaLigada, "Nao");
}
void MoveSonda(Sonda *sonda, double latitude, double longitude)
{
    setLats(sonda, latitude);
    setLongs(sonda, longitude);
}
float LPeso(Sonda *sonda)
{
    float pesoTotal = 0;
    if (sonda == NULL || sonda->cRocha.pPrimeiro->pProx == NULL) {
        return 0;
    }
    
    ApontadorRocha pAux = sonda->cRocha.pPrimeiro->pProx;
    while (pAux != NULL)
    {
        pesoTotal += pAux->rocha.peso;
        pAux = pAux->pProx;
    }
    return pesoTotal;
}

int getIds(Sonda *sonda)
{
    return sonda->id;
}
double getLats(Sonda *sonda)
{
    return sonda->latitude;
}
double getLongs(Sonda *sonda)
{
    return sonda->longitude;
}
float getCapacidade(Sonda *sonda)
{
    return sonda->capacidade;
}
char *getEstaLigadas(Sonda *sonda)
{
    return sonda->EstaLigada;
}

void setIds(Sonda *sonda, int id)
{
    sonda->id = id;
}
void setLats(Sonda *sonda, double latitude)
{
    sonda->latitude = latitude;
}
void setLongs(Sonda *sonda, double longitude)
{
    sonda->longitude = longitude;
}
void setCapacidade(Sonda *sonda, float capacidade)
{
    sonda->capacidade = capacidade;
}
void setEstaLigadas(Sonda *sonda, char *EstaLigada)
{
    strcpy(sonda->EstaLigada, EstaLigada);
}