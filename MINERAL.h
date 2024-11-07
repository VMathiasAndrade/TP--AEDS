typedef struct

{
char nome[50], cor[50];
double reatividade, dureza;
} Mineral;

void InicializaMineral (Mineral *mineral, char *nome, char *cor, double reatividade, double dureza);

char *getNome (Mineral *mineral);
char *getCor (Mineral *mineral);
double *getDureza (Mineral *mineral);
double *getReatividade (Mineral *mineral);

void setNome (Mineral *mineral, char *nome);
void setCor (Mineral *mineral, char *cor);
void setReatividade (Mineral *mineral, double reatividade);
void setDureza (Mineral *mineral, double dureza);
void ImprimeMineral (Mineral *mineral);
void PreencheMineral (Mineral *mineral);
Mineral RetornaMineral (char *mineral);