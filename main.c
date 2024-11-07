#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaMinerais.h"

int main(int argc, char const *argv[])
{
    ListaMinerais *LMinerais = (ListaMinerais*)malloc(sizeof(ListaMinerais));
    Mineral minerais;

    FLVazia(LMinerais);

    InicializaMineral(&minerais, "Ferrolita", "Acinzentado", 0.5, 0.7);
    LInsere(LMinerais, minerais);
    InicializaMineral(&minerais, "Solarium", "Amerelado", 0.7, 0.6);
    LInsere(LMinerais, minerais);

    LImprime(LMinerais);
    LRetira(LMinerais, "Solarium", &minerais);
    LImprime(LMinerais);
}
