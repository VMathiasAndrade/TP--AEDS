#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

//funções auxiliares//
void OperacaoE(SLista *sLista, int numSondas) {
    // Passo 1: Mover todas as sondas para (0,0) Ok
    ApontadorSonda pAtual = sLista->pPrimeiro;
    while (pAtual != NULL) {
        pAtual->sonda.latitude = 0.0;
        pAtual->sonda.longitude = 0.0;
        pAtual = pAtual->pProx;
    }

    // Passo 2: Calcular o peso total e redistribuir 
    double pesoTotal = 0.0;
    int sondaCount = 0;
    pAtual = sLista->pPrimeiro;
    
    // Calculando o peso total das rochas em todas as sondas OK 
    while (pAtual != NULL) {
        pesoTotal += pAtual->sonda.Rocha.peso; 
        sondaCount++;
        pAtual = pAtual->pProx;
    }

    // Peso ideal por sonda OK
    double pesoIdeal = pesoTotal / sondaCount;

    // Redistribuir as rochas entre as sondas
    pAtual = sLista->pPrimeiro;
    while (pAtual != NULL) {
        // Lógica de redistribuição para equilibrar os pesos - fazer
        
        pAtual = pAtual->pProx;
    }

    printf("Operação E concluída. Todas as sondas movidas para (0,0) e pesos redistribuídos.\n");
}





int main() {
    int Escolha = 0;
    while(Escolha != 1 && Escolha != 2){
        printf("Arquivo de entrada (1 - Terminal, 2 - Arquivo): \n");
        scanf("%d", &Escolha);
    }

    if (Escolha == 1)
    {
        int N_Sondas;
        double lat_i, long_i;
        float c_i, v_i, nc_i;
        printf("Digite o numero de sondas: ");
        scanf("%d", &N_Sondas);
        for(int i = 0; i <= N_Sondas; i++){
            printf("Digite os dados das sondas: (latitude, longitude, capacidade maxima, velocidade e combustivel)\n");
            scanf("%lf %lf %f %f %f", &lat_i, &long_i, &c_i, &v_i, &nc_i);
        }

        int N_op;
        printf("Digite o numero de operacoes: \n");
        scanf("%d", &N_op);
        for(int i = 0; i <= N_op; i++){
            char operacao;
            printf("Digite a operacao: \n");
            scanf("%c", &operacao);

            switch (operacao) {
            case 'R':{

                double lat_i, long_i;
                float p_i;
                char cat_i[50];
                char minerais_str[255] = "";
                char* buffer; 
                char linha[255];

                printf("Digite a latitude, longitude, peso, categoria e ate 3 minerais (SEPARE POR ESPACO): \n");

                fgets(linha, sizeof(linha), stdin);
                linha[strcspn(linha, "\n")] = '\0';
                   
                buffer = strtok(linha, " ");
                if (buffer != NULL) lat_i = atof(buffer); else { printf("Erro: Latitude inválida\n"); break;}
                buffer = strtok(NULL, " ");
                if (buffer != NULL) long_i = atof(buffer); else { printf("Erro: Longitude inválida\n"); break;}
                buffer = strtok(NULL, " ");
                if (buffer != NULL) p_i = atof(buffer); else { printf("Erro: Peso inválido\n"); break;}
                buffer = strtok(NULL, " ");
                if (buffer != NULL) strcpy(cat_i, buffer); else { printf("Erro: Categoria inválida\n"); break;
    }
    
                
                
 
                printf("%lf %lf %.2f %s %s\n", lat_i, long_i, p_i, cat_i, minerais_str);

                break;
            }
            case 'I':


                break;
            case 'E': {
    double pesoTotal = 0.0;
    int numSondas = 0;

    // Passo 1: Mover todas as sondas para (0,0)
    ApontadorSonda pAtual = sLista->pPrimeiro;
    while (pAtual != NULL) {
        pAtual->sonda.latitude = 0.0;
        pAtual->sonda.longitude = 0.0;
        pesoTotal += calcularPesoSonda(&(pAtual->sonda)); // Calcular peso total
        numSondas++;
        pAtual = pAtual->pProx;
    }

    // Passo 2: Redistribuir pesos
    if (numSondas > 0) {
        double pesoIdeal = pesoTotal / numSondas;
        redistribuirRochas(sLista, pesoIdeal);
        printf("Redistribuição concluída. Peso ideal por sonda: %.2f\n", pesoIdeal);
    } else {
        printf("Nenhuma sonda disponível para redistribuição.\n");
    }

    break;
}

}
               break;
        
            }
        }

            return 0;

    }
    
    

