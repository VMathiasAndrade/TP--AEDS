#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSondas.h"
#include <math.h>

double distancia_euclid(double lat_r, double long_r, double lat_i, double long_i);

int main() {
    FILE* arq = NULL;
    arq = fopen("teste.txt", "a+");
    if(arq == NULL){
        exit(0);
    }

    int N_Sondas;
    double lat_i, lon_i;
    float c_i, v_i, nc_i
    SLista sondas[N_Sondas];
    fscanf(arq, "%d", &N_Sondas);
    for (int i = 0; i < N_Sondas; i++)
    {
        fscanf(arq, "%lf %lf %f %f %f", &lat_i, &lon_i, &c_i, &v_i, &nc_i);
        
    }

    int N_op;
    double lat_r, long_r;
    float p_r;
    int id_s;
    char[20] rocha_coletada;
    float peso_r;
    fscanf(arq, "%d", &N_op);
    for (int i = 0; i < N_op; i++)
    {
        char tipo_op;
        fscanf(arq, "%c", &tipo_op);

        switch (tipo_op)
        {
        case 'R':
            char linha[255];
            fgets(linha, 255, arq);
            char* buffer = NULL;
            const char delim[2] = " ";
            
            buffer = strtok(linha, delim);
            lat_r = atof(buffer);
            buffer = strtok(NULL, delim);
            long_r = atof(buffer);
            buffer = strtok(NULL, delim);
            p_r = atof(buffer);
            
            int j = 0;
            ListaMinerais minerais[3];
            while (buffer != NULL)
            {
                buffer = strtok(NULL, delim);
                strcpy(minerais[i].ListaM->nome, buffer);
                i++;
            }
            distancia_euclid(lat_r, long_r, lat_i, long_i);
            break;
        case 'I':
            
            break;
        case 'E':
            break;
        
        default:
            printf("Funcao invalida.")
            break;
        }
    }
}


double distancia_euclid(double lat_r, double long_r, double lat_i, double long_i){
    double delta_lat = lat_r - lat_i;
    double delta_long = long_r - long_i;
    return srqt(delta_lat * delta_lat - delta_long * delta_long);
}