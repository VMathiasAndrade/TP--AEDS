#ifndef MINERAL_H
#define MINERAL_H

typedef struct
{
char nome[50], cor[50], propriedades[50];
double reativ, dureza;
} Mineral;

void InicializaMineral(Mineral* mineral, char* nome, char* cor, double dureza, double reativ, char* propriedades);

Mineral RetornaMineral (Mineral* mineral, char* nome, char* cor, char* propriedades, double reativ, double dureza);

char* getNome(Mineral* mineral);
char* getCor(Mineral* mineral);
char* getPropriedades(Mineral* mineral);
double getDureza(Mineral* mineral);
double getReatividade(Mineral* mineral);

void setNome(Mineral* mineral, char* nome);
void setCor(Mineral* mineral, char* cor);
void setPropriedades(Mineral* mineral, char* propriedades);
void setReatividade(Mineral* mineral, double reativ);
void setDureza(Mineral* mineral, double dureza);

#endif