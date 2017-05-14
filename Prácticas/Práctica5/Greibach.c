#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.c"

int OtraVez ();
boolean Chomsky (char *s);
void ImprimeLista (lista *Lista);
void LimpiarGramatica (lista *Lista); 
boolean Inalcanzable (lista *Lista, elemento E, int n);
boolean Unitaria (lista *Lista, elemento E, int n);
void Reemplazar (lista *Lista, elemento E, int n);
boolean LetraMayuscula (lista *Lista, elemento E, int n);
void ConvertirFNG (lista *Lista);
void CombinarProduccion (lista *Lista, elemento E, int n);

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
	Initialize (&GLC);			//Inicializamos la lista
	while (opc != 2)
	{
		system ("cls");
		printf("\n\nIngrese la producci%cn de %c:\n\n\n%c\t->\t", 162, letra, letra);					//Guardamos el símbolo
		E.id = letra++;
		scanf ("%s",E.c);
		if (!Chomsky (E.c))
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
	LimpiarGramatica (&GLC);			//Limpiamos la gramática
	ConvertirFNG (&GLC);
	printf("\n\n\nGram%ctica Libre de Contexto en la Forma Normal de Greibach\n\n", 160);
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

boolean Chomsky (char *s)
{
	char *pt = s;
	int nMay = 0, nmin = 0;
	boolean resp = TRUE;
	for (; *pt != '\0'; pt++)
	{
		if ((*pt >= 'a' && *pt <= 'z') || (*pt >= '0' && *pt <= '9'))		//Si es un símbolo TERMINAL
		{
			if (nmin == 0)
			{
				nmin++;
			}else
			{
				resp = FALSE;
				break;
			}
		}else if (*pt >= 'A' && *pt <= 'Z')								//Si es un símbolo NO TERMINAL
		{
			if (nMay == 0 || nMay == 1)
			{
				nMay++;
			}else
			{
				resp = FALSE;
				break;
			}
		}else if (*pt == '\0')
		{
			if ((nMay == 2 || nMay == 0) && (nmin == 1 || nmin == 0))
			{
				resp = TRUE;
			}else
			{
				resp = FALSE;
				break;
			}
		}else if (*pt == '|')
		{
			if ((nMay == 2 || nMay == 0) && (nmin == 1 || nmin == 0))
			{
				nMay = 0; nmin = 0;
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
	}
	return resp;
}

void ImprimeLista (lista *Lista)
{
	elemento E;
	int i,num_elem;
	num_elem = Size(Lista);
	if(!Empty (Lista))
	{
		for(i = 1; i <= num_elem; i++)
		{
			E = Element(Lista,i);
			printf("\n%c\t->\t%s", E.id, E.c);
		}
	}
	else
	{
		printf("\nLista Vacia");
	}
	return;	
}

void LimpiarGramatica (lista *Lista)
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
			nElementos--;i--;
		}else if (Unitaria (Lista, E, nElementos))
		{
			Reemplazar (Lista, E, nElementos);				//Reemplazamos los símbolos de las producciones unitarias donde corresponde
			//i--;
		}
	}
}

boolean Inalcanzable (lista *Lista, elemento E, int n)
{
	boolean resp = TRUE;
	int i;
	char identificador = E.id;
	elemento auxiliar;
	char *pt;
	if (E.id != 'A')							//Si no es el primer elemento de la lista
	{
		for (i = 1; i <= n; i++)
		{
			auxiliar = Element (Lista, i);					//Obtenemos todos los elementos de la lista
			pt = auxiliar.c;								//Ponemos un apuntador a la producción de cada elemento de la lista
			for (; *pt != '\0'; pt++)
			{
				if (*pt >= 'A' && *pt <= 'Z')
				{
					if (*pt == identificador)
					{
						resp = FALSE;
						break;
					}
				}
			}
		}
	}else
	{
		resp = FALSE;
	}
	return resp;
}

boolean Unitaria (lista *Lista, elemento E, int n)
{
	boolean resp = TRUE;
	char *pt;
	int letra = 0;
	if (E.id != 'A')
	{
		for (pt = E.c; *pt != '\0'; pt++)
		{
			if (*pt >= 'a' && *pt <= 'z')
			{
				letra++;
				if (letra == 2)						//Si hay más de 2 letras minúsculas
				{
					resp = FALSE;
					break;
				}
			}else
			{
				resp = FALSE;
				break;
			}
		}
	}else
	{
		resp = FALSE;
	}
	return resp;
}

void Reemplazar (lista *Lista, elemento E, int n)
{
	int i;
	char *pt, *ptr = E.c;
	posicion pos;
	elemento auxiliar;
	for (i = 1; i <= n; i++)
	{
		auxiliar = Element (Lista, i);						//Obtenemos todos los elementos de la lista
		pos = Search (Lista, auxiliar);
		for (pt = auxiliar.c; *pt != '\0'; pt++)			//Apuntador que recorre toda la producción de todos los elementos de la lista
		{
			if (*pt == E.id && (*(pt - 1) == '|' || *(pt - 1) == '\0'))
			{
				*pt = *ptr;
			}
			Replace (Lista, pos, auxiliar);
		}
	}
}

boolean LetraMayuscula (lista *Lista, elemento E, int n)
{
	char *pt = E.c;
	int mayus = 0;
	boolean resp = FALSE;
	for (; *pt != '\0'; pt++)
	{
		if (*pt >= 'A' && *pt <= 'Z')
		{
			mayus++;
		}else if ((*pt == '|' || *pt == '\0') && mayus != 2)
		{
			mayus = 0;
		}else if (mayus == 2)
		{
			resp = TRUE;;
			break;
		}
	}
	return resp;
}

void ConvertirFNG (lista *Lista)
{
	elemento E;
	int i, nElementos;
	nElementos = Size (Lista);
	for (i = 1; i <= nElementos; i++)
	{
		E = Element (Lista, i);							//Obtenemos todos los elementos de la lista
		if (LetraMayuscula (Lista, E, nElementos))
		{
			CombinarProduccion (Lista, E, nElementos);
		}
	}
}

void CombinarProduccion (lista *Lista, elemento E, int n)
{
	char nueva[35], *pt = E.c, *ptr, *apuntador = nueva;
	int i;
	elemento elementoFinal, auxiliar;
	elementoFinal.id = E.id;
	posicion pos;
	pos = Search (Lista, E);
	for (; *pt != '\0'; pt++)				//Recorremos toda la producción del elemento que no está en Greibach
	{
		for (i = 1; i <= n; i++)			//Obtenemos todos los elementos de la lista
		{
			auxiliar = Element (Lista, i);
			if (*pt == auxiliar.id)
				break;
		}
		if (*pt == auxiliar.id)
			break;
	}
	pt++;									//Ya está apuntando a C
	for (ptr = auxiliar.c; *ptr != '\0'; ptr++)			//Recorremos desde el principio la cadena del elemento que vamos a sustituir en E.c
	{
		if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
		{
			*apuntador++ = *ptr;
		}else if (*ptr == '|')
		{
			*apuntador++ = *pt;
			*apuntador++ = *ptr;
		}
	}
	*apuntador++ = *pt++;
	printf("\n\n\n\n");
	for (; *pt != '\0'; pt++)
	{
		*apuntador++ = *pt;
	}
	*apuntador = '\0';
	strcpy (elementoFinal.c, nueva);
	Replace (Lista, pos, elementoFinal);
}