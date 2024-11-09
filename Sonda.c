#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

void InicializaSonda(Sonda* sonda, int id, double latitude, double longitude, char* EstaLigada, RochaMineral* Rocha){
    setId(sonda, id);
    setLat(sonda, latitude);
    setLong(sonda, longitude);
    strcpy((*sonda).EstaLigada, "Nao");
}
void LigaSonda(Sonda* sonda, char* EstaLigada){
    strcpy((*sonda).EstaLigada, "Sim");
}
void DesligaSonda(Sonda* sonda, char* EstaLigada){
    strcpy((*sonda).EstaLigada, "Nao");
}
void MoveSonda(Sonda* sonda, double latitude, double longitude){
    setLat(sonda, latitude);
    setLong(sonda, longitude);
}