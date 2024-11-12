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

int getIds(Sonda* sonda);
double getLats(Sonda* sonda);
double getLongs(Sonda* sonda);
char* getEstaLigadas(Sonda* sonda);

void setIds(Sonda* sonda, int id);
void setLats(Sonda* sonda, double latitude);
void setLongs(Sonda* sonda, double longitude);
void setEstaLigadas(Sonda* sonda, char* EstaLigada);


#endif