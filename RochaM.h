#ifndef ROCHAM_H
#define ROCHAM_H
#include "ListaMinerais.h"

typedef struct
{
    int id;
    float peso;
    char categoria[40], dataColeta[20];
    double latitude, longitude;
    ListaMinerais LMinerais;
} RochaMineral;

void InicializaRocha(RochaMineral *rocha, int id, float peso, char *categoria, char *dataColeta, double latitude, double longitude);
char *DefCategoria(RochaMineral *rocha);

int getIdentificador(RochaMineral *rocha);
float getPeso(RochaMineral *rocha);
char *getCategoria(RochaMineral *rocha);
char *getDataColeta(RochaMineral *rocha);
double getLatitude(RochaMineral *rocha);
double getLongitude(RochaMineral *rocha);

void setIdentificador(RochaMineral *rocha, int id);
void setPeso(RochaMineral *rocha, float peso);
void setCategoria(RochaMineral *rocha, char *categoria);
void setDataColeta(RochaMineral *rocha, char *dataColeta);
void setLocalizacao(RochaMineral *rocha, double latitude, double longitude);
//.
#endif