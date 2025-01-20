#include <stdio.h>
#include <stdlib.h>
#include <string.h>//.
#include "Compartimento.h"

void FLVazia(RCompartimento *rLista)
{
    rLista->pPrimeiro = (ApontadorRocha)malloc(sizeof(RCelula));
    rLista->pUltimo = rLista->pPrimeiro;
    rLista->pPrimeiro->pProx = NULL;
}

int LTamanho(RCompartimento *rLista)
{
    int cont = 0;
    ApontadorRocha pAux = rLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        cont += 1;
        pAux = pAux->pProx;
    }
    return cont;
}

int LEhVazia(RCompartimento *rLista)
{
    return (rLista->pPrimeiro == rLista->pUltimo);
}

int LInsere(RCompartimento *rLista, RochaMineral *pRocha)
{
    rLista->pUltimo->pProx = (ApontadorRocha)malloc(sizeof(RCelula));
    rLista->pUltimo = rLista->pUltimo->pProx;
    rLista->pUltimo->rocha = *pRocha;
    rLista->pUltimo->pProx = NULL;
    return 1;
}

void LImprime(RCompartimento *rLista)
{
    int cont = 1;
    ApontadorRocha pAux= NULL;
    pAux = rLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("Rocha %d\n", cont++);
        printf("ID: %d\n", pAux->rocha.id);
        printf("Peso: %.2f\n", pAux->rocha.peso);
        printf("Localizacao; %.5lf %.5lf\n", pAux->rocha.latitude, pAux->rocha.longitude);
        printf("Categoria: %s\n", pAux->rocha.categoria);
        printf("Data de Coleta: %s\n\n", pAux->rocha.dataColeta);

        pAux = pAux->pProx;
    }
}

int LRetira(RCompartimento *rLista, RochaMineral *pRocha)
{
    if (LEhVazia(rLista))
    {
        return 0;
    }

    ApontadorRocha pAnterior = NULL;
    ApontadorRocha pAtual = rLista->pPrimeiro;

    while (pAtual != NULL)
    {
        if (strcmp(pAtual->rocha.categoria, pRocha->categoria) == 0)
        {
            if (pAnterior == NULL)
            {
                rLista->pPrimeiro = pAtual->pProx;
                if (rLista->pPrimeiro == NULL)
                {
                    rLista->pUltimo = NULL;
                }
            }
            else
            {
                pAnterior->pProx = pAtual->pProx;
                if (pAtual == rLista->pUltimo)
                {
                    rLista->pUltimo = pAnterior;
                }
            }
            free(pAtual);
            return 1;
        }
        pAnterior = pAtual;
        pAtual = pAtual->pProx;
    }
    return 0;
}

void LTrocaR(RCompartimento *rLista)
{
    if (LEhVazia(rLista) || rLista->pPrimeiro->pProx == NULL)
    {
        return;
    }

    ApontadorRocha pAux = rLista->pPrimeiro->pProx;
    ApontadorRocha maisPesada = NULL;
    float maiorPeso = 0;

    while (pAux != NULL)
    {
        if (pAux->rocha.peso > maiorPeso)
        {
            maiorPeso = pAux->rocha.peso;
            maisPesada = pAux;
        }
        pAux = pAux->pProx;
    }

    if (maisPesada == NULL)
    {
        return;
    }

    char categoriaMaisPesada[40];
    strcpy(categoriaMaisPesada, maisPesada->rocha.categoria);

    ApontadorRocha maisLeve = NULL;
    ApontadorRocha anteriorMaisLeve = NULL;
    float menorPeso = -1;

    pAux = rLista->pPrimeiro->pProx;
    ApontadorRocha pAnt = rLista->pPrimeiro;
    while (pAux != NULL)
    {
        if (strcmp(pAux->rocha.categoria, categoriaMaisPesada) == 0)
        {
            if (menorPeso == -1 || pAux->rocha.peso < menorPeso)
            {
                menorPeso = pAux->rocha.peso;
                maisLeve = pAux;
                anteriorMaisLeve = pAnt;
            }
        }
        pAnt = pAux;
        pAux = pAux->pProx;
    }

    if (maisLeve == NULL)
    {
        return;
    }

    if (maisLeve != NULL && maisLeve != maisPesada && maisLeve->rocha.peso < maisPesada->rocha.peso)
    {
        RochaMineral temp = maisPesada->rocha;
        maisPesada->rocha = maisLeve->rocha;
        maisLeve->rocha = temp;

        if (anteriorMaisLeve == NULL)
        {
            rLista->pPrimeiro = maisLeve->pProx;
        }
        else
        {
            anteriorMaisLeve->pProx = maisLeve->pProx;
        }

        if (maisLeve == rLista->pUltimo)
        {
            rLista->pUltimo = anteriorMaisLeve;
        }
        free(maisLeve);
    }
}
void Selectionsort(RCompartimento *rLista)
{
    int tamanho, comparacoes, movi;
    float time;
    tamanho = LTamanho(rLista);
    ApontadorRocha i, j, min;
    RCompartimento aux;
    for(i=rLista->pPrimeiro->pProx; i!=NULL;i=i->pProx){
        min = i;
        for(j=i->pProx; j!=NULL; j=j->pProx){
            if(j->rocha.peso<min->rocha.peso){
                    min = j;
            }
        }
        if(min!=i){
            RochaMineral temp = i->rocha;
            i->rocha= min->rocha;
            min->rocha = temp;
        }
    }
    printf("Comparações: %d\n", comparacoes);
    printf("Movimentações: %d\n",movi);    
    printf("Tempo de execução: %f\n", time);
    printf("Algoritmo: SelectionSort \n");
}
void QuickSort(RCompartimento *rLista){
    int tamanho, comparacoes, movi;
    float time;
    tamanho = LTamanho(rLista);
    ApontadorRocha i, j, min;
    RCompartimento aux;
    for(i=rLista->pPrimeiro->pProx; i!=NULL;i=i->pProx){
        min = i;
        for(j=i->pProx; j!=NULL; j=j->pProx){
            if(j->rocha.peso<min->rocha.peso){
                    min = j;
            }
        }
        if(min!=i){
            RochaMineral temp = i->rocha;
            i->rocha= min->rocha;
            min->rocha = temp;
        }
    }
    printf("Comparações: %d\n", comparacoes);
    printf("Movimentações: %d\n",movi);    
    printf("Tempo de execução: %f\n", time);
    printf("Algoritmo: QuickSort \n");
}