#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"

int OtraVez ();
boolean Chomsy (char *s);
void ImprimeLista (lista *l);
void ConvertirFNG (lista *Lista);
boolean Inalcanzable (lista *lista, elemento E, int n);

////////////////////////////////////////////////////////////////////////////////////////
////									Greibach.c									////
////																				////
////																				////
//// Programa que al ingresar una GLC que está en la Forma Normal de Chomsky (FNC)	////
//// se modifica para mostrar al usuario la misma GLC pero convertida a la Forma	////
//// Normal de Greibach (FNG) utilizando la estructura lista.						////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
	int opc;						//Declaramos un entero auxiliar para OtraVez ()
	int letra = 65;					//Declaramos 'letra' con el caracter ASCII 65, equivalente a la letra 'A'
	lista GLC;						//Declaramos la lista
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
	printf("\n\n\nGram%ctica Libre de Contexto en la Forma Normal de Chomsky\n\n", 160);
	ImprimeLista (&GLC);
	ConvertirFNG (&GLC);			//Convertimos la GLC ingresada por el usuario a Greibach
	//printf("\n\n\nGram%ctica Libre de Contexto en la Forma Normal de Greibach\n\n", 160);
	//ImprimeLista (&GLC);
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

boolean Chomsy (char *s)
{
	char *pt = s;
	boolean resp;
	for (; *pt != '\0'; pt++)
	{
		if ((*pt >= 'a' && *pt <= 'z') || (*pt >= '0' && *pt <= '9'))		//Si es un símbolo TERMINAL
		{
			pt++;
			if (*pt == '\0' || *pt == '|')
			{
				resp = TRUE;
				pt++;
			}else
			{
				resp = FALSE;
				break;
			}
		}else if (*pt >= 'A' && *pt <= 'Z')								//Si es un símbolo NO TERMINAL
		{
			pt++;
			if (*pt >= 'A' && *pt <= 'Z')
			{
				pt++;
				if (*pt == '\0' || *pt == '|')
				{
					resp = TRUE;
					pt++;
				}else
				{
					resp = FALSE;
					break;
				}
			}else
			{
				resp = FALSE;
				break;
			}
		}else
		{
			resp = FALSE;
		}
	}
	return resp;
}

void ImprimeLista (lista *l)
{
	elemento E;
	int i,num_elem;
	num_elem = Size(l);
	if(!Empty (l))
	{
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

void ConvertirFNG (lista *Lista)
{
	posicion p;										//Posicion para manejar las funciones
	elemento E;
	int i, nElementos;
	nElementos = Size (Lista);						//Obtenemos el numero de elementos de la lista
	for (i = 1; i <= nElementos; i++)
	{
		E = Element (Lista, i);						//Obtenemos cada uno de los elementos de la lista
		if (Inalcanzable (Lista, E, nElementos))
		{
			p = Search (Lista, E);						//Obtenemos la posición de la producción inalcanzable
			Remove (Lista, p);							//Eliminamos la producción inalcanzable
		}else
		{
			//printf("\nLa produccion de %c no es inalcanzable", E.id);
		}
	}
}

boolean Inalcanzable (lista *lista, elemento E, int n)
{
	boolean resp;
	int i;
	elemento auxiliar;
	char *pt = E.c;
	if (E.id != 'A')							//Si no es el primer elemento de la lista
	{
		if (*pt >= 'A' && *pt <= 'Z')			//Si produce 2 símbolos NO TERMINALES
		{
			char *pt1 = pt;
			pt1++;
			for (i = 1; i <= n; i++)
			{
				auxiliar = Element (lista, i);
				//AQUI FALTA TERMINAR LA FUNCION PARA SABER SI ES O NO INALCANZABLE
			}
		}
	}else
	{
		resp = FALSE;
	}
	return resp;
}