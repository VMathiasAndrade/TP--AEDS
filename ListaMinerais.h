#ifndef LISTAMINERAIS_H
#define LISTAMINERAIS_H
#define MaxTam 1000
#include "Mineral.h"

typedef int Apontador;

typedef struct 
{
    Mineral ListaM[MaxTam];
    Apontador first, last;
}ListaMinerais;

void FLVazia(ListaMinerais* LMinerais);
int LEhVazia(ListaMinerais* LMinerais);
int LInsere(ListaMinerais* LMinerais, Mineral x);
int LRetira(ListaMinerais* LMinerais, char* nome, Mineral *pX);
void LImprime(ListaMinerais* LMinerais);

#endif