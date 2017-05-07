#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.c"

void palindromo (int n);

////////////////////////////////////////////////////////////
////					Palindromo.c					////
////													////
////													////
//// Se genera un palindromo automaticamente al darle	////
//// un valor aleatorio a x, el usuario indica el num 	////
//// iteraciones que hará el programa, generando un 	////
//// palíndromo utilizando la estructura pila.			////
////													////
////													////
//// Autor: Romero Gamarra Joel Mauricio				////
////////////////////////////////////////////////////////////

int main (int argc, char const *argv[])
{
	int n;
	system ("cls");
	printf ("%cCuantas iteraciones desea?:\t", 168);
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
		x = rand()%10;
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
		printf("Iteraci%cnn #%d\nValor de x:\t%d\nPal%cndromo:\t", 162, i+1, x, 161);
		while (!empty (auxiliar))
		{
			printf ("%d", top (auxiliar).p);
			push (&principal, pop (&auxiliar));
		}
		printf("\n\n");
	}
	printf("\n\n\n");
}
