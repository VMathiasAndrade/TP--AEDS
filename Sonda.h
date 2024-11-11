#ifndef SONDA_H
#define SONDA_H
#include "Compartimento.h"

typedef struct 
{
    int id;
    double latitude, longitude;
    char EstaLigada[3];
    RochaMineral Rocha;//Olhar na monitoria qual variavel sera usada como "compartimento" da sonda
}Sonda;    

void InicializaSonda(Sonda* sonda, int id, double latitude, double longitude, char* EstaLigada, RochaMineral* Rocha);
void LigaSonda(Sonda* sonda, char* EstaLigada);
void DesligaSonda(Sonda* sonda, char* EstaLigada);
void MoveSonda(Sonda* sonda, double latitude, double longitude);

int getId(Sonda* sonda);
double getLat(Sonda* sonda);
double getLong(Sonda* sonda);
char* getEstaLigada(Sonda* sonda);

void setId(Sonda* sonda, int id);
void setLat(Sonda* sonda, double latitude);
void setLong(Sonda* sonda, double longitude);
void setEstaLigada(Sonda* sonda, char* EstaLigada);


#endif