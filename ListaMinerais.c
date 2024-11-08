#include <stdio.h>
#include <string.h>
#include "ListaMinerais.h"

void FLVaziaMine(ListaMinerais* LMinerais){
    LMinerais->first = 0;
    LMinerais->last = LMinerais->first;
}

int LEhVaziaMine(ListaMinerais* LMineirais){
    return (LMineirais->last == LMineirais->first);
}

int LInsereMine(ListaMinerais* LMinerais, Mineral x){
    if(LMinerais->last == MaxTam) return 0;
    LMinerais->ListaM[LMinerais->last++] = x;
    return 1;
}

int LRetiraMine(ListaMinerais* LMinerais, char* nome, Mineral *pX){
    int i, cont;
    
    for (i = 0; i < LMinerais->last; i++) {
        if (strcmp(LMinerais->ListaM[i].nome, nome) == 0) {
            *pX = LMinerais->ListaM[i];

            LMinerais->last--;

            for (cont = i + 1; cont <= LMinerais->last; cont++) {
                LMinerais->ListaM[cont - 1] = LMinerais->ListaM[cont];
            }

            return 1;
        }
    }
    return 0;
}

void LImprimeMine(ListaMinerais* LMinerias){
    int i;

    printf("Info dos minerais:\n");
    for (i = LMinerias->first; i < LMinerias->last; i++) {
        printf("Nome: %s\n", LMinerias->ListaM[i].nome);
        printf("Cor: %s\n", LMinerias->ListaM[i].cor);
        printf("Dureza: %.3lf\n", LMinerias->ListaM[i].dureza);
        printf("Reatividade: %.3lf\n\n", LMinerias->ListaM[i].reativ);
    }
}