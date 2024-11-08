#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaRocha.h"

int main() {
    RLista minhaLista;
    RochaMineral rocha1, rocha2, rocha3, rochaRemovida;
    Mineral mineral1, mineral2;

    // Inicializa a lista de rochas
    FLVazia(&minhaLista);

    // Inicializa minerais
    InicializaMineral(&mineral1, "Ferrolita", "Cinza", 0.5, 0.7);
    InicializaMineral(&mineral2, "Solarium", "Amarelo", 0.9, 0.2);

    // Inicializa rochas com alguns minerais
    InicializaRocha(&rocha1, 1, 5.2, "Calquer", "2024-04-26", -23.55052, -46.63331);
    LInsereMine(&(rocha1.LMinerais), mineral1);
    DefCategoria(&rocha1); // Define a categoria com base nos minerais


    InicializaRocha(&rocha2, 2, 2.8, "Aquaterra", "2024-04-27", -23.55277, -46.63611);
    LInsereMine(&(rocha2.LMinerais), mineral2);

    DefCategoria(&rocha2);

    InicializaRocha(&rocha3, 3, 7.1, "Terralis", "2024-04-28", -23.55501, -46.63992);
    LInsereMine(&(rocha3.LMinerais), mineral1);
    DefCategoria(&rocha3);



    // Insere as rochas na lista
    LInsere(&minhaLista, &rocha1);
    LInsere(&minhaLista, &rocha2);
    LInsere(&minhaLista, &rocha3);

    // Imprime a lista inicial
    printf("Lista inicial:\n");
    LImprime(&minhaLista);


    // Testa a função LTrocaR
    LTrocaR(&minhaLista);
    printf("\nLista após LTrocaR:\n");
    LImprime(&minhaLista);


    // Testa RetornaPesoAtual
    printf("\nPeso total: %.2f\n", LPeso(&minhaLista));

    // Testa LRetira
    if (LRetira(&minhaLista, "Calquer")) {
        printf("\nRocha removida (ID %d):\n", rochaRemovida.id);
        // Imprima os dados da rocha removida aqui, se necessário
    } else {
        printf("\nRocha não encontrada.\n");
    }

    printf("\nLista após LRetira:\n");
    LImprime(&minhaLista);


    // Testa LRetiraPorCategoria
    if (LRetira(&minhaLista, "")) {
        printf("\nRocha da categoria 'Sedimentar' removida.\n");
    } else {
        printf("\nNenhuma rocha da categoria 'Sedimentar' encontrada.\n");
    }

    printf("\nLista final:\n");
    LImprime(&minhaLista);

    return 0;
}