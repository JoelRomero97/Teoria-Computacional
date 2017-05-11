#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"

int OtraVez ();
boolean Chomsy (char *s);
void ImprimeLista (lista *l);

////////////////////////////////////////////////////////////////////////////////////////
////									Greibach.c									////
////																				////
////																				////
//// Programa que al ingresar una GLC que está en la Forma Normal de Chomsy (FNC)	////
//// se modifica para mostrar al usuario la misma GLC pero convertida a la Forma	////
//// Normal de Greibach (FNG) utilizando la estructura lista.						////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	int opc;						//Declaramos un auxiliar para OtraVez ()
	int letra = 65;					//Declaramos 'letra' con el caracter ASCII 65, equivalente a la letra 'A'
	lista GLC;						//Declaramos la lista
	posicion pos;					//Posición para manear las funciones
	elemento E;						//Elemento para guardar las GLC
	Initialize (&GLC);				//Inicializamos la lista
	while (opc != 2)
	{
		system ("cls");
		printf("\n\nIngrese la producci%cn de %c:\n\n\n%c\t->\t", 162, letra, letra);					//Guardamos el símbolo
		E.id = letra++;
		scanf ("%s",E.c);
		if (!Chomsy (E.c))
		{
			printf("Error, la producci%cn %c%c\t\t->\t%s%c no est%c en FNC\n", 162, 34 ,E.id, E.c, 34, 160);
			return 0;
		}else
		{
			Add (&GLC, E);
			opc = OtraVez();
		}
	}
	ImprimeLista (&GLC);
	return 0;
}

int OtraVez ()
{
	int resp;
	printf("\n\n%cDesea ingresar otra producci%cn?", 168, 162);
	printf("\n\n1.SI\t\t2.NO\n\n");
	scanf ("%d",&resp);
	return resp;
}

boolean Chomsy (char *s)							//Si está en FNC, regresa TRUE
{
	char *pt = s;
	if ((*pt >= 'a' && *pt <= 'z') || (*pt >= '0' && *pt <= '9'))		//Si es un símbolo TERMINAL
	{
		pt++;
		if (*pt == '\0')
		{
			return TRUE;
		}else
		{
			return FALSE;
		}
	}else if (*pt >= 'A' && *pt <= 'Z')								//Si es un símbolo NO TERMINAL
	{
		pt++;
		if (*pt >= 'A' && *pt <= 'Z')
		{
			pt++;
			if (*pt == '\0')
			{
				return TRUE;
			}else
			{
				return FALSE;
			}
		}
	}
}

void ImprimeLista (lista *l)
{
	posicion p;
	elemento E;
	int i,num_elem;
	num_elem = Size(l);
	if(!Empty (l))
	{
		//Mientras la posición sea valida
		for(i = 1; i <= num_elem; i++)
		{
			E = Element(l,i);
			printf("\n%c\t->\t%s", E.id, E.c);
		}
	}
	else
	{
		printf("\nLista Vacia");
	}
	return;	
}