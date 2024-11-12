#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"

int main() {
    // Testando TAD Mineral
    Mineral mineral1, mineral2;
    InicializaMineral(&mineral1, "Ferrolita", "Acinzentado", 0.5, 0.7); // Inicializa com valores padrão
    RetornaMineral(&mineral1, "Ferrolita"); // Define os valores corretos
    InicializaMineral(&mineral2, "Solarium", "Amarelado", 0.9, 0.2);
    RetornaMineral(&mineral2, "Solarium");

    printf("Mineral 1: %s, %s, Dureza: %.1f, Reatividade: %.1f\n", 
           getNome(&mineral1), getCor(&mineral1), getDureza(&mineral1), getReatividade(&mineral1));
    printf("Mineral 2: %s, %s, Dureza: %.1f, Reatividade: %.1f\n",
           getNome(&mineral2), getCor(&mineral2), getDureza(&mineral2), getReatividade(&mineral2));

    ListaMinerais listaMinerais;
    FLVaziaMine(&listaMinerais);
    LInsereMine(&listaMinerais, mineral1);
    LInsereMine(&listaMinerais, mineral2);
    LImprimeMine(&listaMinerais);

    return 0;
}
    /*
    Mineral mineralRemovida;
    if (LRetiraMine(&listaMinerais, "Ferrolita", &mineralRemovida)) {
        printf("Mineral removido: %s\n", getNome(&mineralRemovida));
    }
    LImprimeMine(&listaMinerais);

    // Testando TAD RochaMineral
    RochaMineral rocha1;
    InicializaRocha(&rocha1, 1, 2.5, "Desconhecida", "2024-07-27", -22.8174, -43.2506);
    FLVaziaMine(&(rocha1.LMinerais));
    LInsereMine(&(rocha1.LMinerais), mineral2);
    DefCategoria(&rocha1); // Depois de inserir minerais

    printf("\nRocha 1:\nID: %d, Peso: %.1f, Categoria: %s, Data: %s, Localização: %.4f, %.4f\n",
           getIdentificador(&rocha1), getPeso(&rocha1), getCategoria(&rocha1), 
           getDataColeta(&rocha1), getLatitude(&rocha1), getLongitude(&rocha1));

     RochaMineral rocha2;
    InicializaRocha(&rocha2, 2, 3.0f, "Desconhecida", "2024-07-28", -22.9, -43.2);    


    // Testando TAD Compartimento
    RCompartimento compartimento;
    FLVazia(&compartimento);
    LInsere(&compartimento, &rocha1);
     LInsere(&compartimento, &rocha2);

    printf("Tamanho do compartimento %d\n", LTamanho(&compartimento));
    printf("Peso do compartimento %.2f\n", LPeso(&compartimento));
    printf("\nCompartimento antes da troca:\n");
    LImprime(&compartimento);

    LTrocaR(&compartimento); //testando a troca

    printf("\nCompartimento depois da troca:\n");
    LImprime(&compartimento);


    RochaMineral rochaRemovida;
        if(LRetira(&compartimento, &rocha1)){
            printf("\nRocha removida com sucesso\n");
        }

    printf("\nCompartimento depois da remoção:\n");
    LImprime(&compartimento);

    // Testando TAD Sonda
    Sonda sonda1;
    InicializaSonda(&sonda1, 101, -22.9, -43.2, "", &rocha1);
    LigaSonda(&sonda1, "Sim");
    MoveSonda(&sonda1, -22.9022, -43.2081);
     printf("\nSonda 1:\nID: %d, Ligada: %s, Localização: %.4f, %.4f\n",
           getId(&sonda1), getEstaLigada(&sonda1), getLat(&sonda1), getLong(&sonda1));

    //Testando TAD ListaSondas
    SLista listaSondas;
    FLVaziaSonda(&listaSondas);
    LInsereSonda(&listaSondas, &sonda1);
    Sonda sonda2;
    InicializaSonda(&sonda2, 102, -23, -44, "Nao", &rocha2);
    LInsereSonda(&listaSondas, &sonda2);


    printf("\nLista de Sondas:\n");
    ImprimeLSonda(&listaSondas);

     if (LRetiraSonda(&listaSondas, &sonda1)) {
        printf("\nSonda removida com sucesso!\n");
    }

    printf("\nLista de Sondas após remoção:\n");
    ImprimeLSonda(&listaSondas);



    return 0;
}
*/