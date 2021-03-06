#include <stdio.h>
#include "Quadra.h"
#include <stdlib.h>
#include "CalculoCirculoRetangulo.h"
#include "Retangulo.h"

typedef struct{
	double x;
	double y;
	double w;
	double h;
	char *cep;
	char *corPreenchimento;
	char *corContorno;
} quadra;

Quadra createQuadra(double x, double y, double width, double height, char *cep){
	quadra *newQuadra;
	newQuadra = (quadra*)malloc(sizeof(quadra));
	newQuadra->x = x;
	newQuadra->y = y;
	newQuadra->w = width;
	newQuadra->h = height;
	newQuadra->cep = cep;
	newQuadra->corContorno = NULL;
	newQuadra->corPreenchimento = NULL;
	return (Quadra) newQuadra;
}

char *getQuadraCorContorno(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->corContorno;
}

char *getQuadraCorPreenchimento(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->corPreenchimento;
}

char *getQuadraCep(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->cep;
}

double getQuadraX(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->x;
}

double getQuadraY(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->y;
}

double getQuadraWidth(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->w;
}

double getQuadraHeight(Quadra q){
	quadra *newQuadra = (quadra*)q;
	return newQuadra->h;
}

void setQuadraCorPreenchimento(Quadra q, char *cor){
	quadra *newQuadra = (quadra*)q;
	if (newQuadra->corPreenchimento != NULL)
		free(newQuadra->corPreenchimento);
	newQuadra->corPreenchimento = cor;
}

void setQuadraCorContorno(Quadra q, char *cor){
	quadra *newQuadra = (quadra*)q;
	if (newQuadra->corContorno != NULL)
		free(newQuadra->corContorno);
	newQuadra->corContorno = cor;
}

int quadraInternaRetangulo(FILE **txt, Quadra q, Retangulo r){
	int var = 0;
	var = pontoInternoRetangulo(r, getQuadraX(q), getQuadraY(q));
	if (var == 1){
		var = pontoInternoRetangulo(r, (getQuadraX(q) + getQuadraWidth(q)), getQuadraY(q));
		if (var == 1){
			var = pontoInternoRetangulo(r, (getQuadraX(q) + getQuadraWidth(q)), (getQuadraY(q) + getQuadraHeight(q)));
			if (var == 1){
				var = pontoInternoRetangulo(r, getQuadraX(q), (getQuadraY(q) + getQuadraHeight(q)));
				if (var == 1){
					if (*txt != NULL)
						fprintf(*txt, "%s %f %f %f %f %s %s\n", getQuadraCep(q), getQuadraX(q), getQuadraY(q), getQuadraHeight(q), getQuadraWidth(q), getQuadraCorPreenchimento(q), getQuadraCorContorno(q));					
					return 1;
				}
			}
		}
	}
	return 0;
}

int quadraInternaCirculo(FILE **txt, Quadra q, Circulo c){
	int ver;
	ver = pontoInternoCirculo(c, getQuadraX(q), getQuadraY(q));
	if (ver == 1){
		ver = pontoInternoCirculo(c, (getQuadraX(q) + getQuadraWidth(q)), getQuadraY(q));
		if (ver == 1){
			ver = pontoInternoCirculo(c, (getQuadraX(q) + getQuadraWidth(q)), (getQuadraY(q) + getQuadraHeight(q)));
			if (ver == 1){
				ver = pontoInternoCirculo(c, getQuadraX(q), (getQuadraY(q) + getQuadraHeight(q)));
				if (ver == 1){
					if (*txt != NULL)
						fprintf(*txt, "%s %f %f %f %f %s %s\n", getQuadraCep(q), getQuadraX(q), getQuadraY(q), getQuadraHeight(q), getQuadraWidth(q), getQuadraCorPreenchimento(q), getQuadraCorContorno(q));
					return 1;
				}
			}
		}
	}
	return 0;
}

void freeQuadra(Quadra q){
	quadra *newQuadra = (quadra*)q;
	if (newQuadra->corPreenchimento != NULL)
		free(newQuadra->corPreenchimento);
	if (newQuadra->corContorno != NULL)
		free(newQuadra->corContorno);
	if (newQuadra->cep != NULL)
		free(newQuadra->cep);
}