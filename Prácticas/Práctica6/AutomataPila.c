#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 70
#include "pila.c"

void ImprimirSeptupla (FILE * pt);
booleano verificarCadena (char * cadena);

typedef unsigned char boolean;
typedef struct septupla 																//Estructura para almacenar septupla del automata
{
	char p [MAX];
}septupla;

////////////////////////////////////////////////////////////////////////////////////////
////								AutomataPila.c 									////
////																				////
////																				////
//// Automata de pila que reconoce el lenguaje que haya igual número de 0's que 	////
//// de 1's, el autómata fue diseñado personalmente y la septupla junto con la 		////
//// tabla de transiciones son obtenidas de un archivo.								////
//// Modificar: "Septupla.txt" y "TablaTransiciones.txt".							////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	int x, opc;
	FILE *pt;
	char * expresion = (char *) malloc (sizeof (char *));;
	pt = fopen ("Septupla.txt", "r");
	system ("cls");
	printf("%cQue desea hacer?\n", 168);
	printf("\n1.Mostrar septupla\t\t2.Ingresar Cadenas\n\n");
	scanf ("%d", &x);
	system ("cls");
	if (x == 1)
		ImprimirSeptupla (pt);
	else
	{
		while (opc != 2)
		{
			system ("cls");
			printf("Ingrese la cadena:\t");
			scanf ("%s", expresion);
			if (verificarCadena (expresion))
			{
				printf("\n\n\nExpresion correcta.\n");
			}else
			{
				printf("\n\n\nExpresion incorrecta.\n");
			}
			printf("%cDesea ingresar otra cadena?\n", 168);
			printf("1.SI\t\t2.NO\n\n");
			scanf ("%d", &opc);
		}
	}
	return 0;
}

void ImprimirSeptupla (FILE * pt)
{
	char c;
	septupla automata;													//Estructura de tipo septupla
	fgets (automata.p, 56, pt);
	printf("\n\nP = ( %s )\n\n", automata.p);
	printf("\n\nTabla de transiciones\n");
	fclose (pt);
	pt = fopen ("TablaTransiciones.txt", "r");
	c = fgetc (pt);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc (pt);
	}
	printf("\n\n");
	fclose (pt);
}

booleano verificarCadena (char * cadena)
{
	char *pt = cadena;
	pila stack;
	booleano resp = FALSE;
	ini_pila (&stack);
	NODO D;
	D.x = 'Z';
	push (&stack, D);
	for (; *pt != '\0'; pt++)
	{
		/*if ((*pt == '1') && (empty (stack)))
		{
			printf("Encontramos un 1\n");
			D.x = 'U';
			push(&stack, D);
		}else if ((*pt == '0') && (empty (stack)))
		{
			D.x = 'C';
			push(&stack, D);
		}else if ((*pt == '1') && (top (stack).x == '1'))
		{
			D.x = 'U';
			push(&stack, D);
		}else if ((*pt == '0') && (top (stack).x == '0'))
		{
			D.x = 'C';
			push(&stack, D);
		}else if ((*pt == '1') && (top (stack).x == '0'))
		{
			printf ("Se va a sacar:\t%c", pop (&stack).x);
		}else if ((*pt == '0') && (top (stack).x == '1'))
		{
			printf ("Se va a sacar:\t%c", pop (&stack).x);
		}else if (*pt != '0' && *pt != '1')
		{
			printf("La expresion no corresponde al alfabeto de entrada.\n");
			resp = FALSE;
			break;
		}*/
		printf("El tope de la pila es:\t%c\n", top(stack).x);
	}
	printf("El fondo de la pila es:\t%c\n", top(stack).x);
	/*if (top (stack).x == 'Z')
		resp = TRUE;
	else
		resp = FALSE;*/
	return resp;
}