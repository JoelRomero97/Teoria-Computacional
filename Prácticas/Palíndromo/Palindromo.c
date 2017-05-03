#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void palindromo (int n);

int main (int argc, char const *argv[])
{
	int n;
	system ("clear");
	printf ("¿Cuantas iteraciones desea?:\t");
	scanf ("%d",&n);
	palindromo(n);
	return 0;
}

void palindromo (int n)
{
	int i, x;
	pila principal, auxiliar, final;
	NODO D, E;
	ini_pila (&principal);ini_pila (&auxiliar);		//Inicializamos ambas pilas
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		x = rand()%100;
		D.p = x;E.p = x;
		if (i == 0)
		{
			push (&auxiliar,D);
		}else
		{
			push (&auxiliar, D);
			while (!empty (principal))				//Mientras haya elementos en la pila principal
			{
				push (&auxiliar, pop (&principal));			//Se guarda todo en una pila auxiliar
			}
			push (&auxiliar, E);
		}
		printf("Iteración #%d\nValor de x:\t%d\nPalíndromo:\t", i+1, x);
		while (!empty (auxiliar))
		{
			printf ("%d", top (auxiliar).p);
			push (&principal, pop (&auxiliar));
		}
		printf("\n\n");
	}
	printf("\n\n\n");
}