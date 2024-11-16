#ifndef LISTASONDAS_H
#define LISTASONDAS_H
#include "Sonda.h"

typedef Sonda TipoSonda;

typedef struct CelulaSonda* ApontadorSonda;
typedef struct CelulaSonda
{
    Sonda sonda;
    struct CelulaSonda* pProx;
} SCelula;

typedef struct{
    ApontadorSonda pPrimeiro;
    ApontadorSonda pUltimo;
}SLista;

void FLVaziaSonda(SLista* sLista);
int LInsereSonda(SLista* sLista, Sonda* pSonda);
int LRetiraSonda(SLista* sLista, Sonda *pSonda);
void ImprimeLSonda(SLista* sLista);
void ImprimeLSondaID(SLIsta* sLista);
void MoveOrigem(SLista* sLista);
void RedistribuirRocha(SLista* sLista);
#endif