#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mineral.h"

void InicializaMineral(Mineral *mineral, char *nome, char *cor, double dureza, double reativ)
{
    setNome(mineral, nome);
    setCor(mineral, cor);
    setDureza(mineral, reativ);
    setReatividade(mineral, dureza);
}
void RetornaMineral(Mineral *mineral, char *nome){
    if (strcmp(nome, "Ferrolita") == 0)
    {
        strcpy(mineral->nome, "Ferrolita");
        strcpy(mineral->cor, "Acinzentado");
        mineral->dureza = 0.5;
        mineral->reativ = 0.7;
    }
    else if (strcmp(nome, "Solarium") == 0)
    {
        strcpy(mineral->nome, "Solarium");
        strcpy(mineral->cor, "Amarelo");
        mineral->dureza = 0.9;
        mineral->reativ = 0.2;
    }
    else if (strcmp(nome, "Aquavitae") == 0)
    {
        strcpy(mineral->nome, "Aquavitae");
        strcpy(mineral->cor, "Azulado");
        mineral->dureza = 0.5;
        mineral->reativ = 0.8;
    }
    else if (strcmp(nome, "Terranita") == 0)
    {
        strcpy(mineral->nome, "Terranita");
        strcpy(mineral->cor, "Marrom");
        mineral->dureza = 0.7;
        mineral->reativ = 0.6;
    }
    else if (strcmp(nome, "Calaris") == 0)
    {
        strcpy(mineral->nome, "Calaris");
        strcpy(mineral->cor, "Vermelho");
        mineral->dureza = 0.6;
        mineral->reativ = 0.5;
    }
    else
    {
        printf("Pedra invalida, digite novamente:");
    }
}

void setNome(Mineral *mineral, char *nome)
{
    strcpy(mineral->nome, nome);
}
void setCor(Mineral *mineral, char *cor)
{
    strcpy(mineral->cor, cor);
}
void setDureza(Mineral *mineral, double dureza)
{
    mineral->dureza = dureza;
}
void setReatividade(Mineral *mineral, double reativ)
{
    mineral->reativ = reativ;
}

char *getNome(Mineral *mineral)
{
    return mineral->nome;
}
char *getCor(Mineral *mineral)
{
    return mineral->cor;
}
double getDureza(Mineral *mineral)
{
    return mineral->dureza;
}
double getReatividade(Mineral *mineral)
{
    return mineral->reativ;
}