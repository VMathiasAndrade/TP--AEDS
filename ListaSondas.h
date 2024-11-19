#ifndef LISTASONDAS_H
#define LISTASONDAS_H
#include "Sonda.h"

typedef Sonda TipoSonda;

typedef struct CelulaSonda *ApontadorSonda;
typedef struct CelulaSonda 
{
    Sonda sonda;
    struct CelulaSonda *pProx;
} SCelula;

typedef struct
{
    ApontadorSonda pPrimeiro;
    ApontadorSonda pUltimo;
} SLista;

void FLVaziaSonda(SLista* ListaS);
int LInsereSonda(SLista* ListaS, Sonda *pSonda);
int LRetiraSonda(SLista* ListaS, Sonda *pSonda);
Sonda* DistElclidiana(SLista* ListaS, double lat_r, double long_r);
void InsereRochaS(SLista* ListaS, RochaMineral* rocha);
void ImprimeLSonda(SLista* ListaS);
void MoveOrigem(SLista* ListaS);
void OperacaoI(SLista* ListaS);
#endif