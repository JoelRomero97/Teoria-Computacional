#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 70
#include "pila.c"

void ImprimirSeptupla (FILE * pt);
booleano verificarCadena (char * cadena);

typedef struct septupla 																//Estructura para almacenar septupla del automata
{
	char sept [MAX];
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
	MENU:
	system ("cls");
	printf("%cQue desea hacer?\n", 168);
	printf("\n1.Mostrar septupla\t\t2.Ingresar Cadenas\n\n");
	scanf ("%d", &x);
	if (x == 1)
	{
		system ("cls");
		ImprimirSeptupla (pt);
		printf("%cDesea regresar al menu principal?\n", 168);
		printf("1.SI\t\t2.NO\n\n");
		scanf ("%d", &opc);
		if (opc == 1)
			goto MENU;
		else
			return 0;
	}else
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
	fgets (automata.sept, 56, pt);
	printf("\n\nP = ( %s )\n\n", automata.sept);
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
	int i = 1;
	pila stack;
	booleano resp = FALSE;
	ini_pila (&stack);
	NODO D;
	D.x = 'Z';
	push (&stack, D);
	for (; *pt != '\0'; pt++)
	{
		if (*pt == '1')
		{
			if ((top (stack).x == 'Z') || top (stack).x == 'U')
			{
				D.x = 'U';
				printf("Se va a insertar '%c' en la pila.\n", D.x);
				push (&stack, D);
			}else
			{
				printf ("Se va a sacar '%c' de la pila.\n", pop (&stack).x);
			}
		}else if (*pt == '0')
		{
			if ((top (stack).x == 'Z') || (top (stack).x == 'C'))
			{
				D.x = 'C';
				printf("Se va a insertar '%c' en la pila.\n", D.x);
				push (&stack, D);
			}else
			{
				printf ("Se va a sacar '%c' de la pila.\n", pop (&stack).x);
			}
		}else 
		{
			printf("La expresion no corresponde al alfabeto de entrada.\n");
			resp = FALSE;
			break;
		}
		printf("El tope de la pila en la iteracion %d es:\t%c\n\n", i++, top(stack).x);
	}
	if (top (stack).x == 'Z')
		resp = TRUE;
	else
		resp = FALSE;
	return resp;
}