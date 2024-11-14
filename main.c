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
    RetornaMineral(&mineral2, "Aquavitae");
    RetornaMineral(&mineral3, "Calaris");

    RochaMineral rocha, rocha1, rocha2, rocha3;
    
    FLVaziaMine(&rocha.LMinerais);
    LInsereMine(&rocha.LMinerais, mineral1);
    LInsereMine(&rocha.LMinerais, mineral2);
    LInsereMine(&rocha.LMinerais, mineral3);
    LImprimeMine(&rocha.LMinerais);

    InicializaRocha(&rocha, 124552, 12.0, DefCategoria(&rocha), "20/12/2024", -295536131.024, 25235.232);
    InicializaRocha(&rocha1, 410001, 30.0, "Calquer", "20/12/2024", -295536131.024, 25235.232);
    InicializaRocha(&rocha2, 124515, 19.0, "Terrolis", "19/12/2024", -1526131.024, 51252.232);
    InicializaRocha(&rocha3, 124522, 15.0, "Terrolis", "20/12/2024", -2026131.124, 21252.214);

    RCompartimento listaRocha;

    FLVazia(&listaRocha);
    LInsere(&listaRocha, &rocha);
    LInsere(&listaRocha, &rocha1);
    LInsere(&listaRocha, &rocha2);
    LInsere(&listaRocha, &rocha3);
    LRetira(&listaRocha, &rocha1);
    LTrocaR(&listaRocha);
    LImprime(&listaRocha);
    
    printf("Peso lista de minerais: %.2f\n", LPeso(&listaRocha));
    
    Sonda sonda1, sonda2;

    sonda1.Rocha = rocha3;
    sonda2.Rocha = rocha;

    SLista listaSondas;

    FLVaziaSonda(&listaSondas);
    LInsereSonda(&listaSondas, &sonda1);
    LInsereSonda(&listaSondas, &sonda2);
    ImprimeLSonda(&listaSondas);

    return 0;
}
