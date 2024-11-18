#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sonda.h"

void InicializaSonda(Sonda *sonda, int id, double latitude, double longitude, char *EstaLigada)
{
    setIds(sonda, id);
    setLats(sonda, latitude);
    setLongs(sonda, longitude);
    setEstaLigadas(sonda, EstaLigada);
    FLVazia(&sonda->compartimento_sonda);
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

char *getEstaLigadas(Sonda *sonda)
{
    return sonda->EstaLigada;
}

void setIds(Sonda *sonda, int id)
{
    int x; 
    x=rand();

    sonda->id = x;
}
void setLats(Sonda *sonda, double latitude)
{
    sonda->latitude = latitude;
}
void setLongs(Sonda *sonda, double longitude)
{
    sonda->longitude = longitude;
}
void setEstaLigadas(Sonda *sonda, char *EstaLigada)
{
    strcpy(sonda->EstaLigada, EstaLigada);
}