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

void FLVaziaSonda(SLista *ListaS);
int LInsereSonda(SLista *ListaS, Sonda *pSonda);
int LRetiraSonda(SLista *ListaS, Sonda *pSonda);
Sonda *DistEuclidiana(SLista *ListaS, double lat_r, double long_r, RochaMineral *rocha);
void InsereRochaS(SLista *ListaS, RochaMineral *rocha);
void ImprimeLSonda(SLista *ListaS);
void MoveOrigem(SLista *ListaS);
RochaMineral *copiaRocha(RochaMineral *rocha);
RochaMineral *extraiRochas(SLista *ListaS, int *numRochas);
int comparaRochas(const void *a, const void *b);
void distribuirRochas(SLista *ListaS, RochaMineral *rochas, int NumRochas);
void OperacaoE(SLista *ListaS);
#endif