#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

int main() {
    Mineral mineral1;
    Mineral mineral2;
    Mineral mineral3;

    RetornaMineral(&mineral1, "Ferrolita");
    RetornaMineral(&mineral1, "Aquavitae");
    RetornaMineral(&mineral1, "Calaris");

    ListaMinerais minerais;
    RochaMineral rocha;
    
    FLVaziaMine(&minerais);
    LInsereMine(&minerais, mineral1);
    LInsereMine(&minerais, mineral2);
    LInsereMine(&minerais, mineral3);
    LImprimeMine(&minerais);

    return 0;
}