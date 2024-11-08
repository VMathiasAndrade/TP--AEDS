#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaRocha.h"

int main(int argc, char const *argv[])
{
    ListaMinerais *LMinerais = (ListaMinerais*)malloc(sizeof(ListaMinerais));
    Mineral minerais;

    FLVaziaMine(LMinerais);

    InicializaMineral(&minerais, "Ferrolita", "Acinzentado", 0.5, 0.7);
    LInsereMine(LMinerais, minerais);
    InicializaMineral(&minerais, "Solarium", "Amerelado", 0.7, 0.6);
    LInsereMine(LMinerais, minerais);

    LImprimeMine(LMinerais);
    LRetiraMine(LMinerais, "Solarium", &minerais);
    LImprimeMine(LMinerais);
}
