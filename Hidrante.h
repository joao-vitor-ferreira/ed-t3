#ifndef HIDRANTE_H
#define HIDRANTE_H
#include "Retangulo.h"
#include "Circulo.h"

	typedef void *Hidrante;

Hidrante createHidrante(double x, double y, char *id);
double getHidranteX(Hidrante h);
double getHidranteY(Hidrante h);
char *getHidranteId(Hidrante h);
char *getHidranteCorPreenchimento(Hidrante h);
char *getHidranteCorContorno(Hidrante h);
void setHidranteCorPreenchimento(Hidrante h, char *cor);
void setHidranteCorContorno(Hidrante h, char *cor);
int hidranteInternoRetangulo(FILE **txt, Hidrante h, Retangulo r);
int hidranteInternoCirculo(FILE **txt, Hidrante h, Circulo c);
void freeHidrante(Hidrante h);

#endif