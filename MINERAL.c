#include <stdio.h>
#include <string.h>
#include "Mineral.h"

void InicializaMineral(Mineral* mineral, char *nome, char *cor, double dureza, double reativ) {
    setNome(mineral, nome);
    setCor(mineral, cor);
    setDureza(mineral, reativ);
    setReatividade(mineral, dureza);
}
Mineral RetornaMineral(char* nome){
    if (strcmp(nome, "Ferrolita") == 0) {printf("Mineral acinzentado com dureza de 0,5 e reatividade de 0,7 (magnetismo moderado)\n");}
    else if (strcmp(nome, "Solarium") == 0) {printf("Mineral amarelo, com dureza de 0,9 e reatividade de 0,2 (radioatividade estável)\n");}
    else if (strcmp(nome, "Aquavitae") == 0) { printf("Mineral azulado, com dureza de 0,5 e reatividade de 0,8 (compostos hidrofílicos)\n");}
    else if (strcmp(nome, "Terranita") == 0) {printf("Mineral marrom, com dureza de 0,7 e reatividade de 0,6 (silício e nutrientes)\n");}
    else if (strcmp(nome, "Calaris") == 0) {printf("Mineral vermelho, com dureza de 0,6 e reatividade de 0,5 (compostos reguladores de pH)\n");}
}

void setNome(Mineral* mineral, char* nome){
    strcpy(mineral->nome, nome);
}
void setCor(Mineral* mineral, char* cor){
    strcpy(mineral->cor, cor);
}
void setDureza(Mineral* mineral, double dureza){
    mineral->dureza = dureza;
}
void setReatividade(Mineral* mineral, double reativ){
    mineral->reativ = reativ;
}

char* getNome(Mineral* mineral){
    return mineral->nome;
}
char* getCor(Mineral* mineral){
    return mineral->cor;
}
double getDureza(Mineral* mineral) {
    return mineral->dureza;
}
double getReatividade(Mineral* mineral) {
    return mineral->reativ;
}